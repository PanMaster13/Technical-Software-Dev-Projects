#include <iostream>
#include <math.h>

using namespace std;

// Function to calculate I (Amps)
double calculation(int f, int r, double c, double l, int e, double pi) {
	double answer = 0;
	// pow() raises the base by the exponent
	// sqrt() is square root
	answer = e / sqrt(pow(r, 2) + pow((2 * pi * f * l) - 1 / (2 * pi * f * c), 2));

	return answer;
}

int main() {
	const double pi = 3.14159;
	int f = 0;
	int r = 0;
	double c = 0;
	double l = 0;
	int e = 0;

	cout << "Enter frequency(Hz): ";
	cin >> f;
	cout << "Enter EMF(V): ";
	cin >> e;
	cout << "Enter resistance(Ohms): ";
	cin >> r;
	cout << "Enter capacitance(F): ";
	cin >> c;
	cout << "Enter inductance(H): ";
	cin >> l;
	cout << endl;
	cout << "f(HZ)\tEMF(V)\tR(Ohms)\tC(F)\tI(H)" << endl;
	cout << f << "\t" << e << "\t" << r << "\t" << c << "\t" << l << endl;

	double ans = 0;

	ans = calculation(f, r, c, l, e, pi);

	cout << "The current is " << ans << "Amps." << endl << endl;

	cout << "f (Hz)\t\tI (Amps)" << endl;
	cout << "------\t\t------" << endl;
	for (f = 1; f < 301; f = f + 10) {
		ans = calculation(f, r, c, l, e, pi);
		cout << f << "Hz\t\t" << ans << "A" << endl;
	}
	return 0;
}