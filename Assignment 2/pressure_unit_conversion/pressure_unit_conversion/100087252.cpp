/*
Name: Jason Ang Chia Wuen
Student ID: 100087252
Date: 6/10/2020
Program Description: Program that performs aviation speed unit conversions
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <iomanip>

using namespace std;

// Function that converts string input into a vector array of various data types (etc. string, int)
template <class ArrayType>
vector<ArrayType> stringToArray(string input) {
	vector<ArrayType> array;
	size_t pos = 0;
	string token;
	bool result = true;
	while ((pos = input.find(" ")) != string::npos) {
		token = input.substr(0, pos);
		array.push_back(token);
		input.erase(0, pos + 1);
	}
	array.push_back(input);
	return array;
}

// Function that calculates based on input provided and generates conversion table
void createConversionTable(vector<string> measurement_array, vector<string> value_array, float increment) {

	// Creates table title
	cout << "knots";
	for (int i = 0; i < measurement_array.size(); i++) {
		cout << setw(10);
		cout << measurement_array[i];
	}
	cout << endl;

	// Creates table content
	for (float current_value = stof(value_array[0]); current_value <= stof(value_array[1]); current_value += increment) {
		// Formats the currenct value output to 3 decimal places
		cout << setprecision(3) << fixed << current_value;
		for (int i = 0; i < measurement_array.size(); i++) {
			float multiplier = 0, result = 0;
			// String values cannot be applied to switch case notations, if-else is used instead
			if (measurement_array[i] == "km/h") {
				multiplier = 1.852;
			}
			else if (measurement_array[i] == "m/s") {
				multiplier = 0.514444;
			}
			else if (measurement_array[i] == "mph") {
				multiplier = 1.15078;
			}
			result = current_value * multiplier;
			// Sets a width of 10
			cout << setw(10);
			cout << result;
		}
		cout << endl;
	}
}

int main() {
	string measurements, values;
	float increment;
	vector<string> measurement_array, value_array;
	bool measurement_is_wrong = true, value_is_wrong = true, increment_is_wrong = true;

	// Program Title
	cout << "Aviation Speed Unit Conversion Table" << endl;

	// Input Validation for measurement unit(s) selected
	do {
		cout << "Choose one or more measurement unit(s) as the converted aviation speed units: km/h, m/s and mph (separated with a space if more than one): ";
		getline(cin, measurements);
		// Converts input into string vector
		measurement_array = stringToArray<string>(measurements);
		for (int i = 0; i < measurement_array.size(); i++) {
			if (measurement_array[i] == "km/h" || measurement_array[i] == "m/s" || measurement_array[i] == "mph") {
				measurement_is_wrong = false;
			}
			else {
				measurement_is_wrong = true;
			}
		}
		if (measurement_is_wrong) {
			cout << "Please ensure that the units match the descriptions and there are spacing between them." << endl << endl;
		}
	} while (measurement_is_wrong);

	// Input Validation for starting and ending value
	do {
		cout << "Enter the starting value and ending value for primary unit in knots (separated with a space): ";
		getline(cin, values);
		// Converts input into string vector
		value_array = stringToArray<string>(values);
		if (value_array.size() == 2) {
			if ((regex_match(value_array[0], regex("[+-]?([0-9]*[.])?[0-9]+"))) && (regex_match(value_array[1], regex("[+-]?([0-9]*[.])?[0-9]+")))) {
				value_is_wrong = false;
			} else {
				cout << "Please enter floating point numbers only." << endl << endl;
			}
		} else {
			cout << "Please ensure that there are 2 and only 2 values entered." << endl << endl;
		}
	} while (value_is_wrong);
	
	// Input Validation for increment number
	do {
		cout << "Enter the increment from one primary unit row to the next row: ";
		if (!(cin >> increment)) {
			cout << "Please enter numbers only." << endl << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			increment_is_wrong = false;
		}
	} while (increment_is_wrong);

	// Calls function to generate conversion table
	createConversionTable(measurement_array, value_array, increment);

	return 0;
}