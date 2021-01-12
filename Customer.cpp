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
	
	std::ifstream PricingFile;
	std::string line;
	int numOfTickets;
	int ticketType;
	char moretickettype;
	start:
	system("cls");
	PricingFile.open(PRICING_FILEPATH);
	if (PricingFile.fail())
	{
		std::cout << "\npricing.txt not found,exiting program\n";
		system("pause");
		exit(-1);
	}
	else
	{
		while (std::getline(PricingFile, line))
			std::cout << line << '\n';
	}
	PricingFile.close();
	askagain:
	std::cout << "Enter the ticket type that you want(1-6) : "; std::cin >> ticketType;
	std::cout << "Enter the number of tickets you want : "; std::cin >> numOfTickets;
	std::cin.ignore();
	for (int i = 0; i < numOfTickets; i++)
	{
		Customer* ticketcust = new Customer;
		
		ticketcust->TicketInput();
		switch (ticketType)
		{
			case 1:ticketcust->customerType = "Adult"; ticketcust->pricing = 38; break;
			case 2:ticketcust->customerType = "Senior Citizen"; ticketcust->pricing = 31; break;
			case 3:ticketcust->customerType = "Children"; ticketcust->pricing = 29; break;
			case 4:ticketcust->customerType = "Senior Citizen"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 50; break;
			case 5:ticketcust->customerType = "Adult"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 81; break;
			case 6:ticketcust->customerType = "Children"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 59; break;
			default:goto askagain; break;
		}
		this->guestslist.push_back(ticketcust);
	}
	
	std::cout << std::endl;
	std::cout << "Do you want to add another ticket type?(y/n)"; std::cin >> moretickettype;
	if (moretickettype == 'y')
		goto start;
	std::cout << "Enter the date you want to book (in numbers) : \n";
	std::cout << "Enter the day : "; std::cin >> this->dateofbooking[0];
	std::cout << "Enter the month : "; std::cin >> this->dateofbooking[1];
	std::cout << "Enter the year : "; std::cin >> this->dateofbooking[2];
	
}

void Customer::TicketInput()
{
	static int count = 1;
	
	system("cls");
	std::cout << "Enter info for ticket " << count << " : \n";
	std::cout << "Enter name : "; 
 	std::getline(std::cin, this->name);
	
	count++;
}

void Customer::DisplayReceipt()
{
	system("cls");
	std::cout << "Your booking date : \n";
	std::cout << "Day : " << this->dateofbooking[0] << "\n"<< "Month : " << this->dateofbooking[1] << "\n" << "Year : " << this->dateofbooking[2] << std::endl;
	if (!this->guestslist.empty())
	{
		std::cout << "\nTicket Infos:\n\n";
		for (size_t i = 0; i < this->guestslist.size(); ++i)
		{
			std::cout << std::endl;
			std::cout << "Name of guest " << i + 1 << " : " << this->guestslist.at(i)->name << std::endl;
			std::cout << "Ticket Type : " << this->guestslist.at(i)->nationality << " " << this->guestslist.at(i)->customerType << std::endl;
			std::cout << std::endl;
		}
	}
	system("pause");
}
