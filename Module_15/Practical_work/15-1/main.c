#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <stdbool.h>


static const unsigned WIN_MASKS[8] = {
    0b111000000, 0b000111000, 0b000000111, // строки
    0b100100100, 0b010010010, 0b001001001, // столбцы
    0b100010001, 0b001010100               // диагонали
};
static const unsigned FULL_MASK = 0x1FFu; // 9 младших битов

static inline unsigned BitAt(int row, int col) {
    // Разметка битов:
    // 8 7 6
    // 5 4 3
    // 2 1 0
    int idx = row*3 + col;            // 0..8
    return 1u << (8 - idx);
}

static inline bool CheckWin(unsigned bits, unsigned *winMaskOut) {
    for (int i = 0; i < 8; ++i) {
        unsigned m = WIN_MASKS[i];
        if ((bits & m) == m) { if (winMaskOut) *winMaskOut = m; return true; }
    }
    return false;
}

static inline bool CheckDraw(unsigned xb, unsigned ob) {
    return ((xb | ob) == FULL_MASK);
}


typedef struct {
    unsigned xb;     // биты X
    unsigned ob;     // биты O
    int turn;        // 0 = X, 1 = O
    bool finished;   // игра окончена
    unsigned winMask;// маска выигрышной линии
} Game;

static Game GameNew(void) {
    Game g = {0};
    g.turn = 0;
    g.finished = false;
    g.winMask = 0;
    return g;
}


static bool CellFromMouse(Vector2 p, int w, int h, int *row, int *col) {
    if (p.x < 0 || p.y < 0 || p.x >= w || p.y >= h) return false;
    *col = (int)(p.x / (w/3.0f));
    *row = (int)(p.y / (h/3.0f));
    if (*col < 0 || *col > 2 || *row < 0 || *row > 2) return false;
    return true;
}

static bool PlaceMove(Game *g, int row, int col) {
    unsigned bit = BitAt(row, col);
    if ((g->xb | g->ob) & bit) return false;        // занято
    if (g->turn == 0) g->xb |= bit; else g->ob |= bit;


    g->winMask = 0;
    if (CheckWin(g->turn == 0 ? g->xb : g->ob, &g->winMask)) {
        g->finished = true;
    } else if (CheckDraw(g->xb, g->ob)) {
        g->finished = true;
    } else {
        g->turn ^= 1;
    }
    return true;
}


static void DrawBoardGrid(int w, int h, Color color, float thick) {
    float cw = w/3.0f, ch = h/3.0f;
    DrawLineEx((Vector2){cw, 0},      (Vector2){cw, (float)h}, thick, color);
    DrawLineEx((Vector2){2*cw, 0},    (Vector2){2*cw, (float)h}, thick, color);
    DrawLineEx((Vector2){0, ch},      (Vector2){(float)w, ch}, thick, color);
    DrawLineEx((Vector2){0, 2*ch},    (Vector2){(float)w, 2*ch}, thick, color);
}

static void DrawSymbolXO(int row, int col, int w, int h, bool isX, Color color) {
    float cw = w/3.0f, ch = h/3.0f;
    float x = col*cw, y = row*ch;
    Vector2 c = { x + cw*0.5f, y + ch*0.5f };
    float r = (cw < ch ? cw : ch) * 0.27f;
    float thick = (cw < ch ? cw : ch) * 0.1f;

    if (isX) {
        Vector2 a1 = { c.x - r, c.y - r }, b1 = { c.x + r, c.y + r };
        Vector2 a2 = { c.x - r, c.y + r }, b2 = { c.x + r, c.y - r };
        DrawLineEx(a1, b1, thick, color);
        DrawLineEx(a2, b2, thick, color);
    } else {
        DrawRing(c, r - thick*0.5f, r + thick*0.5f, 0, 360, 64, color);
    }
}

static void HighlightWin(unsigned winMask, int w, int h, Color color) {
    if (!winMask) return;
    float cw = w/3.0f, ch = h/3.0f;
    Color fill = (Color){ color.r, color.g, color.b, 70 };

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (winMask & BitAt(r,c)) {
                DrawRectangle((int)(c*cw), (int)(r*ch), (int)cw, (int)ch, fill);
            }
        }
    }
}

static inline int ScoreTerminal(unsigned xb, unsigned ob, int ai, int depth) {
    unsigned tmp;
    if (CheckWin(xb, &tmp))  return (ai == 0) ? (10 - depth) : (depth - 10);
    if (CheckWin(ob, &tmp))  return (ai == 1) ? (10 - depth) : (depth - 10);
    if (CheckDraw(xb, ob))   return 0;
    return 666666; // не терминал
}

static int Minimax(unsigned xb, unsigned ob, int turn, int ai, int depth, int alpha, int beta) {
    int term = ScoreTerminal(xb, ob, ai, depth);
    if (term != 666666) return term;

    unsigned empty = (~(xb | ob)) & FULL_MASK;

    if (turn == ai) {
        int best = -10000;
        while (empty) {
            unsigned bit = empty & -empty;
            empty -= bit;
            unsigned nxb = xb, nob = ob;
            if (turn == 0) nxb |= bit; else nob |= bit;

            int val = Minimax(nxb, nob, turn ^ 1, ai, depth + 1, alpha, beta);
            if (val > best) best = val;
            if (val > alpha) alpha = val;
            if (beta <= alpha) break;
        }
        return best;
    } else {
        int best = 10000;
        while (empty) {
            unsigned bit = empty & -empty;
            empty -= bit;
            unsigned nxb = xb, nob = ob;
            if (turn == 0) nxb |= bit; else nob |= bit;

            int val = Minimax(nxb, nob, turn ^ 1, ai, depth + 1, alpha, beta);
            if (val < best) best = val;
            if (val < beta) beta = val;
            if (beta <= alpha) break;
        }
        return best;
    }
}

static void RowColFromBit(unsigned bit, int *row, int *col) {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (BitAt(r,c) == bit) { *row = r; *col = c; return; }
}

static void BestMoveAI(const Game *g, int ai, int *outRow, int *outCol) {
    unsigned xb = g->xb, ob = g->ob;
    int turn = g->turn;
    unsigned empty = (~(xb | ob)) & FULL_MASK;

    int bestScore = (ai == turn) ? -10000 : 10000;
    unsigned bestBit = 0;

    while (empty) {
        unsigned bit = empty & -empty;
        empty -= bit;

        unsigned nxb = xb, nob = ob;
        if (turn == 0) nxb |= bit; else nob |= bit;

        int val = Minimax(nxb, nob, turn ^ 1, ai, /*depth*/1, -10000, 10000);

        if (ai == g->turn) {
            if (val > bestScore) { bestScore = val; bestBit = bit; }
        } else {
            if (val < bestScore) { bestScore = val; bestBit = bit; }
        }
    }

    if (bestBit == 0) {
        unsigned avail = (~(g->xb | g->ob)) & FULL_MASK;
        bestBit = avail & -avail;
    }

    RowColFromBit(bestBit, outRow, outCol);
}

int main(void) {
    const int W = 600, H = 600;
    InitWindow(W, H, "Tic-Tac-Toe");
    SetTargetFPS(60);

    Game g = GameNew();

    const int AI_SIDE = 1;
    if (g.turn == AI_SIDE) {
        int r, c; BestMoveAI(&g, AI_SIDE, &r, &c); PlaceMove(&g, r, c);
    }

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            g = GameNew();
            if (g.turn == AI_SIDE) {
                int r, c; BestMoveAI(&g, AI_SIDE, &r, &c); PlaceMove(&g, r, c);
            }
        }
        if (!g.finished && g.turn != AI_SIDE && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int r, c;
            if (CellFromMouse(GetMousePosition(), GetScreenWidth(), GetScreenHeight(), &r, &c)) {
                PlaceMove(&g, r, c);
            }
        }
        if (!g.finished && g.turn == AI_SIDE) {
            int r, c; BestMoveAI(&g, AI_SIDE, &r, &c); PlaceMove(&g, r, c);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        int w = GetScreenWidth();
        int h = GetScreenHeight();
        DrawBoardGrid(w, h, DARKGRAY, 6.0f);


        for (int r = 0; r < 3; ++r) for (int c = 0; c < 3; ++c) {
            unsigned bit = BitAt(r,c);
            if (g.xb & bit)      DrawSymbolXO(r, c, w, h, true,  (Color){30, 144, 255, 255});
            else if (g.ob & bit) DrawSymbolXO(r, c, w, h, false, (Color){220, 20, 60, 255});
        }

        if (g.finished && g.winMask) {
            HighlightWin(g.winMask, w, h, GOLD);
        }

        const int fs = 22;
        if (g.finished) {
            if (g.winMask) {
                DrawText((g.turn==1) ? "O wins! (R - restart)"
                                     : "X wins! (R - restart)", 16, h-36, fs, BLACK);
            } else {
                DrawText("Draw! (R - restart)", 16, h-36, fs, BLACK);
            }
        } else {
            DrawText((g.turn==0) ? "Turn: X (you).  R - restart"
                                 : "Turn: O (AI).  R - restart", 16, h-36, fs, GRAY);
        }

        DrawFPS(w-90, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
