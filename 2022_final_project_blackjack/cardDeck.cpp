#include <iostream>
#include <random>
#include "cardDeck.h"

using namespace std;

cardDeck::cardDeck() {
	// 기본 1 팩 = 52장 (조커 제외)
	card_amount = 52;
	// 카드 덱 초기화 - 구조체라 생성자 실행 시 카드 생성, 셔플 | 1차 for는 S H D C, 2차 for는 A 2 3 4 5 ... J Q K
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
	
	// cardDeck.cards를 셔플한 카드덱으로 바꿔주기
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