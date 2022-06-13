#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"

using namespace std;

Player::Player() {
	name = "플레이어";
}

int Player::getScore() {
	return score;
}

void Player::scoreCalc() {
	if (playerDeck[j-1].index != "") {
		if (playerDeck[j-1].index == "J") //J,Q,K을 받았을시 10의 점수를 주고 A를 받았을시 일단 11을 주지만 플레이어가 BURST판정이 났을시 11을 1로바꿔줌
			score += 10;
		else if (playerDeck[j-1].index == "Q")
			score += 10;
		else if (playerDeck[j-1].index == "K")
			score += 10;
		else if (playerDeck[j-1].index == "A")
			// 11점 미만의 점수를 가지고 있다면 A를 11점 처리
			if (score < 11) score += 11;
		// 11점 이상의 점수를 가지고 있을 경우
			else score += 1;
		else
			score += stoi(playerDeck[j-1].index, 0);
	}

	if (score == 21) { //score가 21일시 자동 스탠드
		cout << "점수 21, 자동 스탠드" << endl;
		stand = true;
	}
	else if (score > 21) { //score가 21이 넘었을떄 BURST지만 플레이어가 A를 가지고 있을시 11로 사용했던 A를 1로 바꿔줌
		int p = 0;
		for (int h = 0; h < j-1; h++) {
			if (playerDeck[h].index == "A") {
				p++;
			}
		}
		if (p == 0) {
			cout << name << "의";
			cout << "BURST ㅠㅠ" << endl;
			burst = true;
		}
		else if (p == 1) {
			cout << name << "의";
			cout << "A가 포함된 BURST입니다. A를 1로 처리합니다." << endl;
			score -= 10;
		}
	}
	printCard();
	printScore();
}

void Player::getCard(struct Card c) {
	if (stand == true or burst == true) return;
	else {
		playerDeck[j] = c;
		//cout << j << endl;
		j++;
		scoreCalc();
	}
}

void Player::printCard() { //플레이어가 뽑은 카드를 출력해주는 함수
	cout << name
		<< "이 뽑은 "
		<< j
		<< "번째 카드는"
		<< playerDeck[j-1].symbol
		<< playerDeck[j-1].index
		<< "입니다" << endl;
}

void Player::printScore() { //플레이어의 점수를 출력해주는 함수
	cout << name
		<< "의 점수는"
		<< score
		<< "입니다" << endl;
}

string Player::endGame() { //플레이어가 STAND를 선택했을시, BURST판정이 났을시, BLACK JACK일 경우 게임을 종료해주는 함수
	if (stand == true or burst == true)
	{
		//STAND를 눌렀거나 BURST시 최종점수를 알려준뒤 
		cout << name
			<< "의 최종점수는"
			<< score
			<< "입니다" << endl;
		return "END";
	}
	else return "CONTINUE";
}

string Player::select() {
	cout << "1.HIT " << "2.STAND " << endl;
	int o;
	cin >> o;
	if (o == 1) {
		//getCard();
		// HIT 선택
		return "HIT";
	}
	else if (o == 2) {
		stand = true;
		// STAND 선택
		return "STAND";
	}
}

string Player::select(string status, CardDeck* cd) {
	if (status == "STAND") {
		stand = true;
		return "STAND";
	}
	else if (status == "HIT") {
		getCard(cd->popCard());
		return "HIT";
	}
}

string Player::status() {
	string returnStr;
	if (burst) returnStr = "BURST";
	else if (stand) returnStr = "STAND";
	else if (hit) returnStr = "HIT";

	return returnStr;
}