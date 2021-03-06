//
//  main.h
//  DVDTracker
//
//  Created by Mark Nemec on 30/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


//      DEFINITIONS     //

#define kMaxLength 128

//      GLOBALS     //

struct DVD {
    int rating;
    char title[kMaxLength];
    char comment[kMaxLength];
    struct DVD *next;
} myDVD, *gHeadPtr=NULL, *gTailPtr=NULL;

//      FUNCTIONS       //

char ReadInstr( void );
void ListDVDs( void );
void NewDVD( void );
