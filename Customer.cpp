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
	std::cout << "Is there any additional guests ? (y/n) :"; std::cin >> cBookXtra;
	switch (cBookXtra)
	{
	case 'Y':ExtraGuests(); break;
	case 'y':ExtraGuests(); break;
	case 'N':break;
	case 'n':break;
	default:Reserve(); break;
	}

	
}

void Customer::EditReservation()
{

}

void Customer::ExtraGuests()
{
	std::vector <Customer*> customerarr;
	int tempint = 0;
	std::cout << "Enter the amount of extra guests"; std::cin >> tempint;
	for (int i = 0; i < tempint; i++)
	{
		Customer* custarr = new Customer;
		customerarr.push_back(custarr);
	}
	std::cout << "custarr :\n";
	for (auto i = customerarr.begin(); i != customerarr.end(); ++i)
		std::cout << *i << " \n";
	std::cout << std::endl;
	system("pause");
	
}
