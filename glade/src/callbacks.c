#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include<iostream>
#include<string>
#include"util.h"
#include"cal_engine.c"


Operation op = E_NONE;
int operand1 = 0;
int operand2 = 0;
int ans = 0;
int memory = 0;
int clear = 0;


void
on_button1_clicked                     (GtkButton       *button,
                                        GtkEntry         *display)
{
    const char *disp_data;
    disp_data = gtk_entry_get_text (display);
    if(strlen(disp_data)==0)
    {
	gtk_entry_set_text(GTK_ENTRY(display),gtk_button_get_label(button));
    }else{
        if(clear == 0)
        {
            gtk_entry_append_text(GTK_ENTRY(display),gtk_button_get_label(button));
        }else{
            gtk_entry_set_text(GTK_ENTRY(display),gtk_button_get_label(button));
            clear = 0;
        }
    }

}


void
on_button_op_clicked                     (GtkButton       *button,
                                        GtkEntry         *display)
{
    const char *disp_data;
    disp_data = gtk_entry_get_text (display);
    if(op == E_NONE){
        std::cout<<gtk_button_get_label(button)<<std::endl;
        operand1 = atoi(disp_data);
        if(!strcmp(gtk_button_get_label(button),"+")){
           op = E_ADD;
        }
        if(!strcmp(gtk_button_get_label(button),"-")){
            op = E_SUB;
        }
        if(!strcmp(gtk_button_get_label(button),"*")){
             op = E_MUL;
        }
        if(!strcmp(gtk_button_get_label(button),"/")){
            op = E_DIV;
        }
        gtk_entry_set_text(display,"");
    }else{
        on_button14_clicked(button,display);
    }
}


void
on_button14_clicked                     (GtkButton       *button,
                                        GtkEntry         *display)
{
    const char *disp_data;
    disp_data = gtk_entry_get_text (display);
    operand2 = atoi(disp_data);
    ans = calculate(operand1,operand2,op) ;
    memory = ans;
    display_int(ans,display);
    op = E_NONE;
    clear = 1;
}

