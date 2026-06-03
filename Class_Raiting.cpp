#include<iostream>
#include<string>


Class Raiting{
	private:
		double value;
	public:
		Raiting(double int_value) {
			value = std::min(std::max(input_value, 1.0), 5.0); //Define that the value should be min 1.0 and max 5.0 
		}
		double getValue() const{ //Get because its private 
			return value;
		}
		//Operator 
		bool operator==(const Raiting& other) const{
			return value == other.value;
		}
		std::string toString() const{
			return std::to_string(value); //Convert double to string 
		}

};
