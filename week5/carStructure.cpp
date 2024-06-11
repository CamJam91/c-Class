#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

struct motorcycle{
        string name;
        string engine;
        string type;
};

	
struct vehicle{
	vector<int> year;
	double weight;
	string type;
	string maker;
	motorcycle bike;
};


int main(){
	vehicle shadow;

		//primitives
	shadow.year.resize(3);
	int years = 2008;
	for (int count = 0; count < shadow.year.size(); count++){
		shadow.year[count] = years;
		years +=2;
	}

	shadow.weight = 438;
	shadow.type = "Motorcycle";
	shadow.maker = "Honda";
		//bike structure
	shadow.bike.name = "Phantom";
	shadow.bike.engine = "V-twin";
	shadow.bike.type = "Cruiser";
	


	cout << setw(20) <<  "Vehicle" << setw(20)  << "Year" << setw(20) << "Weight" << setw(20) << "Type" << setw(20) << "Maker" << endl;
	cout << setw(20) <<  shadow.bike.name << setw(20)  << shadow.year[2] << setw(20) << shadow.weight << setw(20) << shadow.type << setw(20) << shadow.maker << endl;
	cout << setw(20) << "Engine: " << shadow.bike.engine << setw(20) << "Style" << shadow.bike.type << endl;
	return 0;
}

