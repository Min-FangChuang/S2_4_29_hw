#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Subscriber {
public:
	Subscriber(string, int, string*);
	Subscriber();
	void setName(string);
	void setNumChannels(int);
	void setChannelList(string*);
	string getName()const { return name; }
	int getNumChannels()const { return numChannels; }
	string* getChannelList()const { return channelList; }
	void input();
	void output();
	void reset();
	Subscriber& operator =(const Subscriber&);
	~Subscriber();
private:
	string name;
	int numChannels;
	string* channelList;
};

int main() {
	Subscriber S1, S2("Annie", 3, new string[3]{ "channel_A" ,"channel_B" ,"channel_C" });
	cout << "Subscriber 1: " << endl;
	S1.input();
	cout << "-----------------------" << endl;
	cout << "Subscriber 1: " << endl;
	S1.output();
	cout << "-----------------------" << endl;
	cout << "Subscriber 2: " << endl;
	S2.output();
	cout << "-----------------------" << endl;
	cout << "After copy Subscriber 2 to Subscriber 1"<<endl<<"Subscriber 1: " << endl;
	S1 = S2;
	S1.output();
	cout << "--------------------" << endl;
	cout << "After reset the Subscriber 2" << endl << "Subscriber 2: " << endl;
	S2.reset();
	S2.output();
	
	system("pause");
	return(0);
}

Subscriber::Subscriber(string Name, int num, string* List) : name(Name), numChannels(num), channelList(List) {
	//nothing
}
Subscriber::Subscriber() :name(""), numChannels(0), channelList(NULL) {
	//nothing
}
void Subscriber::setName(string name) {
	this->name = name;
}
void Subscriber::setNumChannels(int num) {
	numChannels = num;
}
void Subscriber::setChannelList(string* list) {
	channelList = list;
}
void Subscriber::input() {
	cout << "Enter the name of the subscriber: ";
	cin >> name;
	cout << "Enter how many channels the subscriber Subscribes to: ";
	cin >> numChannels;
	delete[]channelList;
	channelList = NULL;
	channelList = new string[numChannels];
	cout << "Enter the channels names one by on:" << endl;
	for (int i = 0;i < numChannels;i++) {
		cout <<  i + 1 << ". ";
		cin >> channelList[i];
	}
}
void Subscriber::output() {
	cout << "The subscriber: " << name << endl;
	cout << "The number of channels: " << numChannels << endl;
	cout << "Channel List: " << endl;
	for (int i = 0;i < numChannels;i++) {
		cout << i + 1 << ". " << channelList[i] << endl;
	}
}
void Subscriber::reset() {
	numChannels = 0;
	delete[]channelList;
	channelList = NULL;
}
Subscriber& Subscriber::operator =(const Subscriber& S1) {
	if (this == &S1) {
		return *this;
	}
	name = S1.name;
	numChannels = S1.numChannels;
	delete[]channelList;
	channelList = NULL;
	channelList = new string[numChannels];
	for (int i = 0;i < numChannels;i++) {
		channelList[i] = S1.channelList[i];
	}
	return *this;
}
Subscriber::~Subscriber() {
	delete[]channelList;
	channelList = NULL;
}