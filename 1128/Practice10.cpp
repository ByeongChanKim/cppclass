#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

class WordList {
private :
	vector<string> dic;
	list<string> word;
public :
	WordList();
	void Checkprint(string std);
	void CheckDictionary(string str);
	void CheckDuplication(string str);
	void CheckConfirm(string str);
	void add(string str);
	void startGame();
};

int main() {
	
	WordList wl;
	wl.startGame();

	return 0;
}

WordList::WordList()
{
	ifstream infile("dic.txt");

	string dicword;
	while (!infile.eof()) {
		getline(infile, dicword);
		dic.push_back(dicword);
	}	
}

void WordList::Checkprint(string std)
{
	if (std == "printdic") {
		for (int i = 0; i < dic.size(); i++) {
			cout << dic[i] << endl;
		}
	}
	if (std == "printword") {
		list<string>::iterator itr = word.begin();
		for (int i = 0; i < word.size(); i++) {
			cout << *(itr++) << ">> ";
		}
	}
}

void WordList::CheckDictionary(string str)
{
	vector<string>::iterator itr = dic.begin();
	while (itr != dic.end()) {
		if (*itr == str) return;
		itr++;
	}
	throw string("Not Exist in Dictionary!");
}

void WordList::CheckDuplication(string str)
{
	list<string>::iterator itr = word.begin();
	while (itr != word.end()) {
		if (*itr == str) {
			throw string("You already insert SAME word!");
		}
		itr++;
	}
	return;
}

void WordList::CheckConfirm(string str)
{
	if (!word.empty()) {
		string lastword = *(--(word.end()));
		if (lastword.back() != str.front()) {
			throw string("Not Same last char!");
		}
	}
}

void WordList::add(string str)
{
	word.push_back(str);
}

void WordList::startGame()
{	
	string input;
	cout << "**** GAME STARTW ****" << endl;
	cout << "#### IF YOU QUIT, PRESS CTRL+C ####" << endl;
	while (1) {
		cout << "Input Word : " << endl;
		cin >> input;

		try {
			Checkprint(input);
			CheckDictionary(input);
			CheckConfirm(input);
			CheckDuplication(input);

		}
		catch (string s) {
			cout << s;
			cout << "Try Again! " << endl;
			continue;
		}

		add(input);
	}
	
}
