//============================================================================
// Name        : Stack.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * queue is a -(FIFO)- first in first out orderd list 
 * this class is to implement the queue concept using array
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;
class myqueue
{
private:
	char *arr;			//Dynamic memory allocate so it's size can be determined during runtime
	int front, rear, size, counter;		
public:
	//constructor that take the size of our stack from the user
	myqueue(int n)
	{
		size = n;
		arr = new char[size];		//use new operator to allocate an array of size n
		front = rear = counter = 0;
	}
	//constructor that assign a knowing value 10 to the size of our stack
	myqueue(void)
	{
		size = 10;					//use new operator to allocate an array of size 10
		arr = new char[size];
		front = rear = counter = 0;
	}
	/* enqueue Fn. used to insert new elements into our queue
		--r---------------f--------
 	    | 1 | 3 | 8 | 7 | 5 |  |  |  
 	    ---------------------------
 	    * in this case r will get out of the array and 
 	    * tell us it's full yet we have two places empty
 	    * in the begining of the queue so we use (rear+1)%size
 	    * to return to the begingig 
 	    ------------------f------r--
 	    | 1 | 3 | 8 | 7 | 5 |  | 2 |  
 	    ----------------------------
	 */	
	void enqueue(char n)
	{
		arr[rear] = n;		
		rear = (rear + 1) % size;	
		counter++;
	}
	/* dequeue Fn. used to extract elements from our queue
		------------------f------r--
 	    | 1 | 3 | 8 | 7 | 5 |  | 2 |  
 	    ----------------------------
 	    * in this case we also need f to return to
 	    * the begining of the queue so we use (front+1)%size
 	    * to return to the begingig 
 	    --------------------r/f--
 	    |  |  |  |  |  |  |  2  |  
 	    -------------------------
	 */
	char dequeue(void)
	{
		int temp;
		temp = front;
		front = (front + 1) % size;
		counter--;
		return arr[temp];
	}
	// check if the queue is empty -> counter=0
	bool isempty(void)
	{
		return (counter == 0);
		//	if counter = 0 will return true
		//	else will return false;
	}
	// check if the queue is full -> conter=size
	bool isfull(void)
	{
		return (counter == size);
	}
};