/*
Name: Jason Ang Chia Wuen
Student ID: 100087252
Date: 
Program Description: 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <iomanip>
#include "tariff.h"

using namespace std;

struct customerData {
	string propUnit;
	string custType;
	string prevReading;
	string currReading;
};

int main() {
	string fileName;
	ifstream inputFile;
	bool fileIsNotFound = true;
	vector<customerData> customerDataList;
	int domesticNum = 0, commercialNum = 0;
	double domesticTotal = 0, commercialTotal = 0;

	cout << "Welcome to the Electricity Bill Batch Processor Program!\n";

	// Validating user input and reading data from textfile into vector list
	do {
		cout << "Please enter the name of file to be analysed (include file extension, e.g. .txt): ";
		getline(cin, fileName);
		inputFile.open(fileName);
		if (!inputFile) {
			cout << "No file with name '" << fileName << "' is found. Please try again.\n" << endl;
		}
		else {
			fileIsNotFound = false;
			for (string line; getline(inputFile, line); ) {
				customerData customer;
				istringstream buf(line);
				istream_iterator<string> beg(buf), end;
				vector<string> tokens(beg, end);
				customer.propUnit = tokens[0];
				customer.custType = tokens[1];
				customer.prevReading = tokens[2];
				customer.currReading = tokens[3];
				customerDataList.push_back(customer);
			}
		}

		inputFile.close();
	} while (fileIsNotFound);

	// Removes copies of any exisiting files
	remove("domestic.txt");
	remove("commercial.txt");

	for (int i = 0; i < customerDataList.size(); i++) {
		double monthCharge = 0, prevReading = stod(customerDataList[i].prevReading), currReading = stod(customerDataList[i].currReading), unitsConsumed = currReading - prevReading;
		
		if (customerDataList[i].custType == "Domestic") {
			monthCharge = getMonthlyChargeDomestic(unitsConsumed);
			domesticNum++;
			domesticTotal += monthCharge;
			ofstream outputFile("domestic.txt", ios_base::app);
			outputFile << customerDataList[i].propUnit << " " << customerDataList[i].custType << " " << prevReading << " " << currReading << " " << setprecision(2) << fixed << monthCharge << "\n";
			outputFile.close();
		} else if (customerDataList[i].custType == "Commecial") {
			monthCharge = getMonthlyChargeCommercial(unitsConsumed);
			commercialNum++;
			commercialTotal += monthCharge;
			ofstream outputFile("commercial.txt", ios_base::app);
			outputFile << customerDataList[i].propUnit << " " << customerDataList[i].custType << " " << prevReading << " " << currReading << " " << setprecision(2) << fixed << monthCharge << "\n";
			outputFile.close();
		}
	}

	cout << "Number of domestic customers:   " << domesticNum << endl;
	cout << "Number of commercial customers: " << commercialNum << endl;
	cout << "Average monthly charge for domestic customers:   " << setprecision(2) << fixed << (domesticTotal / domesticNum) << endl;
	cout << "Average monthly charge for commercial customers: " << setprecision(2) << fixed << (commercialTotal / commercialNum) << endl;
	return 0;
}