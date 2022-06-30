#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"
#include <windows.h>

using namespace std;

//함수 원형 정의 - 안하면 에러남.
void cardDeckTest();
void game();
void start();

int main() {
	//cardDeckTest();
	cout << endl << endl << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒ		ΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ		ΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ" << endl;
	cout << "\t" << "ΒΒΒ		ΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ		ΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒ		ΒΒΒ		                ΒΒΒ   ΒΒ    ΒΒ		         ΒΒΒ    ΒΒ    ΒΒ" << endl;
	cout << "\t" << "ΒΒΒ		ΒΒΒ			        ΒΒΒ   ΒΒ    ΒΒ		        ΒΒΒ     ΒΒ    ΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒΒΒΒΒ		    ΒΒΒΒ       ΒΒΒΒΒΒ   	" << endl;
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒΒΒΒΒ	          ΒΒΒΒΒΒ     ΒΒΒΒΒΒ  " << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒ		ΒΒΒ		ΒΒΒ	                 ΒΒ    ΒΒ		 ΒΒ      ΒΒ	   ΒΒ    ΒΒ" << endl;
	cout << "\t" << "ΒΒΒ		ΒΒΒ		ΒΒΒ	                 ΒΒ    ΒΒ		ΒΒ        ΒΒ   ΒΒ    ΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒ		ΒΒΒ		ΒΒΒ	                 ΒΒ    ΒΒ	       ΒΒ          ΒΒ  ΒΒ    ΒΒ" << endl;
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ	      ΒΒ           ΒΒ  ΒΒ    ΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ		ΒΒΒΒΒΒΒΒΒΒΒ   ΒΒ    ΒΒ	      ΒΒ           ΒΒ  ΒΒ    ΒΒ" << endl;
	cout << endl;
	Sleep(1000);
	cout << endl;
	cout << " " << "ΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒ         ΒΒΒΒΒΒΒΒΒΒΒΒΒΒ               ΒΒΒΒΒΒΒΒΒΒΒΒΒΒ" << endl;
	Sleep(1000);
	cout << " " << "ΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒΒ         ΒΒΒΒΒΒΒΒΒΒΒΒΒΒ               ΒΒΒΒΒΒΒΒΒΒΒΒΒΒ" << endl;
	cout << " " << "                                                                   ΒΒΒ                                     ΒΒΒ" << endl;
	Sleep(1000);
	cout << " " << "                                                                   ΒΒΒ                                     ΒΒΒ" << endl;
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	cout << "\t                " << "ΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒ		                                            ΒΒΒ                                     ΒΒΒ" << endl;
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ	                                    ΒΒΒ                                     ΒΒΒ" << endl;
	Sleep(1000);
	cout << "\t" << "ΒΒΒΒΒΒΒΒΒΒΒ" << endl;

	start();
	game();
}

void start() {
	char choice, choice1, choice2, choice3;
	cout << "(도박은 나빠요! 도박은 앙대!, 인생한방 노리다가 인생 한방에 갑니다.)" << endl;
	cout << "블랙잭 한판 하실?  [y/n] " << endl;
	cin >> choice;
	if (choice == 'y') {
		cout << "아니 진짜 할꺼에요?  [y/n] " << endl;
		cin >> choice1;
		if (choice1 == 'y') {
			cout << "아니 진짜 정말정말 할꺼에요?  [y/n] " << endl;
			cin >> choice2;
			if (choice2 == 'y') {
				cout << "후회 안할거에요?  [y/n] " << endl;
				cin >> choice3;
				if (choice3 == 'y') {
					cout << "OK 게임을 시작하지ㅋ" << endl;
				}
				else {
					cout << "집에 가서 밥이나 드셔용 빠빠이" << endl;
				}
			}
			else {
				cout << "집에 가서 빨래나 하셔용 빠빠이" << endl;
			}
		}
		else {
			cout << "집에 가서 티비나 보셔용 빠빠이" << endl;
		}
	}
	else {
		cout << "집에 가서 쉬셔용 빠빠이" << endl;
	}
	return;
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
			if (p1.select() == "HIT") {
				// 카드 한 장 뽑기
				p1.getCard(cd.popCard());
			}

			// 딜러 턴
			cout << endl << endl << "--딜러 턴--" << endl << endl;
			d1.decision();
			if (d1.status() == "HIT") {
				d1.getCard(cd.popCard());
			}

			// 플레이어 or 딜러 둘 중에 한명이
			// 1. 버스트일 때
			// -> 먼저 버스트 된 쪽이 패배
			// 2. 스탠드일 때
			// -> 스탠드가 아닌 쪽의 히트/스탠드 여부 먼저 물어본 뒤에(플레이어 -> select() 딜러 -> decision())
			// -> 점수 비교해서(getScore()) 점수 큰 쪽이 승리

			if (p1.status() == "BURST" || d1.status() == "BURST") {
				if (p1.getScore() > 21) {
					cout << "플레이어의 점수가 21점을 초과하여 BURST, 게임을 패배했습니다." << endl;
					cout << "딜러 승!" << endl;
					return;
				}
				else if (d1.getScore() > 21) {
					cout << "딜러의 점수가 21점을 초과하여 BURST, 게임을 패배했습니다." << endl;
					cout << "플레이어 승!" << endl;
					return;
				}
			}
			else if (p1.status() == "STAND") {
				if (p1.getScore() == 21) {
					cout << "플레이어가 STAND 하였습니다. 딜러는 HIT or STAND 를 선택 바랍니다." << endl;
					while (d1.status() != "STAND") {
						d1.decision();
						if (d1.status() == "HIT") {
							d1.getCard(cd.popCard());
							cout << "딜러는 카드 한장을 드로우!";
						}
						else {
							// 딜러가 스탠드일 경우
							cout << "이제 그만 뽑아야징";
							break;
						}
					}
				}
				else if (d1.status() == "STAND") {
					if (d1.getScore() == 21){
						cout << "딜러가 STAND 하였습니다. 플레이어는 HIT or STAND 를 선택 바랍니다." << endl;
						while (p1.status() != "STAND") {
							p1.select();
							if (p1.select() == "HIT") {
								p1.getCard(cd.popCard());
								cout << "플레이어는 카드 한장을 드로우!";
							}
							else {
								// 플레이어가 스탠드일 경우
								cout << "이제 그만 뽑아야징";
								break;
							}
						}
					}
				}
				l++;
			}
		}
		else {
			// 맨 처음 카드 두 번 뽑기
			p1.getCard(cd.popCard());
			d1.getCard(cd.popCard());
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
			l++;
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