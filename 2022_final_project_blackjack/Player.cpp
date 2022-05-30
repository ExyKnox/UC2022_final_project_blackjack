#include <iostream>
#include <string>
#include "CardDeck.h"
#include "Player.h"

using namespace std;

int Player::getScore() {
	return score;
}

void Player::scoreCalc() {
	if (playerDeck[j].index != "") {
		if (playerDeck[j].index == "J") //J,Q,K을 받았을시 10의 점수를 주고 A를 받았을시 일단 11을 주지만 플레이어가 BURST판정이 났을시 11을 1로바꿔줌
			score += 10;
		else if (playerDeck[j].index == "Q")
			score += 10;
		else if (playerDeck[j].index == "K")
			score += 10;
		else if (playerDeck[j].index == "A")
			// 11점 미만의 점수를 가지고 있다면 A를 11점 처리
			if (score < 11) score += 11;
		// 11점 이상의 점수를 가지고 있을 경우
			else score += 1;
		else
			score += stoi(playerDeck[j].index, 0);
	}
	j++;
	// 첫 두장 뽑는 부분 판단 사라짐
	// 작성할것

	if (score == 21) { //score가 21일시 자동 스탠드
		cout << "점수 21, 자동 스탠드" << endl;
		stand = true;
	}
	else if (score > 21) { //score가 21이 넘었을떄 BURST지만 플레이어가 A를 가지고 있을시 11로 사용했던 A를 1로 바꿔줌
		int p = 0;
		for (int h = 0; h < j; h++) {
			if (playerDeck[h].index == "A") {
				p++;
			}
		}
		if (p == 0) {
			cout << "BURST ㅠㅠ";
			burst = true;
		}
		else if (p == 1) {
			cout << "A가 포함된 BURST입니다. A를 1로 처리합니다." << endl;
			score -= 10;
			/*if (select() == true) return "HIT";
			else return "STAND";*/
		}
	}
	//else if (score < 21) { //score가 21보다 낮을떄 플레이어가 HIT와 STAND를 선택할수 있음
	//	/*if (select() == true) return "HIT";
	//	else return "STAND";*/
	//	select();
	//}
	printCard();
	printScore();
}

void Player::getCard(struct Card c) {
	// 얜 또 왜 여기있어?
	if (stand == true or burst == true) { //STAND를 눌렀거나 BURST시 최종점수를 알려준뒤 
		cout << "당신의 최종점수는"
			<< score
			<< "입니다" << endl;
	}
	else {
		playerDeck[j] = c;
		scoreCalc();
	}
}

//string Player::askStatus() {
//
//	//if (score == 21) { //score가 21일시 자동 스탠드
//	//	cout << "점수 21, 자동 스탠드" << endl;
//	//	stand = true;
//	//}
//	//else if (score > 21) { //score가 21이 넘었을떄 BURST지만 플레이어가 A를 가지고 있을시 11로 사용했던 A를 1로 바꿔줌
//	//	int p = 0;
//	//	for (int h = 0; h < j; h++) {
//	//		if (playerDeck[h].index == "A") {
//	//			p++;
//	//		}
//	//	}
//	//	if (p == 0) {
//	//		cout << "BURST ㅠㅠ";
//	//		burst = true;
//	//	}
//	//	else if (p == 1) {
//	//		cout << "A가 포함된 BURST입니다. A를 1로 처리합니다." << endl;
//	//		score -= 10;
//	//		printScore();
//	//		/*if (select() == true) return "HIT";
//	//		else return "STAND";*/
//	//	}
//	//}
//	//else if (score < 21) { //score가 21보다 낮을떄 플레이어가 HIT와 STAND를 선택할수 있음
//	//	/*if (select() == true) return "HIT";
//	//	else return "STAND";*/
//	//	select();
//	//}
//	//select();
//
//
//}

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
	else if(status == "HIT") {
		getCard(cd->popCard());
		return "HIT";
	}
}