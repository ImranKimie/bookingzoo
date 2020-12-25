#include "GlobalFunctions.h"
#include "Customer.h"
#include "includes.h"


void Welcome()
{
	std::ifstream WelcomeFile(WELCOME_FILEPATH);
	std::string line;
	if (WelcomeFile.fail())
	{
		std::cout << "\nwelcome.txt not found,exiting program\n";
		system("pause");
		exit(-1);
	}
	else
	{
		while(std::getline(WelcomeFile,line))
			std::cout << line << '\n';
		
		system("pause");
	}
	WelcomeFile.close();
	
}

void OptionScreen()
{
	Customer customer;
	std::ifstream OptionFile(OPTIONS_FILEPATH);
	std::string line;
	int option;

	if (OptionFile.fail())
	{
		std::cout << "\noptionmessage.txt not found,exiting program\n";
		system("pause");
		exit(-1);
	}
	else
	{
		while (std::getline(OptionFile, line))
			std::cout << line << '\n';

	}
	OptionFile.close();

	std::cout << "\nChoose your option (1,2,3):"; std::cin >> option;
	switch (option)
	{
	case 1:	customer.Reserve(); break;
	default: 
		system("cls");
		OptionScreen(); 
		break;
	}
		

}






