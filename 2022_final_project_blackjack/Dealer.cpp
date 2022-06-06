#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
페어란 에이스부터 9까지 숫자가 같은 카드 두 장이나 10점짜리 카드 두 장(예를 들어 10 카드와 퀸)을 의미합니다.
*/
void Dealer::fair_play_strategy(Player& player) {

	// 딜러 카드안의 index로 판별.
	string nowCard = playerDeck[j].index;
	// 딜러 카드가 2에서 9 사이일때 히트
	// 딜러 카드가 2에서 6사이 일 때 히트
	// 딜러카드가 2에서 7 사이 일때 히트
	// 2에서 7사이일 경우 hit

	// 여기서 select(string status, CardDeck* cd) 사용해서
	// 카드까지 한번에 가져오기? 아니면 main 함수에서 status() 사용해서 getCard()?
	// 후자 쪽이 더 좋은 방법이긴 할 것 같다.

	// 딜러 카드가 2에서 9 사이일때 히트
	//딜러 카드가 2에서 9 사이일때 사용자의 상태를 히트로
	// string으로 판단하면 안 될 것 같은데... stoi()??
	if (2 <= stoi(nowCard) && stoi(nowCard) <= 9)
	{
		hit = true;
		stand = false;
		//burst = false;
	}
	// 딜러카드가 7, 10, or 에이스 일 경우 스탠드 
	//딜러 카드가 10 혹은 에이스 일 경우 사용자의 상태를 스탠드
	else if (nowCard == "10" || nowCard == "A")
	{
		hit = false;
		stand = true;
		//burst = false;
	}
}