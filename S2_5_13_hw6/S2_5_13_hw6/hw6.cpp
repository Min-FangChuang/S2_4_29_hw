#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Television {
public:
	Television(string, double, string*);
	Television();
	~Television();
	void setDisplayType(string);
	void setDimension(double);
	void setConnectivitySupport(string*);
	string getDisplayType()const { return displayType; }
	double getDimension()const { return dimension; }
	string* getConnectivitySupport()const { return connectivitySupport; }
	Television& operator =(Television&);
private:
	string displayType;
	double dimension;
	string* connectivitySupport;
};

void input(Television&);
void clean();

int main() {
	Television Default;
	input(Default);
	cout << endl << "---------------------------------" << endl;
	int number;
	cout << "The number of television: ";
	cin >> number;
	Television* televisions;
	televisions = new Television[number];
	for (int i = 0;i < number;i++) {
		televisions[i] = Default;
	}
	for (int i = 0;i < number;i++) {
		getchar();
		cout << "\nTelevision " << i + 1 << " :\n" << "Do you want customization (y/n) ?";
		if (getchar() == 'n') {
			continue;
		}
		input(televisions[i]);
	}

}

Television::Television(string type, double dim, string* support) : displayType(type), dimension(dim), connectivitySupport(support) {
	//nothing
}
Television::Television() : displayType(""), dimension(0), connectivitySupport(NULL) {
	//nothing
}
void Television::setDisplayType(string type) {
	displayType = type;
}
void Television::setDimension(double dim) {
	dimension = dim;
}
void Television::setConnectivitySupport(string* support) {
	connectivitySupport = support;
}
Television& Television::operator =(Television& T2) {
	if (this == &T2) {
		return *this;
	}
	displayType = T2.displayType;
	dimension = T2.dimension;
	connectivitySupport = T2.connectivitySupport;
	/*delete[]connectivitySupport;
	connectivitySupport = NULL;*/

	//int size = sizeof(T2.connectivitySupport)/sizeof(T2.connectivitySupport[0]);
	/*int size = 0;
	while (T2.connectivitySupport[size] != "") {
		cout << ".";
		cout << T2.connectivitySupport[size]<<" ";
		if (T2.connectivitySupport[size + 1] == "") { break; }
		++size;
	}
	cout << "(" << size << ")" << endl;
	*/
	/*
	connectivitySupport = new string[size] ;
	for (int i = 0;i < size;i++) {
		cout << T2.connectivitySupport[i];
		connectivitySupport[i] = T2.connectivitySupport[i];
	}
	*/
	return *this;
}

Television::~Television() {
	if (connectivitySupport) {
		delete[]connectivitySupport;
		connectivitySupport = NULL;
	}
}

void input(Television& T1) {
	string type;
	cout << "Enter the display type of television: ";
	cin >> type;
	T1.setDisplayType(type);

	double inches;
	cout << "Enter the dimension of the television in inches: ";
	cin >> inches;
	T1.setDimension(inches);

	const int max = 10;
	int num = 0;
	string support[max];
	cout << "Enter the different connectivity modes support by the television: " << endl;
	while (num < max) {
		cout << num + 1 << ". connectivity mode: ";
		cin >> support[num];

		clean();
		cout << "Have other different connectivity modes (y/n) ? ";
		if (getchar() == 'n') {
			clean;
			break;
		}

		clean;
		num++;
	}
	//cout << "num+1 = " << num + 1 << endl;
	string* supportPtr = new string[num + 1];
	//cout << sizeof(support) << "," << sizeof(string);

	for (int i = 0;i <= num;i++) {
		supportPtr[i] = support[i];
	}
	T1.setConnectivitySupport(supportPtr);
}

void clean() {
	do {
		if (getchar() == '\n') { break; }
	} while (true);
}