#include <iostream>
#include <string>
using namespace std;


/* Агрегація та композиція

Агрегація - дозволяє використовувати той клас, який ми включаємо в інший клас у різних місцях;

Композиція - не дозволяє, тобто є більш строгим включенням одного класу в інший;

*/

/* Агрегація */

class Cap
{
public:
	string GetColor()
	{
		return color;
	}
	
private:
	string color = "red";  

};

class Model
{
public:
	void InspectModel()
	{
		cout << "Cap is " << cap.GetColor() << endl;
	}
	
private:
	Cap cap;
};

/* Композиція */
//class Human
//{
//public:
//	void Think()
//	{
//		brain.Think();    
//	}
//
//	void InspectTheCap()
//	{
//		cout << "My cap is " << cap.GetColor() << endl;
//	}
//
//private:
//
//	class Brain
//	{
//	public:
//		void Think()
//		{
//			cout << "I'm thinking!" << endl;
//		}
//	};
//
//	Brain brain;
//	Cap cap;
//	 
//};

class User 
{
public:

	int age;
	int weight;
	string name;

	void Print()
	{
		cout << "Name: " << name << "\nWeight: " << weight << "\nAge: " << age << endl;
	}

}; 

class Point
{
private:

	int x;
	int y;

public:

	Point()
	{
		x = 0;
		y = 0;
	}

	
	Point(int ValueX, int ValueY)
	{
		this->x = ValueX;
		this->y = ValueY;
	}
	
	// Перегрузка оператора "==" та "!="

	bool operator == (const Point &other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point &other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	// Перегрузка оператора "+"

	Point operator +(const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	// Перегрузка оператора "інкремента" у префіксній формі

	Point& operator ++()
	{
		this->x++;
		this->y += 1;

		return *this;
	}

	// Перегрузка оператора "інкремента" у постфіксній формі

	Point& operator ++(int value)
	{
		Point temp(*this);

		this->x++;
		this->y++;

		return temp;
	}

	// Перегрузка оператора "інкремента" у префіксній формі

	Point& operator --()
	{
		this->x--;
		this->y--;

		return *this;
	}

	// Перегрузка оператора "декремента" у постфіксній формі

	Point& operator --(int value)
	{
		Point temp(*this);

		this->x--;
		this->y--;

		return temp;
	}

	friend void ChangeX(Point& value);
	
	int GetX()
	{
		return x;
	}

	void SetX(int valueX)
	{
		this->x = valueX;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int valueY)
	{
		this->y = valueY;
	}

	string Print()
	{
		return "X: " + to_string(x) + "  Y: " + to_string(y);
	}
	
};

class CoffeeGrinder
{
private:

	bool CheckVoltage()
	{
		return true;
	}

public:
	void Start()
	{
		if (CheckVoltage())
		{
			cout << "Go!" << endl;
		}
		else
		{
			cout << "Beep Beep!" << endl;
		}
	}
}; 

class Image
{
public:

	void GetImageInfo()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			cout << pixels[i].GetInfo() << endl;
		}

	}

private:

	class Pixel 
	{
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		 
		string GetInfo()
		{
			return "Pixel: r= " + to_string(r) + " g= " + to_string(g) + " b= " + to_string(b);
		}
	private:

		int r;
		int g;
		int b;

	};

	static const int LENGTH = 5;

	Pixel pixels[LENGTH]
	{
		Pixel(0, 4, 64),
		Pixel(4, 14, 10),
		Pixel(111, 4, 24),
		Pixel(244, 244, 14),
		Pixel(111, 179, 64) 
	};

};

class MyClass
{
private:
	int *data;
	int size;

public:
	MyClass(int size);
	MyClass(const MyClass& other);
	MyClass &operator = (const MyClass& other);
	~MyClass();

};

MyClass::MyClass(int size)
{
	this->size = size;
	this->data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = i;
	}
	cout << "Constructor is called! " << this << endl;
}

// Конструктор копіювання

MyClass::MyClass(const MyClass& other)
{
	cout << "Constructor of copy is called! " << this << endl;
	this->size = other.size;

	this->data = new int[other.size];

	for (int i = 0; i < other.size; i++)
	{
		this->data[i] = other.data[i];
	}
}

// Перегрузка оператора "=" 

MyClass& MyClass:: operator = (const MyClass& other)
{
	cout << "Operator = is called! " << this << endl;
	this->size = other.size;

	if (this->data != nullptr)
	{
		delete[] this->data;
	}

	this->data = new int[other.size];

	for (int i = 0; i < other.size; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
}

MyClass::~MyClass()
{
	cout << "Distructor is called! " << this << endl;
	delete[] data; 
}

void Foo(MyClass value)
{
	cout << "Function Foo was called!" << endl;
}

MyClass Foo2()
{
	cout << "Function Foo_2 was called!" << endl;
	MyClass temp(2);

	return temp;
}


// Перегрузка оператора "[]"

class TestClass
{
public:

	int& operator[] (int index)
	{
		return arr[index];
	}

private:
	int arr[5] {5, 44, 4, 987, 69};
};


// friend function 


void ChangeX(Point& value)
{
	value.x = -1;
}




/* Успадкування */

class Human
{
private:
	string name;
public:
	string GetName()
	{
		return name;
	}

	void SetName(string name)
	{
		this->name = name;
	}
};

class Student : public Human   
{
public:
	string group;
	void Study()
	{     
		cout << "I'm studying!" << endl;
	}
};

class ExtramuralStudent : public Student
{
public:
	void Study()
	{
		cout << "I'm studying less than ordinary student!" << endl;
	}
};

class Professor : public Human
{
public:
	string subject;
};



/* Модифікатори доступа */

//class A
//{
//public:
//	string msgOne = "Message one";
//	void PrintMsg2()
//	{
//		cout << this->msgTwo << endl;
//	}
//
//private:
//	string msgTwo = "Message two";
//
//protected:
//	string msgThree = "Message three";
//};
//
//class B : protected A
//{
//public:
//	
//	void PrintMsg()
//	{
//		cout << msgOne << endl;
//		this->PrintMsg2();
//		cout << msgThree << endl;
//	}
//};


/* Порядок виклику конструкторів при успадкуванні */

class A
{
public:
	A()
	{
		msg = "Empty message";
		/*cout << "Constructor A is called!" << endl;*/
	}

	A(string msg)
	{
		this->msg = msg;
	}

	void PrintMsg()
	{
		cout << msg << endl;
	}
	
private:
	string msg;
};

class B : public A
{
public:
	B() : A("new message")
	{
		/*cout << "Constructor B is called!" << endl;*/
	}
	
};

//class C : public B
//{
//public:
//	C()
//	{
//		cout << "Constructor C is called!" << endl;
//	}
//	~C()
//	{
//		cout << "Destructor C is called!" << endl;
//	}
//};


/*
* Поліморфізм
* Віртуальні функції
* virtual
* override
*/

/*
* Абстрактні класи
* Чисто віртуальні функції
* virtual
* override
*/


class Weapon
{
public:
	virtual void Shoot() = 0;
};

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};

class SubmachineGun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class ShotGun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG! BANG! BANG! BANG! BANG!" << endl;
	}
};

class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH!" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon *weapon)
	{
		weapon->Shoot();
	}
};


/*
* Віртуальний деструктор
*/

class Temp1
{
public:
	Temp1()
	{
		cout << "Constructor Temp1 is called!" << endl;
	}
	virtual ~Temp1()
	{
		cout << "Destructor Temp1 is called!" << endl;
	}

};


class Temp2 : public Temp1
{
public:
	Temp2()
	{
		cout << "Constructor Temp2 is called!" << endl;
	}
	~Temp2() override
	{
		cout << "Destructor Temp2 is called!" << endl;
	}

};


class Person
{
public:
	Person(string Name)
	{
		this->Name = Name;
		this->Age = 0;
		this->Weight = 0;
	}

	Person(string Name, int Age) : Person(Name)
	{
		this->Age = Age;
	}

	Person(string Name, int Age, int Weight) : Person(Name, Age)
	{
		this->Weight = Weight;
	}

	string Name;
	int Age;
	int Weight;
};

int main()
{  
	/*Person Second();*/

	/*Person First("Oleg", 18, 82);*/


	/*Temp1* temp1ptr = new Temp2;
	
	delete temp1ptr;*/


	/*ShotGun shotgun;
	Knife knife;
	Player player;
	player.Shoot(&knife);*/


	/*Gun gun;
	SubmachineGun machinegun;
	ShotGun shotgun;

	Player player;
	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&shotgun);*/

	// Gun* weapon = &gun;
	// Gun *weapon = &machinegun;

	// weapon->Shoot();

	/*SubmachineGun A;

	A.Shoot();*/

	/*Gun gun;
	gun.Shoot();*/



	/*B value;
	value.PrintMsg();  */

	/*B b;
	b.PrintMsg();*/

	/*ExtramuralStudent ex;

	ex.Study();

	ex.SetName("Sergiy");

	ex.group = "PMP-21";

	cout << ex.GetName() << endl;
	cout << ex.group << endl;*/


	/*Model m;
	m.InspectModel();*/

	/*Human human;
	human.Think();
	human.InspectTheCap();*/

	/*TestClass a;

	cout << a[1] << endl;*/


	/*Point a(1, 1);
	Point b = a++;
	cout << a.Print() << endl;
	cout << b.Print() << endl;*/
	
	
	/*Point a;
	++a;
	Point b = a;
	cout << b.Print() << endl;*/



	/*Point a(5, 1);
	Point b(6, 1);
	Point res = a + b;*/

	/*bool res = a != b;

	cout << res << endl;*/

	/*MyClass a(10);
	MyClass b(2);
	MyClass c(5);

	c = a = b;*/

	/*MyClass a(10);
	MyClass b(a);*/


	/*
	Image img;
	img.GetImageInfo();
	*/
	
	/*
	int length = 5;

	Point* arr = new Point[length];

	arr[0] = Point(2, 5);
	arr[1] = Point(5, 2);
	arr[2] = Point(34, 43);
	arr[3] = Point(54, 45);
	arr[4] = Point(543, 434);

	for (int i = 0; i < length; i++)
	{
		cout << arr[i].Print() << endl;
	}

	delete[] arr;
	*/

	return 0;
} 

