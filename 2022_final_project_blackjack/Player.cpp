#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"

using namespace std;

int Player::getScore() {
	return score;
}

void Player::scoreCalc() {
	if (playerDeck[j].index != "") {
		if (playerDeck[j].index == "J") //J,Q,K�� �޾����� 10�� ������ �ְ� A�� �޾����� �ϴ� 11�� ������ �÷��̾ BURST������ ������ 11�� 1�ιٲ���
			score += 10;
		else if (playerDeck[j].index == "Q")
			score += 10;
		else if (playerDeck[j].index == "K")
			score += 10;
		else if (playerDeck[j].index == "A")
			// 11�� �̸��� ������ ������ �ִٸ� A�� 11�� ó��
			if (score < 11) score += 11;
		// 11�� �̻��� ������ ������ ���� ���
			else score += 1;
		else
			score += stoi(playerDeck[j].index, 0);
	}
	j++;
	// ù ���� �̴� �κ� �Ǵ� �����
	// �ۼ��Ұ�

	if (score == 21) { //score�� 21�Ͻ� �ڵ� ���ĵ�
		cout << "���� 21, �ڵ� ���ĵ�" << endl;
		stand = true;
	}
	else if (score > 21) { //score�� 21�� �Ѿ����� BURST���� �÷��̾ A�� ������ ������ 11�� ����ߴ� A�� 1�� �ٲ���
		int p = 0;
		for (int h = 0; h < j; h++) {
			if (playerDeck[h].index == "A") {
				p++;
			}
		}
		if (p == 0) {
			cout << "BURST �Ф�";
			burst = true;
		}
		else if (p == 1) {
			cout << "A�� ���Ե� BURST�Դϴ�. A�� 1�� ó���մϴ�." << endl;
			score -= 10;
			/*if (select() == true) return "HIT";
			else return "STAND";*/
		}
	}
	//else if (score < 21) { //score�� 21���� ������ �÷��̾ HIT�� STAND�� �����Ҽ� ����
	//	/*if (select() == true) return "HIT";
	//	else return "STAND";*/
	//	select();
	//}
	printCard();
	printScore();
}

void Player::getCard(struct Card c) {
	// �� �� �� �����־�?
	if (stand == true or burst == true) { //STAND�� �����ų� BURST�� ���������� �˷��ص� 
		cout << "����� ����������"
			<< score
			<< "�Դϴ�" << endl;
	}
	else {
		playerDeck[j] = c;
		scoreCalc();
	}
}

//string Player::askStatus() {
//
//	//if (score == 21) { //score�� 21�Ͻ� �ڵ� ���ĵ�
//	//	cout << "���� 21, �ڵ� ���ĵ�" << endl;
//	//	stand = true;
//	//}
//	//else if (score > 21) { //score�� 21�� �Ѿ����� BURST���� �÷��̾ A�� ������ ������ 11�� ����ߴ� A�� 1�� �ٲ���
//	//	int p = 0;
//	//	for (int h = 0; h < j; h++) {
//	//		if (playerDeck[h].index == "A") {
//	//			p++;
//	//		}
//	//	}
//	//	if (p == 0) {
//	//		cout << "BURST �Ф�";
//	//		burst = true;
//	//	}
//	//	else if (p == 1) {
//	//		cout << "A�� ���Ե� BURST�Դϴ�. A�� 1�� ó���մϴ�." << endl;
//	//		score -= 10;
//	//		printScore();
//	//		/*if (select() == true) return "HIT";
//	//		else return "STAND";*/
//	//	}
//	//}
//	//else if (score < 21) { //score�� 21���� ������ �÷��̾ HIT�� STAND�� �����Ҽ� ����
//	//	/*if (select() == true) return "HIT";
//	//	else return "STAND";*/
//	//	select();
//	//}
//	//select();
//
//
//}

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
	else if(status == "HIT") {
		getCard(cd->popCard());
		return "HIT";
	}
}