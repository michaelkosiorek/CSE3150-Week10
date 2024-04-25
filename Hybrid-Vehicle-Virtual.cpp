#include <iostream>
#include <vector>
#include <string>

#include "Hybrid-Vehicle-Virtual.h"

using namespace std;


void Vehicle::Start() { cout << "Vehicle START"  << endl; }
void Vehicle::Stop() { cout << "Vehicle STOP"  << endl; }
double Vehicle::calcFuelEfficiency() {
	cout << "Vehicle type unknown so fuel efficiency unknown" << endl;
	return -1;
}


double Gasoline::calcFuelEfficiency(double mpg) {
	double average_cost_per_gallon = 3.72;
	cout << "Gas miles per dollar:" << mpg / average_cost_per_gallon << endl;
	return mpg / average_cost_per_gallon;
}

void Gasoline::Start() {cout << "Gasoline vehicle START" << endl;}
void Gasoline::Stop() {cout << "Gasoline vehicle STOP";}


double Electric::calcFuelEfficiency(double mpge) {
	double average_cost_per_kWh = .24;
	double kWh_per_gallon = 33.7;
	return average_cost_per_kWh * kWh_per_gallon;

	cout << "Elec miles per dollar:" << ((kWh_per_mile * average_cost_per_kWh) / mpge) << endl;
	return ((kWh_per_mile * average_cost_per_kWh) / mpge);
}

void Electric::Start() {
	cout << "Electric vehicle START" << endl;
}
void Electric::Stop() {
	cout << "Electric vehicle STOP";
}


double Hybrid::calcFuelEfficiency() {
	double percentGas = PercentGas();
	return ((Electric::calcFuelEfficiency(getMPGE()) * (100-percentGas) + percentGas*Gasoline::calcFuelEfficiency(getMPG()))/100);
}

void Hybrid::Start() { cout << "Hybrid v START"  << endl;}
void Hybrid::Stop() { cout << "Hybrid v STOP"  << endl;}
