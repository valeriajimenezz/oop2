//FieldZone 
#ifndef FIELDZONE_H
#define FIELDZONE_H
#include<iostream>
#include<string>
#include<stdexcept>

class FieldZone{
	private:
		std::string id;
		double moistureLevel;
		double nutrientLevel;
	public:
		//Constructor
	FieldZone(std::string id, double moistureLevel, double nutrientLevel): id(id), moistureLevel(moistureLevel), nutrientLevel(nutrientLevel){
		if (moistureLevel < 0 || moistureLevel > 100)
    	throw std::invalid_argument("moistureLevel must be between 0 and 100");		
	}
	//Getters 
	double getmoistureLevel() const {return moistureLevel;}
	double getnutrientLevel() const {return nutrientLevel;}
	std::string getId() const {return id;}
	
	// Methods 
	
	void display() const {
		std::cout<<"Zone: "<<id << "\n";
		std::cout<<"Moisture Level: " <<moistureLevel<< "/100 \n";
		std::cout<<"Nutrient Level: " <<nutrientLevel<< "/100 \n";
	
	}
};
#endif
