/*
Name: Jason Ang Chia Wuen
Student ID: 100087252
Date: 4/11/2020
Program Description: Program that calculates monthly charge for each customer and other additional details in a text file
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

// Struct data type for Customer Data
struct customerData {
	string propUnit = "";
	string custType = "";
	string prevReading = "";
	string currReading = "";
	double monthlyCharge = 0;
};

// Function that gets user input for textfile name, validates it, and transforms the acquired data into a vector list
void textFileInputValidation(vector<customerData> &customerDataList) {
	bool fileIsNotFound = true;
	string fileName;
	ifstream file;

	// Input Validation using do while loop
	do {
		cout << "Please enter the name of file to be analysed (include file extension, e.g. .txt): ";
		getline(cin, fileName);
		file.open(fileName);
		if (!file) {
			cout << "No file with name '" << fileName << "' is found. Please try again.\n" << endl;
		} else {
			fileIsNotFound = false;
			// Obtains file data by line until it reaches end of file
			for (string line; getline(file, line); ) {
				// Split file into by spaces into a vector token
				istringstream buf(line);
				istream_iterator<string> beg(buf), end;
				vector<string> tokens(beg, end);

				// Create customer struct with data and pushed into vector list to be referred to later
				customerData customer;
				customer.propUnit = tokens[0];
				customer.custType = tokens[1];
				customer.prevReading = tokens[2];
				customer.currReading = tokens[3];
				customerDataList.push_back(customer);
			}
		}
	} while (fileIsNotFound);
}

// Function that determines the top 3 highest values based on given values
void findTopThreeHighestValues(customerData &value, customerData &first, customerData &second, customerData &third) {
	if (value.monthlyCharge > first.monthlyCharge) {
		third = second;
		second = first;
		first = value;
	} else if (value.monthlyCharge > second.monthlyCharge) {
		third = second;
		second = value;
	} else if (value.monthlyCharge > third.monthlyCharge) {
		third = value;
	}
}

// Function to remove duplicate files
void removeDuplicateFiles() {
	remove("domestic.txt");
	remove("commecial.txt");
}

// Function that calculates the monthly charge for each customer and other additional analysis
void performAnalysis(vector<customerData> &customerList, int &domesticNum, double &domesticTotal, customerData &domesticFirst, customerData& domesticSecond, customerData& domesticThird, int & commecialNum, double &commecialTotal, customerData &commecialFirst, customerData &commecialSecond, customerData &commecialThird) {
	for (int i = 0; i < customerList.size(); i++) {
		double monthCharge = 0, previous = stod(customerList[i].prevReading), current = stod(customerList[i].currReading), unitsConsumed = current - previous;

		if (customerList[i].custType == "Domestic") {
			monthCharge = getMonthlyChargeDomestic(unitsConsumed);
			customerList[i].monthlyCharge = monthCharge;
			domesticNum++;
			domesticTotal += monthCharge;
			// Set file to open with append mode
			ofstream outputFile("domestic.txt", ios_base::app);
			outputFile << customerList[i].propUnit << " " << customerList[i].custType << " " << previous << " " << current << " " << setprecision(2) << fixed << monthCharge << "\n";
			outputFile.close();

			// Finding out top 3 for domestic customers
			findTopThreeHighestValues(customerList[i], domesticFirst, domesticSecond, domesticThird);
		} else if (customerList[i].custType == "Commecial") {
			monthCharge = getMonthlyChargeCommercial(unitsConsumed);
			customerList[i].monthlyCharge = monthCharge;
			commecialNum++;
			commecialTotal += monthCharge;
			// Set file to open with append mode
			ofstream outputFile("commecial.txt", ios_base::app);
			outputFile << customerList[i].propUnit << " " << customerList[i].custType << " " << previous << " " << current << " " << setprecision(2) << fixed << monthCharge << "\n";
			outputFile.close();

			// Finding out top 3 for commercial customers
			findTopThreeHighestValues(customerList[i], commecialFirst, commecialSecond, commecialThird);
		}
	}
}

// Outputs the results of analysis
void printSummary(int domesticNum, double domesticTotal, int commecialNum, double commecialTotal, customerData domesticFirst, customerData domesticSecond, customerData domesticThird, customerData commecialFirst, customerData commecialSecond, customerData commecialThird) {
	cout << "\nNumber of domestic customers:   " << domesticNum << endl;
	cout << "Number of commercial customers: " << commecialNum << endl;
	cout << "Average monthly charge for domestic customers:   RM " << setprecision(2) << fixed << (domesticTotal / domesticNum) << endl;
	cout << "Average monthly charge for commercial customers: RM " << setprecision(2) << fixed << (commecialTotal / commecialNum) << endl;

	cout << "\nTop 3 domestic customers with highest monthly charges:\n";
	cout << "1. " << domesticFirst.propUnit << " - RM " << setprecision(2) << fixed << domesticFirst.monthlyCharge;
	cout << "\n2. " << domesticSecond.propUnit << " - RM " << setprecision(2) << fixed << domesticSecond.monthlyCharge;
	cout << "\n3. " << domesticThird.propUnit << " - RM " << setprecision(2) << fixed << domesticThird.monthlyCharge;

	cout << "\n\nTop 3 commercial customers with highest monthly charges:\n";
	cout << "1. " << commecialFirst.propUnit << " - RM " << setprecision(2) << fixed << commecialFirst.monthlyCharge;
	cout << "\n2. " << commecialSecond.propUnit << " - RM " << setprecision(2) << fixed << commecialSecond.monthlyCharge;
	cout << "\n3. " << commecialThird.propUnit << " - RM " << setprecision(2) << fixed << commecialThird.monthlyCharge << endl;
}

int main() {
	vector<customerData> customerDataList;

	// Variables used to calculate number of customer types and average monthly charges for each type
	int domesticNum = 0, commecialNum = 0;
	double domesticTotal = 0, commecialTotal = 0;
	customerData domesticFirst, domesticSecond, domesticThird, commecialFirst, commecialSecond, commecialThird;

	cout << "Welcome to the Electricity Bill Batch Processor Program!\n";

	// Validating user input and reading data from textfile into vector list
	textFileInputValidation(customerDataList);

	// Removes copies of any exisiting files
	removeDuplicateFiles();

	// Monthly Charge Calculation and additional analysis (e.g. Average Montly Charges)
	performAnalysis(customerDataList, domesticNum, domesticTotal, domesticFirst, domesticSecond, domesticThird, commecialNum, commecialTotal, commecialFirst, commecialSecond, commecialThird);

	// Displays Analysis Summary
	printSummary(domesticNum, domesticTotal, commecialNum, commecialTotal, domesticFirst, domesticSecond, domesticThird, commecialFirst, commecialSecond, commecialThird);
	return 0;
}