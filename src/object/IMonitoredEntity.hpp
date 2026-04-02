#pragma once
#include <string>
#include <map>
#include <variant>
#include <QObject>
#include <QString>
#include <QTimer>

enum class	Threshold {DANGER, WARNING, SAFE};
enum class	Direction {NORTH, SOUTH, EAST, OUEST};
enum class	Health {CONNECTED, DISCONNECTED, MAINTENANCE, DESTROY};

using MetricValue = std::variant<int, float, bool, std::string, QString, 
	Threshold, Direction, Health>;

class IMonitoredEntity : public QObject {
	public:
		virtual ~IMonitoredEntity() = default;

		virtual QString getId() const = 0;
		virtual QString getName() const = 0;
		virtual Health getHealth() const = 0;

		virtual std::map<std::string, MetricValue> getMetrics() const = 0;

		// virtual void renderWidget() const = 0;
};