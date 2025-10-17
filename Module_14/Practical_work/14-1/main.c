#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPL 16 // ���������� ����� �� ������
#define AMP 325 // �������� �������� ���������

#define WIN_R 2 // ������ ���� ���������� (���� ���������� = WIN_R*2+1)


#define MEDIAN       0 // ��������� ������
#define MOV_AVER     1 // ������� �������
#define CUT_MOV_AVER 2 // ��������� ������� �������

#define FILTR_MODE CUT_MOV_AVER


float noiseRatio = 0.2; // ����. ����; 0 - ��� ����, 1 - ��� ����� ���������

float median (float *arr, int n, int i);
float movAverage (float *arr, int n, int i);
float cutMovAverage(float *arr, int n, int i);

int main()
{
    int num;
    //srand (time(NULL));
    srand (0);
    printf(" Enter the number of array elements: \n");
    scanf("%d", &num);
    puts("");
    float *arrC = malloc(num*sizeof(float));
    float *arrN = malloc(num*sizeof(float));
    float *arrF = malloc(num*sizeof(float));
    if (arrC == NULL) return 0;
    if (arrN == NULL) return 0;
    if (arrF == NULL) return 0;
    for (int i = 0; i < num; i++)
    {
        arrC[i] = AMP*sin(((float)1/SAMPL)*i);
        float noise = rand()%2 ? (rand()%AMP)*noiseRatio : (-1)*(rand()%AMP)*noiseRatio;
        arrN[i] = arrC[i] + noise;
    }
    for (int i = 0; i < num; i++)
    {
#if FILTR_MODE == MEDIAN
        arrF[i] = median(arrN, num, i);
#elif FILTR_MODE == MOV_AVER
        arrF[i] = movAverage(arrN, num, i);
#elif FILTR_MODE == CUT_MOV_AVER
        arrF[i] =cutMovAverage (arrN, num, i);
#endif // FILR_MODE
    }
    printf (" Clear            Noise          Filtered\n");
    for (int i = 0; i < num; i++)
    {
        printf (" %f\t %f\t %f\n", arrC[i], arrN[i], arrF[i]);
    }
#if FILTR_MODE == MEDIAN
        FILE *f = fopen("signalMed.tsv", "w");
#elif FILTR_MODE == MOV_AVER
        FILE *f = fopen("signalMovAv.tsv", "w");
#elif FILTR_MODE == CUT_MOV_AVER
        FILE *f = fopen("signalCutMovAv.tsv", "w");
#endif // FILR_MODE
    fprintf(f, "i\tClean\tNoise\tFiltered\n");
    for (int i=0;i<num;++i) fprintf(f, "%d\t%.6f\t%.6f\t%.6f\n", i, arrC[i], arrN[i], arrF[i]);
    fclose(f);
    free(arrC);
    free(arrN);
    free(arrF);
    return 0;
}


float median (float *arr, int n, int i)
{
    const int m = 2*WIN_R + 1;
    if (i < m-1) // ������� ���������
    {
        float sum = 0;
        for (int k = 0; k < m-1; ++k) sum += *(arr + k);
        return (sum/(m-1) + *(arr + i))/2;
    }
    float tmp[m];
    for (int k = 0; k < m; ++k) tmp[k] = *(arr+i-k);
    for (int k = 0; k < m-1; ++k){
        for (int j = 0; j < m-1-k; ++j){
            if (tmp[j] > tmp[j+1]) {
                    float t=tmp[j];
                    tmp[j]=tmp[j+1];
                    tmp[j+1]=t;
            }
        }
    }
    return tmp[WIN_R];
}

float movAverage(float *arr, int n, int i){
    const int m = 2*WIN_R + 1;
    if (i < m-1) // ������� ���������
    {
        float sum = 0;
        for (int k = 0; k < m-1; ++k) sum += *(arr + k);
        return (sum/(m-1) + *(arr + i))/2;
    }
    float sum = 0;
    for (int k = 0; k < m; ++k) sum += *(arr+i-k);
    return sum / m;
}


float cutMovAverage(float *arr, int n, int i){
    const int m = 2*WIN_R + 1;
    if (i < m-1) // ������� ���������
    {
        float sum = 0;
        for (int k = 0; k < m-1; ++k) sum += *(arr + k);
        return (sum/(m-1) + *(arr + i))/2;
    }
    float tmp[m];
    float sum = 0;
    for (int k = 0; k < m; ++k) tmp[k] = *(arr+i-k);
    for (int k = 0; k < m-1; ++k){
        for (int j = 0; j < m-1-k; ++j){
            if (tmp[j] > tmp[j+1]) {
                    float t=tmp[j];
                    tmp[j]=tmp[j+1];
                    tmp[j+1]=t;
            }
        }
    }
    for (int k = 1; k <= m-2; ++k) sum += tmp[k];
    return sum /(m-2);
}

