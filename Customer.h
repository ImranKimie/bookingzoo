#pragma once
#include "includes.h"
class Customer {
public:
	Customer();
	~Customer();
	void Reserve();
	void ReserveExtra();
	void DisplayReceipt();
	void ExtraGuests();
	void CalculatePricing();
private:
	std::string name;
	std::vector <Customer*> extraguests;
	std::string customerType;
	int dateofbooking[3]; // 0 - day,1 - month, 2 - year
	float pricing;
	std::string nationality;
};



