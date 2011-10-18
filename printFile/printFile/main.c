//
//  main.c
//  printFile
//
//  Created by Mark Nemec on 16/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[])
{
    FILE *fp;
    int num, nums;
    
    if ( (fp=fopen("~/Development/My C Stuff/printFile/My Data File", "r+") ) == NULL ) {
        printf("File not found\n");
    }
    fscanf(fp, "%d\n", &num);
    fscanf(fp, "%d", &nums);
    printf("%d",nums);
    
    return 0;
}

