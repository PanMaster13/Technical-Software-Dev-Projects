/*
Name: Jason Ang Chia Wuen
Student ID: 100087252
Date: 27/9/2020
Program Description: Program that predicts individual's admission status based on user info
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	// Variable Initialisation
	int age;
	double weight, height, bmi;
	string diabetes, gender, race, retry = "";
	bool isAdmission = false;

	while (retry != "no") {
		// Input validation for Age
		do {
			cout << "Enter your age: ";
			// Error type input (entered character instead of number)
			if (!(cin >> age)) {
				cout << "Please enter integer numbers only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			} else if (age < 1 || age >= 123) {
				cout << "Age cannot be less than 1 or more than 122." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} // Validation range for age is based on oldest person record (Source: https://www.guinnessworldrecords.com/news/2020/5/worlds-oldest-man-bob-weighton-dies-aged-112#:~:text=The%20oldest%20person%20ever%20to,days%20on%2012%20June%202013.)
		while (age < 1 || age >= 123);


		// Input validation for Weight
		do {
			cout << "Enter your weight (kg): ";
			// Error type input (entered character instead of number)
			if (!(cin >> weight)) {
				cout << "Please enter numbers only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			} else if (weight <= 2.0 || weight >= 443.0) {
				cout << "Weight cannot be less than 2.1kg or more than 442kg." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} // Validation range for weight based on lightest person and heaviest person in kg (Source: https://en.wikipedia.org/wiki/Luc%C3%ADa_Z%C3%A1rate & https://www.guinnessworldrecords.com/news/2018/12/history-of-heaviest-humans-as-worlds-biggest-man-loses-half-his-body-weight-550495#:~:text=The%20Heaviest%20man%20ever%20was,%3B%2069%20st%209%20lb).)
		while (weight <= 2.0 || weight >= 443.0);

		// Input validation for Height
		do {
			cout << "Enter your height (m): ";
			// Error type input (entered character instead of number)
			if (!(cin >> height)) {
				cout << "Please enter numbers only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			} else if (height <= 0.544 || height >= 2.73) {
				cout << "Height cannot be less than 0.545m or more than 2.73m." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} // Validation range for height based on shortest man and tallest man in meters (Source: https://en.wikipedia.org/wiki/List_of_tallest_people & https://en.wikipedia.org/wiki/List_of_the_verified_shortest_people)
		while (height <= 0.544 || height >= 2.73);

		// Input validation for Diabetes
		do {
			cout << "Do you have diabetes? (Yes/No): ";
			cin >> diabetes;

			// Coverts input into lowecase
			transform(diabetes.begin(), diabetes.end(), diabetes.begin(), ::tolower);
			if (diabetes != "yes" && diabetes != "no") {
				cout << "Please enter 'yes' or 'no' only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (diabetes != "yes" && diabetes != "no");

		// Input validation for Gender
		do {
			cout << "Gender (Male/Female): ";
			cin >> gender;

			// Coverts input into lowecase
			transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
			if (gender != "male" && gender != "female") {
				cout << "Please enter 'male' or 'female' only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (gender != "male" && gender != "female");

		// Input validation for Race
		do {
			cout << "Race (White/African American/Asian/Other/Unknown): ";
			cin.ignore();
			getline(cin, race);

			// Coverts input into lowecase
			transform(race.begin(), race.end(), race.begin(), ::tolower);
			if (race != "white" && race != "african american" && race != "asian" && race != "other" && race != "unknown") {
				cout << "Please enter 'white', 'african american', 'asian', 'other' or 'unknown' only." << endl;
			}
		} while (race != "white" && race != "african american" && race != "asian" && race != "other" && race != "unknown");

		// Calculate BMI
		bmi = weight / pow(height, 2.0);

		// Checking admission
		if (age > 65) {
			isAdmission = true;
		} else if (bmi > 40) {
			if (age > 35) {
				isAdmission = true;
			}
			else if (gender == "male") {
				isAdmission = true;
			}
			else {
				isAdmission = false;
			}
		} else if (age >= 20 && age <= 44) {
			isAdmission = false;
		} else if (gender == "male") {
			if (diabetes == "yes") {
				isAdmission = true;
			} else if (race == "white") {
				isAdmission = false;
			} else {
				isAdmission = true;
			}
		} else if (diabetes == "yes") {
			isAdmission = true;
		} else {
			isAdmission = false;
		}

		// Display Admission or No Admission
		if (isAdmission) {
			cout << "You have admission." << endl;
		} else {
			cout << "You do not have admission." << endl;
		}

		// User retry option
		do {
			cout << "\nWould you like to try again? (Yes/No): ";
			cin >> retry;
			// Coverts input into lowecase
			transform(retry.begin(), retry.end(), retry.begin(), ::tolower);
			if (retry != "yes" && retry != "no") {
				cout << "Please enter 'yes' or 'no' only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (retry != "yes" && retry != "no");
	}

	cout << "\nThank you for using this application!" << endl;
	return 0;
}