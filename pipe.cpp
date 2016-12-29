#include <string>
#include <iostream>
int main(){
	std::string name;
	while(!std::getline(std::cin, name, '|').eof())
	{
  		std::string jersey_number;
  		std::string best_time;
  		std::string sport;
  		std::string high_school;
  		std::getline(std::cin, jersey_number, '|'); //#read thru pipe
 		std::getline(std::cin, best_time,'|');          //#read thru newline
  		std::getline(std::cin, sport, '|');         //#read thru pipe
  		std::getline(std::cin, high_school,'|');        //#read thru newlin
	

		std::cout <<"j no:"<< jersey_number << std::endl;

		std::cout <<" bestnime: "<< best_time << std::endl;
		std::cout <<"sport : " << sport <<std::endl;
		std::cout << "high school: "<< high_school << std::endl; 
	}

}

