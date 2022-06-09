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
	int j = 0;
	int score = 0;
	// 구조체 Card의 포인터 주소를 저장하는 포인터 변수
	struct Card playerDeck[7];

	bool stand = false;
	bool hit = false;
	bool burst = false;

	void scoreCalc(); // 점수 계산, 자동 스탠드, 버스트
	string select(string status, CardDeck* cd); // dealer용 인터페이스. status = "HIT" or "STAND".
public:
	void getCard(struct Card c); // 패 받을 때마다 점수 계산, 버스트 판정 필요 - 서석환 파트?
	void printCard(); // 플레이어가 뽑은 카드를 출력해주는 함수
	void printScore(); // 플레이어의 누적점수를 출력해주는 함수
	int getScore();
	string endGame(); // STAND, BURST, BLACK JACK 일경우 게임을 종료해주는 함수
	string select(); // HIT할지 STAND 할지 결정하는 함수 - HIT일 시 true 리턴, STAND일 시 false 리턴
	string status(); // "stand" "hit" "burst" string 값 리턴 - 딜러용
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