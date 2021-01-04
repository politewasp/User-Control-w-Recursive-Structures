#pragma once
//File: Player.h
// Initializes a Player object
//-------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Player {
	//initialize private attributes
	string firstname;
	string lastname;
	int stats[8];

public:
	//default constructor
	Player();

	//methods

	//allows the user to input the data in one line
	void input_player_data(ifstream& cin);

	/*Get methods for any data the test driver program might need to display
	on the screen later (at a minimum gets to retrieve each name and the values
	needed for this program’s output)*/

	//displays first name or last name to the screen
	string get_firstname();
	string get_lastname();
	string get_name();

	//displays stats from stats[] array
	int get_plateapps();
	int get_atbats();
	int get_singles();
	int get_doubles();
	int get_triples();
	int get_homeruns();
	int get_walks();
	int get_hbp();

	/*computes player's batting average. The batting average is the sum of
	the hits (singles, doubles, triples, home runs) divided by the number of
	at-bats. */
	double batting_average();
	double OPS();

	//computes player's On Base Percentage. OBP is the sum of all hits, walks 
	//and hit by pitch divided by the number of plate appearances. 
	double OBP();



};