#pragma once

#include <string>
#include "CardDeck.h"

using namespace std;

/*
* "블랙잭 플레이어" 클래스 Player.
*
* -플레이어가 가질 수 있는 상태 혹은 행동
* 스탠드(카드를 더 이상 가져오지 않음)
* 히트(카드를 한 장 더 가져옴)
* 버스트(플레이어 패의 카드 총합이 21을 초과, 게임오버)
* 
* 플레이어는 자신의 패를 가지고 있음
*/

class Player
{
	// 구조체 Card의 포인터 주소를 저장하는 포인터 변수
	struct Card* playerDeck[6];
};

