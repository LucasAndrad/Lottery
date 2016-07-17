/*
Name: Lucas Andrade Olivera
University: UnB - Campus Gama
Age: 20 years
Country: Brasil
Program Description: This program show how many times some 
number has appeared in specific lottery game of Brasil.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define numbersGame 100
using namespace std;

FILE *results;

// struct to save numbers information
typedef struct {
	
	int number;
	int count;
	double percent;
}Info;

// list of functions
void setValueNumbers(Info *lot);
int countLines();

int main() {
 
	int lines=0;
  lines = countLines();
  Info lottery[numbersGame];
  setValueNumbers(lottery[numbersGame]);
  int n;
	results = fopen("teste.csv", "r");
	while (fscanf(results, "%d ", &n) != EOF) { 
		lottery[n].count++;
		lottery[n].percent = (lottery[n].count/lines) * 100.0;
		printf ("Number: %d  Times: %d  Percent: %.03lf\n", lottery[n].number, lottery[n].count, lottery[n].percent);
	}
	
	return 0;

}
// function to count number of lines in file
int countLines() {
	int l=0;
	char w;
	results = fopen("teste.csv", "r");
	w = fgetc(results);
	while (w!=EOF) {
		w = fgetc(results);
		if (w == '\n') { 
			l++;
		}
	}
	fclose(results);
	return l;
}

void setValueNumbers(Info *lot) {

	int i=0;
	for (i=0; i<100; i++) {
		lot[i].number = i;
	}
}
