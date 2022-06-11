#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
���� ���̽����� 9���� ���ڰ� ���� ī�� �� ���̳� 10��¥�� ī�� �� ��(���� ��� 10 ī��� ��)�� �ǹ��մϴ�.
*/

//void Dealer::fair_play_strategy() {
//
//	// ���� ī����� index�� �Ǻ�.
//	string nowCard = playerDeck[j].index;
//	// ���� ī�尡 2���� 9 �����϶� ��Ʈ
//	// ���� ī�尡 2���� 6���� �� �� ��Ʈ
//	// ����ī�尡 2���� 7 ���� �϶� ��Ʈ
//	// 2���� 7������ ��� hit
//
//	// ��� �Ǵ� �ڵ� �ʿ�
//
//	// ���⼭ select(string status, CardDeck* cd) ����ؼ�
//	// ī����� �ѹ��� ��������? �ƴϸ� main �Լ����� status() ����ؼ� getCard()?
//	// ���� ���� �� ���� ����̱� �� �� ����.
//
//	// ���� ī�尡 2���� 9 �����϶� ��Ʈ
//	//���� ī�尡 2���� 9 �����϶� ������� ���¸� ��Ʈ��
//	if (2 <= stoi(nowCard) && stoi(nowCard) <= 9)
//	{
//		hit = true;
//		stand = false;
//		//burst = false;
//	}
//	// ����ī�尡 7, 10, or ���̽� �� ��� ���ĵ� 
//	//���� ī�尡 10 Ȥ�� ���̽� �� ��� ������� ���¸� ���ĵ�
//	else if (nowCard == "7" || nowCard == "10" || nowCard == "A")
//	{
//		hit = false;
//		stand = true;
//		//burst = false;
//	}
//
//	// ���� �Ǵ� ��
//	// main()���� status() ��� �� ��Ʈ�� �� select(string status, CardDeck* cd) ���
//}

// ����Ʈ �ڵ�(A = 11)? �ϵ� �ڵ�(A = 1 or A�� ����)?
void Dealer::decision() {
	// ���� ����Ʈ/�ϵ� �ڵ� ���� �ǵ�
	bool isSoft = false;
	for (int i = 0; i < j-1; i++) {
		if (playerDeck[i].index == "A") {
			if ((score - 1) + 11 > 21) {
				// A�� 11�� ó������ �� ����Ʈ��� A = 1
				// ���� A�� �ִ� �ϵ� �ڵ�
				isSoft = false;
			}
			else {
				// A�� 11�� ó������ �� ����Ʈ�� �ƴϹǷ� A = 11
				// ���� A�� �ִ� ����Ʈ �ڵ�
				isSoft = true;
			}
		}
	}

	// A�� ������ isSoft = false -> A ���� �ϵ� �ڵ�

	/*
	* [���� ����]
	*
	* [�ϵ� 11] ���� ��Ʈ
	* [�ϵ� 17] �̻� ���ĵ�
	* [�ϵ� 12 ~ �ϵ� 16] ��Ʈ - ����Ʈ �� Ȯ���� ��������� ����
	*
	* [����Ʈ 19 or 20] ���ĵ�
	* [����Ʈ 18] ���ĵ�
	* [����Ʈ 17] ��Ʈ
	* [����Ʈ 16] ��Ʈ(�·��� �� ����)
	* [����Ʈ 13 or 14] ��Ʈ
	*/

	if (isSoft) {
		// ����Ʈ ���� ��
		if (score >= 19 || score == 18) {
			stand = true;
			return;
		}
		else if (score == 17 || score == 16 || score == 14 || score == 13) {
			hit = true;
			return;
		}
	}
	else {
		// �ϵ� ���� ��
		if (score <= 11 || (score >= 12 && score <= 16) ) {
			hit = true;
			return;
		}
		else if (score >= 17) {
			stand = true;
			return;
		}
	}

}