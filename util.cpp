//
// Created by TraAL on 2/28/2021.
//

#include "util.h"
#include <stdio.h>

int nextCommand(int *n, int *f, int *flag, int *i)
{
    char c;
    while(1){
        scanf("%c", &c);
        if (c == ' ' || c == '\t' || c == '\n'){
            continue;
        }
        if (c == 'S' || c == 's'){
            break;
        }
        if (c == 'C' || c == 'c'){
            scanf("%d", n); //value
            break;
        }
        if (c == 'R' || c == 'r'){
            //flag
            scanf("%d", flag);
            break;
        }
        if (c == 'W' || c == 'w')
        {
            break;
        }
        if (c == 'P' || c == 'p')
        {
            break;
        }
        if (c == 'I' || c == 'i')
        {
            scanf("%d", n); //value
            break;
        }
        if (c == 'D' || c == 'd')
        {
            //flag
            scanf("%d", flag);
            break;
        }
        if (c == 'K' || c == 'k')
        {
            //index value
            //scanf("&d", i); //index
            //scanf("%d", n); //value
            break;
        }
    }
    return c;
}