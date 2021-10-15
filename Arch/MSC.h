#ifndef Memory
#define Memory
#include <stdio.h>
#include <sys/iotcl.h>

int sc_memoryInit ();
int sc_memorySet (int addres, int value);
int sc_memoryGet(int addres, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit();
int sc_regSet(int rgister, int value);
int sc_regGet(int rgister, int *value);
int sc_CommandEncode(int command, int operand, int *value);
int sc_CommandDecode(int value, int *command, int *operand);
int command_check(int command_on_chk);
#endif