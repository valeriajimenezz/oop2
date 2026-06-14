//CameraScanner
#ifndef CAMERASCANNER_H
#define CAMERASCANNER_H
#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>
#include "FieldZone.h"

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
    std::ostringstream oss;
    oss << "[SCAN] Zone " << zone.getId() 
        << " | Moisture: " << zone.getmoistureLevel()
        << " | Nutrients: " << zone.getnutrientLevel();
    return oss.str();
}
};
#endif 
