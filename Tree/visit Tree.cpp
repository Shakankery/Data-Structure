//============================================================================
// Name        : visit Tree.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 16, 2017
/* Description :
 * we have two methods to visit tree: 
 * 1-Depth first search ""based on stack concept ""
 * 2-Bridth first search ""based on queue concept ""
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
#include "stack.h"
#include "queue.h"
using namespace std;
//we can represent our tree in term of array of structure
struct treeNode
{
	char name, father;
	int order;
};
//Depth first search fn. that take 2 parameters
// a pointer to our structure and an int=no.of nodes
void print_DFS(treeNode*, int); 
//Bridth first search fn. that take 2 parameters
// a pointer to our structure and an int=no.of nodes
void print_BFS(treeNode*, int);

int main(void)
{
	//create our array of structure
	struct treeNode treeArray[12] = 
	{{'A','M',2},{'B','M',1},{'C','A',1},{'D','H',3},{'F','H',1},
	{'G','H',2},{'H','M',3},{'K','B',2},{'M','0',0},{'P','K',2},
	{'X','K',1},{'Y','B',1}};

	cout << "DFS: \n";
	print_DFS(treeArray,12);

	cout << "\n BFS: \n";
	print_BFS(treeArray, 12);
}

//Depth first search fn.
void print_DFS(treeNode *ptr, int size)
{
	int k, counter;
	char *sons;				
	sons = new char[size];	//create an array of sons it's size = no of nodes
	mystack st1;			//create an object from stack class
	for(k = 0 ; k < size ; k++)
		//check father column to find the root
		if(ptr[k].father == '0')
		{	
			//push the root to our stack
			st1.push(ptr[k].name);    
			break;
		}

		char temp;
		while(st1.isempty() == false)
		{
			temp = st1.pop();			//pop father
			cout << temp << "\t";		//Print father
			counter = 0;
			for(k = 0 ; k < size ; k++)
			{
				//Search for father sons
				if(ptr[k].father == temp)
				{ 
					//put node order as index to son array
					sons[ptr[k].order] = ptr[k].name; 
					counter++;
				}
			}
			//LIFO loop				
			for(k = counter ; k >= 1 ; k--)
				//Push sons
				st1.push(sons[k]);
		}
}

//Bridth first search fn.
void print_BFS(treeNode *ptr, int size)
{
	int k, counter;
	char *sons;
	sons = new char[size];	//create an array of sons it's size = no of nodes
	myqueue qu1;			//create an object from queue class
	for(k = 0 ; k < size ; k++)
		//check father column to find the root
		if(ptr[k].father == '0')		
		{	
			//push the root to our queue
			qu1.enqueue(ptr[k].name);
			break;
	    }

		char temp;
		while(qu1.isempty() == false)
		{
			temp = qu1.dequeue();	//dequeu father
			cout << temp << "\t";	//print father
			counter = 0;
			for(k = 0 ; k < size ; k++)
				//Search for father sons
				if(ptr[k].father == temp)		
				{
				  //put node order as index to son array
				  sons[ptr[k].order] = ptr[k].name; 
				  counter++;
				}

			//FIFO loop
			for(k = 1 ; k <= counter ; k++)
				//enqueue sons
				qu1.enqueue(sons[k]);
		}
}

