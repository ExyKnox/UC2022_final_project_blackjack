#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
���� ���̽����� 9���� ���ڰ� ���� ī�� �� ���̳� 10��¥�� ī�� �� ��(���� ��� 10 ī��� ��)�� �ǹ��մϴ�.
*/
void Dealer::decision() {

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
	// string���� �Ǵ��ϸ� �� �� �� ������... stoi()??
	if ("2" <= nowCard && nowCard <= "9")
	{
		hit = true;

		stand = false;
		//burst = false;
	}
	// ����ī�尡 7, 10, or ���̽� �� ��� ���ĵ� 
	else if (nowCard == "7" || nowCard == "10" || nowCard == "A")
	{
		stand = true;

		hit = false;
		//burst = false;
	}
	// ���� ��Ģ�� �ش���� �ʴ� ���
	else
	{
		//������ 11 �����̸� ��Ʈ(10��¥�� ī�尡 ���͵� ������ ����Ʈ���� ����)
		if (score < 11) {
			stand = false;
			hit = true;
		}
		else {
			// ��?��
		}
	}
}