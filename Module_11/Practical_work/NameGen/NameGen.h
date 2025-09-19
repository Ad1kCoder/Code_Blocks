#ifndef NAMEGEN_H_INCLUDED
#define NAMEGEN_H_INCLUDED

void init_namegen(void);
void set_namegen_seed(unsigned int seed);

const char *nameM(void);
const char *patronymicM(void);
const char *surnameM(void);

const char *nameF(void);
const char *patronymicF(void);
const char *surnameF(void);

#endif // NAMEGEN_H_INCLUDED
