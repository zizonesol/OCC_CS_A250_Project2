#include "MemberType.h"

// Default Constructor
MemberType::MemberType()
{
	memberID = 0;
}

// Overloaded Constructor
MemberType::MemberType(const string& newFName, const string& newLName,
	int newMemberID)
{
	fName = newFName;
	lName = newLName;
	memberID = newMemberID;
}

// Setter Function
void MemberType::setMemberInfo(const string& newFName, const string& newLName,
	int newMemberID)
{
	fName = newFName;
	lName = newLName;
	memberID = newMemberID;
}

// Getter Functions
string MemberType::getFirstName() const
{
	return fName;
}

string MemberType::getLastName() const
{
	return lName;
}

int MemberType::getMembershipNo() const
{
	return memberID;
}

// Printer Functions
void MemberType::printName() const
{
	cout << lName << ", " << fName << endl;
}

void MemberType::printMemberInfo() const
{
	cout << memberID << " - " << fName << " " << lName << endl;
}

// Destructor
MemberType::~MemberType()
{
}