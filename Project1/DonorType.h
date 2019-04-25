/*
	Park, David
	CS A250
	March 3, 2015

	Project 1 B
*/

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class DonorType: public MemberType
{
public:
	// Default and Overloaded Constructors
	DonorType();
	DonorType(const string& newFName, const string& newLName,
				int newMemberID, double newDonationAmt);

	// Setter Functions
	void setDonorInfo(const string& newFName, const string& newLName,
				int newMemberID, double newDonationAmt);
	void setAmountDonated(double newDonationAmt);

	// Getter Functions
	double getAmountDonated() const;

	// Printer Functions
	void printDonor() const;
	void printDonation() const;

	// Destructor
	~DonorType();

private:
	double donationAmt;	// Donor's donation amount
};

#endif