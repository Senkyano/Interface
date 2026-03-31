#pragma once
#include <string>
#include <map>
#include <variant>

using MetricValue = std::variant<int, float, bool, std::string>;

enum	class Health {RUNNING, DOWN, MAINTENANCE, DESTROY};

class IMonitoredEntity {
	public:
		virtual ~IMonitoredEntity() = default;

		virtual std::string getId() const = 0;
		virtual std::string getName() const = 0;
		virtual std::string getStatus() const = 0;
		virtual Health getHealth() const = 0;

		virtual std::map<std::string, MetricValue> getMetrics() const = 0;

		virtual void renderWidget() const = 0;
};