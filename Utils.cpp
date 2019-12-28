#include "Utils.h"
#include "Jogadores.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> nameSplitter(string& str)
{
	vector<string> vnomes;
	string word = "";
	for (auto x : str)
	{
		if (x == ' ')
		{
			vnomes.push_back(word);
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	vnomes.push_back(word);
	return vnomes;
}

vector<string> divideStrings(string &s) {
	vector<string> info;
	string v;
	while (s != "") {
		if (s.find("|") == string::npos) {
			info.push_back(s);
			s.clear();
		}
		else {
			v = s.substr(0, s.find("|") - 1);
			s = s.substr(s.find("|") + 2, string::npos);
			info.push_back(v);
			v.clear();
		}
	}
	return info;
}

void logo() {
	cout << endl << "--------------------------------------------- " << endl;
	cout << " BEM VINDO A FEDERACAO PORTUGUESA DE FUTEBOL " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl;
}