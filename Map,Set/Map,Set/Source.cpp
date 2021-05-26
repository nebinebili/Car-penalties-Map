#include<iostream>
#include<map>
#include<list>
#include<set>
#include<iomanip>
using namespace std;

class Penalty {
	string text;
	string day;
	string place;
public:
	Penalty() :text(), day(), place() {};
	Penalty(const string&text,const string&day,const string&place)
	{
		this->text = text;
		this->place = place;
		this->day = day;
	}
	void ShowPenalty() {
		cout << " |" << "Cerime->" << text << setw(9)
			 << "Gun->" << day <<setw(10)
			 << "Mekan->" << place << endl;
		      cout<< setw(9)<<"";
	}
};

class Car {
	list<Penalty> penalties;
public:
	void addCarPenalty(Penalty penalty) {
		penalties.push_back(penalty);
	}
	auto& GetPenalties()const {
		return penalties;
	}
};

class YPX {
	map < string, list<Penalty>> ypx;
public:
	void AddYpxDatabase(const string& carnumber,list<Penalty> penalties) {
		ypx.insert({ carnumber,penalties });
	}
	void ShowPenalties() {
		for (auto& i : ypx)
		{
			
			cout << i.first;
			for (auto& penalty : i.second)
			{
				penalty.ShowPenalty();
			}
			
		}
	}
};

int main() {

	Penalty p1("Qosha xett 60 Azn", "11/09/21", "Sulh Kucesi");
	Penalty p2("Dayanma Durma 40 Azn", "10/01/21", "Zeynalov Kucesi");

	Car car1;
	car1.addCarPenalty(p1);
	car1.addCarPenalty(p2);
	
	YPX ypx;
	ypx.AddYpxDatabase("99-EE-611", car1.GetPenalties());
	ypx.ShowPenalties();
	
	
	return EXIT_SUCCESS;
}

