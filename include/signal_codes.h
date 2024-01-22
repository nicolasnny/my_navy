/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-enzo.fokwen-rocher
** File description:
** signal.h
*/

#ifndef SIGNAL_H
    #define SIGNAL_H
    #define WAIT 1<<0
    #define END 1<<1
    #define A_COL 1<<2
    #define B_COL 1<<3
    #define C_COL 1<<4
    #define D_COL 1<<5
    #define E_COL 1<<6
    #define F_COL 1<<7
    #define G_COL 1<<8
    #define H_COL 1<<9
    #define ROW_1 1<<10
    #define ROW_2 1<<11
    #define ROW_3 1<<12
    #define ROW_4 1<<13
    #define ROW_5 1<<14
    #define ROW_6 1<<15
    #define ROW_7 1<<16
    #define ROW_8 1<<17
    #define CONNECTED 1<<18
    #define ATTACK 1<<19
typedef struct signal_s {
    int value;
    int index;
}sig_val;
extern sig_val sig;

#endif /*   SIGNAL_H    */