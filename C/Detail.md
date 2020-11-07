# C Detail

## 细节

1. `do....while()`和`while()`的区别

   `do...while(0U)`的作用

   1. 确保宏定义正确展开

      如果原语句为：

      ```c
      if(!value)
          foo(wolf);
      ```

      在`#define foo(x) bar(x); baz(x)`的情况下，展开为：

      ```c
      if(!value)
          bar(wolf);
      baz(wolf);
      //展开效果与我们期望的不符
      ```

      如果采用`do...while(0U)`，则展开为：

      ```c
      if(!value)
          do{
              bar(x);
              baz(x);
          }while(0U);
      ```

   2. 实现局部作用域

      ```c
      #define swap(a,b) do{\
      					a = a + b;\
      					b = a - b;\
      					a = a - b;\
      				}while(0U)
      
      int main()
      {
          int a = 1, b = 2;
          if(1)
              swap(a,b);
          else
              a = b;
          return 0;
      }
      //展开后为
      int main()
      {
          int a = 1, b = 2;
          if(1)
              do{
                  a = a + b;
                  b = a - b;
      			a = a - b;
              }while(0U);
          else
              a = b;
          return 0;
      }
      ```

   3. 避免使用`goto`语句

      `goto`语句可以用来进行错误处理，但是过多的`goto`会使代码的维护困难，因此，采用`do...while(0U)`加`break`的方法，来实现`goto`的功能。

      ```c
      #include <stdio.h>
      #include <stdlib.h>
      
      int main()
      {
          int res = -1;
          if(0 != res)
          {
              goto failed;
          }
          res = fun1();
          if(1 != res)
          {
              goto failed;
          }
          return 0;
          
      failed:
          do_err();
      }
      //do...while(0U)方法
      int main()
      {
          int res = -1;
          do
          {
              if(0 != res)
              {
                  break;
              }
          	res = fun1();
              if(0 != res)
              {
                  break;
              }
              
              return 0;
          }while(0U);
          
          do_err();
      }
      ```

2. `sizeof`和`strlen`的区别：

   `sizeof`是一个操作符，`strlen`是库函数，二者得到的结果类型为`size_t`，即`unsigned int`类型；`sizeof`计算的是数据类型占用内存的大小，`strlen`计算的是字符串**实际**的大小，以`\0`作为长度判定依据，遇到`\0`结束，`\0`本身不计算在内，**但是`\n`会被计算在内**。大部分编译程序在编译的时候就把 **sizeof** 计算过了，而 **strlen** 的结果要在运行的时候才能计算出来。

   对于以下语句：

   ```c
   char *str1 = "asdfgh";
   char str2[] = "asdfgh";
   char str3[8] = {'a', 's', 'd'};
   char str4[] = "as\0df";
   ```

   执行结果是：

   ```c
   sizeof(str1) = 4;  strlen(str1) = 6;
   sizeof(str2) = 7;  strlen(str2) = 6;
   sizeof(str3) = 8;  strlen(str3) = 3;
   sizeof(str4) = 6;  strlen(str4) = 2;
   ```

   str1是字符指针变量，sizeof 获得的是该指针所占的地址空间，32 位操作系统对应 4 字节，所以结果是 4；strlen 返回的是该字符串的长度，遇到 **\0** 结束， **\0** 本身不计算在内，故结果是 6。

   str2 是字符数组，大小由字符串常量 "asdfgh" 确定，sizeof 获得该数组所占内存空间大小，包括字符串结尾的 **\0** ，所以结果为 7；strlen 同理返回 6。

   str3 也是字符数组，但大小确定为 8，故 sizeof 得到的结果是 8；strlen 统计 **\0** 之前所有字符的个数，即为 3；

   str4 是常量字符数组，sizeof 得到字符总数即 6；strlen 计算至 **\0** 结束，因此返回 2；

   从命令行输入字符的话，strlen遇到空格就结束了，空格不计算在长度内

3. 余数和被除数同号

4. `scanf("%c\n", &a)`中`\n`不可以加

5. `const char* p`，


## 变量作用范围

一个变量的**作用域**，一般可以界定为变量声明之后、包裹了它的声明语句的最内一层`{}`之内。例如下图所示，变量`alpha`的作用域为黄色箭头的部分。

![](/home/q7/Blog/AIot/C/Photo/变量作用域.png)

程序实例：

```c
#include <stdio.h>

int main()
{
    int test = 1;
    {
        int test = 2;
        printf("The test value is %d\n", test);
    }
    printf("The test value is %d\n", test);
    
    return 0;
}
/*
*程序输出分别为2和1
*/
```

## 变量类型和对应的占位符

|   数据类型   |    关键字    | 格式占位符 |
| :----------: | :----------: | :--------: |
| 有符号型整数 |     int      |     %d     |
|    字符型    |     char     |     %c     |
|    浮点型    | float/double |     %f     |
| 无符号型整数 | unsigned int |     %u     |

其它一些常用占位符：

|     数据类型     | 格式占位符 | 示例数据 |
| :--------------: | :--------: | :------: |
| 科学计数法浮点数 |   %e或%E   | 3.96e+2  |
|     内存地址     |     %p     | 0x123456 |

## 常见数学函数

`#include <math.h>`

### 绝对值函数

整数绝对值函数`abs`，`abs(-5) = 5`，注：`abs`函数是需要引入`stdlib.h`

实数绝对值函数`fabs`，`fabs(-3.14) = 3.14`

### 对数函数

对于以`e`为底的对数函数`ln` ，C 语言的数学库中提供了名为`log`的函数；对于以10为底的对数函数，数学库中则提供了一个名为`log10`的函数，例`log10(100.0) = 2.000000`。

### 其他函数

四舍五入函数`round`，`round(2.5) = 3`

向下取整函数`floor`，`floor(2.5) = 2`

向上取整函数`ceil`，`ceil(-2.5) = 1`

平方根函数`sqrt`，`sqrt(9) = 3`

## 数组与内存

一般情况下，通过地址上进行运算的方式访问数组的效率要比用数组索引的方式执行更快。

```c
#include <stdio.h>

int main() {
    int array[3] = {1,2,3};
    int *p;
    p = &array[0];
    printf("%d\n", *(p+1));//输出array[1]的数值
    //上句等价于printf("%d\n", *(&array[0]+1));
    return 0;
}
```

## 字面量

在字面量后，我们往往会增加一个后缀标记类型。

* 长类型（long）字面量，会加一个`l`或`L`，例如`1234L`
* 无符号字面量（unsigned）以字母`u`或`U`作为后缀，例如`345U`
* 后缀`f`或`F`则用于标记单精度浮点型（float）字面量，例如`3.14F`或`1e-2f`。不增加后缀的浮点型字面量均为双精度浮点型（double）字面量

```c
#include <stdio.h>

int main() {
    char string[] = "Hello";
    printf("%s\n", string);
    //输出Hello
    char *string2 = "Hello";
    printf("%s\n", string2);
    //输出Hello
    printf("%p\n", &string);  
    //string的地址和string2的地址是完全不同的
    //string的地址是内存栈区的地址
    printf("%p\n", string2);
    //string2则是直接关联到"Hello"字符串字面量在内存中
    //字面量池中的地址
    printf("%p\n", &"Hello");
    
    return 0;
}
```

## 长度未知的大数组

`#include<malloc.h>`

`void *malloc(size_t size);`

`void *calloc(size_t nmemb, size_t size);`

`malloc`和`calloc`的区别：

* `calloc`函数申请的内存空间是经过初始化的，全部被设成了`0`，而不是像`malloc`所申请的空间那样是未经初始化的。
* `calloc`函数适合为数组申请空间，我们可以将第二个参数设置为数组元素的空间大小，将第一个参数设置为数组的元素数量。

## 类型转换

如果一个运算（和一个运算符关联）中，参与运算的数值类型不同，则会先转成同一类型，然后再进行运算。**赋值时，类型会以赋值号左侧为准**，右侧的表达式的结果类型会被转为左边变量的类型。

## 编程范式

C语言：面向过程

C++语言：面向过程、面向对象、泛型、函数式

## 位运算

`^`的**逆运算**是其本身，即在`a^b=c`的情况下，`c^b=a,c^a=b`，互为逆运算的前提是满足交换律。位运算的时钟周期最短。

## 关系运算符

`!!(x)`为逻辑归一化，如果`x`为真值则结果归为1，`x`为假值则结果归为0；比如`!!(3) `等价于`!(3) = 0, !(0) = 1`，同理`!!(-1) = 1`

`!`为条件运算符，是逻辑的非，返回值只有0和1两种；`~`为按位取反

`&&`的结合优先级高于`||`的，也就是说

`m == 5 || m == 6 || m == 9 && d < 30`等价于

`m == 5 || m == 6 || (m == 9 && d < 30)`

`val & 1`等价于`val % 2`

`val & 3`等价于`val % 4`

`val & 7`等价于`val % 8 `

`val & (2^i)-1` 等价于 `val % 2^i`

## CPU的分支预测

```c
#define likely(x) __builtin_expect(!!(x), 1)
// likely代表x经常成立
#define unlikely(x) __builtin_expect(!!(x), 0)
// unlikely代表x不经常成立
```

```c
__builtin_ffs(x)// 返回x中最后一个为1的位是从后往前的第几位
__builtin_popcount(x)// x中1的个数
__builtin_ctz(x)// x末尾0的个数。x=0时结果未定义
__builtin_cls(x)// x前导0的个数。x=0时结果未定义
__builtin_prefetch(const void *addr, ...)
// 对数据手工预取的方法
__builtin_types_compatible_p(type1,type2)
// 判断type1和type2是否是相同的数据类型
__builtin_expect(long exp, long c)
// 用来引导gcc进行条件分支预测
__builtin_constant_p(exp)
// 判断exp是否在编译时就可以确定其为常量
__builtin_parity(x)
// x中1的奇偶性
__builtin_return_address(n)
// 当前函数的第n级调用者的地址
```

## 递归函数

考虑递推公式

## 变参函数

va一族来实现变参函数

`int max_int(int a, ...);`

获得a往后的参数列表->`va_list`：类型的变量，用来存储变参列表（...）中的所有内容

定位a后面第一个参数的位置->`va_arg`：

获取下一个可变参数列表中的参数->`va_start`：

结束整个获取可变参数列表的动作->`va_end`：

## Makefile

`.PHONY`用于声明一些伪目标，伪目标与普通目标的主要区别是伪目标不会被检查是否存在于文件系统中，而默认不存在且不会应用默认规则生成它。

## 文件操作

文件复制的函数

```c
void filecopy(FILE *in_fp, FILE *out_fp) {
    char ch;
    while ((ch = fgetc(in_fp)) != EOF) {
        fputc(ch, out_fp);
    }
}
```

## 输入输出

```c
fscanf(in_fp, "%c", &a);//使用fscanf从文件指针in_fp进行读取
fscanf(stdin, "%c", &a);//等价于scanf("%c", &a);
fprintf(out_fp, "%c", a);
fprintf(stdout, "%c", a);//等价于printf("%c", a);
```

## GDB

```shell
gcc -g text.c  # 编译时加入-g参数才能调用gdb进行调试
gdb ./a.out    # 进入gdb进行调试
(gdb) l        # list的首字母，列出带有行号的前10行程序
(gdb) b 5 # breakpoint的首字母，在第五行设置断点参数也可以为函数名
(gdb) r   # run的首字母，程序开始运行，暂停在断点处
(gdb) p 表达式  # print的首字母，打印表达式的值
(gdb) n   # next的首字母，程序执行端点后的下一条语句，并暂停
(gdb) c   # continue的首字母，程序执行到下一个端点处
(gdb) info p   # 显示文件的端点信息
```



共用体类型中可以含有共用体类型成员

枚举类型中成员的编号只能是整数，枚举类型中可以有多个成员被编号

[流程图](https;//app.diagrams.net)