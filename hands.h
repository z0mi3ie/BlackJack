/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

hands.h header file for player hand and dealer hand classes.

*/


#include <iostream>
#include <string>
#include "cards.h"

using namespace std;

class PlayerHand
{
    private:
		vector <Card> playercards;
		int playervalue;
		int playerNumCards;
	public:
		PlayerHand();
		int total(){ return playervalue; }
		int getNumCards( ){ return playercards.size(); }
		void giveCard( Card );
		void clear(){ playercards.clear(); playervalue = 0; }
		void printCards();
};


class DealerHand
{
    private:
		vector <Card> dealercards;
		int dealervalue;
		int dealerNumCards;
	public:
		DealerHand();
        	int total(){ return dealervalue; }
       		int getNumCards(){ return dealercards.size(); }
        	void giveCard( Card );
		    void clear(){ dealercards.clear(); dealervalue = 0; }
		    void printCards();
};

