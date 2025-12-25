#pragma once

extern "C"
{
	//int AllAdd(int a, int b);
	//int AllAdd(int a, int b, int c);
}

// 함수의 오버로딩
// 개념 : 같은 이름의 함수가 여러개 존재함이 가능한 개념.
// 같은 이름의 함수를 구별하는 방식에서 네임 맹글링 개념이 등장하게 된다.
// GetSumValue 함수의 이름 실제로 GetSumValue로 정해짐.
// GetSumValue 함수의 이름 GetSumValue + 매개변수로 정해짐.

//GetSumValueii
//GetSumValueiii

/*
// CPU 파이프라인
5단계
IF		Instruction Fetch		PC로 부터 명령어 가져와
ID		Instruction Decde		명령어 해석, 레지스터 읽기
EX		Execute					연산, 분기 조건 계산
MEM		Memory					load/store
WB		Write Back				기록
*/

class Part02
{
public:
	Part02();

private:
	void OverLoading();
	void Reference();

private:
	int GetSumValue(int a, int b);
	int GetSumValue(int a, int b, int c);
	//int GetAvr(int a, int b) { return (a + b) / 2.0f; } // 반환형의 차이로는 구별이 안됨.
	float GetAvr(int a, int b) { return (a + b) / 2.0f; }
	float GetAvr(int a, int b, int c) { return (a + b + c) / 3.0f; }
};
