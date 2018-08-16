#ifndef _UTIL_H
#define _UTIL_H
#include<iostream>

typedef enum{
    E_NONE,
    E_ADD,
    E_SUB,
    E_DIV,
    E_MUL
}Operation;
void display_int(int int_to_disp,GtkEntry *display)
{
    char stringNum[20];
    sprintf(stringNum,"%d",int_to_disp);
    gtk_entry_set_text((display),stringNum);
}

#endif
