#pragma once
#include "includes.h"
class Customer {
public:
	Customer();
	~Customer();
	void Reserve();
	void ReserveExtra();
	void DisplayReservation();
	void ExtraGuests();
	void CalculatePricing();
private:
	std::string name;
	int age;
	std::vector <Customer*> extraguests;
	std::string currentCustGroup;
	//int ageGroup[3] = {};//0 - child , 1 - adults , 2 - senior citizen
	int inationality;
	int dateofbooking[3]; // 0 - day,1 - month, 2 - year
	float pricing;
	std::string nationality;
};



