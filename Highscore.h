#include <string>

class Highscore {

	public:
		
		Highscore();

		Highscore(int score);//, std::string initials);

		int getScore();
		std::string getInitials();
		int getRank();
		

	
	private:

		int score;
		//std::string initials;
		int rank;
		int findRank(int score);

};
