//ListMain.cpp
#include <iostream>
#include "List.h"
using namespace std;


int main()
{
	

	List ItemList;

	int item, num, index, answer, target;
	bool find;

	cout << "Now there are " << ItemList.numberOfItem();
	cout << " in the list.\n\n";
	cout << "Enter a digit : ";
	cin >> item;

	for (int i = 0; i < 10; i++)
	{
		ItemList.addItem(item);
		cout << "Item " << item++ << " is added. \n";
	}

	cout << "Now there are " << ItemList.numberOfItem() << " item in the list \n\n";
	cout << "The list are : ";
	ItemList.printItem();

	cout << "Please input one number : ";
	cin >> num;
	cout << "please input which index did you want to add : ";  //insert data in array
	cin >> index;
	ItemList.addItem(index,num);

	cout << "The new list now are : ";
	ItemList.printItem();

	cout << "please input which index you want to delete : ";  // delete data in array
	cin >> index;
	ItemList.deleteItem(index);


	cout << "The new list now are : ";
	ItemList.printItem();

	cout << "The total of all lists is : ";   //total data in array
	answer = ItemList.totalItem();
	cout << answer;


	do
	{
		cout << "\n\nPlease input number you want to search in list of array or enter 0 to exit : ";  //search in array = sequential sentinel
	cin >> target;

	item = ItemList.findItem(target, find);

	if (find == true)
	{
		cout << "Target was found in index : " << item;
		cout << endl;
	}

	else if (find == false)
	{
		cout << "Error!! target not found";
		cout << endl;
	}
	} while (target != 0);

	
}