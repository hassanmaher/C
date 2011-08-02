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
#include "main.h"

int main (int argc, const char * argv[])
{
    char command;
    
    printf("Press q - quit, n - new entry or l - list entries: ");
    while ((command=ReadInstr())!='q') {
        switch (command) {
            case 'n':
                ArrangeDVD(NewDVD());
                break;
            case 'l':
                ListDVDs();
                break;
            default:
                printf("Press q - quit, n - new entry or l - list entries: ");
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


void ListDVDs () {
    struct DVD *myPtr;
    
    for (myPtr=gHeadPtr; myPtr!=NULL; myPtr=myPtr->next) {
        printf("\n%s | %s | %d\n", myPtr->title, myPtr->comment, myPtr->rating);
    }
}


void ArrangeDVD ( struct DVD *curPtr ) {
    struct DVD *myPtr;
    
    if (gHeadPtr==NULL) {
        gHeadPtr=curPtr;
        gTailPtr=curPtr;
        gTailPtr->next=NULL;
    } else if (curPtr->rating<gTailPtr->rating) {
        gTailPtr->next=curPtr;
        gTailPtr=curPtr;
        gTailPtr->next=NULL;
    } else if (curPtr->rating>gHeadPtr->rating) {
        curPtr->next=gHeadPtr;
        gHeadPtr=curPtr;
    } else {
        for (myPtr=gHeadPtr; myPtr!=gTailPtr; myPtr=myPtr->next) {
            if (curPtr->rating<myPtr->rating && curPtr->rating>=myPtr->next->rating) {
                curPtr->next=myPtr->next;
                myPtr->next=curPtr;
            }
        }
    }
}