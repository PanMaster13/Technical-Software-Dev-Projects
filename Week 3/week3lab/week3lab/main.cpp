#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	string text = "poggers";
	int integer = 50;
	float floatingNum = 6.590209042;

	/*
	cout << "String example: ";
	getline(cin, text);
	cout << "Integer example: ";
	cin >> integer;
	cout << "Floating point number example: ";
	cin >> floatingNum;
	*/

	cout << "Your String: " << text << endl;
	cout << "Your Integer: " << integer << endl;
	cout << "Your Floating point number: " << floatingNum << endl;

	cout << endl << "Example of setw(10) command: " << endl;
	cout << "10 spaces of width" << setw(10) << text << endl;

	cout << endl << "setfill('-') << setw(80) << '-';" << endl;
	cout << setfill('-') << setw(80) << "-" << endl;

	cout << endl << "setprecision(3) for floating point numbers:" << endl;
	cout << setprecision(3) << floatingNum << endl;

	cout << endl << "Examples with setbase(integer):" << endl;
	cout << "Base 8 (oct): " << setbase(8) << integer << endl;
	cout << "Base 10 (dec): " << setbase(10) << integer << endl;
	cout << "Base 16 (hex): " << setbase(16) << integer << endl;
	return 0;
}