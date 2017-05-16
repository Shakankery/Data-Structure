//============================================================================
// Name        : All-to-All Shortest path.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 16, 2017
/* Description :
 * The idea of All-to-All shortest path is to select the 
 * path with minimum weight between all Nodes in our Graph
 * we do so by:
 * 1-Select source & distenation
 * 2-Choose path with min weight
 * 3-Change destination
 * 4-Repeat 2&3 till same source reach all distenations
 * 5-choose different source and repeat 2,3&4 till all Nodes
 * in the Graph able to communicate with each other with min cost 
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#define dim 7		//dimension of the Graph =no.of nodes
#define inf 999		//assume infinity=999

//represent Graph with 2 dimenstional array
int weight[dim][dim] = {{ 0, 1, inf, inf, inf, 2, 9 },
    					{ 1, 0, 8, inf, inf, inf, inf },
						{ inf, 8, 0, 4, inf, 3, inf },
						{ inf, inf, 4, 0, 2, inf, inf },
	  					{ inf, inf, inf, 2, 0, 1, inf },
						{ 2, inf, 3, inf, 1, 0, 2 },
						{ 9, inf, inf, inf, inf, 2, 0 }};

int main(void)
{
	int r, c, flag;	//r:Row , c:Column 
	//print our original 2 dimensional array
	for (r = 0; r < dim; r++)
	{
		for (c = 0; c < dim; c++)
			if (weight[r][c] == inf)		cout << "#\t"; 		//print # instead of inf
			else							cout << weight[r][c] << "\t";
		cout << "\n";
	}

	do{
		flag = 0;			//to determine no.of changes in the original array
		for (int src = 0; src < dim; src++)				//select source 
			for (int dest = 0; dest < dim; dest++)		//select destination
				for (int via = 0; via < dim; via++)		//choose path with minimum weight
					if (weight[src][dest] > weight[src][via] + weight[via][dest])
					{
						weight[src][dest] = weight[src][via] + weight[via][dest]; 
						flag++;
					}
		cout << "\n Flag = " << flag << endl;
		//print the updated 2 dimensional array
		for (r = 0; r < dim; r++)
		{
			for (c = 0; c < dim; c++)
				cout << weight[r][c] << "\t";
			cout << "\n";
		}
		cout << "\n";
	} while (flag > 0);		//loop till no change happen  
}
