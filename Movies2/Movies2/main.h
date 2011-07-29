//
//  main.h
//  Movies2
//
//  Created by Mark Nemec on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Movies2_main_h
#define Movies2_main_h
#define kMaxDVDs 4
#define kMaxTitleLength 256
#define kMaxCommentLength 256

struct DVDFilm {
    int rating;
    char title[kMaxTitleLength];
    char comment[kMaxCommentLength];
};

void ReplaceReturnAtTheEndOfString(struct DVDFilm *myDVDPtr);


#endif
