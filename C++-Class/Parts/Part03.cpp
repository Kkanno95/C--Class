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