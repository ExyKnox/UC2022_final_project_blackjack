#include <iostream>
#include "CardDeck.h"
#include "Dealer.h"

using namespace std;

void Dealer::decision(CardDeck* cd) {
	// https://xn--c79a67g3zy6dt4w.com/%EB%B8%94%EB%9E%99%EC%9E%AD-%EC%A0%84%EB%9E%B5/
	scoreCalc();
	if (burst) {
		cout << "딜러 버스트" << endl;
		return;
	}
	else {
		// 딜러 알고리즘 작성
		/*
		*ex) select("HIT", cd);
		*    select("STAND", cd);
		*/
	}
}

