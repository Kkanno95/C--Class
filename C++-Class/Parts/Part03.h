#pragma once

// struct == class
// C : struct
// C++ : class

class Part03
{
public:
	Part03();
	
private:
	void Class();
};

class Player
{
public:
	// 기본 생성자
	Player() : Player(1, 0, 0) { cout << "기본 생성자 호출!\n"; }
	// 생성자 오버로딩
	Player(int id, int hp, int atk) // 이니셜라이져
		: id(id), hp(hp), atk(atk)
	{
		ptr = new int(5);
		arr = new int[5];
	}

	// 복사 생성자
	Player(const Player& other)
		: id(other.id), hp(other.hp), atk(other.atk)
	{

	}

	// 대입 연산자(연산자 오버로딩)
	Player& operator=(const Player& other);

	Player(Player&& other) noexcept
		: id(other.id), hp(other.hp), atk(other.atk)
	{

	}

	// 소멸자
	~Player() 
	{
		SAFE_DELETE(ptr);
		SAFE_DELETE_ARRAY(ptr);
	};

public:
	int GetHP() { HPReadCount++; return this->hp; } const
	void SetHP(int hp) { this->hp = hp; }

private:
	int hp = 0;
	int atk = 0;

	const int id;
	mutable int HPReadCount = 0;

	int* ptr = nullptr;
	int* arr = nullptr;
};
