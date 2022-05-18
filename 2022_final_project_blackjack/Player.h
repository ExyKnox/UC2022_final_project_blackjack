#pragma once

#include <string>
#include "CardDeck.h"

using namespace std;

/*
* "���� �÷��̾�" Ŭ���� Player.
*
* -�÷��̾ ���� �� �ִ� ���� Ȥ�� �ൿ
* ���ĵ�(ī�带 �� �̻� �������� ����)
* ��Ʈ(ī�带 �� �� �� ������)
* ����Ʈ(�÷��̾� ���� ī�� ������ 21�� �ʰ�, ���ӿ���)
* 
* �÷��̾�� �ڽ��� �и� ������ ����
*/

class Player
{
	// ����ü Card�� ������ �ּҸ� �����ϴ� ������ ����
	struct Card* playerDeck[6];
	bool stand, hit, burst;
public:
	Player();
	void getCard(struct Card* c); // �� ���� ������ ���� ���, ����Ʈ ���� �ʿ� - ����ȯ ��Ʈ?
	void askStatus(); // �÷��̾�(���)���� ��Ʈ, ���ĵ� ���θ� ����� �Լ�
	string status(); // returns "stand", "hit", "burst"
};
