/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: March 11 @ 11:59pm
 * CPSC 223C Midterm
 */

#include <stdio.h>
#include <stdlib.h>

void bubble(double * a, int size)
{
    int pass;
    int k;
    double hold;
    for(pass=1;pass < size;pass++)
    for(k=0;k<size-1;k++)
    if(a[k] > a[k+1])
    { 
        hold = a[k];
        a[k] = a[k+1];
        a[k+1] = hold;
    }

}//End of bubble.