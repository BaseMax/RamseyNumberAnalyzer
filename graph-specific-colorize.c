/**
*
* @Name : RamseyNumberAnalyzer/graph-specific-colorize.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-11-30
* @Released under : https://github.com/BaseMax/RamseyNumberAnalyzer/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/RamseyNumberAnalyzer
*
**/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
// #include <dir.h>
// #include <process.h>

// #define FOR_GLOB(index,end)\
//      for(; index<end;index++)

#define FOR(index, start, end)\
	for(int index=start; index<end;index++)

#define SET_PAIR(item, first, end) \
	item.a=first;\
	item.b=end;

typedef enum {
	false,
	true,
} bool;

typedef struct {
	int a;
	int b;
} pair;

typedef struct {
	int a;
	int b;
	unsigned int c;
} color;

int art;
int count;
int value;
pair **items;
color *edges;
int edgesCount=0;
int itemsCount=0;
int subCount=10;

unsigned int randomColor() {
	return rand() % count;
}

unsigned int found(int i, int j) {
	FOR(x, 0, edgesCount) {
		// printf("==>%d\n", i);
		if(
			(edges[x].a == i && edges[x].b == j) ||
			(edges[x].a == j && edges[x].b == i)) {
			// printf("Found...\n");
			return edges[x].c;
		}
	}
	// printf("Not found...\n");
	return -1;
}

int main(int argc, char const *argv[]) {
	art=43;
	count=2;
	value=5;// both is 3
	printf("R(%d, %d) ?= %d\n", value, value, art);
	////////////////////////////////////
	srand(time(0));
	items=malloc(sizeof(pair*)*9625989);
	int first_limit=100000;//*10;
	int first_limit_index=0;
	edges=malloc(sizeof(color)*90399);
	edgesCount=0;
	FOR(i, 0, art) {
		FOR(j, i+1, art) {
			SET_PAIR(edges[edgesCount], i+1, j+1);
			printf("edge: %d,%d\n", i+1, j+1);
			edgesCount++;
		}
	}
	FOR(i, 0, art) {
		FOR(j, i+1, art) {
			FOR(l, j+1, art) {
				FOR(w, l+1, art) {
					FOR(e, w+1, art) {
						// printf("%d, %d, %d, %d, %d\n", i+1, j+1, l+1, w+1, e+1);
						items[itemsCount]=malloc(sizeof(pair)*subCount);
						// printf("(%d,%d), (%d,%d), (%d,%d)\n", i+1, j+1, i+1, l+1, j+1, l+1);
						SET_PAIR(items[itemsCount][0], i+1, j+1);
						SET_PAIR(items[itemsCount][1], i+1, l+1);
						SET_PAIR(items[itemsCount][2], i+1, w+1);
						SET_PAIR(items[itemsCount][3], i+1, e+1);

						// SET_PAIR(items[itemsCount][2], j+1, l+1);

						SET_PAIR(items[itemsCount][4], j+1, l+1);
						SET_PAIR(items[itemsCount][5], j+1, w+1);
						SET_PAIR(items[itemsCount][6], j+1, e+1);

						SET_PAIR(items[itemsCount][7], l+1, w+1);
						SET_PAIR(items[itemsCount][8], l+1, e+1);

						SET_PAIR(items[itemsCount][9], w+1, e+1);
						itemsCount++;
					}
				}
			}
		}
	}
	printf("===> itemsCount is %d\n", itemsCount);
	int check = mkdir(argv[1], 0700);
	if(!check) {
		printf("Directory created\n");
	}
	else { 
		printf("Unable to create directory\n"); 
		exit(1);
    }
	char filename1[50];
	sprintf(filename1, "%s/graph-result.txt", argv[1]);
	char filename2[50];
	sprintf(filename2, "%s/graph-rank-result.txt", argv[1]);
	FILE *pf = fopen(filename1, "a");
	FILE *pfr = fopen(filename2, "a");
	{
		first_limit_index++;
		if(first_limit_index > first_limit) {
				printf("END, Limit.....");
				exit(-1);
		}
		printf("%d/%d\n", first_limit_index, first_limit);
		fprintf(pf, "Colorize the %d edges: ", edgesCount);
		char *colors=malloc(sizeof(char)*903+1);
		strcpy(colors, "011001110000011100100001110110000000010100110010010111110111010100111111110100011001000010011001111100101011111000001010011101101110100101011001100110001101101000000011000010110100011111001110100010101011001110010001110000111101000101010111100100000101110111101101011010000011000110001101001110110110111001011001101011110100011111011010001100010100010100101011110101100010001100101111011011000010110000101001001010101000101110110111110011101100001000100011111011101001010101111010101110011010001111000110111010011011001001011001100000000100110010111111100010010001011010110011010101001110010100111001001011100100100100100010110011110000100101010111110101101000001111001111101100011111001010101000010011001110100100011100101011000011100010101110011101111000101000110001010100100111100101111011010100001100010010101011000100010101110101010111101001110000110110101001000010011110111001100101111011100001010");
		FOR(i, 0, edgesCount) {
			// edges[i].c=randomColor();
			edges[i].c=(colors[i] - '0');
			// printf("%d ", edges[i].c);
			fprintf(pf, "%d ", edges[i].c);
		}
		// printf("\n");
		bool sameColor=false;
		int lll=0;
		FOR(i, 0, itemsCount) {
			bool checkContinue=true;
			unsigned int color=-1;
			FOR(j, 0, value) {
				if(color == -1) {
					color=found(items[i][j].a, items[i][j].b);
					// printf(":::%d\n", color);
					continue;
				}
				else {
					unsigned int tcolor=found(items[i][j].a, items[i][j].b);
					// printf("==>%d != %d\n", color, tcolor);
					if(tcolor != color) {
						checkContinue=false;
						break;
					}
				}
			}
			if(checkContinue == true) {
				sameColor=true;
				lll++;
			}
		}
		printf("%d\n", lll);
		fprintf(pf, "\n===>%d\n", lll);
		fprintf(pfr, "%d\n", lll);
		if(sameColor == false) {
			printf("Done\n");
			fprintf(pf, "Done\n");
			exit(1);
		}
	}
	fclose(pf);
	printf("%d\n", itemsCount);
	return 0;
}
