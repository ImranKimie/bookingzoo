#include "GlobalFunctions.h"
#include "Customer.h"
#include "includes.h"


void Welcome()
{
	system("cls");
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
	system("cls");
	Customer customer;
	std::ifstream OptionFile;
	std::string line;
	int option;
	while (1)
	{
		OptionFile.open(OPTIONS_FILEPATH);
		system("cls");
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
		
		std::cout << "\nChoose your option (1,2,3,4) : "; std::cin >> option;

		switch (option)
		{
			case 1:	customer.Reserve(); break;
			case 2:	customer.EditReservation(); break;
			case 3:	customer.DisplayReservation(); break;
			case 4:	exit(-1); break;
			default: 
				system("cls");
				OptionScreen(); 
				break;
		}
		OptionFile.close();
	}
	
}






