#include "stdafx.h"
#include "Part01.h"

Part01::Part01()
{
	//IOStream();
	//OutputStream();
	InputStream();
}

void Part01::IOStream()
{
	std::cout << "Hello, World!\n" << std::endl;
	
	std::cout << "Int : " << num << ", Float : " << fltNum << '\n';
	
	std::cout << "\n데이터 입력(정수) : ";
	std::cin >> num;

	std::cout << '\n' << num << " * " << num << " = " << num * num;
}

void Part01::OutputStream()
{
	std::cout.width(18); // 출력칸 설정
	std::cout.fill('='); // 빈 공간을 뭘로 채울지 결정
	std::cout << " 자릿수 ";
	std::cout.width(11);
	std::cout << '\n';

	std::cout.precision(3);

	std::cout << "fltNum : " << fltNum << '\n';
}

void Part01::InputStream()
{
	std::cout << "정수 입력 : ";
	std::cin >> num;
	std::cout << "결과 : " << num << '\n';


	std::cout << "실수 입력 : ";
	std::cin >> fltNum;
	std::cout << "결과 : " << fltNum << '\n';
	std::cin.get();

	char string[100] = "";
	std::cout << "\n문자열 입력 : ";
	//std::cin >> string;
	std::cin.getline(string, sizeof(string));
	std::cout << string;
}
