#include<stdio.h>
#include"Lifeboard.h"
#include<cstdio>
#include<string.h>
#include<ctype.h>

void Lifeboard ::allocate(int n, int m) {
	rows = n;
	cols = m;
	board = new char*[n];
	newboard = new char*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		newboard[i] = new char[m];
	}
}//Allocates 2D array

void Lifeboard::ReadFile(const char* filename) {

	FILE *fp;	//POINTER TO FILE
	char ch;
	char buff[200] = { '\0' };
	int dim[2] = { 0 };
	int n, m = 0;
	int k = 0;
	fp = fopen(filename, "r");	//OPENS FILE FOR READING
	fgets(buff, 10, fp);	//RETRIVES FIRST TEN TOKENS IN FILE
	for (int i = 0; i < 10; i++) {
		if (isdigit(buff[i])) {
			dim[k] = buff[i] - '0';	// FINDS DIMENSIONS OF FILE
			k++;
		}
	}
	n = dim[0];
	m = dim[1];
	allocate(n, m);
	int t = 0;
	do {	//EXTRACTS INITIAL CONFIGURATION
		fseek(fp, 0, SEEK_CUR);
		fgets(buff, 12, fp);
		int s = 0;
		for (int i = 0; i < 12; i++) {
			if (buff[i] == '.' || buff[i] == '*') {
				board[t][s] = buff[i];
				s++;
			}
		}
		t++;
	} while (t<rows);

	fclose(fp);
}
void Lifeboard::PrintBoard() {
	printf("\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
void Lifeboard::Logic() {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int lcount = 0;

			if (j != 0) {
				if (board[i][j - 1] == '*') {
					lcount++;
				}

			}
			if (j != (cols - 1)) {
				if (board[i][j + 1] == '*') {
					lcount++;
				}
			}
			if (i != (rows - 1) && j != (cols - 1)) {
				if (board[i + 1][j + 1] == '*') {
					lcount++;
				}
			}
			if (i != 0 && j != 0) {
				if (board[i - 1][j - 1] == '*') {
					lcount++;
				}
			}

			if (i != 0) {
				if (board[i - 1][j] == '*') {
					lcount++;
				}
			}
			if (i != (cols - 1) && j != 0) {
				if (board[i + 1][j - 1] == '*') {
					lcount++;
				}
			}
			if (i != (0) && j != (cols - 1)) {
				if (board[i - 1][j + 1] == '*') {
					lcount++;
				}
			}
			if (i != (rows - 1)) {
				if (board[i + 1][j] == '*') {
					lcount++;
				}
			}

			if (lcount < 2 || lcount > 3) {
				newboard[i][j] = '.';
			}
			else if (lcount == 3) { newboard[i][j] = '*'; }
			else { newboard[i][j] = board[i][j]; }
		}



	}

}

void Lifeboard::copy() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = newboard[i][j];
		}
	}

}
void Lifeboard::NumofGen(int num) {
	for (int i = 0; i <= num; i++) {
		Logic();
	}
}

void Lifeboard::Writefile(const char* filename) {
	FILE *fp;
	fp = fopen(filename, "w+");	//OPEN FILES FOR WRITING
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != NULL) {
				fprintf(fp, "%c", board[i][j]);
			}
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

