#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Complex {
public:
	Complex(double, double);
	Complex(double);
	Complex();
	double getReal() const { return real; }
	double getImaginary()const { return imaginary; }
	friend bool operator ==(const Complex&, const Complex&);
	friend const Complex operator +(const Complex&, const Complex&);
	friend const Complex operator -(const Complex&, const Complex&);
	friend const Complex operator -(const Complex&);
	friend const Complex operator *(const Complex&, const Complex&);
	friend ostream& operator <<(ostream& outputStream, Complex&);
	friend istream& operator >>(istream& inputStream, Complex&);
private:
	double real;
	double imaginary;
};

int main() {
	const Complex i(0, 1);
	Complex Complex1, Complex2, answer;
	cout << "Enter two complex numbers by formal 'a +/- bi':" << endl;
	cout << "Complex 1:";
	cin >> Complex1;
	cout << "Complex 2:";
	cin >> Complex2;

	answer = Complex1 + Complex2;
	cout << "(" << Complex1 << ") + (" << Complex2 << ") = " <<  answer  << endl;

	answer = Complex1 - Complex2;
	cout << "(" << Complex1 << ") - (" << Complex2 << ") = " << answer << endl;

	answer = Complex1 * Complex2;
	cout << "(" << Complex1 << ") * (" << Complex2 << ") = " << answer << endl;

	system("pause");
	return(0);
}

Complex::Complex(double realPart, double imaginaryPart) :real(realPart), imaginary(imaginaryPart) {}
Complex::Complex(double realPart) :real(realPart), imaginary(0){}
Complex::Complex():real(0), imaginary(0) {}

bool operator ==(const Complex& C1, const Complex& C2) {
	if (C1.real == C2.real && C1.imaginary == C2.imaginary) { return true; }
	else { return false; }
 }
const Complex operator +(const Complex& C1, const Complex& C2) {
	return Complex(C1.real + C2.real, C1.imaginary + C2.imaginary);
 }
const Complex operator -(const Complex& C1, const Complex& C2) {
	return Complex(C1.real - C2.real, C1.imaginary - C2.imaginary);
 }
const Complex operator -(const Complex& C1) {
	return Complex(-C1.real, -C1.imaginary);
}
const Complex operator *(const Complex& C1, const Complex& C2) {
	double ansR = 0, ansI = 0;
	ansR += C1.real * C2.real;
	ansR -= C1.imaginary * C2.imaginary;
	ansI += C1.real * C2.imaginary;
	ansI += C1.imaginary * C2.real;
	return Complex(ansR, ansI);
 }
ostream& operator <<(ostream& outputStream, Complex& C1) {
	outputStream << C1.real;
	if (C1.imaginary > 0) {
		outputStream << " + ";
		if (C1.imaginary == 1) {
			outputStream << "i";
		}
		else {
			outputStream << C1.imaginary << "i";
		}
	}
	if (C1.imaginary < 0) {
		outputStream << " - ";
		if (C1.imaginary == -1) { outputStream << "i"; }
		else { outputStream << abs(C1.imaginary) << "i"; }
	}

	return outputStream;
 }

istream& operator >>(istream& inputStream, Complex& C1) {
	char op;
	inputStream >> C1.real >> op >> C1.imaginary;
	if (getchar() != 'i') { cout << "Input formal 'a +/- bi'" << endl; }
	if (op == '-') {
		C1.imaginary = - C1.imaginary;
	}
	else if (op != '+') { cout << "Input formal 'a +/- bi'" << endl; }
	return(inputStream);
 }