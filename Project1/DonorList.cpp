#include "DonorList.h"

void printMemberID(int memberID);

// default constructor
DonorList::DonorList()
{
	donors = new list<DonorType>;
}

// addDonor
void DonorList::addDonor(const string& fName, const string& lName,
	int memberID, double donationAmt)
{
	donors->push_back(DonorType(fName, lName, memberID, donationAmt));
}


// searchDonor
bool DonorList::searchDonorByMemberNo(int memberID) const
{
	bool found = false;
	list<DonorType>::const_iterator iterList = donors->begin();

	while (!found && iterList != donors->end())
	{
		if (iterList->getMembershipNo() == memberID)
			found = true;
		else
			++iterList;
	}

	return found;
}


// isEmpty
bool DonorList::isEmpty() const
{
	return donors->empty();
}

// printAllDonors
void DonorList::printAllDonors() const
{
	list<DonorType>::const_iterator iterList = donors->begin();

	while (iterList != donors->end())
	{
		cout << iterList->getMembershipNo() << " - ";
		iterList->printName();
		++iterList;
	}
}

// destructor
DonorList::~DonorList()
{
}

void DonorList::deleteDonor(int memberID)
{
	if (isEmpty())
		cerr << "Cannot delete from an empty list.";
	else
	{
		list<DonorType>::iterator iterList = donors->begin();

		if (searchDonorLocation(memberID, iterList))
			donors->erase(iterList);
	}
}

void DonorList::printDonorByName(const string& lName) const
{
	list<DonorType>::const_iterator iterList = donors->begin();
	bool found = false;

	while (!found && iterList != donors->end())
	{
		if (iterList->getLastName() == lName)
			found = true;
		else
			++iterList;
	}


	if (iterList == donors->end())
		cerr << "There are no donors with this last name." << endl;
	else
		iterList->printMemberInfo();
}

void DonorList::printDonor(int memberID) const
{
	list<DonorType>::iterator iterList = donors->begin();


	if (searchDonorLocation(memberID, iterList))
		iterList->printMemberInfo();
	else
		cerr << "This membership number is not in the list." << endl;
}

void DonorList::printDonation(int memberID) const
{
	list<DonorType>::iterator iterList = donors->begin();

	if (searchDonorLocation(memberID, iterList))
	{
		iterList->printName();
		cout << "    Donation amount: $" << fixed << setprecision(2) <<
			iterList->getAmountDonated() << endl;
	}
	else
		cerr << "This membership number is not in the list." << endl;
}

void DonorList::printTotalDonations() const
{
	double total = 0.0;
	list<DonorType>::const_iterator iterList = donors->begin();

	while (iterList != donors->end())
	{
		total += iterList->getAmountDonated();
		++iterList;
	}

	cout << "Total Donations: $" << fixed << setprecision(2) << total << endl;
}

void DonorList::printHighestDonation() const
{
	double highest = 0.0;
	list<DonorType>::const_iterator iterList = donors->begin();
	list<DonorType>::const_iterator highestDonor = donors->begin();

	while (iterList != donors->end())
	{
		if (highest < iterList->getAmountDonated())
		{
			highest = iterList->getAmountDonated();
			highestDonor = iterList;
		}
		++iterList;
	}

	cout << "Highest Donation: $" << fixed << setprecision(2) << highest << endl;
	cout << "    Donated by: ";
	highestDonor->printName();
}

bool DonorList::searchDonorLocation(int memberID, list<DonorType>::iterator& iter) const
{
	bool found = false;

	while (iter != donors->end() && !found)
	{
		if (iter->getMembershipNo() == memberID)
			found = true;
		else
			++iter;
	}

	return found;
}