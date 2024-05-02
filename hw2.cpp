#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class MyInteger {
public:
	int getInteger()const { return integer; }
	void setInteger(int);
	int& operator [](int);
private:
	int integer;
};

int main() {
	MyInteger num;
	int number;
	cout << "Enter an integer>>";
	cin >> number;
	num.setInteger(number);
	int index = -1, digit;
	do {
		index++;
		cout << "integer [" << index << "] = ";
		cout << num[index] << endl;
	} while (num[index] != -1);

	system("pause");
	return 0;
}

void MyInteger::setInteger(int num) {
	integer = num;
}
int& MyInteger::operator [](int index) {
	if (index < 0) {
		cout << "<Error> : the least-significant digit is 0" << endl;
	}
	int digit;
	if (integer < pow(10, index)) {
		digit = -1;
	}
	else {
		digit = integer / pow(10, index);
		digit %= 10;
	}
	return digit;
}