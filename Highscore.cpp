#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Highscore.h"


/**********************************************************************
*Default Constructor
**********************************************************************/
Highscore::Highscore(){
	score = 0;
	//initials = "";
	rank = 0;
}

/**********************************************************************
*Constructor takes in a score
**********************************************************************/
Highscore::Highscore(int score){  //,std::string initials){
	this->score = score;
	//this->initials = initials;
	this->rank = findRank(score);
}
/**********************************************************************
*returns the rank
**********************************************************************/
int Highscore::getRank(){
	return rank;
}

/**********************************************************************
*Calculates the rank of a number compared to the list in Highscores.txt
**********************************************************************/
int Highscore::findRank(int score){

	//open "Highscores.txt"
	std::string line;
	std::ifstream file ("Highscores.txt");
	int count = 0;

	//The file is available
	if (file.is_open()){

		//there are more lines	
		while (getline(file,line)){
			int oldScore = 0;
			count++;			

			//compare score to the current line's value
			std::istringstream (line) >> oldScore;
			std::cout << oldScore << std::endl;
			if(score > oldScore){
				return count;
			}

		}
			
		//end of file reached: last place
		count++;

	}else{
		std::cout << "FILE ERROR" << std::endl;
	}
	
	return count;
}

/**********************************************************************
*Test for findRank, example: "./a.out 3200"
*Outputs the scores it compares to, then prints the rank.
**********************************************************************/
int main(int argc, char** argv){
	int score;
	std::istringstream (argv[1]) >> score;
	Highscore h(score);
	std::cout << h.getRank() << std::endl;
}	
