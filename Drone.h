//Drone 
#ifndef DRONE_H
#define DRONE_H
#include<iostream>
#include<string>
#include<vector>
#include "CameraScanner.h"
#include "FieldZone.h"

class Drone{
	private:
		std::string id;
		CameraScanner camera;
		std::vector<std::string> scanLog;
	public:
	//Constructor 
		Drone(std::string id, std::string resolution) : id(id), camera(resolution){ }
		
	//Getter 
	std::string getId() const { return id; }
	//Methods	
	void scanZone(const FieldZone& zone){
	    std::string result = camera.scan(zone);
    	scanLog.push_back(result);
    	std::cout << result << "\n";
	}
	void displayLog() const {
    for(const std::string& entry : scanLog)
        std::cout << entry << "\n";
	}
}; 
#endif 
	
