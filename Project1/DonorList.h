/*
	Park, David
	CS A250
	April 23, 2015
	
	Project 2 A
*/

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include<iostream>
#include <string>		
#include <iomanip>
#include <list>

using namespace std;

class DonorList
{
public:
	// default constructor
	DonorList();

	// addDonor
	void addDonor(const string& fName, const string&lName,
		int memberID, double donationAmt);

	// searchDonorByMemberNo
	bool searchDonorByMemberNo(int memberID) const;

	// isEmpty
	bool isEmpty() const;

	// printAllDonors
	void printAllDonors() const;

	// destroyList
	void destroyList();

	// destructor
	~DonorList();

	void deleteDonor(int memberID);

	void printDonorByName(const string& lName) const;

	void printDonor(int memberID) const;

	void printDonation(int memberID) const;

	void printTotalDonations() const;

	void printHighestDonation() const;

private:
	list<DonorType> * donors;

	bool searchDonorLocation(int memberID, 
						list<DonorType>::iterator& iterList) const;
};

#endif

