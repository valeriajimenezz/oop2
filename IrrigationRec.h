//IrrigationRec 
#include<iostream>
#include<string>
#include "Recommendation.hpp"

class IrrigationRec : public Recommendation{
	private:
		double waterAmount;
	public:
	//Constructor
	IrrigationRec(std::string zoneId, int priority, double waterAmount) 
	: Recommendation(zoneId, priority), waterAmount(waterAmount) {
		if(waterAmount <= 0)
		throw std::invalid_argument("Water amount needs to be higher than 0");
	}
	
	//Getter 
	double getwaterAmount() const { return waterAmount; }
	
	//Methods 
	void apply() const override {
    std::cout << "Irrigating zone " << zoneId << "...\n";
	}

	std::string getType() const override {
    return "Irrigation";
	}
	void display() const {
    Recommendation::display(); 
    std::cout << "Water Amount: " << waterAmount << " liters\n";
	}
    
};
