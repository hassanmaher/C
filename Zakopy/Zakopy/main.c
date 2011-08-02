//
//  main.c
//  Zakopy
//
//  Created by Mark Nemec on 29/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char * argv[])
{
    int i,zakop,prihod,zakopy[3];
    srand(time(NULL));
    
    for (i=0; i<3; i++) {
        zakopy[i]=(rand()%3)-3;
    }
    for (i=0; i<3; i++) {
        printf("%d\n",zakopy[i]);
    }    
    while ((zakopy[0]!=0) && (zakopy[1]!=0) && (zakopy[2]!=0)) {
        printf("Zadaj cislo zakopu:");
        scanf("%d",&zakop);
        printf("Kolko mam prihodit?");
        scanf("%d",&prihod);
        zakopy[zakop]+=prihod;
        for (i=0; i<3; i++) {
            printf("%d\n",zakopy[i]);
        }    
    }
}

