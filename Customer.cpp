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
	char hasAddGuests; // Has additional guests?
	system("cls");
	std::cout << "Enter your name :"; std::cin >> this->name;
	std::cout << "Enter your age :"; std::cin >> this->age;
	
	if (age >= 18)
		this->currentCustGroup = "Adult";

	std::cout << "Is there any additional guests ? (y/n) :"; std::cin >> hasAddGuests;
	switch (hasAddGuests)
	{
	case 'Y':ExtraGuests(); break;
	case 'y':ExtraGuests(); break;
	case 'N':break;
	case 'n':break;
	default: Reserve(); break;
	}

	
}

void Customer::EditReservation()
{

}

void Customer::ExtraGuests()
{
	
	int numberofguests;
	std::cout << "Enter the amount of extra guests : "; std::cin >> numberofguests;
	for (int i = 0; i < numberofguests; i++)
	{
		Customer* custarr = new Customer;
		std::cout << "Enter the name for guest " << i+1 << " : "; std::cin >> custarr->name;
		std::cout << "Enter the age for guest " << i + 1 << " : "; std::cin >> custarr->age;

		this->extraguests.push_back(custarr);
	}
	//std::cout << "custarr :\n";
	
	
		
	
	
}
