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
	system("cls");
	char hasAddGuests; // Has additional guests?
	std::cout << "Enter your name : "; std::cin >> this->name;
	std::cout << "Enter your age : "; std::cin >> this->age;
	std::cout << "Are you a foreigner or a local citizen ? : "; std::cin >> this->nationality;
	std::cout << "Enter the date you want to book (in numbers) : \n";
	std::cout << "Enter the day : "; std::cin >> this->dateofbooking[0];
	std::cout << "Enter the month : "; std::cin >> this->dateofbooking[1];
	std::cout << "Enter the year : "; std::cin >> this->dateofbooking[2];
	
	if (age >= 18 && age < 60)
		this->currentCustGroup = "Adult";
	else if(age >= 60)
		this->currentCustGroup = "Senior Citizen";
	else
		this->currentCustGroup = "Child";

	std::cout << "Is there any additional guests ? (y/n) : "; std::cin >> hasAddGuests;
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

void Customer::DisplayReservation()
{
	system("cls");
	std::cout << "Your name : " << this->name << std::endl;
	std::cout << "Your age : " << this->age << std::endl;
	std::cout << "Your current age group : " << this->currentCustGroup << std::endl;
	std::cout << "Your nationality : " << this->nationality << std::endl;
	std::cout << "Your booking date : \n";
	std::cout << "Day : " << this->dateofbooking[0] << "\n"<< "Month : " << this->dateofbooking[1] << "\n" << "Year : " << this->dateofbooking[2] << std::endl;
	system("pause");
}

void Customer::ExtraGuests()
{
	int numberofguests;
	std::cout << "Enter the amount of extra guests : "; std::cin >> numberofguests;
	for (int i = 0; i < numberofguests; i++)
	{
		Customer* custarr = new Customer;
		std::cout << "Enter the name for guest " << i + 1 << " : "; std::cin >> custarr->name;
		std::cout << "Enter the age for guest " << i + 1 << " : "; std::cin >> custarr->age;

		this->extraguests.push_back(custarr);
	}

}
