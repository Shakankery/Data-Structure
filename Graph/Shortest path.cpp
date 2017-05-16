//============================================================================
// Name        : Shortest path.cpp
// Version     : 1.0
// Created on  : May 16, 2017
/* Description :
 * The idea of shortest path is to select the 
 * path with minimum cost between source and destination
 * in our Graph we do so by:
 * 1-Create an extra matrix
     * No.of row = no.of nodes= dim
	 * No.of column =3 (from,cost,bol)
	 * bol mean to check if node inside
	 * the circle or not ""reachable or not""
 * 2-Choose source and destination then put src in a circle
 * 3-check the node directly connect to the source 
 * then choose the node with the minimum cost to enter the circle 
 * 4-check the node directly connect to the new node in the circle
 * then choose the node with the minimum cost to enter the circle 
 * 5-Repeat 4 till reach our destination 
 * in the Graph able to communicate with each other with minCost cost 
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;

#define dim 7		//dimension of the Graph =no.of nodes
#define inf 99		//assume infinity=99

//represent Graph with 2 dimenstional array
int weight[dim][dim] = 
{{ 0, 1, inf, inf, inf, 2, inf },
{ 1, 0, 8, inf, inf, inf, inf },
{ inf, 8, 0, 4, inf, 3, inf },
{ inf, inf, 4, 0, 6, inf, inf },
{ inf, inf, inf, 6, 0, 5, inf },
{ 2, inf, 3, inf, 5, 0, 2 },
{ inf, inf, inf, inf, inf, 2, 0 } };

int main(void)
{
	int z[dim][3], source, des, r, minCost, node;
	
	// Create an extra matrix
	for (r = 0; r < dim; r++)
	{
		//intial values
		z[r][0] = -1; 		//first column=-1 for all rows 
		z[r][1] = inf;  	//second column=inf for all rows
		z[r][2] = 0;		//third column=0 for all rows
	}

	cout << "Enter source  ";
	cin >> source;

	cout << "Enter destination  ";
	cin >> des;

	node = source;					//source is the only node inside the circle
	minCost = weight[node][node];	//mincost=0
	//update matrix with source values 
	z[source][0] = source; z[source][1] = 0;	z[source][2] = 1;

	do{
		for (r = 0; r < dim; r++)
		{
		//check the nodes that connected to source inside the circle 	
		//if the node is not reachable and it's cost is larger
		//than the cost of reaching it via another Node then
		//swap cost and assign the new via node to the matrix
			if ((z[r][2] == 0) && (z[r][1] > (weight[node][r] + minCost)))
			{
				z[r][1] = weight[node][r] + minCost;	//swap cost
				z[r][0] = node;						//assign via node
			}
		}

		minCost = inf;		//cost=infinity
		node = -1;			//No node enter the circle yet
		for (r = 0; r < dim; r++)
		{	
			//loop to find the node with the minimum cost to put
			//it inside the circle ,to do so we check if node 
			//is not reachable and it's cost< inf
			if ((z[r][2] == 0) && (z[r][1] < minCost))
			{
				minCost = z[r][1];	//cost =node cost
				node = r;		
			}
		}
		//print extra array 
		for (r = 0; r < dim; r++)
		{
			cout << "\t" << r << "\t" << z[r][0] << "\t" << z[r][1] << "\t" << z[r][2] << "\n";
		}
		//print the Node that will enter the circle & it's cost
		cout << "node= " << node << "\t minCost = " << minCost << "\n\n";
		//Make the Node reachable -inside the circle
		z[node][2] = 1;

	} while (node != des); 			//loop till reach destination

	cout << "Final Result Path: ";
	r = des;
	cout << r;
	//Print the path from source to destination
	while (r != source)
	{
		r = z[r][0];
		cout << "<--" << r;
	}
}





