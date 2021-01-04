//Player class definition
#include "Player.h"

//default constructor
Player::Player() {
	firstname = "unknown";
	lastname = "unknown";
	for (int i = 0; i < 8; i++) {
		stats[i] = 0;
	}
}

//methods

//allows the user to input the data in one line
void Player::input_player_data(ifstream& cin) {
	//reads in first name and last name from the input stream
	cin >> firstname >> lastname;

	//reads in all 8 statistics from the line into an integer array
	for (int i = 0; i < 8; i++) {
		string stat;
		cin >> stat;

		//reads statistic into stats[i] as integer
		stats[i] = stoi(stat);
	}

}

/*Get methods for any data the test driver program might need to display
on the screen later (at a minimum gets to retrieve each name and the values
needed for this program’s output)*/

//displays first name or last name to the screen
string Player::get_firstname() { return firstname; }
string Player::get_lastname() { return lastname; }
string Player::get_name() { return firstname + " " + lastname; }

//displays stats from stats[] array
int Player::get_plateapps() { return stats[0]; }
int Player::get_atbats() { return stats[1]; }
int Player::get_singles() { return stats[2]; }
int Player::get_doubles() { return stats[3]; }
int Player::get_triples() { return stats[4]; }
int Player::get_homeruns() { return stats[5]; }
int Player::get_walks() { return stats[6]; }
int Player::get_hbp() { return stats[7]; }

/*computes player's batting average. The batting average is the sum of
the hits (singles, doubles, triples, home runs) divided by the number of
at-bats. */
double Player::batting_average() {
	int singles = get_singles();
	int doubles = get_doubles();
	int triples = get_triples();
	int homeruns = get_homeruns();
	int atbats = get_atbats();

	double sum = double(singles + doubles + triples + homeruns);
	double batting_average = sum / atbats;
	return batting_average;
}

/*On-base plus slugging (OPS) is a baseball statistic composed of the sum of a 
player's on-base percentage and slugging percentage. This is a measure of two 
very important offensive skills: the ability to get on base and to hit for power.*/
double Player::OPS() {
	int singles = get_singles();
	int doubles = get_doubles();
	int triples = get_triples();
	int homeruns = get_homeruns();
	int atbats = get_atbats();

	double slugging = double(singles + (2 * doubles) + (3 * triples) + (4 * homeruns)) / atbats;
	double OPS = OBP() + slugging;
	return OPS;
}

//computes player's On Base Percentage. OBP is the sum of all hits, walks 
//and hit by pitch divided by the number of plate appearances. 
double Player::OBP() {
	int singles = get_singles();
	int doubles = get_doubles();
	int triples = get_triples();
	int homeruns = get_homeruns();
	int walks = get_walks();
	int hbp = get_hbp();
	int plateapps = get_plateapps();

	double sum = double(singles + doubles + triples + homeruns + walks + hbp);
	double OBP = sum / plateapps;
	return OBP;
}
