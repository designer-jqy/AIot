# C++ 语言细节

## 构造函数

* 函数名与类名完全相同
* **可以重载**
* 可以有形参，也可以没有形参，可以带有默认参数
* 不能定义返回值类型，也不能有`return`语句

```c++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Clock{
public:
    Clock() {
        second = 0;
        minute = 0;
        hour = 0;
    }
    Clock(int newS, int newM, int newH);
    // 构造函数的重载
    void setTime(int newS,int newM,int newH){
        second = newS;
        minute = newM;
        hour = newH;
    }
    void showTime();
private:
    int second,minute,hour;
};
void Clock::showTime(){
    cout << hour << ":" << minute << ":" << second << endl;
}
Clock::Clock(int newS, int newM, int newH) {
    second = newS;
    minute = newM;
    hour = newH;
}
int main(){
    Clock MyClock;
    MyClock.showTime();
    int second,minute,hour;
    cin >> second >> minute >> hour;
    MyClock.setTime(second,minute,hour);
    MyClock.showTime();
    Clock MyClock2(1, 2, 3);
    MyClock2.showTime();
    return 0;
}
```

### 拷贝构造函数

```c++
class Point{
public:
    Point(Point &p);
private:
    int x,y;
};
// 拷贝构造函数
Point::Point(Point &p) {
    x = p.x;
    y = p.y;
}
```

* 当用类的一个对象去初始化该类的另一个对象的时候

  ```c++
  Point a(1,2);
  Point b(a);  // 用对象a初始化对象b，拷贝构造函数被调用
  Point c = b; // 用对象b给对象c赋值，拷贝构造函数被调用
  ```

* 当函数的形参是类的对象，调用函数时进行形实结合的时候

  ```c++
  void f(Point p) {
      // code here
  }
  int main() {
      Point a(1,2);
      f(a);
      return 0;
  }
  ```

* 当函数的返回值是类的对象，函数执行完成返回调用者的时候

  ```c++
  Point g() {
      Point a(1,2);
      return a;
  }
  ```

  在我们没有定义类的构造函数的时候，编译器可以在必要的时候，自动帮我们生成一个**隐含的拷贝构造函数**，在类的数据成员中有**指针**类型的时候，这个时候**默认的复制构造函数**能够实现的只有**浅拷贝**，要实现正确的复制，就是所谓的**深拷贝**，就必须重新编写复制构造函数才行。

### 初始化列表

```C
构造函数(参素列表)：成员变量(常量或者参数) {
    // 构造函数的函数体
}
```

```c++
clock::clock (int newS, int newM, int newH) {
    second = newS;
    minute = newM;
    hour = newH;
}
// 初始化列表格式
// 必须写在类的声明中
clock (int newS, int newM, int newH):minute(newM),second(newS),hour(newH) {
    // 如果还需要构造函数干别的事
    // 可以和以前一样在构造函数中写下代码
}
```

一个类被实例化为一个对象，整个过程分为两段：

1. 对象的构造和成员变量的初始化，**初始化列表**就是在此期间发挥作用
2. 执行构造函数中的操作

## 类的组合

当创建类的对象时，如果这个类具有内嵌对象成员，那么各个内嵌对象将会**首先被自动创建**。在创建对象的时候，**既要对类中的基本数据类型进行初始化，也要对内嵌对象成员进行初始化**。

内嵌对象的初始化使用了**初始化列表**来完成——内嵌对象必须使用初始化列表来实现初始化

```c++
class Point{
private:
    int x, y;
public:
    Point(int newX, int newY):x(newX),y(newY) {}
};
class Circle{
private:
    double radius;
    point center;
public:
    Circle(double r, point p):radius(r),center(p) {}
};
```



当我们创建一个组合类的实例对象的时候，不光是它自己的构造函数的函数体被调用执行，而且还将调用其内嵌对象的构造函数。构造函数的调用顺序如下：

1. 调用内嵌对象的构造函数，调用顺序按照内嵌对象在组合类中的定义中出现的顺序。需要注意的是，在初始化列表中的内嵌对象顺序，跟内嵌对象构造函数的调用顺序是没有关系的
2. 执行本类构造函数的函数体

析构函数的调用执行顺序与构造函数正好相反

### 前向引用声明

当遇到两个类互相引用的情况，如下所示：

```c++
class A{
public:
    void function(B b);
};
class B{
public:
    void function2(A a);
};
```

不管哪个类放在前面，结果都会导致编译错误。要解决这种问题，可以使用**前向引用声明**。如下所示：

```c++
class B;
class A{
public:
    void function(B b);
};
class B{
public:
    void function2(A a);
};
```

需要注意的是，**在提供一个完整的类定义之前，不能定义该类的对象，也不能在成员函数中使用该对象**。

```c++
class Elder;
class Toad {
    Elder h; // 错误：类Elder的定义不完善
};
class Elder {
    Toad h;
};
```

这种情况，可以通过声明**前向引用声明类的引用或者指针**

```c++
class Elder;
class Toad {
    Elder &h;
};
class Elder {
    Toad &h;
};
```

但是，即使声明了引用，仍然不能在类内的方法定义中直接调用定义不完善的类的方法：

```c++
class Elder;
class Toad {
private:
    Elder &h;
public:
    void setWeather() {
        h.sunny(); // 不合法，因为此时h尚未定义完善
    }
};
```

## 数组

```C++
void func(int a[][4]) {
    // 函数定义
}
int table[3][4]; // 作为参数的数组
func(table);     // 直接使用数组名作为参数
// 使用数组名传递参数的时候，传递的是地址
```

### 对象数组

```C++
class Point{
    // 类定义
};
Point p[10];
// 在使用对象数组的时候，每个数组元素都是一个对象
int p_x = p[1].x // 这里我们假设x是整形公有成员变量
```

对象数组的初始化

```c++
Point p[2] = {Point(1,2), Point(3,4)}; 
// 假设Point有对应的构造函数
// 也可以只初始化前面的一部分对象元素
Point p[2] = {Point(1,2)};
// 对象数组在初始化的过程中，就会使用带参构造函数初始化p[0]，然后用默认构造函数初始化p[1]
```

### 数组排序

```c++
#include <iostream>
using namespace std;
void sort(int data[], int length) {
    // 数组名的传递int data[]
    for (int i = 0; i < length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (data[j] > data[j+1]) {
                swap(data[j], data[j+1]);
            } else {
                break;
            }
        }
    } 
}

int main(){
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    sort(a,10);
    for (int i = 0; i < 10 ; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}
```

数组的传递，使用**数组类型+数组名+[]**

## 数组与内存

在C++语言中，无论数组内的元素是什么类型的，对一个元素的地址加一个位移值n得到的就是这个元素往后数n后所在元素的地址。一般来说，**通过在地址上进行运算的方式，访问数组的效率是比用数组索引的方式执行更快的**。

```C++
int n = 3;
int a[3] = {1,2,3};
int *p;

p = &a[0];
while (n != 0) {
    n--;
    cout << *p << endl;
    p++;
}
```

## 字面量

```C++
#include <iostream>
using namespace std;
int main() {
    char string[] = "Hello";
    cout << string << endl;
    char *string2 = "Hello";
    cout << string2 << endl;
    cout << &string << endl;
    // string的地址是内存栈区的地址
    cout << static_cast<const void *>(string2) << endl;
    // string2则是直接关联到"Hello"字符串字面量
    // 在内存中字面量池中的地址
    // 不可以通过string2来对字符串做修改
    cout << &"Hello" << endl;
    // "Hello"字符串字面量在内存中字面量池中的地址
    
    return 0;
}
```

