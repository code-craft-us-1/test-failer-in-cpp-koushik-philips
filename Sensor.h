#pragma once
#include <string>
#include <iostream>
#include "ISensor.h"

/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development

namespace WeatherSpace {
    class SensorStub : public IWeatherSensor {
        int Humidity() const override {
            return m_humidity;
        }

        int Precipitation() const override {
            return m_precipitation;
        }

        double TemperatureInC() const override {
            return m_temperature;
        }

        int WindSpeedKMPH() const override {
            return m_windspeed;
        }

    public:
        int m_humidity;
        int m_precipitation;
        double m_temperature;
        int m_windspeed;
        SensorStub(int humidity = 72, int precipitation = 70,
            double temperature = 26, int windspeed = 52) :
            m_humidity(humidity), m_precipitation(precipitation),
            m_temperature(temperature), m_windspeed(windspeed) {}
    };
}