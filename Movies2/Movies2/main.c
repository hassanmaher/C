//
//  main.c
//  Movies2
//
//  Created by Mark Nemec on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "main.h"

int main (int argc, const char * argv[])
{
    struct DVDFilm  myDVD[kMaxDVDs];
    int i=0;
    
    while (i<kMaxDVDs) {
        printf("Zadaj nazov filmu #%d:",i+1);
        scanf("%s",myDVD[i].title);
        printf("Zadaj komentar filmu #%d:",i+1);
        scanf("%s",myDVD[i].comment);
        printf("Zadaj hodnotenie filmu #%d:",i+1);
        scanf("%d",&myDVD[i].rating);
        printf("----------------\n");
        i++;
    }
    for (i=0; i<kMaxDVDs; i++) {
//        ReplaceReturnAtTheEndOfString(&myDVD[i]);
        printf("DVD #%d: %s | %s | %d\n", i+1, myDVD[i].title, myDVD[i].comment, myDVD[i].rating);
    }
}


/*void ReplaceReturnAtTheEndOfString(struct DVDFilm *myDVDPtr) {
    myDVDPtr->title[strlen(myDVDPtr->title)-1]='\0';
    myDVDPtr->comment[strlen(myDVDPtr->comment)-1]='\0';
}*/