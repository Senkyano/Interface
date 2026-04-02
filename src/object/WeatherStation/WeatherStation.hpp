#pragma once
#include "IMonitoredEntity.hpp"

class WeatherStation : public IMonitoredEntity {
	Q_OBJECT

	Q_PROPERTY(float temperature READ getTemperature NOTIFY dataUpdated)

	public:
		WeatherStation(QString id, QString name);
		~WeatherStation();
		QString			getId() const override;
		QString			getName() const override;
		Health			getHealth() const override;
		Threshold		getStatus() const;
		float			getTemperature() const;

		std::map<std::string, MetricValue>	getMetrics() const override;

		void	updateData(float temp, float humidity, float pressure);

		void	updateTemperature();

	private:
		QString	id_, name_;
		Threshold	status_;
		float 		temperature_, humidity_, pressure_;
		Health		materialHealth_;

	signals:
		void	dataUpdated();
};
