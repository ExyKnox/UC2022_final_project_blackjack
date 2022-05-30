#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"

using namespace std;

//함수 원형 정의 - 안하면 에러남.
void cardDeckTest();

int main() {
	cardDeckTest();
}

void cardDeckTest() {
	CardDeck testDeck;
	Player player1;
	int l = 0;

	while (true) {
		if (l >= 2) { //맨처음 2장은 무조건 받으니 2장을 받고 난뒤에는 히트와 스탠드를 선택할수 있다.
			player1.askStatus();
			testDeck.shuffleCards();
			player1.getCard(testDeck.popCard());
			if (player1.endGame() == "END")
				break;

			l++;
		}
		else {
			testDeck.shuffleCards();
			player1.getCard(testDeck.popCard());
			l++;
		}
	}

	/*for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";
	}
	cout << endl;*/
	cout << "pop 5 cards" << endl;
	for (int i = 0; i < 5; i++) {
		struct Card cardBuf = testDeck.popCard();
		cout << "[" << cardBuf.symbol << cardBuf.index << "]" << endl;
	}

	testDeck.shuffleCards();

	/*for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";
	}*/
	cout << endl;
	cout << "pop 5 cards" << endl;
	for (int i = 0; i < 5; i++) {
		struct Card cardBuf = testDeck.popCard();
		cout << "[" << cardBuf.symbol << cardBuf.index << "]" << endl;
	}

	testDeck.shuffleCards();

	/*for (int i = 0; i < 52; i++) {
		cout << "[" << testDeck.cards[i].symbol << testDeck.cards[i].index << "]";
	}*/
	cout << "pop 5 cards" << endl;
	for (int i = 0; i < 5; i++) {
		struct Card cardBuf = testDeck.popCard();
		cout << "[" << cardBuf.symbol << cardBuf.index << "]" << endl;
	}

	testDeck.shuffleCards();

	// pass!
	cout << "pop all cards for test" << endl;
	for (int i = 0; i < 60; i++) {
		struct Card popBuf = testDeck.popCard();
		cout << "[" << popBuf.symbol << popBuf.index << "] ";
	}
}