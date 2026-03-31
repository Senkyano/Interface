#pragma onece

#include <vector>
#include <memory>
#include "IMonitoredEntity.hpp"

class EntityManager {
	public:
		void	add(std::unique_ptr<IMonitoredEntity> new_entity);
		std::vector<IMonitoredEntity*> getAll() const;

	private:
		std::vector<std::unique_ptr<IMonitoredEntity>> entities_;
};