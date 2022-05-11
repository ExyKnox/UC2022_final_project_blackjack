#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
* 뽑아가는 카드 덱을 담당하는 클래스 cardDeck.
* 플레이어/딜러의 카드 뽑기, 카드 덱 셔플, 게임의 카드 장수
* 게임 룰 참고 https://m.blog.naver.com/jajuye123/221352238101
*/

struct Card {
	char symbol;
	string index; // 숫자 혹은 J, Q, K - stoi() 먼저 돌리고 -> 숫자가 아니면(JQK) 0를 리턴할 것임 -> 10점 처리
};

class cardDeck
{
	int card_amount;
	const char symbols[4] = { 'S', 'H', 'D', 'C' }; // SPADE HEART DIAMOND CLUB
	const string indexes[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

public:
	// private로 돌려야 함!
	struct Card cards[52];

	cardDeck();
	cardDeck(int packs);
	void shuffleCards();
	//struct Card getCard(int number);
	struct Card popCard();
}; 