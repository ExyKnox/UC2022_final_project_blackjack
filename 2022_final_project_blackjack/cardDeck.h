#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
* �̾ư��� ī�� ���� ����ϴ� Ŭ���� CardDeck.
* �÷��̾�/������ ī�� �̱�, ī�� �� ����, ������ ī�� ���
* ���� �� ���� https://m.blog.naver.com/jajuye123/221352238101
*/

struct Card {
	char symbol;
	string index;
};

class CardDeck
{
	int cardAmount;
	int popCardIndex = 0;
	const char symbols[4] = { 'S', 'H', 'D', 'C' }; // SPADE HEART DIAMOND CLUB
	const string indexes[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	struct Card cards[52];

public:
	CardDeck();
	CardDeck(int packs);
	void shuffleCards();
	struct Card popCard();
}; 