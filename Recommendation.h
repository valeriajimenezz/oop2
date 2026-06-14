//Recommendation 

#include<iostream>
#include<string>
#include<stdexcept>

class Recommendation {
	protected:
		std::string zoneId;
		int priority;
	public:
	//Constructor and exception 
		Recommendation(std::string zoneId, int priority): zoneId(zoneId), priority(priority){
			if(priority < 1 || priority > 5)
			throw std::invalid_argument("priority needs to be between 1 - 5 :)");
		}
	//Getters
	std::string getzoneId() const {return zoneId;}
	int getpriority() const {return priority; }
	
	//Method 
	virtual void apply() const = 0;
	virtual std::string getType() const = 0;
	
		void display() const {
		std::cout<<"Zone: "<<zoneId << "\n";
		std::cout<<"Priority: " <<priority<< "/5\n";
	}
	virtual ~Recommendation() = default; 
};
