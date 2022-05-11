#include <iostream>
#include <random>
#include "cardDeck.h"

using namespace std;

cardDeck::cardDeck() {
	// �⺻ 1 �� = 52�� (��Ŀ ����)
	card_amount = 52;
	// ī�� �� �ʱ�ȭ - ����ü�� ������ ���� �� ī�� ����, ���� | 1�� for�� S H D C, 2�� for�� A 2 3 4 5 ... J Q K
	int indexes_counter = 0;
	for (int i = 0; i < card_amount; i++) {
		cards[i].symbol = symbols[i / 13];
		cards[i].index = indexes[indexes_counter];
		indexes_counter++;
		if (indexes_counter == 13) indexes_counter = 0;
	}
}

cardDeck::cardDeck(int packs) {
	this->card_amount = packs * 52;
}

void cardDeck::shuffleCards() {
	struct Card shuffleBuffer[52];
	bool duplicationChecker[52] = { false, };
	for (int i = 0; i < card_amount; i++) {
		int randBuf = rand() % 52;
		int shuffleIndex = 0;
		while (shuffleIndex < card_amount) {
			if (!duplicationChecker[randBuf]) {
				shuffleBuffer[shuffleIndex] = cards[randBuf];
				randBuf = rand() % 52;
				shuffleIndex++;
			}
			else {
				randBuf = rand() % 52;
			}
		}
	}
	
	// cardDeck.cards�� ������ ī�嵦���� �ٲ��ֱ�
	for (int i = 0; i < card_amount; i++) {
		//cards[i] = shuffleBuffer[i];
		cards[i].symbol = shuffleBuffer[i].symbol;
		cards[i].index = shuffleBuffer[i].index;
	}
}

/*
struct Card cardDeck::popCard() {
	// have to use something like stack...
}
*/