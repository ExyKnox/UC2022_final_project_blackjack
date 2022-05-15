#include <iostream>
#include <string>
#include "CardDeck.h"

using namespace std;

int main() {
	CardDeck testDeck;
	testDeck.shuffleCards();

	for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";	
	}
	cout << endl;
	cout << "pop 5 cards" << endl;
	for (int i = 0; i < 5; i++) {
		struct Card cardBuf = testDeck.popCard();
		cout << "[" << cardBuf.symbol << cardBuf.index << "]" << endl;
	}

	testDeck.shuffleCards();

	for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";
	}
	cout << "pop 5 cards" << endl;
	for (int i = 0; i < 5; i++) {
		struct Card cardBuf = testDeck.popCard();
		cout << "[" << cardBuf.symbol << cardBuf.index << "]" << endl;
	}
}