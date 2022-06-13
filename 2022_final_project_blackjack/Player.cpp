#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"

using namespace std;

Player::Player() {
	name = "�÷��̾�";
}

int Player::getScore() {
	return score;
}

void Player::scoreCalc() {
	if (playerDeck[j-1].index != "") {
		if (playerDeck[j-1].index == "J") //J,Q,K�� �޾����� 10�� ������ �ְ� A�� �޾����� �ϴ� 11�� ������ �÷��̾ BURST������ ������ 11�� 1�ιٲ���
			score += 10;
		else if (playerDeck[j-1].index == "Q")
			score += 10;
		else if (playerDeck[j-1].index == "K")
			score += 10;
		else if (playerDeck[j-1].index == "A")
			// 11�� �̸��� ������ ������ �ִٸ� A�� 11�� ó��
			if (score < 11) score += 11;
		// 11�� �̻��� ������ ������ ���� ���
			else score += 1;
		else
			score += stoi(playerDeck[j-1].index, 0);
	}

	if (score == 21) { //score�� 21�Ͻ� �ڵ� ���ĵ�
		cout << "���� 21, �ڵ� ���ĵ�" << endl;
		stand = true;
	}
	else if (score > 21) { //score�� 21�� �Ѿ����� BURST���� �÷��̾ A�� ������ ������ 11�� ����ߴ� A�� 1�� �ٲ���
		int p = 0;
		for (int h = 0; h < j-1; h++) {
			if (playerDeck[h].index == "A") {
				p++;
			}
		}
		if (p == 0) {
			cout << name << "��";
			cout << "BURST �Ф�" << endl;
			burst = true;
		}
		else if (p == 1) {
			cout << name << "��";
			cout << "A�� ���Ե� BURST�Դϴ�. A�� 1�� ó���մϴ�." << endl;
			score -= 10;
		}
	}
	printCard();
	printScore();
}

void Player::getCard(struct Card c) {
	if (stand == true or burst == true) return;
	else {
		playerDeck[j] = c;
		//cout << j << endl;
		j++;
		scoreCalc();
	}
}

void Player::printCard() { //�÷��̾ ���� ī�带 ������ִ� �Լ�
	cout << name
		<< "�� ���� "
		<< j
		<< "��° ī���"
		<< playerDeck[j-1].symbol
		<< playerDeck[j-1].index
		<< "�Դϴ�" << endl;
}

void Player::printScore() { //�÷��̾��� ������ ������ִ� �Լ�
	cout << name
		<< "�� ������"
		<< score
		<< "�Դϴ�" << endl;
}

string Player::endGame() { //�÷��̾ STAND�� ����������, BURST������ ������, BLACK JACK�� ��� ������ �������ִ� �Լ�
	if (stand == true or burst == true)
	{
		//STAND�� �����ų� BURST�� ���������� �˷��ص� 
		cout << name
			<< "�� ����������"
			<< score
			<< "�Դϴ�" << endl;
		return "END";
	}
	else return "CONTINUE";
}

string Player::select() {
	cout << "1.HIT " << "2.STAND " << endl;
	int o;
	cin >> o;
	if (o == 1) {
		//getCard();
		// HIT ����
		return "HIT";
	}
	else if (o == 2) {
		stand = true;
		// STAND ����
		return "STAND";
	}
}

string Player::select(string status, CardDeck* cd) {
	if (status == "STAND") {
		stand = true;
		return "STAND";
	}
	else if (status == "HIT") {
		getCard(cd->popCard());
		return "HIT";
	}
}

string Player::status() {
	string returnStr;
	if (burst) returnStr = "BURST";
	else if (stand) returnStr = "STAND";
	else if (hit) returnStr = "HIT";

	return returnStr;
}