#pragma once
#include <assert.h>
#include <iostream>
#include "Sensor.h"
#include "weatherreport.h"

namespace WeatherSpace {
    // Test a rainy day
    void TestRainy() {
        SensorStub sensor;
        string report = Report(sensor);
        std::cout << report << std::endl;
        assert(report.find("rain") != string::npos);
    }

    // Test another rainy day
    void TestHighPrecipitationAndLowWindspeed() {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        SensorStub sensor = { 72 , 70 , 26 , 32 };

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        string report = Report(sensor);
        std::cout << report << std::endl;
        assert(report.find("rain") != string::npos);
    }
} // namespace WeatherSpace
