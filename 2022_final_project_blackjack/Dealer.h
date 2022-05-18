#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

/*
* "블랙잭 딜러" 클래스 Dealer.
* Player 클래스를 상속받음
* -> private) struct card playerDeck, bool stand, hit, burst
* -> getCard(), askStatus(), status()
* 
* -딜러가 따로 가져야 할 행동
* 스탠드, 히트, 버스트 자동 판단
*/

class Dealer : public Player {

public:


};
