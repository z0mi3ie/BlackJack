/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

Cards.h
Header file for card class and deck class.
*/

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Card
{
	public:
		Card( int v, int suit );
		void setAce( int );
        	string getSuit();
		int  suit;
		int  initial;
		int  value;
		string face;
};

class Deck
{
	public:
		Deck();
		int getSize();
		Card drawCard();
		void shuffle();
	private:
		vector <Card> cards;
};

#endif
