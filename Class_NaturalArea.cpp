#include<iostream>
#include<string>

Class NaturalArea{
	protected:
		int id;
		std::string name;
		
	public:
		//Constructor 
		NaturalArea(int input_id, std::strig input_name): id(input_id), name(input_name) {} 
		//Destructor
		virtual ~NaturalArea = default;
		//Methods 
		virtual void showInfo() const=0;
		virtual double conservationLevel() const=0;
		//Overloading operatos >
		bool operator>(const NaturalArea& other) const{
		return this->conservationLevel() > other.conservationLevel();
		}		
};
