#include "stdafx.h"
#include "Part03.h"

Part03::Part03()
{
	Class();
}

void Part03::Class()
{
	Player player1 = { 1, 0, 0 };
	Player player2(Player()); // 복사 생성자

	player1.GetHP();
}

Player& Player::operator=(const Player& other)
{
	hp = other.hp;
	atk = other.atk;

	SAFE_DELETE(this->ptr);
	SAFE_DELETE_ARRAY(this->arr);

	ptr = new int(*other.ptr);
	arr = new int[5];
	memcpy(arr, other.arr, sizeof(arr[0]) * 5);

	cout << "복사 할당 연산자 호출!\n";

	return *this;
}
