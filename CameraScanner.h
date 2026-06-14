//CameraScanner
#include<iostream>
#include<string>
#include<stdexcept>
#include "FieldZone.hpp"

class CameraScanner{
	private:
		std::string resolution;
	public:
	//Constructor 
	CameraScanner(std::string resolution): resolution(resolution){
		if(resolution.empty())
		throw std::invalid_argument("Resolution cannot be empty"); 
	}
	//Getter 
	std::string getresolution() const {return resolution;}
	
	//Methods 
	std::string scan(const FieldZone& zone) const {
    return "[SCAN] Zone " + zone.getId() 
        + " | Moisture: " + std::to_string(zone.getmoistureLevel())
        + " | Nutrients: " + std::to_string(zone.getnutrientLevel());
}
};
