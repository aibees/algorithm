#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define SEA 0
#define LAND 1

using namespace std;

int map[51][51]; //[w][h]
int checked[51][51];
int w, h;

void init() {
	int num = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			scanf("%d", &map[j][i]);
			if(map[j][i] == SEA)
				checked[j][i] = -1;
			else
				checked[j][i] = 1;
		}
	}
}

void check(int W, int H) {
	printf("checking : map[%d][%d]\n", W, H);
	checked[W][H] = -1;
	/*
	123
	4 5
	678
	*/
	if((W-1 >= 0) && (H-1 >= 0) && map[W-1][H-1] == LAND && checked[W-1][H-1] == 1) {
		check(W-1, H-1);
	}
	if((H-1 >= 0) && map[W][H-1] == LAND && checked[W][H-1] == 1) {
		check(W, H-1);
	}
	if((H-1 >= 0) && (W+1 < w) && map[W+1][H-1] == LAND && checked[W+1][H-1] == 1) {
		check(W+1, H-1);
	}
	if((W-1 >= 0) && map[W-1][H] == LAND && checked[W-1][H] == 1) {
		check(W-1, H);
	}
	if((W+1 < w) && map[W+1][H] == LAND && checked[W+1][H] == 1) {
		check(W+1, H);
	}
	if((W-1 >= 0) && (H+1 < h) && map[W-1][H+1] == LAND && checked[W-1][H+1] == 1) {
		check(W-1, H+1);
	}
	if((H+1 < h) && map[W][H+1] == LAND && checked[W][H+1] == 1) {
		check(W, H+1);
	}
	if((W+1 < w) && (H+1 < h) && map[W+1][H+1] == LAND && checked[W+1][H+1] == 1) {
		check(W+1, H+1);
	}
}

void process() {
	cout << "process start" << '\n';
	int answer = 0;
	for(int i = 0; i < h; i++) { 
		for(int j = 0; j < w; j++) {
			printf("map[%d][%d] : %d\n", j, i, map[j][i]);
			printf("check[%d][%d] : %d\n", j, i, checked[j][i]);
			if(map[j][i] == LAND && checked[j][i] == 1) {
				answer++;
				check(j, i);
			}
		}
	}
	printf("answer : %d\n", answer);
}

int main(void) {
	while(true) {
		scanf("%d %d", &w, &h);
		if((w + h) == 0) {break;}
		init();
		printf("init complete\n");
		process();
	}
	return 0;
}
