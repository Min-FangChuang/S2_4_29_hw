/*Programming: Min-Fang Chuang   Date: 2024/04/29
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *define a class "MyInteger" and operator: []
 */
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;


//define the class
class MyInteger {
public:
	int getInteger()const { return integer; }
	void setInteger(int);
	int& operator [](int);
private:
	int integer;
};

int main() {
	//declare a object
	MyInteger num;

	//set the number by the keyboard
	int number;
	cout << "Enter an integer>>";
	cin >> number;
	num.setInteger(number);

	//display every digit of the number by operator '[]'
	int index = -1;
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
	//not allow
	if (index < 0) {
		cout << "<Error> : the least-significant digit is 0" << endl;
		exit(1);
	}
	int digit;
	//no digit return -1
	if (integer < pow(10, index)) {
		digit = -1;
	}
	else {
		digit = integer / pow(10, index);
		digit %= 10;
	}
	return digit;
}
