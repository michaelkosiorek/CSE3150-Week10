#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Hybrid-Vehicle-Virtual.h"

TEST_CASE("Virtual inheritance exp.") {

    SUBCASE("simple hybrid test") {
        string whichVehicle = "Super vehicle";
	    Hybrid hybrid(whichVehicle);

        hybrid.setMPGE(100);
        hybrid.setMPG(30);
        hybrid.PercentGas(100);

	    hybrid.Start();


	    cout << hybrid.calcFuelEfficiency() << endl;
    };

};   