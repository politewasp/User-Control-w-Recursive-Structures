//PlayerList Linked List Class
#include "PlayerList.h"
//------------------------------------------------------------------------
// TreeNode constructor
//------------------------------------------------------------------------
TreeNode::TreeNode(Player player) { // node constructor
	item = player;
	left = NULL;
	right = NULL;
}
//------------------------------------------------------------------------
// PlayerList(): PlayerList constructor
//------------------------------------------------------------------------
PlayerList::PlayerList() {
	root = NULL;
	m_length = 0;
}
//------------------------------------------------------------------------
// ~PlayerList(): PlayerList destructor
//------------------------------------------------------------------------
PlayerList::~PlayerList() {
	clear(); // call destructor automatically when object is destroyed
}

//************************************************************************
// PRIVATE METHODS
//************************************************************************

//------------------------------------------------------------------------
// private method - internal utility
// insertNode: recursive method to insert a node into the ordered 
// tree starting at the Referenced root node R.  
//------------------------------------------------------------------------
bool PlayerList::insert(TreeNode*& R, Player& player) {
	if (R == NULL) {
		R = new TreeNode(player);
		return true;
	}
	else {
		string oldName = R->item.get_lastname() + R->item.get_firstname();
		string newName = player.get_lastname() + player.get_firstname();

		if (newName.compare(oldName) == 0) {   // node already exists!
			return false;
		}
		else if (newName.compare(oldName) < 0) {	// insert the string into left child tree
			return insert(R->left, player);
		}
		else {
			return insert(R->right, player); // otherwise, insert into right child tree
		}
			
	}
	
}

//-------------------------------------------------------------------
// free: recursively frees binary tree
//-------------------------------------------------------------------
void PlayerList::free(TreeNode* R) {
	if (!isEmpty()) // if playerlist tree is not empty
	{
		free(R->left);
		free(R->right);
		delete R;
	}
}

//-------------------------------------------------------------------
// countNodes: recursive method to count all nodes in the tree.
//-------------------------------------------------------------------
int PlayerList::count(TreeNode* R) {
	if (R == NULL) // there is no node here
		return 0;
	else
		return 1 + count(R->left) + count(R->right);
}

//-------------------------------------------------------------------
// countNodes: recursive method to count all nodes in the tree.
//-------------------------------------------------------------------
double PlayerList::battingTotal(TreeNode* R) {
	if (R == NULL) // there is no node here
		return 0;
	else
		return R->item.batting_average() + battingTotal(R->left) + battingTotal(R->right);
}

//------------------------------------------------------------------------
// INORDER Traversal
//------------------------------------------------------------------------
void PlayerList::display(ostream& out, TreeNode* R) {
	if (R != NULL) {
		display(out, R->left);
		out << R->item.get_name() << endl;
		display(out, R->right);
	}
}

//------------------------------------------------------------------------
// backwards traversal
//------------------------------------------------------------------------
void PlayerList::displayBackwards(ostream& out, TreeNode* R) {
	if (R != NULL) {
		
		displayBackwards(out, R->right);
		out << R->item.get_name() << endl;;
		displayBackwards(out, R->left);
		
	}
}

//------------------------------------------------------------------------
// constructs report recursively
//------------------------------------------------------------------------
void PlayerList::constructReport(ostream& out, TreeNode* R, void (*f)(ostream&, Player)) {
	if (R != NULL) {
		constructReport(out, R->left, f);
		f(out, R->item);
		constructReport(out, R->right, f);
	}
}

//************************************************************************
// PUBLIC METHODS
//************************************************************************

//------------------------------------------------------------------------
// add(): adds Player object to PlayerList linked list
//------------------------------------------------------------------------
void PlayerList::add(Player &player) {
	//runs private recursive insertNode() method
	bool successful = insert(root, player);
	//increments list length to keep track of how many players
	if (successful) { m_length++; }
}

//------------------------------------------------------------------------
// isEmpty(): checks if linked list is empty
//------------------------------------------------------------------------
bool PlayerList::isEmpty() { return root == NULL; }

//------------------------------------------------------------------------
// isFull(): checks if linked list is full; always returns false
//------------------------------------------------------------------------
bool PlayerList::isFull() { return false; }

//------------------------------------------------------------------------
// clear(): used in destructor to clear list
//------------------------------------------------------------------------
void PlayerList::clear() {
	free(root);
}

//------------------------------------------------------------------------
// getSize(): returns private attribute m_length or amount of players
//------------------------------------------------------------------------
int PlayerList::getSize() { return m_length; }

//------------------------------------------------------------------------
// getBatAvg(): returns batting average of all players
//------------------------------------------------------------------------
double PlayerList::getBatAvg() { 
	//initializes sum and player variables
	double sum = battingTotal(root);

	//returns amount of players and computes avg
	double numPlayers = getSize();
	return (sum / numPlayers);
}

//------------------------------------------------------------------------
// print(): prints name of each player
//------------------------------------------------------------------------
void PlayerList::print() {
	display(cout, root);
}

//------------------------------------------------------------------------
// printBackwards(): prints name of each player... except backwards
//------------------------------------------------------------------------
void PlayerList::printBackwards() {
	displayBackwards(cout, root);
}

//------------------------------------------------------------------------
// printReport(): prints report to file
//------------------------------------------------------------------------
void PlayerList::printReport(ostream& out, void (*f)(ostream&, Player)) {
	constructReport(out, root, f);
}

