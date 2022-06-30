#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"
#include <windows.h>

using namespace std;

//�Լ� ���� ���� - ���ϸ� ������.
void cardDeckTest();
void game();
void start();

int main() {
	//cardDeckTest();
	cout << endl << endl << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥�		�¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥�    �¥�		�¥¥¥¥¥¥¥�   �¥�    �¥�" << endl;
	cout << "\t" << "�¥¥�		�¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥�    �¥�		�¥¥¥¥¥¥¥�   �¥�    �¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥�		�¥¥�		                �¥¥�   �¥�    �¥�		         �¥¥�    �¥�    �¥�" << endl;
	cout << "\t" << "�¥¥�		�¥¥�			        �¥¥�   �¥�    �¥�		        �¥¥�     �¥�    �¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥¥¥¥¥�		    �¥¥¥�       �¥¥¥¥¥�   	" << endl;
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥¥¥¥¥�	          �¥¥¥¥¥�     �¥¥¥¥¥�  " << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥�		�¥¥�		�¥¥�	                 �¥�    �¥�		 �¥�      �¥�	   �¥�    �¥�" << endl;
	cout << "\t" << "�¥¥�		�¥¥�		�¥¥�	                 �¥�    �¥�		�¥�        �¥�   �¥�    �¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥�		�¥¥�		�¥¥�	                 �¥�    �¥�	       �¥�          �¥�  �¥�    �¥�" << endl;
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥�    �¥�	      �¥�           �¥�  �¥�    �¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�		�¥¥¥¥¥¥¥¥¥¥�   �¥�    �¥�	      �¥�           �¥�  �¥�    �¥�" << endl;
	cout << endl;
	Sleep(1000);
	cout << endl;
	cout << " " << "�¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥�         �¥¥¥¥¥¥¥¥¥¥¥¥¥�               �¥¥¥¥¥¥¥¥¥¥¥¥¥�" << endl;
	Sleep(1000);
	cout << " " << "�¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥�         �¥¥¥¥¥¥¥¥¥¥¥¥¥�               �¥¥¥¥¥¥¥¥¥¥¥¥¥�" << endl;
	cout << " " << "                                                                   �¥¥�                                     �¥¥�" << endl;
	Sleep(1000);
	cout << " " << "                                                                   �¥¥�                                     �¥¥�" << endl;
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	cout << "\t                " << "�¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥�		                                            �¥¥�                                     �¥¥�" << endl;
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�	                                    �¥¥�                                     �¥¥�" << endl;
	Sleep(1000);
	cout << "\t" << "�¥¥¥¥¥¥¥¥¥¥�" << endl;

	start();
	game();
}

void start() {
	char choice, choice1, choice2, choice3;
	cout << "(������ ������! ������ �Ӵ�!, �λ��ѹ� �븮�ٰ� �λ� �ѹ濡 ���ϴ�.)" << endl;
	cout << "���� ���� �Ͻ�?  [y/n] " << endl;
	cin >> choice;
	if (choice == 'y') {
		cout << "�ƴ� ��¥ �Ҳ�����?  [y/n] " << endl;
		cin >> choice1;
		if (choice1 == 'y') {
			cout << "�ƴ� ��¥ �������� �Ҳ�����?  [y/n] " << endl;
			cin >> choice2;
			if (choice2 == 'y') {
				cout << "��ȸ ���Ұſ���?  [y/n] " << endl;
				cin >> choice3;
				if (choice3 == 'y') {
					cout << "OK ������ ����������" << endl;
				}
				else {
					cout << "���� ���� ���̳� ��ſ� ������" << endl;
				}
			}
			else {
				cout << "���� ���� ������ �ϼſ� ������" << endl;
			}
		}
		else {
			cout << "���� ���� Ƽ�� ���ſ� ������" << endl;
		}
	}
	else {
		cout << "���� ���� ���ſ� ������" << endl;
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
		if (l >= 2) { //��ó�� 2���� ������ ������ 2���� �ް� ���ڿ��� ��Ʈ�� ���ĵ带 �����Ҽ� �ִ�.
			// �÷��̾� ��
			if (p1.select() == "HIT") {
				// ī�� �� �� �̱�
				p1.getCard(cd.popCard());
			}

			// ���� ��
			cout << endl << endl << "--���� ��--" << endl << endl;
			d1.decision();
			if (d1.status() == "HIT") {
				d1.getCard(cd.popCard());
			}

			// �÷��̾� or ���� �� �߿� �Ѹ���
			// 1. ����Ʈ�� ��
			// -> ���� ����Ʈ �� ���� �й�
			// 2. ���ĵ��� ��
			// -> ���ĵ尡 �ƴ� ���� ��Ʈ/���ĵ� ���� ���� ��� �ڿ�(�÷��̾� -> select() ���� -> decision())
			// -> ���� ���ؼ�(getScore()) ���� ū ���� �¸�

			if (p1.status() == "BURST" || d1.status() == "BURST") {
				if (p1.getScore() > 21) {
					cout << "�÷��̾��� ������ 21���� �ʰ��Ͽ� BURST, ������ �й��߽��ϴ�." << endl;
					cout << "���� ��!" << endl;
					return;
				}
				else if (d1.getScore() > 21) {
					cout << "������ ������ 21���� �ʰ��Ͽ� BURST, ������ �й��߽��ϴ�." << endl;
					cout << "�÷��̾� ��!" << endl;
					return;
				}
			}
			else if (p1.status() == "STAND") {
				if (p1.getScore() == 21) {
					cout << "�÷��̾ STAND �Ͽ����ϴ�. ������ HIT or STAND �� ���� �ٶ��ϴ�." << endl;
					while (d1.status() != "STAND") {
						d1.decision();
						if (d1.status() == "HIT") {
							d1.getCard(cd.popCard());
							cout << "������ ī�� ������ ��ο�!";
						}
						else {
							// ������ ���ĵ��� ���
							cout << "���� �׸� �̾ƾ�¡";
							break;
						}
					}
				}
				else if (d1.status() == "STAND") {
					if (d1.getScore() == 21){
						cout << "������ STAND �Ͽ����ϴ�. �÷��̾�� HIT or STAND �� ���� �ٶ��ϴ�." << endl;
						while (p1.status() != "STAND") {
							p1.select();
							if (p1.select() == "HIT") {
								p1.getCard(cd.popCard());
								cout << "�÷��̾�� ī�� ������ ��ο�!";
							}
							else {
								// �÷��̾ ���ĵ��� ���
								cout << "���� �׸� �̾ƾ�¡";
								break;
							}
						}
					}
				}
				l++;
			}
		}
		else {
			// �� ó�� ī�� �� �� �̱�
			p1.getCard(cd.popCard());
			d1.getCard(cd.popCard());
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
			l++;
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