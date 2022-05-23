#pragma once

#include <string>
#include "CardDeck.h"

using namespace std;

/*
* "블랙잭 플레이어" 클래스 Player.
*
* -플레이어가 가질 수 있는 상태 혹은 행동
* 스탠드(카드를 더 이상 가져오지 않음)
* ㄴ 블랙잭 처음 뽑아온 패의 점수가 21
* 히트(카드를 한 장 더 가져옴)
* 버스트(플레이어 패의 카드 총합이 21을 초과, 게임오버)
* 
* 플레이어는 자신의 패를 가지고 있음
*/

class Player
{
protected:
	// 구조체 Card의 포인터 주소를 저장하는 포인터 변수
	struct Card* playerDeck[6];
	bool stand, hit, burst;
public:
	Player();
	void getCard(struct Card* c); // 패 받을 때마다 점수 계산, 버스트 판정 필요 - 서석환 파트?
	void askStatus(); // 플레이어(사람)에게 히트, 스탠드 여부를 물어보는 함수
	string status(); // "stand", "hit", "burst" string 리턴
};

/* 점수판단
	* 숫자 혹은 J, Q, K
	* ->stoi() 먼저 돌리고->숫자가 아니면(AJQK) 0를 리턴할 것임
	* ->숫자면
	* stoi()가 리턴한 숫자를 점수로 처리
	* ->숫자가 아니면
	* A면 1 혹은 11, J Q K 이라면 10점 처리
*/

//playerDeck[0] = testDeck.getCard();
// 카드 번호 불러오기는 이렇게
//cout << playerDeck[0].index << endl;