//FertilizerRec

#include<iostream>
#include<string>
#include "Recommendation.hpp"

class FertilizerRec : public Recommendation{
	private:
		double fertilizerAmount;
	public:
	//Constructor
	FertilizerRec(std::string zoneId, int priority, double fertilizerAmount):
		Recommendation(zoneId, priority), fertilizerAmount(fertilizerAmount) {
			if(fertilizerAmount <= 0)
			throw std::invalid_argument("Fertilizer amount needs to be higher than 0");
		}
	//Getter 
	double getfertilizerAmount() const {return fertilizerAmount;}
	//Methods 
	void apply() const override {
    std::cout << "Applying " << fertilizerAmount << " kg of fertilizer to zone " << zoneId << "\n";
	}

	std::string getType() const override {
    return "Fertilization";
	}
	void display() const {
    Recommendation::display(); 
    std::cout << "Fertilizer Amount: " << fertilizerAmount << " kg\n";
	}
    
};

