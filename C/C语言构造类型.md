# C 语言

## C语言预处理

### 宏定义

定义代码段：

```c
#define P(a) { \
	printf("%d\n", a); \
}
// \为链接符
```

```c
/*
	预处理过程就是将预处理指令转化为实际代码（展开）的过程
	（此时会将注释代码去掉）
*/
//#include为包含头文件的操作
#include <stdio.h>
//#define为宏定义，只是简单的字符替，不会计算优先级等问题
//为了避免运算符优先级的问题，对替换单元加上括号
#define NAME "designer"
#define MAX(A,B) ((A) > (B) ? (A) : (B))

//定义了一个全局变量，会占用内存
const int Num = 5;

int main(int argc, char const *argv[])
{
    printf("%s");
    return 0;
}
```

### 预定义的宏

|          宏           | 说明                            |
| :-------------------: | :------------------------------ |
|      `__DATE__`       | 日期：Mmm dd yyyy（编译的日期） |
|      `__TIME__`       | 时间：hh:mm:ss                  |
|      `__LINE__`       | 行号                            |
|      `__FILE__`       | 文件名                          |
|      `__func__`       | 函数名/**非标准**               |
|      `__FUNC__`       | 函数名/**非标准**               |
| `__PRETTY_FUNCTION__` | 更详细的函数信息/**非标准**     |

### 条件编译

```c
#include <stdio.h>

#define TEST
/*  
    #undef TEST //取消宏定义
*/

//条件编译是以#和if开头，必须以#endif结尾
//#ifdef  如果已经定义
//#ifndef 如果尚未定义
#ifdef TEST
void test1()
{
    printf("已经定义了TEST\n");
}
#else
void test1()
{
    printf("未定义TEST\n");
}
#endif
/*
	通过gcc -E test.c对上述部分经过预编译后
	以上部分将只有#ifdef和#else之间的存在
*/

#define NUM 8
//条件起始，必须加上条件
#if NUM == 1
int a = 10;
#elif NUM < 10
int a = 100;
#else
int a = 1000;
#endif
/*
	经过gcc -E test.c对预编译后
	以上部分将只有int a = 100;存在
*/

//对于代码中尚未开发完成的代码，可能会导致一些不可预见的问题
//但是又不想让程序无法执行，可以加上这样一个预处理指令
#warning 出现警告

//抛出错误
#error 直接抛出错误

//这个指令功能比较强大
//非致命警告，只有添加了-Wall才可发现，-W警告，all显示所有警告
#pragma warning("非致命警告!")

//显示一段信息
#pragma message("输出一个信息")

//内存对齐方式，括号内指定内存对齐的字节数
#pragma pack(2)

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
```

### 头文件

`test.h`文件：

```c
//头文件当中可以定义一些接口（函数原型） 类型 全局变量等
//为了避免编译效率过低 不要将实现部分放在头文件当中
#ifndef _TEST_H_
#define _TEST_H_

void display_message();

typedef unsigned int uint;

#define NAME "designer"

int a = 100;

#endif
```

`test.c`文件：

```c
#include <stdio.h>
//""先从当前文件路径查找头文件，如果找不到，再到系统路径中查找
#include "test.h"
//需要注意的是，如果自定义的头文件和引用其的源文件不再同一目录，需要引用的是相对路径

int main(int argc, char *argv[])
{
    printf("%d\n", a);

    return 0;
}
```

## 工程项目开发

### 多文件编译

声明只能在头文件`.h`中，定义只能在头文件对应的源文件`.c`中

一般将`.h`头文件放在`include`或者`header`文件夹下，把头文件对应的`.c`源文件放在`src`或者`source`文件夹下，在发布工程的时候，为了防止重新编译源文件和源码泄露，通过将`src`或者`source`文件夹下的`.c`文件生成相应的`.o`文件，并将生成的`.o`文件打包成静态链接库`libxxx.a`（`ar -r libxxx.a xxx.o ...`），之后，在`include`和`src`的同级目录下，新建一个`lib`文件夹，将打包后的静态链接库移入。此时，只通过`include`和`lib`文件就可以进行发布了。

`gcc -I./include -c xxx.c` 增加头文件的引用路径`include`

`gcc xxx.o -L./lib -lxxx ` 程序在链接过程中，链接`lib`目录下的静态库文件`libxxx.a`

`main.c`文件：

```c
#include <stdio.h>
#include "header/test.h"
#include "header/max.h"

int main(int argc, char *argv[])
{
    display();
    int temp = max_int_two(10, 100);
    printf("%d\n", temp);
    return 0;
}
```

`header/max.h`文件：

```c
#ifndef _MAX_H_
#define _MAX_H_

int max_int_two(int a, int b);

#endif
```

`header/test.h`文件：

```c
#ifndef _TEST_H_
#define _TEST_H_

//不管这个头文件被包含了多少次，只进行一次编译解析
#pragma once
void display();

#endif
```

`source/max.c`文件：

```c
#include "../header/max.h"

int max_int_two(int a, int b) {
    return a > b ? a : b;
}
```

`source/test.c`文件：

```c
#include <stdio.h>
#include "../header/test.h"

void display()
{
    printf("Display!\n");
}
```

编译：`gcc main.c source/max.c source/test.c -o output/target`

