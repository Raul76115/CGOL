//HEADER FILE FOR CONWAY'S GAME OF LIFE

#ifndef LIFEBOARD_H
#define LIFEBOARD_H

class Lifeboard
{
public:
	char** newboard;
	char** board;
	int rows;
	int cols;
	Lifeboard() {	//CONSTRUCTOR
		rows = 0;
		cols = 0;
	}
	~Lifeboard() {	//DESTRUCTOR
		for (int i = 0; i < rows; i++) {
			delete[] board[i];
			delete[] newboard[i];
		}
	};//Deallocates 2D ARRAY 
	
	void Lifeboard::allocate(int n, int m);
	void Lifeboard::ReadFile(const char* filename);
	void Lifeboard::PrintBoard();
	void Lifeboard::Logic();
	void Lifeboard::copy();
	void Lifeboard::NumofGen(int num);
	void Lifeboard::Writefile(const char* filename);
};

#endif