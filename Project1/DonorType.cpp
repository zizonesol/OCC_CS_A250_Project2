#include "DonorType.h"

// Default and Overloaded Constructors
DonorType::DonorType()
{
	donationAmt = 0.0;
}

DonorType::DonorType(const string& newFName, const string& newLName,
	int newMemberID, double newDonationAmt)
	: MemberType(newFName, newLName, newMemberID)
{
	donationAmt = newDonationAmt;
}

// Setter Functions
void DonorType::setDonorInfo(const string& newFName, const string& newLName,
	int newMemberID, double newDonationAmt)
{
	setMemberInfo(newFName, newLName, newMemberID);
	donationAmt = newDonationAmt;
}

void DonorType::setAmountDonated(double newDonationAmt)
{
	donationAmt = newDonationAmt;
}

// Getter Functions
double DonorType::getAmountDonated() const
{
	return donationAmt;
}

// Printer Functions
void DonorType::printDonor() const
{
	printMemberInfo();
}

void DonorType::printDonation() const
{
	printName();
	cout << endl;
	cout << "    Donation amount: $";
	cout << fixed << setprecision(2) << donationAmt << endl;
}

// Destructor
DonorType::~DonorType()
{
} 