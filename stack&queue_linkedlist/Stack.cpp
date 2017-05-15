//============================================================================
// Name        : Stack.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * stack is a -(FILO)- first in last out orderd list 
 * this code is to implement the stack concept using Linkedlist
 * the idea is to store k^2 in a stack when [1<= k <=10]
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
/* linked list consist of number of nodes each with a place
 * to store the data and a pointer to point to the next node
 ----------		----------		
 |    |   |		|    |   |		--------
 |Data| P |---->|Data| P |----> | Null |
 |    |   |		|    |   |		--------
 ----------		----------
 * so we create a structure with integer to store data and
 * pointer to point to the next node
 */
struct stackNode
{
	int data;			//integer to store data in the node
	stackNode *next;	//a pointer that point to the next node  
};

class LinkedListStack
{
private:
	stackNode *top;		// a pointer that point to the first Node
public:
	//constructor that Make top piont to Null at the begining
	LinkedListStack()
	{
		top = NULL;
	}
	/* Push Fn.used to insert new elements into our Node
	 * first we create a temporary poiner that point to a node 
	 * create new node and make our pointer point to it 
	    		----------		
 				|    |   |
 		temp-->	|Data| P |
 				|    |   |
 				----------
 	 * insert num in data part 
 	 			----------		
 				|    |   |
 		temp-->	|Num | P |
 				|    |   |
 				----------
 	 * make node pointer point to top which is poinnt to null
 	  			---------		
 				|    |  |		------
 		temp-->	|Num |  |----> | Null |
 				|    |  |		------
 				---------
 	 * make top point to the first node instead of temp 
 	   			---------		
 				|    |  |		------
 		top--->	|Num |  |----> | Null |
 				|    |  |		------
 				--------- 
 	 */
	void push(int num)
	{
		stackNode *temp;		// a temporary pointer that point to a Node
		temp = new stackNode ;	// create a Node and make temp point to it
		temp->data = num;		// insert number in data part of the node 
		temp->next = top;		// make node pointer point to top which is poinnt to null
		top = temp;				
	}
	/* Pop Fn.used to extract elements from our Node
	 * first we create a temporary poiner that point to a node 
	  		-------	   -------		
 			|   | |    |   | |	   ------
 	  top-->| 4 | |--->| 7 | |---> |Null|
 			|   | |	   |   | |	   ------
			-------	   -------
	 * extract number from data part in the node and put it in num
	 * then num =4 , make temp point to the first node and top point
	 * to the next one  
	  		-------	   	  -------		
 			|   | |top--> |   | |	  ------
 	 temp-->| 4 | |-----> | 7 | |---> |Null|
 			|   | |		  |   | |	  ------
			-------	      -------
	 * delete the node that temp point to
	 	    -------		
 	 		|   | |	  ------
 	  top-->| 7 | |-->|Null|
 			|   | |	  ------
			-------
	 */
	int pop(void)
	{
		stackNode *temp;		// a temporary pointer that point to a Node
		int num;
		num = top->data;		// extract number from data part in the node and put it in num
		temp = top;
		top = top->next ;
		delete temp;			//delete the Node not the temp 
		return num;
	}
	// check if the list is empty -> top=Null
	bool isEmpty(void)
	{
		return top == NULL;
		//	if counter = 0 will return true
		//	else will return false;
	}

	int getNumberOfElements(void)
	{
		int counter=0;
		stackNode *temp;	// a temporary pointer that point to a Node
		//loop from top to Null
		for(temp = top ; temp != NULL ; temp = temp->next)		
			counter++;	
		return counter;
	}
	// print stack Fn. use to print element in stack without deleting it 
	void printStack(void)
	{
		stackNode *temp;	// a temporary pointer that point to a Node
		cout << "Data in stack: ";
		//loop from top to Null
		for(temp = top ; temp != NULL ; temp = temp->next)		
			cout << temp->data << "\t"; 	//print data 
		cout << "\n";
	}
};

int main()
{
	LinkedListStack st1;		//create object from our class
	for(int k = 1 ; k <= 10 ; k++)
		st1.push(k*k);

	cout << "Number of elements after push = " << st1.getNumberOfElements() << "\n";

	st1.printStack();
	cout << "Number of elements after print= " << st1.getNumberOfElements() << "\n";

	while(st1.isEmpty() == false)		
		cout << st1.pop() << "\n";

	cout << "Number of elements after pop= " << st1.getNumberOfElements() << "\n";
}