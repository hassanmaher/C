#include <stdio.h>
#include <string.h>

#define kMaxDVDs 4
#define kMaxText 256


void PrintDVDs (int i, char title[][kMaxText], char comment[][kMaxText], int rating);
void ReplaceReturntAtEndOfString (char *string1, char *string2);


int main (int argc, const char * argv[]) {
	char	title[kMaxDVDs][kMaxText],comment[kMaxDVDs][kMaxText];
	char	rating[kMaxDVDs];
    int		i,numDVDs = 0;
	
	while (numDVDs < kMaxDVDs) {
		printf("Please enter the title of DVD #%d: ", numDVDs+1);
		fgets(title[numDVDs], kMaxText, stdin);
		printf("Please enter the comment of DVD #%d: ", numDVDs+1);
		fgets(comment[numDVDs], kMaxText, stdin);
		printf("Please enter the rating of DVD #%d: ", numDVDs+1);
		fgets(&rating[numDVDs], kMaxText, stdin);
		printf("-----\n");
		numDVDs++;
	}
	for (i=0; i<kMaxDVDs; i++) {
		ReplaceReturntAtEndOfString (title[i], comment[i]);
		PrintDVDs(i,title,comment,rating[i]);
	}
    return 0;
}


void ReplaceReturntAtEndOfString (char *string1, char *string2) {
	string1[strlen(string1)-1]='\0';
	string2[strlen(string2)-1]='\0';
}


void PrintDVDs (int i, char title[][kMaxText], char comment[][kMaxText], int rating) {
	printf("DVD #%d: %s | %s | %c\n", i+1, title[i], comment[i], rating);
}
