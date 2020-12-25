#pragma once
#include "includes.h"
class Customer {
public:
	Customer();
	~Customer();
	void Reserve();
	void EditReservation();
	void ExtraGuests();
private:
	std::string name;
	int age;
	int numOfPeople[3];//0 - adult ,1 - kids,2 - elders
	std::string nationality;
	int dateofbooking[3]; // 0 - date,1 - month, 2 - year
	bool isElder, isChild;
};



