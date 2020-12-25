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
	system("cls");
	std::cout << "Enter your name :"; std::cin >> this->name;
	std::cout << "Enter your age :"; std::cin >> this->age;
	std::cout << "Do you have any child/elders?";
	Sleep(1000);
}

void Customer::EditReservation()
{
}
