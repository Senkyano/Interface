#include "ADrone.hpp"

ADrone::ADrone(std::string id, std::string name) : id_(id), name_(name) {}

ADrone::~ADrone() {}

std::string		ADrone::getId() const {
	return (this->id_);
}

std::string		ADrone::getName() const {
	return (this->name_);
}

Health			ADrone::getHealth() const {
	return (this->materialHealth_);
}

float			ADrone::getBattery() const {
	return (this->battery);
}