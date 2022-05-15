#include <iostream>
#include <random>
#include "cardDeck.h"

using namespace std;

CardDeck::CardDeck() {
	// 기본 1 팩 = 52장 (조커 제외)
	cardAmount = 52;
	// 카드 덱 초기화 - 구조체라 생성자 실행 시 카드 생성, 셔플 | 1차 for는 S H D C, 2차 for는 A 2 3 4 5 ... J Q K
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
	
	// cardDeck.cards를 셔플한 카드덱으로 바꿔주기
	for (int i = 0; i < cardAmount; i++) {
		//cards[i] = shuffleBuffer[i];
		cards[i].symbol = shuffleBuffer[i].symbol;
		cards[i].index = shuffleBuffer[i].index;
	}

	// 카드덱 스택(?) 인덱스 초기화
	popCardIndex = 0;
}


struct Card CardDeck::popCard() {
	// have to use something like stack...
	this->popCardIndex++;
	return cards[popCardIndex - 1];
}
