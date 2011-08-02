//
//  main.c
//  Palindrome
//
//  Created by Mark Nemec on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define kMaxText 100

int main (int argc, const char * argv[])
{
    char c,palindrom[kMaxText],obratene[kMaxText];
    int i,j=0;
    
    printf("Zadaj text pre overenie palindromu:");
    for (i=0; (c=getchar())!='\n'; i++) {
        if (c!=' ') {
            palindrom[i]=c;
        }
    }
    palindrom[i]='\0';
    for (i--; i>=0; i--) {
        obratene[j]=palindrom[i];
        j++;
    }
    obratene[j]='\0';
    for (i=0; i<=strlen(palindrom); i++) {
        if (palindrom[i]!=obratene[i]) {
            printf("Toto nie je palindrom");
            return 0;
        }
    }
    printf("Toto je palindrom");
    return 0;
}

