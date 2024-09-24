#pragma once
#include <string>
#include "ISensor.h"
using std::string;

// This is a function to predict the weather, based on readings
// from a sensor
namespace WeatherSpace {
    string Report(const IWeatherSensor& sensor) {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny day";

        if (sensor.TemperatureInC() > 25) {
            if (precipitation >= 20 && precipitation < 60) {
                report = "Partly cloudy";
            } else if (precipitation >= 60) {
                if (sensor.WindSpeedKMPH() > 50)
                    report = "Alert, Stormy with heavy rain";
                else
                    report = "Heavy rain with low wind speed";
            }
        }
        return report;
    }
}