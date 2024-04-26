#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Hybrid-Vehicle-Virtual.h"

TEST_CASE("Virtual inheritance exp.") {

    SUBCASE("all EV hybrid test") {
        string hybrid_name = "Super vehicle";
	    Hybrid hybrid(hybrid_name);

        string ev_name = "I am EV";
	    Electric electric(ev_name);

        double full_ev_miles_per_dollar = electric.calcFuelEfficiency(100);

        hybrid.setMPGE(100);
        hybrid.setMPG(30);
        hybrid.PercentGas(0);

	    hybrid.Start();

        // a full EV should be the same as a 0% gas hybrid
	    CHECK_EQ(hybrid.calcFuelEfficiency(), full_ev_miles_per_dollar);
    };

    SUBCASE("all gas hybrid test") {
        string hybrid_name = "Super vehicle";
	    Hybrid hybrid(hybrid_name);

        string gas_name = "I am gas";
	    Gasoline gasoline(gas_name);

        double full_gas_miles_per_dollar = gasoline.calcFuelEfficiency(30);

        hybrid.setMPGE(100);
        hybrid.setMPG(30);
        hybrid.PercentGas(100);

	    hybrid.Start();

        // a full gasoline car should be the same as a 100% gasoline EV
	    CHECK_EQ(hybrid.calcFuelEfficiency(), full_gas_miles_per_dollar);
    };

    SUBCASE("all gas hybrid test") {
        string hybrid_name = "Super vehicle";
	    Hybrid hybrid(hybrid_name);

        string gas_name = "I am gas";
	    Gasoline gasoline(gas_name);

        double full_gas_miles_per_dollar = gasoline.calcFuelEfficiency(30);

        string ev_name = "I am EV";
	    Electric electric(ev_name);

        double full_ev_miles_per_dollar = electric.calcFuelEfficiency(100);

        double half_ev_half_gas = (full_ev_miles_per_dollar + full_gas_miles_per_dollar) / 2;

        hybrid.setMPGE(100);
        hybrid.setMPG(30);
        hybrid.PercentGas(50);

	    hybrid.Start();

	    CHECK_EQ(hybrid.calcFuelEfficiency(), half_ev_half_gas);
    };

    SUBCASE("very high mpg") {
        string gas_name = "I am gasoline";
	    Gasoline gasoline(gas_name);

        double mpg = 1000000;
        double full_gas_miles_per_dollar = gasoline.calcFuelEfficiency(mpg);

	    CHECK(full_gas_miles_per_dollar > 100000);

        string ev_name = "I am ev";
	    Electric electric(ev_name);

        double mpge = 1000000;
        double full_ev_miles_per_dollar = gasoline.calcFuelEfficiency(mpge);

	    CHECK(full_ev_miles_per_dollar > 100000);
    };

    SUBCASE("invalid efficiency") {
        string ev_name = "I am EV";
	    Electric electric(ev_name);

        CHECK_THROWS_AS(electric.calcFuelEfficiency(0), Efficiency_Exception);

        string gas_name = "I am gas";
	    Gasoline gasoline(gas_name);

        CHECK_THROWS_AS(gasoline.calcFuelEfficiency(0), Efficiency_Exception);
    }
};   