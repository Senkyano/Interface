#pragma once
#include "IMonitoredEntity.hpp"

class WeatherStation : public IMonitoredEntity {
	public:
		WeatherStation(std::string id, std::string name);
		~WeatherStation();
		std::string		getId() const override;
		std::string		getName() const override;
		std::string 	getStatus() const override;
		Health			getHealth() const override;

		std::map<std::string, MetricValue>	getMetrics() const override;

		void	updateData(float temp, float humidity, float pressure);

	private:
		std::string	id_, name_;
		float 	temperature_, humidity_, pressure_;
		Health	materialHealth_;
};