// Visual Studio 2019
// Maraiah Matson
// Due: 09/26/2020 11:59 PM
// develop a program to read Baseball Player objects from an input file
#include "Player.h"
#include "PlayerList.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void reportLineFormat(ostream& out, Player player) {
	string name = player.get_name();
	double batting_average = player.batting_average();
	double ops = player.OPS();
	out << setw(19) << right << name << " :\t";
	out << fixed << setprecision(3) << batting_average << "\t\t" << ops << endl;
}

int main() {
	//io filestream variables
	ifstream inFile;
	ofstream outFile;

	//io filename variables
	string input_file;
	string output_file;

	//creates instance of player and playerlist objects
	Player player;
	PlayerList playerlist;

	//displays purpose of program to the terminal
	cout << "Welcome to the player statistics calculator test program. I am going to " << endl;
	cout << "read players from an input data file.You will tell me the names of " << endl;
	cout << "your input and output files. I will store all of the players, in a list, " << endl;
	cout << "computer each player's stats and then write the resulting report to " << endl;
	cout << "your output file. " << endl << endl;
	
	//prompt the user for the input and output file names.
	cout << "Enter the name of your input file: ";
	cin >> input_file;
	cout << "Enter the name of your output file: ";
	cin >> output_file;
	cout << endl << endl;

	/*input_file = "playerdata.txt";
	output_file = "outputdata.txt";*/

	//open input file
	inFile.open(input_file);
	
	//read each player and add them to playerlist
	cout << "Reading Players from: " << input_file << endl;
	while (!inFile.eof()) {
		player.input_player_data(inFile);
		playerlist.add(player);
	}

	//open the output file
	outFile.open(output_file);

	//write a report summary line to the output file and
	//write each item from the list into the output file
	//report summary
	outFile << "BASEBALL TEAM REPORT --- ";
	outFile << playerlist.getSize() << " PLAYERS FOUND IN FILE" << endl;
	outFile << "OVERALL BATTING AVERAGE IS " << fixed << setprecision(3) 
		<< playerlist.getBatAvg() << endl << endl;
	outFile << "    PLAYER NAME     :   AVERAGE     OPS\n";
	outFile << "----------------------------------------------\n";

	//outputs stats for each player to output file
	playerlist.printReport(outFile, reportLineFormat);

	cout << "The sorted list has been written to your output file: " << output_file << endl << endl;

	// print everything backwards to the console to test recursive backwards print function
	cout << endl;
	playerlist.printBackwards();
	cout << endl;

	cout << "\nTesting Complete. The new version of your list has been added to " << endl;
	cout << "the report file. " << endl << endl;
	
	cout << "End of Program 4";
}