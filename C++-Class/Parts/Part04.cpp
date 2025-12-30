#include "stdafx.h"
#include "Part04.h"

Part04::Part04()
{
	//Inheritance();
	Polymorphism();
}

void Part04::Inheritance()
{
	using namespace Part04_Inheritance;

	Base base(10, 3.14f);
	cout << '\n';
	base.PrintInfo();
	cout << '\n';

	Derived derived;
	cout << '\n';
	derived.PrintInfo();
	cout << '\n';

	// 업캐스팅
	// 파생 클래스를 기반 클래스에 맞춰 형변환 하는 것. (묵시적 형변환)
	// 왜 이렇게 쓰냐? 다형서에 희해서
	Base* basePtr = (Base*)new Derived(10, 3.14f, "Hello, World!");
	cout << '\n';
	basePtr->PrintInfo();
	cout << '\n';

	SAFE_DELETE(basePtr);

	cout << '\n';
}

void Part04::Polymorphism()
{
	using namespace Part04_Polymorphism;

	Base* base1 = new Base(); // 업캐스팅
	cout << '\n';
	Base* base2 = static_cast<Base*>(new SubDerived()); // Up-Casting
	cout << '\n';

	Derived* derived1 = new SubDerived(); // Up-Casting
	cout << '\n';

	Derived* derived2 = dynamic_cast<Derived*>(base2); // 다운캐스팅
	assert(derived2 != nullptr);

	cout << typeid(*base1).name() << endl;
	cout << typeid(*base2).name() << endl << endl;

	base1->ShowInfo();
	cout << '\n';
	base2->ShowInfo();
	cout << '\n';
	derived1->ShowInfo();
	cout << '\n';
	derived2->ShowInfo();
	cout << '\n';

	cout << "===== 상수 멤버 함수 호출 결과 ====\n";
	dynamic_cast<SubDerived*>(derived1)->SetValue();
	cout << "Value : " << dynamic_cast<SubDerived*>(derived1)->GetValue() << "\n\n";

	SAFE_DELETE(derived1);
	cout << '\n';
	SAFE_DELETE(base2);
	cout << '\n';
	SAFE_DELETE(base1);
	cout << '\n';
}

namespace Part04_Inheritance
{
	Base::Base(int num, float fltNum)
		: num(num)
		, fltNum(fltNum)
	{
		cout << "Base(int, float) 생성자 호출!\n";
	}

	Base::~Base()
	{
		cout << "~Base() 소멸자 호출!\n";
	}

	void Base::PrintInfo()
	{
		cout << "===== 기반 객체 정보 =====\n";
		cout << "Int : " << num << '\n';
		cout << "Float : " << fltNum << '\n';
	}

	Derived::Derived()
		: Derived(0, 0.0f, "")
	{
		cout << "Derived() 생성자 호출!\n";
	}

	Derived::Derived(int num, float fltNum, const char* string)
		: Base(num, fltNum)
	{
		strcpy(this->string, string);
		cout << "Derived(int, float, const char*) 생성자 호출!\n";
	}

	void Derived::PrintInfo()
	{
		Base::PrintInfo();
		cout << "===== 파생 객체 정보 =====\n";
		cout << "String : " << string << '\n';
	}

	Derived::~Derived()
	{
		cout << "~Derived() 소멸자 호출!\n";
	}
}

namespace Part04_Polymorphism
{
	void Base::ShowInfo()
	{
		cout << "Base::ShowInfo() 호출!\n";
	}

	void Derived::ShowInfo()
	{
		this->DoShowInfo();
		cout << "Derived::ShowInfo() 호출!\n";
	}

	void SubDerived::SetValue() const
	{
		const_cast<SubDerived*>(this)->val = 10;
	}

	int SubDerived::GetSumValue(const SubDerived& a, SubDerived& b)
	{
		return a.GetValue() + b.GetValue();
	}

	void SubDerived::ShowInfo()
	{
		cout << "SubDerived::ShowInfo() 호출!\n";
	}

	void SubDerived::DoShowInfo()
	{
		cout << "SubDerived::DoShowInfo() 호출!\n";
	}
}