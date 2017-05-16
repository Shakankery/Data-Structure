//============================================================================
// Name        : Stack.cpp
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * stack is a -(FILO)- first in last out orderd list 
 * this code is to implement the stack concept using array
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
class mystack
{
private:
	int *arr;	//Dynamic memory allocate so it's size can be determined during runtime
	int top,size;   //top:indication to the elements in our stack , size:size of our stack

public:
	//constructor that take the size of our stack from the user 
	mystack(int n)
	{
		arr = new int [n];	//use new operator to allocate an array of size n 
		size=n;
		top=0;
	}
	//constructor that assign a knowing value 10 to the size of our stack 
	mystack (void)
	{
		arr= new int [10];	//use new operator to allocate an array of size 10
		size=10;
		top=0;
	}
	//Push fn. used to insert new elements into our stack 
	void push(int data)
	{
		arr[top]=data; 
		top++;
	}
	//Pop Fn. used to extract elements from our stack
	int pop(void)
	{
		top--;
		return arr[top];
	}
	// check if the stack is empty -> top=0
	bool isempty(void)
	{
		if (top == 0)		return true;
		else			return false;
	}
	// check if the stack is full -> top=size
	bool isfull(void)
	{
		if (top == size)		return true;
		else				return false;
	}
	void double_size(void)
	{
		int *temp;
		temp = new int[size * 2]; 		//use new operator to double the size
		for (int k = 0; k < size; k++)
		{
			temp[k] = arr[k];		//copy element from old array to the new one
		}  
		delete arr;						
		size = size * 2;				
		arr = temp;
	}

	int get_top(void)
	{
	 return arr[top - 1]; 	// if top=8 then return arr[7] and top still =8
	}	

	int get_no_of_elements(void)
	{ return top; }

	int get_max_size(void)
	{ return size; }

};

int main()
{
	srand(time(NULL));	//select a random sequence based on the value returned by function time
	int num;
	mystack odd(14), even;	//create 2 object from our class 
				//odd stack with size=14,even stack with size =10
	for (int k = 1; k <= 30; k++)
	{
		num = rand() % 100;
		cout << num << "\t";
		if (num % 2 == 0)  	//even number
		{
			if (even.isfull() == true) 	
			{
				even.double_size();
			}	
			even.push(num);
		}
		else 			//odd number
		{
			if (odd.isfull() == false)	
			{
				odd.push(num);
			}
			else
			{
				cout << "\n odd stack is full\n";
		    }	
		}
	}
	cout << "\n Even numbers are: "<<endl;
	while(even.isempty() == false)	
		cout << even.pop() << "\t";

	cout << "\n Odd numbers are: "<<endl;
	while (odd.isempty() == false)
		cout << odd.pop() << "\t";
	return 0;
}
