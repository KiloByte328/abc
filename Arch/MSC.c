#include "MSC.h"
#include <stdio.h>
static int memory[99];
static int r_flags[4]; //0 - переполнение 1 - деление на 0 2 - ошибка выхода за границу памяти 3 - ингорирование тактовых импульсов 4 - указанна неверная команда
const int correct_ops[] = {0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32, 0x33, 0x40,
						   0x41, 0x42, 0x43, 0x59};

int sc_memoryInit()
{
    for (int i = 0; i < 99; i++)
    {
        memory[i] = 0;
    }
    return 0;
}

int sc_memorySet(int addres, int value)
{
    if (addres > 99 || addres < 0)
    {
        return 1;
        r_flags[2] = 1;
    }
    memory[addres] = value;
    return 0;
}

int sc_memoryGet(int addres, int *value)
{
    if (addres > 99 || addres < 0)
    {
        return 1;
        r_flags[2] = 1;
    }
    *value = memory[addres];
    return 0;
}

int sc_memorySave(char *filename)
{
    FILE *open;
    int writed;
    open = fopen(filename, "rb");
    if (open == NULL)
        return 1;
    writed = fwrite(memory, 4, 100, open);
    fclose (open);
    if (writed != 100)
        return 2;
    else
        return 0;
}

int sc_memoryLoad(char *filename)
{
    FILE *open;
    int loaded;
    open = fopen(filename, "rd");
    if (open == NULL)
        return 1;
    loaded = fread(filename, 4, 100, open);
    fclose(open);
    if (loaded != 100)
        return 2;
    else
    return 0;
}

int sc_regInit()
{
    for (int i = 0; i < 6; i++)
    {
        r_flags[i] = 0;
    }
    return 0;
}

int sc_regGet(int rgister, int *value)
{
    if (rgister < 0 || rgister > 6)
    {
        return 1;
        r_flags[2] = 1;
    }
    *value = r_flags[rgister];
    return 0;
}

int sc_regSet(int rgister, int value)
{
    if ((rgister < 0) || (rgister > 6) || (value > 1) || (value < 0))
    {
        return 1;
        r_flags[2] = 1;
    }
    r_flags[rgister] = value;
    return 0;
}

int sc_CommandEncode(int command, int operand, int *value)
{
    int chk;
    chk = command_check(command);//проверка
    if (chk == 1)
    {
        r_flags[4] = 1;
        return 1;
    }
    int comand = 1;
    comand = comand << 8;
    comand = comand + command;
    comand = comand << 8;
    comand = comand + operand;
    *value = operand;
    return 0;
}

int sc_CommandDecode(int value, int *command, int *operand)
{
    int temp = value;
    int chk;
    temp = temp >> 31;
    if (temp != 1)
        return 1;
    temp = value;
    temp = temp << 1;
    temp = temp >> 24;
    *command = temp;
    chk = command_check(temp);//проверка
    if (chk == 1)
    {
        r_flags[4] = 1;
        return 1;
    }
    temp = value;
    temp = temp << 9;
    temp = temp >> 23;
    *operand = temp;
    return 0;
}

int command_check(int command_on_chk)
{
    int chk;
    for(int i = 0; i < 13; i ++)
    {
        if(command_on_chk == correct_ops[i])
        {
            chk = 1;
            return 0;
        }
        chk = 0;
    }
return 1;
}