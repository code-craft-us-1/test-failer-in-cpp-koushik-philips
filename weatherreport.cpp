#include <assert.h>
#include <string>
#include <iostream>
#include "Sensor.h"
#include "weatherreport.h"
#include "weatherTests.h"

using namespace WeatherSpace;

using std::cout;
using std::endl;
using std::string;

int main() {
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitationAndLowWindspeed();
    cout << "All is well (maybe)\n";
    return 0;
}
