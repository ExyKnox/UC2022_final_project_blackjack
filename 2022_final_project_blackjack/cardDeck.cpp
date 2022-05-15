#include <iostream>
#include <random>
#include "cardDeck.h"

using namespace std;

CardDeck::CardDeck() {
	// �⺻ 1 �� = 52�� (��Ŀ ����)
	cardAmount = 52;
	// ī�� �� �ʱ�ȭ - ����ü�� ������ ���� �� ī�� ����, ���� | 1�� for�� S H D C, 2�� for�� A 2 3 4 5 ... J Q K
	int indexes_counter = 0;
	for (int i = 0; i < cardAmount; i++) {
		cards[i].symbol = symbols[i / 13];
		cards[i].index = indexes[indexes_counter];
		indexes_counter++;
		if (indexes_counter == 13) indexes_counter = 0;
	}
}

CardDeck::CardDeck(int packs) {
	this->cardAmount = packs * 52;
}

void CardDeck::shuffleCards() {
	struct Card shuffleBuffer[52];
	bool duplicationChecker[52] = { false, };
	int randBuf = rand() % 52;
	int shuffleIndex = 0;

	while (shuffleIndex < cardAmount) {
		if (!duplicationChecker[randBuf]) {
			shuffleBuffer[shuffleIndex] = cards[randBuf];
			duplicationChecker[randBuf] = true;
			randBuf = rand() % 52;
			shuffleIndex++;
		}
		else {
			randBuf = rand() % 52;
		}
	}
	
	// cardDeck.cards�� ������ ī�嵦���� �ٲ��ֱ�
	for (int i = 0; i < cardAmount; i++) {
		//cards[i] = shuffleBuffer[i];
		cards[i].symbol = shuffleBuffer[i].symbol;
		cards[i].index = shuffleBuffer[i].index;
	}

	// ī�嵦 ����(?) �ε��� �ʱ�ȭ
	popCardIndex = 0;
}


struct Card CardDeck::popCard() {
	// have to use something like stack...
	this->popCardIndex++;
	return cards[popCardIndex - 1];
}
