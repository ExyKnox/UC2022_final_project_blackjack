#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//�Լ� ���� ���� - ���ϸ� ������.
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
		if (l >= 2) { //��ó�� 2���� ������ ������ 2���� �ް� ���ڿ��� ��Ʈ�� ���ĵ带 �����Ҽ� �ִ�.
			// �÷��̾� ��
			cout << "--p1--" << endl;
			if (p1.select() == "HIT") {
				// ī�� �� �� �̱�
				p1.getCard(cd.popCard());
				cout << " ����� �°����� ī�� ��ο�"; // <<- ����� �ƴմϴ�,
			}

			// ���� ��
			cout << "--d1--" << endl;
			d1.decision();
			if (d1.status() == "HIT") {
				d1.getCard(cd.popCard());
			}

			// �÷��̾ ����Ʈ�ų� ���ĵ��϶�
			//if (p1.status() == "STAND") {
			//	if (p1.getScore() > d1.getScore()) {
			//		cout << "�÷��̾� ��" << endl;
			//	}
			//	else {
			//		cout << "���� ��" << endl;
			//	}
			//	break;
			//}
			//else {
			//	// �÷��̾ ����Ʈ�� ��
			//	cout << "���� ��" << endl;
			//	break;
			//}

			//// ������ ����Ʈ�ų� ���ĵ��϶�
			//if (d1.status() == "STAND") {
			//	if (p1.getScore() > d1.getScore()) {
			//		cout << "�÷��̾� ��" << endl;
			//	}
			//	else {
			//		cout << "���� ��" << endl;
			//	}
			//	break;
			//}
			//else {
			//	// ������ ����Ʈ�� ��
			//	cout << "�÷��̾� ��" << endl;
			//}

			// �÷��̾� or ���� �� �߿� �Ѹ���
			// 1. ����Ʈ�� ��
			// -> ���� ����Ʈ �� ���� �й�
			// 2. ���ĵ��� ��
			// -> ���ĵ尡 �ƴ� ���� ��Ʈ/���ĵ� ���� ���� ��� �ڿ�(�÷��̾� -> select() ���� -> decision())
			// -> ���� ���ؼ�(getScore()) ���� ū ���� �¸�

			l++;
		}
		else {
			// �� ó�� ī�� �� �� �̱�
			p1.getCard(cd.popCard());
			d1.getCard(cd.popCard());
			l++;
			if (l == 1) {
				// 2�� �̾��� �� BLACKJACK �Ǵ�
				if (p1.getScore() == 21) {
					cout << "�÷��̾� ����, ���� ����" << endl;
					return;
				}
				if (d1.getScore() == 21) {
					cout << "���� ����, ���� ����" << endl;
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
		if (l >= 2) { //��ó�� 2���� ������ ������ 2���� �ް� ���ڿ��� ��Ʈ�� ���ĵ带 �����Ҽ� �ִ�.
			if (player1.select() == "HIT") {
				// ī�� �� �� �̱�
				player1.getCard(testDeck.popCard());
			}
			//testDeck.shuffleCards();
			// Player ��ü�� stand �� true �� ���
			if (player1.endGame() == "END")
				break;

			l++;
		}
		else {
			//testDeck.shuffleCards();
			player1.getCard(testDeck.popCard());
			l++;
			if (l == 2) {
				// BLACKJACK �Ǵ�
				if (player1.getScore() == 21) {
					cout << "�÷��̾� ����, ���� ����" << endl;
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