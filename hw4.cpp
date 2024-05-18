/*Programming: Min-Fang Chuang   Date: 2024/05_6
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *replace all four-letter words with word "love"
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

//clean the char
void clear(void);

int main() {
	string Upper("Love") //start with a capital letter
		 , Lower("love");
	//repeat until the user say no
	while (true) {
		//input a line of text
		string line;
		cout << "Enter a line of text: ";
		getline(cin, line);

		//number of letters in a word
		// //the first index in a word
		// //now checking index
		int num = 0, first = 0, index = 0;
		//upper letter?
		bool up = true;

		//check each char in the text
		while (index < line.length()) {
			//is the first word in a word?
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
				//check the number of the word before this char
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
			//when the text end, check the last time
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
