//============================================================================
// Name        : Stack.cpp
// Author      : Abdelrahman Elshakankery
// Version     : 1.0
// Created on  : May 15, 2017
/* Description :
 * stack is a -(FILO)- first in last out orderd list 
 * this class is to implement the stack concept using array
 * hope it will be useful 
 */
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;
class mystack
{
private:
	char *arr;		//Dynamic memory allocate so it's size can be determined during runtime
	int top,size;   //top:indication to the elements in our stack , size:size of our stack

public:
	//constructor that take the size of our stack from the user 
	mystack(int n)
	{
		arr = new char [n];		//use new operator to allocate an array of size n 
		size=n;
		top=0;
	}
	//constructor that assign a knowing value 10 to the size of our stack 
	mystack (void)
	{
		arr= new char [10];		//use new operator to allocate an array of size 10
		size=10;
		top=0;
	}
	//Push fn. used to insert new elements into our stack 
	void push(char data)
	{
		arr[top]=data; 
		top++;
	}
	//Pop Fn. used to extract elements from our stack
	char pop(void)
	{
		top--;
		return arr[top];
	}
	// check if the stack is empty -> top=0
	bool isempty(void)
	{
		if (top == 0)	return true;
		else			return false;
	}
	// check if the stack is full -> top=size
	bool isfull(void)
	{
		if (top == size)	return true;
		else				return false;
	}
};
