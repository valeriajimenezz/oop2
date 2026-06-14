//FieldManager
#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H
#include <memory>
#include "Recommendation.h"
#include "FieldZone.h"

class FieldManager{
	private:
		std::vector<std::unique_ptr<Recommendation>> recommendations;
		std::vector<FieldZone> zones;
	
	public:
	//Constructor
		FieldManager() = default;
	//Methods 
	void addZone(const FieldZone& zone) {
		zones.push_back(zone);
	}
	void addRecommendation(std::unique_ptr<Recommendation> rec) {
    recommendations.push_back(std::move(rec));
	}
	void runAll() const {
    for(const auto& rec : recommendations)
        rec->apply();
	}
	void displayAll() const {
    for(const auto& rec : recommendations)
        rec->display();
	}
};
#endif
