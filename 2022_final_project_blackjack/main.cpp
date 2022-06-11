#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//함수 원형 정의 - 안하면 에러남.
void cardDeckTest();
void game();

int main() {
	//cardDeckTest();
	game();
}

void game() {
	Player p1;
	Dealer d1;
	CardDeck cd;
	int l = 0;

	cd.shuffleCards();

	while (true) {
		if (l >= 2) { //맨처음 2장은 무조건 받으니 2장을 받고 난뒤에는 히트와 스탠드를 선택할수 있다.
			// 플레이어 턴
			cout << "--p1--" << endl;
			if (p1.select() == "HIT") {
				// 카드 한 장 뽑기
				p1.getCard(cd.popCard());
				cout << " 쎄끈한 승갑이의 카드 드로우"; // <<- 사실이 아닙니다,
			}

			// 딜러 턴
			cout << "--d1--" << endl;
			d1.decision();
			if (d1.status() == "HIT") {
				d1.getCard(cd.popCard());
			}

			// 플레이어가 버스트거나 스탠드일때
			//if (p1.status() == "STAND") {
			//	if (p1.getScore() > d1.getScore()) {
			//		cout << "플레이어 승" << endl;
			//	}
			//	else {
			//		cout << "딜러 승" << endl;
			//	}
			//	break;
			//}
			//else {
			//	// 플레이어가 버스트일 때
			//	cout << "딜러 승" << endl;
			//	break;
			//}

			//// 딜러가 버스트거나 스탠드일때
			//if (d1.status() == "STAND") {
			//	if (p1.getScore() > d1.getScore()) {
			//		cout << "플레이어 승" << endl;
			//	}
			//	else {
			//		cout << "딜러 승" << endl;
			//	}
			//	break;
			//}
			//else {
			//	// 딜러가 버스트일 때
			//	cout << "플레이어 승" << endl;
			//}

			// 플레이어 or 딜러 둘 중에 한명이
			// 1. 버스트일 때
			// -> 먼저 버스트 된 쪽이 패배
			// 2. 스탠드일 때
			// -> 스탠드가 아닌 쪽의 히트/스탠드 여부 먼저 물어본 뒤에(플레이어 -> select() 딜러 -> decision())
			// -> 점수 비교해서(getScore()) 점수 큰 쪽이 승리

			l++;
		}
		else {
			// 맨 처음 카드 두 번 뽑기
			p1.getCard(cd.popCard());
			d1.getCard(cd.popCard());
			l++;
			if (l == 1) {
				// 2장 뽑았을 때 BLACKJACK 판단
				if (p1.getScore() == 21) {
					cout << "플레이어 블랙잭, 게임 종료" << endl;
					return;
				}
				if (d1.getScore() == 21) {
					cout << "딜러 블랙잭, 게임 종료" << endl;
					return;
				}
			}
		}
	}
}

void cardDeckTest() {
	CardDeck testDeck;
	Player player1;
	int l = 0;

	while (true) {
		if (l >= 2) { //맨처음 2장은 무조건 받으니 2장을 받고 난뒤에는 히트와 스탠드를 선택할수 있다.
			if (player1.select() == "HIT") {
				// 카드 한 장 뽑기
				player1.getCard(testDeck.popCard());
			}
			//testDeck.shuffleCards();
			// Player 객체의 stand 가 true 일 경우
			if (player1.endGame() == "END")
				break;

			l++;
		}
		else {
			//testDeck.shuffleCards();
			player1.getCard(testDeck.popCard());
			l++;
			if (l == 2) {
				// BLACKJACK 판단
				if (player1.getScore() == 21) {
					cout << "플레이어 블랙잭, 게임 종료" << endl;
					return;
				}
			}
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