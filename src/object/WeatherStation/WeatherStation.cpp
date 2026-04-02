#include "WeatherStation.hpp"

WeatherStation::WeatherStation(QString id, QString name)
	: id_(id), name_(name), temperature_(20.0f) {
		humidity_ = 0;
		pressure_ = 0;
		materialHealth_ = Health::DISCONNECTED;

		// Test affichage changement avec event
		QTimer	*timer = new QTimer(this);

		connect(timer, &QTimer::timeout, this, &WeatherStation::updateTemperature);
		timer->start(2000);
	}

WeatherStation::~WeatherStation() {}

QString	WeatherStation::getId() const {
	return (id_);
}

QString WeatherStation::getName() const {
	return (name_);
}

Threshold WeatherStation::getStatus() const {
	return (status_);
}

std::map<std::string, MetricValue>	WeatherStation::getMetrics() const {
	return {
		{"Health", materialHealth_},
		{"Temperature", temperature_},
		{"Humidity", humidity_},
		{"Pressure", pressure_}
	};
}

void	WeatherStation::updateTemperature() {
	this->temperature_++;

	emit dataUpdated();
}

void	WeatherStation::updateData(float temp, float humidity, float pressure) {
	this->temperature_ = temp;
	this->humidity_ = humidity;
	this->pressure_ = pressure;
	
	emit	dataUpdated();
}

Health	WeatherStation::getHealth() const {
	return (this->materialHealth_);
}

float	WeatherStation::getTemperature() const {
	return (temperature_);
}