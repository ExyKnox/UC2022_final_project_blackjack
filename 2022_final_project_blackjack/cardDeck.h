#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
* �̾ư��� ī�� ���� ����ϴ� Ŭ���� cardDeck.
* �÷��̾�/������ ī�� �̱�, ī�� �� ����, ������ ī�� ���
* ���� �� ���� https://m.blog.naver.com/jajuye123/221352238101
*/

struct Card {
	char symbol;
	string index; // ���� Ȥ�� J, Q, K - stoi() ���� ������ -> ���ڰ� �ƴϸ�(JQK) 0�� ������ ���� -> 10�� ó��
};

class cardDeck
{
	int card_amount;
	const char symbols[4] = { 'S', 'H', 'D', 'C' }; // SPADE HEART DIAMOND CLUB
	const string indexes[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

public:
	// private�� ������ ��!
	struct Card cards[52];

	cardDeck();
	cardDeck(int packs);
	void shuffleCards();
	//struct Card getCard(int number);
	struct Card popCard();
}; 