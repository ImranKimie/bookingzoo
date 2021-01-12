//List.cpp
#include<iostream>
#include "List.h"
using namespace std;

//class name :: method name
List::List() //constructor
{
	size = 0;

}

List::~List()
{}

//method type
int List::numberOfItem()
{
	return size;
}
void List::addItem(int item)
{
	if (size == maxSize)
	{
		cout << "there is no more index left\n";
	}
	array[size] = item;
	size++;
}
//Qa
void List::addItem(int index, int num)  //overloading method
{
	if (size == maxSize)
	{
		cout << "***List is full****\n";
		return;
	}
	if (index<0 || index>size)
	{
		cout << "***Invalid position****\n";
		return;
	}

	for (int i = size-1 ; i >= index - 1; i--)  //last array until index that had been chose to add data in it
	{
		array[i + 1] = array[i];  // bcs of added new data in index. example= added data in index 4 so that the original data in index 4 will move to index 5. the rest will follow up until last array
	}

	array[index] = num;  // "follow example" that have been given. so now, index 4 didnt have any data in it so it'll be fill with the data that we ask
	size++; //size data will increase by follow up bcs of adding new data in array

}

//Qb
void List::deleteItem(int index)
{
	for (int i = index ; i < size; i++)  
	{
		array[i] = array[i+1];    //data after index will have in index before it. repeat until last array. example = data index 4  will have in index 3
	}
	size--;  //size data will decrease by follow up bcs of deleting data
}

//Qc
int List::totalItem()
{
	int total=0;
	for (int i = 0; i < size; i++)
	{
		total = total + array[i];
	}
	return total;
}
void List::printItem()
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}
	cout << "\n\n";
}

//Qd
int List::findItem(int target, bool& answer)
{
	answer = false;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (target == array[i])
		{
			answer = true;
			break;
		}
		num++;
	}
	return num;
	
}