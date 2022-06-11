#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

/*
페어란 에이스부터 9까지 숫자가 같은 카드 두 장이나 10점짜리 카드 두 장(예를 들어 10 카드와 퀸)을 의미합니다.
*/

//void Dealer::fair_play_strategy() {
//
//	// 딜러 카드안의 index로 판별.
//	string nowCard = playerDeck[j].index;
//	// 딜러 카드가 2에서 9 사이일때 히트
//	// 딜러 카드가 2에서 6사이 일 때 히트
//	// 딜러카드가 2에서 7 사이 일때 히트
//	// 2에서 7사이일 경우 hit
//
//	// 페어 판단 코드 필요
//
//	// 여기서 select(string status, CardDeck* cd) 사용해서
//	// 카드까지 한번에 가져오기? 아니면 main 함수에서 status() 사용해서 getCard()?
//	// 후자 쪽이 더 좋은 방법이긴 할 것 같다.
//
//	// 딜러 카드가 2에서 9 사이일때 히트
//	//딜러 카드가 2에서 9 사이일때 사용자의 상태를 히트로
//	if (2 <= stoi(nowCard) && stoi(nowCard) <= 9)
//	{
//		hit = true;
//		stand = false;
//		//burst = false;
//	}
//	// 딜러카드가 7, 10, or 에이스 일 경우 스탠드 
//	//딜러 카드가 10 혹은 에이스 일 경우 사용자의 상태를 스탠드
//	else if (nowCard == "7" || nowCard == "10" || nowCard == "A")
//	{
//		hit = false;
//		stand = true;
//		//burst = false;
//	}
//
//	// 딜러 판단 끝
//	// main()에서 status() 사용 후 히트일 시 select(string status, CardDeck* cd) 사용
//}

// 소프트 핸드(A = 11)? 하드 핸드(A = 1 or A가 없음)?
void Dealer::decision() {
	// 먼저 소프트/하드 핸드 여부 판독
	bool isSoft = false;
	for (int i = 0; i < j-1; i++) {
		if (playerDeck[i].index == "A") {
			if ((score - 1) + 11 > 21) {
				// A를 11로 처리했을 때 버스트라면 A = 1
				// 따라서 A가 있는 하드 핸드
				isSoft = false;
			}
			else {
				// A를 11로 처리했을 때 버스트가 아니므로 A = 11
				// 따라서 A가 있는 소프트 핸드
				isSoft = true;
			}
		}
	}

	// A가 없으면 isSoft = false -> A 없는 하드 핸드

	/*
	* [종류 점수]
	*
	* [하드 11] 이하 히트
	* [하드 17] 이상 스탠드
	* [하드 12 ~ 하드 16] 히트 - 버스트 할 확률이 상대적으로 낮음
	*
	* [소프트 19 or 20] 스탠드
	* [소프트 18] 스탠드
	* [소프트 17] 히트
	* [소프트 16] 히트(승률은 좀 낮음)
	* [소프트 13 or 14] 히트
	*/

	if (isSoft) {
		// 소프트 패일 때
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
		// 하드 패일 때
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