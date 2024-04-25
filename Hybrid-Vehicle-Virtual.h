#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
	protected:
		double weight;
		string name;

	public:
		Vehicle() { cout << "Constructor: Vehicle" << endl; }
		Vehicle(string name) { cout << "Constructor(string name): Vehicle" << endl; }
		~Vehicle() {cout << "destructor: Vehicle" << endl;}

		virtual void Start();
		virtual void Stop();
		virtual double calcFuelEfficiency();
};

class Gasoline : public virtual Vehicle {
	public:
		Gasoline(string name) : Vehicle(name) {cout << "Constructor: Gasoline" << endl;}
		~Gasoline() {cout << "destructor: Gasoline" << endl;}

		virtual double calcFuelEfficiency(double mpg);
        virtual void Start() override;
        virtual void Stop() override;
};

class Electric : public virtual Vehicle {
	public:
		Electric(string name) : Vehicle(name) {cout << "Constructor: Electric" << endl;}
		~Electric() {cout << "destructor: Electric" << endl;}

		virtual double calcFuelEfficiency(double mpge);
        virtual void Start() override;
        virtual void Stop() override;
};

class Hybrid : public Electric, public Gasoline {
	private:
		double _percentGas;
		double mpge;
		double mpg;

	public:
		Hybrid(string name) : Electric(name), Gasoline(name) {cout << "Constructor: Hybrid" << endl;}
		~Hybrid() {cout << "destructor: Hybrid" << endl;}
        double PercentGas() {return _percentGas;}
		void PercentGas(double pg) {_percentGas = pg;}
		void setMPGE(double new_mpge) {mpge = new_mpge;}
		void setMPG(double new_mpg) {mpg = new_mpg;};
		double getMPGE() {return mpge;}
		double getMPG() {return mpg;};

		double calcFuelEfficiency() override;
		void Start() override;
		void Stop() override;
};