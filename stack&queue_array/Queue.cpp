//============================================================================
// Name        : Queue.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * queue is a -(FIFO)- first in first out orderd list 
 * this code is to implement the queue concept using array
 * the idea is to generate a random sequence of 30 number
 * then put the odd numbers in stack and the even numbers  
 * in another one ,hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class myqueue
{
private:
	int *arr;		//Dynamic memory allocate so it's size can be determined during runtime
	int front, rear, size, counter;		
public:
	//constructor that take the size of our stack from the user
	myqueue(int n)
	{
		size = n;
		arr = new int[size];		//use new operator to allocate an array of size n
		front = rear = counter = 0;
	}
	//constructor that assign a knowing value 10 to the size of our stack
	myqueue(void)
	{
		size = 10;			//use new operator to allocate an array of size 10
		arr = new int[size];
		front = rear = counter = 0;
	}
	/*enqueue Fn. used to insert new elements into our queue
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
	void enqueue(int n)
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
	int dequeue(void)
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
	void double_size(void)
	{
		int *temp;
		temp = new int[size * 2];			//use new operator to double the size
		for (int k = 0; k < size; k++)
		{
			temp[k] = arr[(k+front)%size];		//copy element from old array to the new one
		}
		delete arr;
		size = size * 2;
		arr = temp;
		front = 0;
		rear = front + counter;
	}

	int get_number_of_elements(void)
	{ return counter; }
	
	int get_max_size(void)
	{ return size; }

	int get_front(void)
	{ return arr[front]; }
};
int main()
{
	srand (time(NULL));	//select a random sequence based on the value returned by function time
	int num;
	myqueue odd(14),even;	//create 2 object from our class 
				//odd queue with size=14,even queue with size =10
	for (int i = 0; i < 30; ++i)
	{
		num =rand() %100;
		cout<< num<<"\t";
		if (num%2 ==0)		//even number
		{
			if (even.isfull() == true)
			{
				even.double_size();
			}
			even.enqueue(num);
		}
		else			//odd number
		{
			if(odd.isfull() == false)
			{
				odd.enqueue(num);
			}
			else
			{
				cout<<"\n odd stack is full"<<endl;
			}
		}
	}
	cout<<"\n even front = "<<even.get_front() <<endl;
	cout <<"\n Even number are:"<<endl;
	while(even.isempty() == false)
	{
		cout<< even.dequeue()<<"\t";
	}
	cout <<"\n odd number are:"<<endl;
	while(odd.isempty() == false)
	{
		cout<< odd.dequeue()<<"\t";
	}
	return 0;
}
