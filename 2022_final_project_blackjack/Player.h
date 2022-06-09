#pragma once

#include <string>
#include "CardDeck.h"

using namespace std;

/*
* "���� �÷��̾�" Ŭ���� Player.
*
* -�÷��̾ ���� �� �ִ� ���� Ȥ�� �ൿ
* ���ĵ�(ī�带 �� �̻� �������� ����)
* �� ���� ó�� �̾ƿ� ���� ������ 21
* ��Ʈ(ī�带 �� �� �� ������)
* ����Ʈ(�÷��̾� ���� ī�� ������ 21�� �ʰ�, ���ӿ���)
*
* �÷��̾�� �ڽ��� �и� ������ ����
*/

class Player
{
protected:
	int j = 0;
	int score = 0;
	// ����ü Card�� ������ �ּҸ� �����ϴ� ������ ����
	struct Card playerDeck[7];

	bool stand = false;
	bool hit = false;
	bool burst = false;

	void scoreCalc(); // ���� ���, �ڵ� ���ĵ�, ����Ʈ
	string select(string status, CardDeck* cd); // dealer�� �������̽�. status = "HIT" or "STAND".
public:
	void getCard(struct Card c); // �� ���� ������ ���� ���, ����Ʈ ���� �ʿ� - ����ȯ ��Ʈ?
	void printCard(); // �÷��̾ ���� ī�带 ������ִ� �Լ�
	void printScore(); // �÷��̾��� ���������� ������ִ� �Լ�
	int getScore();
	string endGame(); // STAND, BURST, BLACK JACK �ϰ�� ������ �������ִ� �Լ�
	string select(); // HIT���� STAND ���� �����ϴ� �Լ� - HIT�� �� true ����, STAND�� �� false ����
	string status(); // "stand" "hit" "burst" string �� ���� - ������
};

/* �����Ǵ�
	* ���� Ȥ�� J, Q, K
	* ->stoi() ���� ������->���ڰ� �ƴϸ�(AJQK) 0�� ������ ����
	* ->���ڸ�
	* stoi()�� ������ ���ڸ� ������ ó��
	* ->���ڰ� �ƴϸ�
	* A�� 1 Ȥ�� 11, J Q K �̶�� 10�� ó��
*/

//playerDeck[0] = testDeck.getCard();
// ī�� ��ȣ �ҷ������ �̷���
//cout << playerDeck[0].index << endl;