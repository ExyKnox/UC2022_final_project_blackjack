#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

void Player::getCard(struct Card c) {
	if (stand == false and hit == false) { // STAND�� HIT�� �������� ���� ��ó�� 2���ϰ�� ����

		playerDeck[j] = c;

		if (playerDeck[j].index != "") {
			if (playerDeck[j].index == "J") //J,Q,K�� �޾����� 10�� ������ �ְ� A�� �޾����� �ϴ� 11�� ������ �÷��̾ BURST������ ������ 11�� 1�ιٲ���
				score += 10;
			else if (playerDeck[j].index == "Q")
				score += 10;
			else if (playerDeck[j].index == "K")
				score += 10;
			else if (playerDeck[j].index == "A")
				score += 11;
			else
				score += stoi(playerDeck[j].index, 0);
		}
		printCard();
		printScore();
		j++;
	}
	else if (stand == true or burst == true) { //STAND�� �����ų� BURST�� ���������� �˷��ص� 
		cout << "����� ����������"
			<< score
			<< "�Դϴ�" << endl;
	}
	else if (hit == true and stand == false) { //2���� ī�带 ������ ��Ʈ�� ���������� ����
		playerDeck[j] = c;

		if (playerDeck[j].index != "") {
			if (playerDeck[j].index == "J") //J,Q,K�� �޾����� 10�� ������ �ְ� A�� �޾����� �ϴ� 11�� ������ �÷��̾ BURST������ ������ 11�� 1�ιٲ���
				score += 10;
			else if (playerDeck[j].index == "Q")
				score += 10;
			else if (playerDeck[j].index == "K")
				score += 10;
			else if (playerDeck[j].index == "A")
				score += 11;
			else
				score += stoi(playerDeck[j].index, 0);


			hit = false;
		}
		printCard();
		printScore();
		j++;
	}
}

void Player::askStatus() {

	if (score == 20) { //score�� 21�Ͻ� BLACK JACK
		cout << "BLACK JACK!!" << endl;
		stand = true;
	}
	else if (score > 20) { //score�� 21�� �Ѿ����� BURST���� �÷��̾ A�� ������ ������ 11�� ����ߴ� A�� 1�� �ٲ���
		int p = 0;
		for (int h = 0; h < j; h++) {
			if (playerDeck[h].index == "K") {
				p++;
			}
		}
		if (p == 0) {
			cout << "BURST �Ф�";
			burst = true;
		}
		else if (p == 1) {
			cout << "K�� ���Ե� BURST�Դϴ�" << endl;
			score -= 10;
			printScore();
			select();
		}
	}
	else if (score < 20) { //score�� 21���� ������ �÷��̾ HIT�� STAND�� �����Ҽ� ����
		select();
	}
}
void Player::printCard() { //�÷��̾ ���� ī�带 ������ִ� �Լ�
	cout << "����� ���� "
		<< j + 1
		<< "��° ī���"
		<< playerDeck[j].symbol
		<< playerDeck[j].index
		<< "�Դϴ�" << endl;
}
void Player::printScore() { //�÷��̾��� ������ ������ִ� �Լ�
	cout << "����� ������"
		<< score
		<< "�Դϴ�" << endl;
}
string Player::endGame() { //�÷��̾ STAND�� ����������, BURST������ ������, BLACK JACK�� ��� ������ �������ִ� �Լ�
	if (stand == true or burst == true)
		return "END";
	else
		return "CONTINUE";
}
void Player::select() {
	cout << "1.HIT " << "2.STAND " << endl;
	int o;
	cin >> o;
	if (o == 1) {
		hit = true;
	}
	else if (o == 2) {
		stand = true;
	}
}
