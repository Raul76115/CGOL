#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h> 
#include "Lifeboard.h"

int main(int argc,char**argv)
{
	int gens = 0;
	int count = 0;
	int choice = 0;
	Lifeboard lb;
	printf("What pattern would you like to see?\n1.)Blinker\n2.)Block\n Enter Choice Number:");
	scanf("%d", &choice);
	switch (choice){
	case 1:
		lb.ReadFile("Text.txt");
		break;
	case 2:
		lb.ReadFile("Text1.txt");
		break;
	case 3:
		lb.ReadFile("Text2.txt");
		break;
	case 4:
		lb.ReadFile("Text3.txt");
		break;
	default: 
		printf("Error\n");
		break;
	}
	printf("Generation :%d", count);
	lb.PrintBoard();
	printf("How many generations would you like to see?\n");
	scanf("%d", &gens);
	count++;
	do{
		
		lb.Logic();
		lb.copy();
		printf("Generation :%d", count);
		lb.PrintBoard();
		count++;
	} while (count <= gens);
	lb.Writefile("data.txt");
	return  0;
}