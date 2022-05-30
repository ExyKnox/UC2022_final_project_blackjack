#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

void Player::getCard(struct Card c) {
	if (stand == false and hit == false) { // STAND와 HIT를 선택하지 않은 맨처음 2장일경우 실행

		playerDeck[j] = c;

		if (playerDeck[j].index != "") {
			if (playerDeck[j].index == "J") //J,Q,K을 받았을시 10의 점수를 주고 A를 받았을시 일단 11을 주지만 플레이어가 BURST판정이 났을시 11을 1로바꿔줌
				score += 10;
			else if (playerDeck[j].index == "Q")
				score += 10;
			else if (playerDeck[j].index == "K")
				score += 10;
			else if (playerDeck[j].index == "A")
				score += 11;
			else
				score += stoi(playerDeck[j].index, 0);
		}
		printCard();
		printScore();
		j++;
	}
	else if (stand == true or burst == true) { //STAND를 눌렀거나 BURST시 최종점수를 알려준뒤 
		cout << "당신의 최종점수는"
			<< score
			<< "입니다" << endl;
	}
	else if (hit == true and stand == false) { //2장의 카드를 받은뒤 히트를 선택했을시 실행
		playerDeck[j] = c;

		if (playerDeck[j].index != "") {
			if (playerDeck[j].index == "J") //J,Q,K을 받았을시 10의 점수를 주고 A를 받았을시 일단 11을 주지만 플레이어가 BURST판정이 났을시 11을 1로바꿔줌
				score += 10;
			else if (playerDeck[j].index == "Q")
				score += 10;
			else if (playerDeck[j].index == "K")
				score += 10;
			else if (playerDeck[j].index == "A")
				score += 11;
			else
				score += stoi(playerDeck[j].index, 0);


			hit = false;
		}
		printCard();
		printScore();
		j++;
	}
}

void Player::askStatus() {

	if (score == 20) { //score가 21일시 BLACK JACK
		cout << "BLACK JACK!!" << endl;
		stand = true;
	}
	else if (score > 20) { //score가 21이 넘었을떄 BURST지만 플레이어가 A를 가지고 있을시 11로 사용했던 A를 1로 바꿔줌
		int p = 0;
		for (int h = 0; h < j; h++) {
			if (playerDeck[h].index == "K") {
				p++;
			}
		}
		if (p == 0) {
			cout << "BURST ㅠㅠ";
			burst = true;
		}
		else if (p == 1) {
			cout << "K가 포함된 BURST입니다" << endl;
			score -= 10;
			printScore();
			select();
		}
	}
	else if (score < 20) { //score가 21보다 낮을떄 플레이어가 HIT와 STAND를 선택할수 있음
		select();
	}
}
void Player::printCard() { //플레이어가 뽑은 카드를 출력해주는 함수
	cout << "당신이 뽑은 "
		<< j + 1
		<< "번째 카드는"
		<< playerDeck[j].symbol
		<< playerDeck[j].index
		<< "입니다" << endl;
}
void Player::printScore() { //플레이어의 점수를 출력해주는 함수
	cout << "당신의 점수는"
		<< score
		<< "입니다" << endl;
}
string Player::endGame() { //플레이어가 STAND를 선택했을시, BURST판정이 났을시, BLACK JACK일 경우 게임을 종료해주는 함수
	if (stand == true or burst == true)
		return "END";
	else
		return "CONTINUE";
}
void Player::select() {
	cout << "1.HIT " << "2.STAND " << endl;
	int o;
	cin >> o;
	if (o == 1) {
		hit = true;
	}
	else if (o == 2) {
		stand = true;
	}
}
