#include<iostream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

void clear(void);

int main() {
	string Upper("Love"), Lower("love");
	while (true) {
		string line;
		cout << "Enter a line of text: ";
		getline(cin, line);
		int num = 0, first = 0, index = 0;
		bool up = true;
		while (index < line.length()) {
			if (isalpha(line[index])) {
				if (num == 0) { 
					first = index; 
					if (isupper(line[index])) {
						up = true;
					}
					else {
						up = false;
					}
				}
				num++;
			}
			else {
				if (num == 4) {
					if (up) {
						line.replace(first, 4, Upper);
					}
					else {
						line.replace(first, 4, Lower);
					}
				}
				num = 0;
			}
			if (index == line.length() - 1) {
				if (num == 4) {
					if (up) {
						line.replace(first, 4, Upper);
					}
					else {
						line.replace(first, 4, Lower);
					}
				}
			}
			index++;
		}
		cout << line << endl;
		cout << "Again? (y/n): ";
		if (getchar() == 'n') {
			break;
		}
		clear();
		cout << endl;
	}

	system("pause");
	return(0);
}

void clear(void) {
	char op;
	do {
		op = getchar();
	} while (op != '\n');
}
