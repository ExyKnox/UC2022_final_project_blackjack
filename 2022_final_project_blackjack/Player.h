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
	// ����ü Card�� ������ �ּҸ� �����ϴ� ������ ����
	struct Card* playerDeck[6];
	bool stand, hit, burst;
public:
	Player();
	void getCard(struct Card* c); // �� ���� ������ ���� ���, ����Ʈ ���� �ʿ� - ����ȯ ��Ʈ?
	void askStatus(); // �÷��̾�(���)���� ��Ʈ, ���ĵ� ���θ� ����� �Լ�
	string status(); // "stand", "hit", "burst" string ����
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