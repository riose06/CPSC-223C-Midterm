/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: March 11 @ 11:59pm
 * CPSC 223C Midterm
 */

#include <stdio.h>
#include <stdlib.h>

void show(char* info[20], int lines) 
{
    for (int i = 0; i < lines; i++) {
        printf("%s\n", info[i]);
    }
}