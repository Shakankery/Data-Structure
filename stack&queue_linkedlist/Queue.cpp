//============================================================================
// Name        : Queue.cpp
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * queue is a -(FIFO)- first in first out orderd list 
 * this code is to implement the queue concept using Linkedlist
 * the idea is to store k^2 in a queue when [1<= k <=10]
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
 ----------	----------		
 |    |   |	|    |   |	--------
 |Data| P |---->|Data| P |----> | Null |
 |    |   |	|    |   |	--------
 ----------	----------
 * so we create a structure with integer to store data and
 * pointer to point to the next node
 */
struct queueNode
{
	int data;		//integer to store data in the node
	queueNode *next;	//a pointer that point to the next node
};

class LinkedListQueue
{
private:
	queueNode *front, *rear;	// two pointers that we need to insert or extract elements to or from the Node
public:
	//constructor that Make front&rear piont to Null at the begining
	LinkedListQueue()
	{
		front = rear = NULL;
	}
	/* enqueue Fn.used to insert new elements into our Node
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
 	 * make node pointer point to Null
 	  		---------		
 			|    |  |	------
 		temp-->	|Num |  |----> | Null |
 			|    |  |	------
 			---------
 	 * check if this the insertion of first element  
 	   		---------		 |		 ----	
 			|    |  |	------	 |	rear -->| Nu |
 		temp-->	|Num |  |----> | Null |	 |	front-->| ll |
 			|    |  |	------	 |		 ----
 			--------- 		 |
 	 * if so let front&rear Point to the same Node as temp
 	  	  	---------		
 		front->	|    |  |	------
 			|Num |  |----> | Null |
 		rear-->	|    |  |	------
 			---------
 	 * if not that mean front point to a different node than rear 
 	  		--------	--------
 			|    | | rear-->|    | |     ------
		front-->|Num1| |        |Num2| |--->| Null |	
 			|    | |------->|    | |     ------
 			--------	--------

 	  		---------		
 			|    |  |	------
 		temp-->	|Num3|  |----> | Null |
 			|    |  |	------
 			---------
	 * in this case make rear.next point to temp then make rear point to temp node
			--------      --------	      --------
 			|    | |      |    | | rear-->|    | |      ------
		front-->|Num1| |----> |Num2| |        |Num3| |---> | Null |	
 			|    | |      |    | |------->|    | |      ------
 			--------      --------	      --------
 	 */
	void enqueue(int num)
	{
		queueNode *temp;		// a temporary pointer that point to a Node
		temp = new queueNode;		// create a Node and make temp point to it
		temp->data = num;		// insert number in data part in the node
		temp->next = NULL;		// make node pointer point to Null
		if(rear == NULL)		//check if this the insertion of first element -->rear=Null
		{
			front = rear = temp; 
		}	
		else
		{
			rear->next = temp;	//make the rear node pointer point to temp
			rear = temp;		//make rear point to temp Node
		}
	}
	/* dequeue Fn. used to extract elements from our Node
	 * first we create a temporary poiner that point to a node 
 	  		--------	--------
 			|    | | rear-->|    | |     ------
		front-->|Num1| |        |Num2| |--->| Null |	
 			|    | |------->|    | |     ------
 			--------	--------
	 * extract number from data part in the node and put it in num
	 * then num =Num1 , make temp point to the first node and front point
	 * to the next one  
			--------	--------
 			|    | | rear-->|    | |     ------
		 temp-->|Num1| |front-->|Num2| |--->| Null |	
 			|    | |------->|    | |     ------
 			--------	--------
	 * delete the node that temp point to
	 	 --------		
 	  rear-->|    | |    ----
 	 front-->|Num2| |-->|Null|
 		 |    | |    ----
		 --------
	 * Check if front = Null ,if so let rear also =Null
	 * which mean we extract all data
	 	    	 ----	
 		rear -->| Nu |
 		front-->| ll |
 			 ----
	 */
	int dequeue(void)
	{
		queueNode *temp;	// a temporary pointer that point to a Node	
		int num;
		num = front->data;	// extract number from data part in the node and put it in num
		temp = front;		
		front = front->next;
		delete temp;		//delete the Node not the temp
		if(front == NULL)	//dequeue condition to know we extract all elements
		{
			rear = NULL;
		}	
		return num;
	}
	// check if the list is empty -> front=Null
	bool isEmpty(void)
	{
		return front == NULL;
	}
	// print Queue Fn. use to print element in queue without deleting it
	void printQueue(void)
	{
		queueNode *temp;		// a temporary pointer that point to a Node
		cout << "All data in queue : "; 
		//loop from front to Null
		for(temp = front ; temp != NULL ; temp = temp->next)
			cout << temp->data << "\t";
		cout << "\n";
	}
	int getNumberOfElements(void)
	{
		int counter=0;			// a temporary pointer that point to a Node
		queueNode *temp;
		//loop from front to Null
		for(temp = front ; temp != NULL ; temp = temp->next)		
			counter++;
		return counter;
	}
};

int main()
{
	LinkedListQueue qu1;		//create object from our class
	for(int k = 1 ; k <= 10 ; k++)
		qu1.enqueue(k*k);		

	cout << "Number of elements after dequeue = " << qu1.getNumberOfElements() << "\n";

	qu1.printQueue();
	cout << "Number of elements after print= " << qu1.getNumberOfElements() << "\n";

	while(qu1.isEmpty() == false)		
		cout << qu1.dequeue() << "\n";

	cout << "Number of elements after dequeue= " << qu1.getNumberOfElements() << "\n";
}
