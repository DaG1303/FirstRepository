#include <iostream>
#include<string>

using namespace std;

class Point
{
private:

	int x;
	int y;

public:

	bool operator == (const Point & other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	Point operator =(const Point& other)
	{
		Point temp;
		temp.x = this->x = other.x;
		temp.y = this->y = other.y;
		return temp;
	}


	Point()
	{
		x = 0;
		y = 0;
		cout << this << " constructor" << endl;
	}

	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
		cout << this << " constructor" << endl;
	}

	Point(int valueX, bool boolean)
	{
		x = valueX;
		if (boolean)
		{
			y = 1;
		}
		else
		{
			y = -1;
		}
	}

	int GetY()
	{
		return y;
	}

	void SetY(int y)
	{
		this->y = y;
	}

	int GetX()
	{
		return x;
	}

	void SetX(int valueX)
	{
		x = valueX;
	}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

class Human 
{
public:

	int age;
	int weight;
	string name;

	void Print()
	{
		cout << "Имя " << name << "\nРост " << weight << "\nВозраст " << age << endl << endl;
	}
};

class CoffieGrinder
{
private:

	bool CheckVoltage()
	{
		return false;
	}

public:
	void Start()
	{
		if (CheckVoltage())
		{
			cout << "VjUUUUh!!!" << endl;
		}
		else
		{
			cout << "BEEEEEEEP" << endl;
		}
	}
};

class MyClass
{
	int* data;
	int size;
public:



	MyClass(int size)
	{
		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}

		cout << "Вызвался конструктор " << this << endl;
	}




	MyClass(const MyClass& other)
	{		
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Вызвался конструктор копирования " << this << endl;
	}




	MyClass& operator = (const MyClass& other)
	{
		cout << "Вызвался оператор ( = ) " << this << endl;

		this->size = size;

		if (this->data!=nullptr)
		{
			delete this->data;

		}

		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		return *this;
	}





	~MyClass()
	{
		cout << "Вызвался деструктор " << this << endl;
		delete[] data;
	}
};

void Foo(MyClass value)
{
	cout << "Вызвалась функция Foo" << endl;
}

MyClass Foo2()
{
	cout << "Вызвалась функция Foo 2" << endl;
	MyClass temp(2);

	return temp;
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	Point a(6, 5);
	Point b(13, 9);
	a = b;

	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	a = b;

	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}

	
	return 0;
}