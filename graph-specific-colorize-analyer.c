/**
*
* @Name : RamseyNumberAnalyzer/graph-specific-colorize-analyer.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-12-02
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
color *ctemp;
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
			(ctemp[x].a == i && ctemp[x].b == j) ||
			(ctemp[x].a == j && ctemp[x].b == i)) {
			// printf("Found...\n");
			return ctemp[x].c;
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
	// int check = mkdir(argv[1], 0700);
	// if(!check) {
	// 	printf("Directory created\n");
	// }
	// else { 
	// 	printf("Unable to create directory\n"); 
	// 	exit(1);
 //    }
	// char filename1[50];
	// sprintf(filename1, "%s/graph-result.txt", argv[1]);
	// char filename2[50];
	// sprintf(filename2, "%s/graph-rank-result.txt", argv[1]);
	// FILE *pf = fopen(filename1, "a");
	// FILE *pfr = fopen(filename2, "a");
	{
		first_limit_index++;
		if(first_limit_index > first_limit) {
				printf("END, Limit.....");
				exit(-1);
		}
		printf("%d/%d\n", first_limit_index, first_limit);
		// fprintf(pf, "Colorize the %d edges: ", edgesCount);
		char *colors=malloc(sizeof(char)*903+1);
		strcpy(colors, "000100011111011001010100110101011000001100001111010101110110111010010100101010111000111110101100111101001100100000010001011001010011111101111111000000100000110011100010111100000100111111010011100101110001011100111011010011001011100001100010011010111100000101011011100111110110101111111001101110001000011001001011100101001110011101100001111110000011101110111001111000111000000010100011011011111111100001001000001000011111000111001101001111011100101110010010110001101000100110100011010011001101010110010001011011110110100011110100101101000001110111101000111110100001101100011010000100010111101011100000000011011100101100011010100110011010101011000000001101101010010111101010011011001110010011011010001110011111011100111110110001001110111100001100111110101101001001010001001011011100110010010110000100001100101011001010011001111101101010100000000101100011100010100111100100101011100011101110100111001000110");
		FOR(i, 0, edgesCount) {
			// edges[i].c=randomColor();
			edges[i].c=(colors[i] - '0');
			// printf("%d ", edges[i].c);
			// fprintf(pf, "%d ", edges[i].c);
		}
		// printf("\n");
		for(int ooo=0;ooo<903;ooo++) {
			ctemp=edges;
			if(ctemp[ooo].c == 0) {
				ctemp[ooo].c=1;
			}
			else {
				ctemp[ooo].c=0;
			}
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
			if(sameColor == false) {
				printf("Done\n");
				// fprintf(pf, "Done\n");
				exit(1);
			}
		}
	}
	// fclose(pf);
	// printf("%d\n", itemsCount);
	return 0;
}