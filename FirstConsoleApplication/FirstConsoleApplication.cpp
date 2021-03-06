// FirstConsoleApplication.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;
using std::setw;

int support_count;
extern void write_extern();

int changeNum(int);
double getAverage(int arr[], int size);
void mtlDouble(int *num);
int *getRandom();
void swap(int &x, int &y);
double & setValues(int i);
void printBook(struct Books book);
void printBookByPoint(struct Books *book);


double vals[] = { 11.1, 12.1, 13.1, 14.1, 15.1, 16.1 };

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

typedef struct newBooks
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} newBooks;

class Box
{
	double printWidth;
public:
	double length;
	double breadth;
	double height;
	double getVolume(void);
	void setLength(double length);
	void setBreadth(double breadth);
	void setHeight(double height);
	double getArea(void)
	{
		return length * breadth;
	}
	friend void printBoxWidth(Box box);
	void setPrintWidth(double wid);

	double Volume()
	{
		return length * breadth * height;
	}

	int compare(Box box)
	{
		return this->Volume() > box.Volume();
	}

protected:
	double width;

};

//void Box::setWidth(double wid)
//{
//	width = wid;
//}

void Box::setPrintWidth(double wid)
{
	printWidth = wid;
}

void printBoxWidth(Box box)
{
	cout << "width of box = " << box.printWidth << endl;
}

class Line
{
public:
	int a, b, c, d, e;
	Line(int a, int b, int c, int d, int e);//构造函数
	~Line(); //析构函数
};

Line::Line(int a, int b, int c, int d, int e) :a(a), b(b), c(c), d(d), e(e)//使用初始化列表来初始化参数，字段名和参数名可以相同，不用this来区分
{
	cout << "Line is being created " << endl;
}

Line::~Line()
{
	cout << "Line is being deleted" << endl;
}

class newLine
{
public:
	int getLength(void);
	newLine(int len);
	newLine(const newLine &obj);
	~newLine();

private:
	int *ptr;
};

newLine::newLine(int len)
{
	cout << "newLine is being created" << endl;
	ptr = new int; // 为指针分配内存;
	*ptr = len;
}

newLine::newLine(const newLine &obj)
{
	cout << "newLine is being created by copy " << endl;
	ptr = new int; // 为指针分配内存
	*ptr = *obj.ptr;  // 将obj中的ptr值赋值给*ptr，两者值相同指向地址不同
}

newLine::~newLine()
{
	cout << "newLine is being deleted " << endl;
	delete ptr;
}

int newLine::getLength()
{
	return *ptr;
}

void display(newLine obj); // 函数声明中使用到了newLine类，需要把函数声明放在newLine类的后面，否则会报错

class SmallBox :Box
{
public:
	void setSmallWidth(double wid)
	{
		width = wid;
	}
	double getSmallWidth(void)
	{
		return width;
	}
};

double Box::getVolume(void)
{
	return length * breadth*height;
}

void Box::setLength(double length)
{
	this->length = length;//传参和变量名相同时必须使用this
}

void Box::setBreadth(double breadth)
{
	this->breadth = breadth;
}

void Box::setHeight(double height)
{
	this->height = height;
}

//内联函数，在函数的定义出添加inline前缀称为内联函数。
//内联函数针对行数不多又频繁调用的函数在编译时将所有函数调用处用函数体替换，
//减少了函数调用的时间消耗，使代码运行更加高效
//另外在类定义中的函数都是内联函数，即使它没有inline关键字修饰。
//修改了内联函数必须要重新编译
inline int Max(int x, int y)
{
	return (x > y) ? x : y;
}

class BoxPoint
{
public:
	static int objectCount;
	BoxPoint(double l, double b, double h );
	~BoxPoint();
	double Volume();
	static int getCount()
	{
		//静态成员函数没有this指针，只能访问静态成员
		//普通成员函数有this指针，可以访问类中的任意成员；而静态成员函数没有this指针
		return objectCount;
	}

private:
	double length;
	double breadth;
	double height;
};

BoxPoint::BoxPoint(double l = 2.0, double b = 2.0, double h = 2.0)
{
	cout << " BoxPoint Constructor called." << endl;
	this->length = l;
	this->breadth = b;
	this->height = h;
	this->objectCount++;
}

BoxPoint::~BoxPoint() 
{
	
}


double BoxPoint::Volume()
{
	return length * breadth * height;
}

int BoxPoint::objectCount = 0;

int main()
{
	cout << "hello world!\n";
	/*
	cout << "hello\tworld\r\n";
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
	cout << "\t最大值：" << (numeric_limits<bool>::max)();
	cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
	cout << "\t最大值：" << (numeric_limits<char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
	cout << "\t最大值：" << (numeric_limits<signed char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
	cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
	cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
	cout << "\t最大值：" << (numeric_limits<short>::max)();
	cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
	cout << "\t最大值：" << (numeric_limits<int>::max)();
	cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
	cout << "\t最大值：" << (numeric_limits<long>::max)();
	cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "double: \t" << "所占字节数：" << sizeof(double);
	cout << "\t最大值：" << (numeric_limits<double>::max)();
	cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
	cout << "\t最大值：" << (numeric_limits<long double>::max)();
	cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
	cout << "\t最大值：" << (numeric_limits<float>::max)();
	cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
	// << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
	cout << "type: \t\t" << "************size**************" << endl;
	enum { red, blue, green = 5, white} c ; // 枚举值默认后一个比前一个值大1
	c = white;
	cout << "c value = " << c << endl ;
*/

/*
	//signed unsigned
	short int i;
	unsigned short int j;
	j = 50000;
	i = j;
	cout << "i = " << i << " j = " << j << endl;

	unsigned int a = 20;
	signed int b = -130;
	cout << "a + b = " << a + b << endl;
*/

/*
	//c++存储类auto 存储类
	auto f = 3.14;
	auto s("hello");
	auto z = new auto(9);
	//auto x1 = 5, x2 = 5.0, x3 = 'r'; //错误，必须是初始化为同一类型
	cout << "f = " << f << " s = " << s << " z = " << z << endl;
*/

/*
	//extern 存储类
	support_count = 5;
	write_extern();
*/

/*
	//函数调用，（传值调用，指针调用，引用调用）
	int num = 10;
	num =changeNum(num);
	cout << "num = " << num << endl;
*/

/*
	int i, j;
	srand((unsigned)time(NULL));
	for ( i = 0; i < 10; i++)
	{
		j = rand();
		cout << "random num = " << j << endl;
	}
*/
/*
int balance[5] = { 1,4,6,44,0 };
cout << "Element" << setw(13) << "Value" << endl;
for (int i = 0; i < 5; i++)
{
	cout << setw(7) << i << setw(13) << balance[i] << endl;
}
*/

/*
	int balance[5] = { 1000,2,3,17,50 };
	double avg;
	avg = getAverage(balance, 5);
	cout << "average = " << avg << endl;
*/

/*
	string str1 = "hello";
	string str2 = "world";
	string str3;
	int len;
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	str3 = str2 + str1;
	cout << "str1 + str2 = " << str3 << endl;

	len = str3.size();
	cout << "str3.size() = " << len << endl;

	int length = str3.length();
	cout << "str3.length() = " << length << endl;
	//c++中string.size() 和 string.length()没有区别，返回的都是string的字节数
*/

/*
	//c++指针和数组
	int var[3] = { 10,100,200 };
	for (int i = 0; i < 3; i++)
	{
		*var = i; //合法操作，将var数组的第一个值重新赋值
		*(var + 2) = 500;  //将var数组的第三个元素重新赋值
		cout << "*var = " << *var;
		cout << "  first = " << var[0];
		cout << "  value = " << var[i] << endl;
	}
*/

/*
//指针数组
	int var[3] = { 10,100,200 };
	int *ptr[3];
	for (int i = 0; i < 3; i++)
	{
		ptr[i] = &var[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "value of var[" << i << "] = ";
		cout << *ptr[i] << endl;
	}
	*/
	/*
		//字符串指针数组
		const char *names[4] = { "abc","def", "ghi", "jkl"};  //这里到底是怎么存的？不知道啊！
		cout << "test : names[1] = " << names[1] << " *names[1] = " << *names[1] << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << " --- names[i]              = " << names[i] << endl;
			cout << " --- *names[i]             = " << *names[i] << endl;
			cout << endl;
			cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;
			cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;
			cout << " ------------------------------------ " << endl << endl << endl << endl;
		}
	*/

	/*
		//指向指针的指针
		int value = 100;
		int *ptr;
		int ** pptr;
		ptr = &value;
		pptr = &ptr;
		cout << "value = " << value << " *ptr = " << *ptr << " **pptr = " << **pptr << endl;
	*/

	/*
		//传递指针到函数
		int value = 100;
		int *ptr = &value;
		mtlDouble(ptr);
		cout << "*ptr = " << *ptr << endl;
	*/

	/*
		//函数返回指针
		int *p;
		p = getRandom();
		for (int i = 0; i < 10; i++)
		{
			cout << "*(p + " << i << ") : ";
			cout << *(p + i) << endl;
		}
	*/
	/*
		//创建引用
		int i;
		double d;
		int & ii = i;
		double & dd = d;
		i = 5;
		cout << "value of i = " << i << endl;
		cout << "value of i reference = " << ii << endl;
		d = 3.14;
		cout << "value of d = " << d << endl;
		cout << "value of d reference = " << dd << endl;
	*/

	/*
		//传递引用到函数
	int a = 100;
	int b = 200;
	swap(a, b);
	cout << "a = " << a << " b = " << b << endl;
	*/

	/*
		//函数返回引用
		setValues(1) = 22.2;
		setValues(3) = 33.3;
		cout << "vals[1] = " << vals[1] << " vals[3] = " << vals[3] << endl;
	*/

	/*
		//当前日期和时间
		time_t now = time(0);
		char *dt = ctime(&now);  //此处编译会报错，需要在项目--属性--配置属性--c/c++--预处理器--预处理器定义--添加_CRT_SECURE_NO_WARNINGS
		cout << "now = " << now << " dt = " << dt << endl;
	*/
	/*
		//使用结构tm格式化时间
		time_t now = time(0);
		cout << "seconds form 1970 = " << now << endl;
		tm *ltm = localtime(&now);
		cout << "year  = " << 1900 + ltm->tm_year << endl;
		cout << "month = " << 1 + ltm->tm_mon << endl;
		cout << "day   = " << ltm->tm_mday << endl;
		cout << "time  = " << ltm->tm_hour << ":";
		cout << ltm->tm_min << ":";
		cout << ltm->tm_sec << endl;
		*/

		/*
			//标准输入流
			char name[50];
			int age;
			cout << " please input your name :";
			cin >> name;
			cout << "please input your age :";
			cin >> age;
			cout << "your name is " << name << "  age is " << age << endl;
		*/

		/*
			//标准错误流
			char str[] = "unable to read ....";
			cerr << "Error message : " << str << endl;
		*/

		/*
			// 标准日志流
			char str[] = "unable to read ....";
			clog << " Error message : " << str << endl;
		*/

		/*
			//访问结构成员
			Books book1;
			Books book2;

			strcpy(book1.title, "C++ 教程");
			strcpy(book1.author, "Runoob");
			strcpy(book1.subject, "编程语言");
			book1.book_id = 12345;

			strcpy(book2.title, "css 教程");
			strcpy(book2.author, "Runoob");
			strcpy(book2.subject, "前端技术");
			book2.book_id = 54321;

			cout << "fist book title :" << book1.title << endl;
			cout << "fist book author :" << book1.author << endl;
			cout << "fist book subject :" << book1.subject << endl;
			cout << "fist book id :" << book1.book_id << endl;

			cout << endl;

			cout << "second book title :" << book2.title << endl;
			cout << "second book author :" << book2.author << endl;
			cout << "second book subject :" << book2.subject << endl;
			cout << "second book id :" << book2.book_id << endl;
		*/

		/*
			//结构体作为函数传参
			Books book1;
			Books book2;

			strcpy(book1.title, "C++ 教程");
			strcpy(book1.author, "Runoob");
			strcpy(book1.subject, "编程语言");
			book1.book_id = 12345;

			strcpy(book2.title, "css 教程");
			strcpy(book2.author, "Runoob");
			strcpy(book2.subject, "前端技术");
			book2.book_id = 54321;

			printBook(book1);
			printBook(book2);

		*/

		/*
			//使用指向结构的指针
			Books book1;
			Books book2;

			strcpy(book1.title, "C++ 教程");
			strcpy(book1.author, "Runoob");
			strcpy(book1.subject, "编程语言");
			book1.book_id = 12345;

			strcpy(book2.title, "css 教程");
			strcpy(book2.author, "Runoob");
			strcpy(book2.subject, "前端技术");
			book2.book_id = 54321;

			printBookByPoint(&book1);
			printBookByPoint(&book2);

		*/

		/*
			// typedef 关键字
			newBooks b1;
			strcpy(b1.title, "adc");
			strcpy(b1.author, "qwert");
			strcpy(b1.subject, "science");
			b1.book_id = 45;
			cout << "book title : " << b1.title << endl;
			cout << "book author : " << b1.author << endl;
			cout << "book subject : " << b1.subject << endl;
			cout << "book id : " << b1.book_id << endl;
			cout << endl;
		*/

		/*
			//访问数据成员
			Box Box1, Box2;
			double volume = 0.0;

			Box1.height = 5.0;
			Box1.length = 6.0;
			Box1.breadth = 7.0;

			Box2.height = 10.0;
			Box2.length = 12.0;
			Box2.breadth = 13.0;

			volume = Box1.height * Box1.length * Box1.breadth;
			cout << "Box1 volume = " << volume << endl;

			volume = Box2.height * Box2.length*Box2.breadth;
			cout << "Box2 volume = " << volume << endl;
		*/

		/*
			//在类内部声明函数，在类的外部使用范围解析运算符::定义函数
			Box Box1, Box2;
			double volume = 0.0;

			Box1.setLength(6.0);
			Box1.setBreadth(7.0);
			Box1.setHeight(5.0);

			Box2.setLength(12.0);
			Box2.setBreadth(13.0);
			Box2.setHeight(10.0);

			volume = Box1.getVolume();
			cout << "box1 area = " << Box1.getArea() << endl;
			cout << "box1 volume = " << volume << endl;

			volume = Box2.getVolume();
			cout << "box2 area = " << Box2.getArea() << endl;
			cout << "box2 volume = " << volume << endl;
		*/

		/*
			//子类
			SmallBox sb;
			sb.setSmallWidth(5.0);
			cout << "width of box : " << sb.getSmallWidth() << endl;
		*/

/*
	//多参数初始化
	Line line(1, 2, 3, 4, 5);
	cout << "params in line a = " << line.a << " b = " << line.b << " c = " << line.c << " d = " << line.d << " e = " << line.e << endl;
*/

/*
	//拷贝构造函数
	newLine newline1(10);
	newLine newline2 = newline1;
	display(newline1);
	display(newline2);
*/

/*

	//友元函数,可以在类的外部访问类的private和protected成员变量和成员函数
	Box box;
	box.setPrintWidth(10.0);
	printBoxWidth(box);

*/

/*
	//内联函数，在函数的定义出添加inline前缀称为内联函数。
	//内联函数针对行数不多又频繁调用的函数在编译时将所有函数调用处用函数体替换，
	//减少了函数调用的时间消耗，使代码运行更加高效
	//另外在类定义中的函数都是内联函数，即使它没有inline关键字修饰。
	cout << "Max (20,10) : " << Max(20, 10) << endl;
*/

/*
	//this指针
	Box box1, box2;
	box1.setBreadth(1);
	box1.setHeight(2);
	box1.setLength(3);

	box2.setBreadth(4);
	box2.setHeight(5);
	box2.setLength(6);

	if (box1.compare(box2))
	{
		cout << "box2 is small than box1" << endl;
	}
	else 
	{
		cout << "box2 is equal to or larger than box1" << endl;
	}
*/

/*
	//指向类的指针
	BoxPoint box1(3.3, 1.2, 1.5);
	BoxPoint box2(8.5, 6.0, 2.0);
	BoxPoint *ptrBox;

	ptrBox = &box1;
	cout << " Volume of box1 = " << ptrBox->Volume() << endl;
	ptrBox = &box2;
	cout << " Volume of box2 = " << ptrBox->Volume() << endl;
*/

/*
	//类的静态成员
	BoxPoint box1(3.3, 1.2, 1.5);
	BoxPoint box2(8.5, 6.0, 2.0);

	cout << " Total objects = " << BoxPoint::objectCount << endl; //--->Total objects = 2
	
*/

/*
	//类的静态函数
	cout << "Inital stage Count : " << BoxPoint::getCount() << endl; //--->Inital stage Count : 0
	BoxPoint box1(3.3, 1.2, 1.5);
	BoxPoint box2(8.5, 6.0, 2.0);
	
	cout << " Total objects = " << BoxPoint::getCount() << endl; //--->Total objects = 2	
*/

	return 0;
}

int changeNum(int a)
{
	a = a++;
	cout << " changeNum a = " << a << endl;
	return a;
}


double getAverage(int arr[], int size)
{
	int i, sum = 0;
	double avg;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	avg = double(sum) / size;
	return avg;
}

void mtlDouble(int *num)
{
	*num = *num * 2;
	return;
}

int *getRandom()
{
	static int r[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		r[i] = rand();
	}
	return r;
}

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	return;
}

double & setValues(int i)
{
	return vals[i];//返回第i个元素的引用
}

void printBook(struct Books book)
{
	cout << "book title : " << book.title << endl;
	cout << "book author : " << book.author << endl;
	cout << "book subject : " << book.subject << endl;
	cout << "book id : " << book.book_id << endl;
	cout << endl;
}

void printBookByPoint(struct Books *book)
{
	cout << "book title : " << book->title << endl;
	cout << "book author : " << book->author << endl;
	cout << "book subject : " << book->subject << endl;
	cout << "book id : " << book->book_id << endl;
	cout << endl;
}

void display(newLine obj)
{
	cout << " line size is " << obj.getLength() << endl;
	return;
}

