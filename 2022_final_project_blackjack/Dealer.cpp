#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
페어란 에이스부터 9까지 숫자가 같은 카드 두 장이나 10점짜리 카드 두 장(예를 들어 10 카드와 퀸)을 의미합니다.
*/
void Dealer::decision() {

	// 딜러 카드안의 index로 판별.
	string nowCard = playerDeck[j].index;
	// 딜러 카드가 2에서 9 사이일때 히트
	// 딜러 카드가 2에서 6사이 일 때 히트
	// 딜러카드가 2에서 7 사이 일때 히트
	// 2에서 7사이일 경우 hit
	if ("2" <= nowCard && nowCard <= "9")
	{
		hit = true;

		stand = false;
		burst = false;
	}
	// 딜러카드가 7, 10, or 에이스 일 경우 스탠드 
	else if (nowCard == "7" || nowCard == "10" || nowCard == "A")
	{
		stand = true;

		hit = false;
		burst = false;
	}
}