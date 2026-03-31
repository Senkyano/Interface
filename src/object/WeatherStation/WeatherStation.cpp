#include "WeatherStation.hpp"

WeatherStation::WeatherStation(std::string id, std::string name)
	: id_(id), name_(name) {

}

WeatherStation::~WeatherStation() {}

std::string	WeatherStation::getId() const {
	return (id_);
}

std::string WeatherStation::getName() const {
	return (name_);
}

std::string WeatherStation::getStatus() const {
	// return (status_);
}

std::map<std::string, MetricValue>	WeatherStation::getMetrics() const {
	return {
		{"Temperature", temperature_},
		{"Humidity", humidity_},
		{"Pressure", pressure_}
	};
}

void	WeatherStation::updateData(float temp, float humidity, float pressure) {
	this->temperature_ = temp;
	this->humidity_ = humidity;
	this->pressure_ = pressure;
}

Health	WeatherStation::getHealth() const {
	return (this->materialHealth_);
}