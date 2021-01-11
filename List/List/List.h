//List.h
#pragma once

#ifndef LIST_H
#define LIST_H



const int maxSize = 100;

class List
{
public:
	List();
	~List();

	int numberOfItem();
	void addItem(int item);
	void printItem();
	void addItem(int,int);
	void deleteItem(int);
	int totalItem();
	int findItem(int, bool&);

private:
	int size;
	int array[maxSize];
};

#endif // !LIST_H
