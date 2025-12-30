#pragma once

class Part04
{
public:
	Part04();
	
private:
	void Inheritance();
	void Polymorphism();
};

namespace Part04_Inheritance
{
	// 기반 클래스
	class Base
	{
	public:
		Base() : Base(1, 0.1f){};
		Base(int num, float fltNum);

		virtual ~Base();

	public:
		virtual void PrintInfo();

	private:
		int num;
		float fltNum;
	};

	// 파생 클래스
	class Derived : public Base
	{
	public:
		Derived();
		Derived(int num, float fltNum, const char* string);

		void PrintInfo() override;

		~Derived() override;

	private:
		char string[100] = "";
	};
}

namespace Part04_Polymorphism
{
	class Base
	{
	public:
		Base() { cout << "Base() 생성자 호출!\n"; };
		virtual ~Base() { cout << "~Base() 소멸자 호출!\n"; };

	public:
		virtual void ShowInfo();
	};

	class Derived : public Base
	{
	public:
		Derived() { cout << "Derived() 생성자 호출!\n"; };
		~Derived() override { cout << "~Derived() 소멸자 호출!\n"; };

	public:
		//void ShowInfo() final override;
		void ShowInfo() override;

	protected:
		virtual void DoShowInfo() = 0; // 순수 가상 함수
	};

	class SubDerived : public Derived
	{
	public:
		SubDerived() { cout << "SubDerived() 생성자 호출!\n"; };
		~SubDerived() override { cout << "~SubDerived() 소멸자 호출!\n"; };

	public:
		int GetValue() const
		{
			return val;
		};
		int GetValue() { return val; }
		void SetValue() const;

		int GetSumValue(const SubDerived& a, SubDerived& b);
		
	public:
		void DoShowInfo() override;
		void ShowInfo() override;

	private:
		int val = 0;
	};
}