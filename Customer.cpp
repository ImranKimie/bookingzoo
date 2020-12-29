#include "Customer.h"
#include "includes.h"
Customer::Customer()
{
	this->pricing = 0.0f;
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
	std::cout << "Are you a foreigner(1) or a local citizen(2) ? (1/2): "; std::cin >> this->inationality;
	std::cout << "Enter the date you want to book (in numbers) : \n";
	std::cout << "Enter the day : "; std::cin >> this->dateofbooking[0];
	std::cout << "Enter the month : "; std::cin >> this->dateofbooking[1];
	std::cout << "Enter the year : "; std::cin >> this->dateofbooking[2];
	
	if (this->age >= 18 && this->age < 60)
		this->currentCustGroup = "Adult";
	else if(this->age >= 60)
		this->currentCustGroup = "Senior Citizen";
	else
		this->currentCustGroup = "Child";

	switch (this->inationality)
	{
		case 1:this->nationality = "Foreigner"; break;
		case 2:this->nationality = "Local Citizen"; break;
		default:this->nationality = "Local Citizen"; break;
	}

	


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

void Customer::ReserveExtra()
{
	static int count = 1;
	system("cls");
	std::cout << "Enter info for guest " << count << " : \n";
	std::cout << "Enter your name : "; std::cin >> this->name;
	std::cout << "Enter your age : "; std::cin >> this->age;
	std::cout << "Are you a foreigner(1) or a local citizen(2) ? (1/2): "; std::cin >> this->inationality;


	if (this->age >= 18 && this->age < 60)
		this->currentCustGroup = "Adult";
	else if (this->age >= 60)
		this->currentCustGroup = "Senior Citizen";
	else
		this->currentCustGroup = "Child";

	switch (this->inationality)
	{
		case 1:this->nationality = "Foreigner"; break;
		case 2:this->nationality = "Local Citizen"; break;
		default:this->nationality = "Local Citizen"; break;
	}
	count++;
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
	if (!this->extraguests.empty())
	{
		std::cout << "\nExtra guests :\n\n";
		for (size_t i = 0; i < this->extraguests.size(); ++i)
		{
			std::cout << std::endl;
			std::cout << "Name of guest " << i + 1 << " : " << this->extraguests.at(i)->name << std::endl;
			std::cout << "Guest " << i + 1 << " 's Age : " << this->extraguests.at(i)->age << std::endl;
			std::cout << std::endl;
		}
	}
	system("pause");
}

void Customer::ExtraGuests()
{
	int numberofguests;
	std::cout << "Enter the amount of extra guests : "; std::cin >> numberofguests;
	for (int i = 0; i < numberofguests; i++)
	{
		Customer* custarr = new Customer;
		custarr->ReserveExtra();
		this->extraguests.push_back(custarr);
	}

}

void Customer::CalculatePricing()
{
	if ((this->currentCustGroup == "Adult") && (this->nationality == "Local Citizen"))
		this->pricing += 38.0f;
	else if (((this->currentCustGroup == "Senior Citizen") || (this->currentCustGroup == "Child")) && (this->nationality == "Local Citizen"))
		this->pricing += 31.0f;
	else if ((this->currentCustGroup == "Senior Citizen") && (this->nationality == "Foreigner"))
		this->pricing += 50.0f;
	else if ((this->currentCustGroup == "Adult") && (this->nationality == "Foreigner"))
		this->pricing += 81.0f;
	else if ((this->currentCustGroup == "Child") && (this->nationality == "Foreigner"))
		this->pricing += 59.0f;

	for (size_t i = 0; i < this->extraguests.size(); ++i)
	{
		if ((this->extraguests.at(i)->currentCustGroup == "Adult") && (this->extraguests.at(i)->nationality == "Local Citizen"))
			this->pricing += 38.0f;
		else if (((this->extraguests.at(i)->currentCustGroup == "Senior Citizen") || (this->extraguests.at(i)->currentCustGroup == "Child")) && (this->extraguests.at(i)->nationality == "Local Citizen"))
			this->pricing += 31.0f;
		else if ((this->extraguests.at(i)->currentCustGroup == "Senior Citizen") && (this->extraguests.at(i)->nationality == "Foreigner"))
			this->pricing += 50.0f;
		else if ((this->extraguests.at(i)->currentCustGroup == "Adult") && (this->extraguests.at(i)->nationality == "Foreigner"))
			this->pricing += 81.0f;
		else if ((this->extraguests.at(i)->currentCustGroup == "Child") && (this->extraguests.at(i)->nationality == "Foreigner"))
			this->pricing += 59.0f;
		
	}
	system("cls");
	std::cout << "Total Price : RM " << this->pricing << std::endl;
	system("pause");
}
