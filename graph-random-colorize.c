/**
*
* @Name : RamseyNumberAnalyzer/graph-random-colorize.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-10
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
	while(1) {
		check:
		first_limit_index++;
		if(first_limit_index > first_limit) {
				printf("END, Limit.....");
				exit(-1);
		}
		printf("%d/%d\n", first_limit_index, first_limit);
		fprintf(pf, "Colorize the %d edges: ", edgesCount);
		FOR(i, 0, edgesCount) {
			edges[i].c=randomColor();
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
				// printf("===>%d\n", i);
				lll++;
				// fprintf(pf, "\n===>%d\n", i);
				// fprintf(pfr, "%d\n", i);
				// goto check;
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
