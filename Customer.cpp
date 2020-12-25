#include "Customer.h"
#include "includes.h"
Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::Reserve()
{
	bool hasOtherGroup = false;
	char cBookXtra;
	system("cls");
	std::cout << "Enter your name :"; std::cin >> this->name;
	std::cout << "Enter your age :"; std::cin >> this->age;
	std::cout << "Would you like to book for extra people? (y/n) :"; std::cin >> cBookXtra;
	switch (cBookXtra)
	{
	case 'Y':
	default:
	}

	
}

void Customer::EditReservation()
{
}
