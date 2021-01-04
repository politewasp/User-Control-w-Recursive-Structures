#pragma once
#include <iostream>
#include "Player.h"
using namespace std;

//File: PlayerList.h
// This is a linked list of Player objects
//------------------------------------------------------------------------
// The interface includes:
//    add, remove
//	  hasNext, hasPrev
//    getNext, getPrev
//    isEmpty, isFull
//    clear, reset, set_to_end
//	  getSize, bat_avg, print
//-------------------------------------------------------------------------
class PlayerList; // forward declaration so name is visible to class TreeNode

class TreeNode {  // a node in our binary tree
	Player item;      // data item in the node
	TreeNode* left;   // left child node
	TreeNode* right;  // right child node
	TreeNode(Player); // constructor for new nodes
	friend PlayerList;  // this makes private attributes visible to the friend
};

class PlayerList {
	TreeNode* root;		// root node of the binary tree
	int  m_length;    // current size of the list contents
	
	// Recursive Methods
	bool insert(TreeNode*&, Player&); // used in add()
	void free(TreeNode*); // used in destructor
	int count(TreeNode*); // used in getSize()
	double battingTotal(TreeNode*); // used in getBatAvg()
	void display(ostream&, TreeNode*); // used in print()
	void displayBackwards(ostream&, TreeNode*); // used in printBackwards()
	void constructReport(ostream&, TreeNode*, void (*f)(ostream&, Player)); // used in printReport()
public:
	// Operations for Playerlist: 
	// add(), hasNext(), getNext(), getPrev(), clear(), reset() 
	// isEmpty(), getSize(), bat_avg()

	// default constructor and destructor
	PlayerList();
	~PlayerList();

	// add capability
	void add(Player &player);

	// checks if list is empty or full
	bool isEmpty();
	bool isFull();

	// used in destructor
	void clear();

	// returns length of list or batting average of all players
	int getSize();
	double getBatAvg();

	//prints every player in list
	void print();
	void printBackwards();
	void printReport(ostream&, void (*f)(ostream&, Player));
};