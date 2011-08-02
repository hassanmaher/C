//
//  main.c
//  DVDTracker
//
//  Created by Mark Nemec on 30/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

int main (int argc, const char * argv[])
{
    char command;
    
    printf("Press q - quit, n - new entry, l - list entries or r - reversed list: ");
    while ((command=ReadInstr())!='q') {
        switch (command) {
            case 'n':
                ArrangeDVD(NewDVD());
                break;
            case 'l':
                ListDVDs(false);
                break;
            case 'r':
                ListDVDs(true);
                break;
            default:
                printf("Press q - quit, n - new entry, l - list entries or r - reversed list: ");
                break;
        }
    }
    printf("Goodbye, thank you for using me!\n");
    exit(0);
}


char ReadInstr () {
    char command;
    
    scanf("%c",&command);
    return command;
}


struct DVD *NewDVD () {
    struct DVD *infoPtr;
    int num;
    
    infoPtr=malloc(sizeof(struct DVD));
    printf("\nPlease enter the DVD Title: ");
    scanf("%s",infoPtr->title);
    printf("Please enter your comment on the DVD: ");
    scanf("%s",infoPtr->comment);
    printf("Please enter your rating: ");
    scanf("%d",&num);
    infoPtr->rating=num;
    printf("\n--------\n\n");
    return infoPtr;
}


void ListDVDs (bool isReversed) {
    struct DVD *myPtr;
    
    if (isReversed==false) {
        for (myPtr=gHeadPtr; myPtr!=NULL; myPtr=myPtr->next) {
            printf("\n%s | %s | %d", myPtr->title, myPtr->comment, myPtr->rating);
        }        
    } else {
        for (myPtr=gTailPtr; myPtr!=NULL; myPtr=myPtr->prev) {
            printf("\n%s | %s | %d", myPtr->title, myPtr->comment, myPtr->rating);
        }
    }
    printf("\n\n");
}


void ArrangeDVD ( struct DVD *curPtr ) {
    struct DVD *myPtr;
    
    if (gHeadPtr==NULL) {       // Ak je jediny
        gHeadPtr=curPtr;
        gHeadPtr->prev=NULL;
        gTailPtr=curPtr;
        gTailPtr->next=NULL;
    } else if (curPtr->rating<gTailPtr->rating) {       // Ak je posledny
        gTailPtr->next=curPtr;
        curPtr->prev=gTailPtr;
        gTailPtr=curPtr;
        gTailPtr->next=NULL;
    } else if (curPtr->rating>gHeadPtr->rating) {       // Ak je prvy
        curPtr->next=gHeadPtr;
        gHeadPtr->prev=curPtr;
        gHeadPtr=curPtr;
        gHeadPtr->prev=NULL;
    } else {
        for (myPtr=gHeadPtr; myPtr!=gTailPtr; myPtr=myPtr->next) {      // Ak je niekde v strede
            if (curPtr->rating<myPtr->rating && curPtr->rating>=myPtr->next->rating) {
                myPtr->next->prev=curPtr;
                curPtr->next=myPtr->next;
                curPtr->prev=myPtr;
                myPtr->next=curPtr;
            }
        }
    }
}