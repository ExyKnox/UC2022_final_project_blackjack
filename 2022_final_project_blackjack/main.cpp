#include <iostream>
#include "cardDeck.h"

using namespace std;

int main() {
	cardDeck testDeck;
	testDeck.shuffleCards();

	for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";	
	}
}