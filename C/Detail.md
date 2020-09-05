# C Detail

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

   

3. 余数和被除数同号

4. `scanf("%c\n", &a)`中`\n`不可以加

5. `const char* p`，

   

[流程图](https;//app.diagrams.net)