/*Programming: Min-Fang Chuang   Date: 2024/04/29
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *define a class "PrimeNumber" and operators: ++ & --
 */
#include<iostream>
#include<cstdlib>
using namespace std;

//define class
class PrimeNumber {
public:
	PrimeNumber(int);
	PrimeNumber();
	int getPrime()const { return prime; }
	//operator '++' pre-increment
	PrimeNumber operator ++();
	//operator '++' post-increment
	PrimeNumber operator ++(int);
	//operator '--' pre-decrement
	PrimeNumber operator --();
	//operator '--' post-decrement
	PrimeNumber operator --(int);
private:
	int prime;
	void test();
};

int main() {
	PrimeNumber p1(13), ans;

	//test four operator and display the result
	cout << "p1=" << p1.getPrime() << endl;
	ans = ++p1;
	cout << ans.getPrime() << " = ++p1" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "p1=" << p1.getPrime() << endl;
	ans = p1++;
	cout << ans.getPrime() << " = p1++" << endl;
	ans = p1;
	cout << "after p1++, p1 = " << ans.getPrime() << endl;

	cout << "-----------------------------------\n" << endl;
	cout << "p1=" << p1.getPrime() << endl;
	ans = --p1;
	cout << ans.getPrime() << " = --p1" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "p1=" << p1.getPrime() << endl;
	ans = p1--;
	cout << ans.getPrime() << " = p1--" << endl;
	ans = p1;
	cout << "after p1--, p1 = " << ans.getPrime() << endl;


	system("pause");
	return(0);
}

PrimeNumber::PrimeNumber(int num): prime(num){
	test();
}
PrimeNumber::PrimeNumber():prime(1){}
PrimeNumber PrimeNumber::operator ++(int ignore) {
	int old = prime;
	//find next largest prime number
	while (true) {
		prime++;
		int num = 2;
		bool di = true;
		while (num != prime) {
			if (prime % num == 0) {
				di = false;
				break;
			}
			num++;
		}
		if (di) { break; }
	}
	return PrimeNumber(old);
}
PrimeNumber PrimeNumber::operator ++() {
	//find next largest prime number
	while (true) {
		prime++;
		int num = 2;
		bool di = true;
		while (num != prime) {
			if (prime % num == 0) {
				di = false;
				break;
			}
			num++;
		}
		if (di) { break; }
	}
	return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator --(int ignore) {
	int old = prime;
	//find next smallest prime number
	while (true) {
		prime--;
		int num = 2;
		bool di = true;
		while (num != prime) {
			if (prime % num == 0) {
				di = false;
				break;
			}
			num++;
		}
		if (di) { break; }
	}
	return PrimeNumber(old);
}
PrimeNumber PrimeNumber::operator --() {
	//find next smallest prime number
	while (true) {
		prime--;
		int num = 2;
		bool di = true;
		while (num != prime) {
			if (prime % num == 0) {
				di = false;
				break;
			}
			num++;
		}
		if (di) { break; }
	}
	return PrimeNumber(prime);
}

void PrimeNumber::test() {
	int n = 2;
	while (n != prime) {
		if (prime % n == 0) {
			cout << "<Error> : " << prime << " isn't prime number" << endl;
			exit(1);
		}
		n++;
	}
}
