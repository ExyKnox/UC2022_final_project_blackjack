#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
���� ���̽����� 9���� ���ڰ� ���� ī�� �� ���̳� 10��¥�� ī�� �� ��(���� ��� 10 ī��� ��)�� �ǹ��մϴ�.
*/
void Dealer::fair_play_strategy(Player& player) {

	// ���� ī����� index�� �Ǻ�.
	string nowCard = playerDeck[j].index;
	// ���� ī�尡 2���� 9 �����϶� ��Ʈ
	// ���� ī�尡 2���� 6���� �� �� ��Ʈ
	// ����ī�尡 2���� 7 ���� �϶� ��Ʈ
	// 2���� 7������ ��� hit

	// ���⼭ select(string status, CardDeck* cd) ����ؼ�
	// ī����� �ѹ��� ��������? �ƴϸ� main �Լ����� status() ����ؼ� getCard()?
	// ���� ���� �� ���� ����̱� �� �� ����.

	// ���� ī�尡 2���� 9 �����϶� ��Ʈ
	//���� ī�尡 2���� 9 �����϶� ������� ���¸� ��Ʈ��
	// string���� �Ǵ��ϸ� �� �� �� ������... stoi()??
	if (2 <= stoi(nowCard) && stoi(nowCard) <= 9)
	{
		hit = true;
		stand = false;
		//burst = false;
	}
	// ����ī�尡 7, 10, or ���̽� �� ��� ���ĵ� 
	//���� ī�尡 10 Ȥ�� ���̽� �� ��� ������� ���¸� ���ĵ�
	else if (nowCard == "10" || nowCard == "A")
	{
		hit = false;
		stand = true;
		//burst = false;
	}
}