/*----------------------------------------------------------------
实现printf函数
----------------------------------------------------------------*/
/*----------------------------------------------------------------
const char *     内容不可以被修改
char* const      指针变量的指向不能被修改
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int cal_num(int n, int* temp) {
    int digit = 0;
    *temp = 0;
    do 
    {
        (*temp) = (*temp) * 10 + n % 10;
        n /= 10;
        ++digit;
    } while (n);

    return digit;
}

int output_num(int n, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(n % 10 + '0');
        cnt++;
        n /= 10;
    }

    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a), ++cnt;                         // 宏定义
    for (int i = 0; frm[i]; i++) {                             // 字符\0不可见，\0对应十进制的0值    因此可以通过frm[i]来判断
        switch (frm[i])
        {
            case '%':                                         // 判断是否为%
            {
                switch (frm[++i])                             // 判断%的下一位
                {
                    case '%':                                 // 如果下一位为%
                    {
                        PUTC(frm[i]);
                        break;
                    }
                    case 'd':                                 // 如果下一位为d
                    {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0)                           // 为了防止溢出
                        {
                            PUTC('-');
                            x = -xx;
                        } else
                        {
                            x = xx;
                        }
                        int temp1, temp2;
                        int x1 = x / 100000, x2 = x % 100000; // 为了防止翻转后溢出，把x分成前5位和后5位
                        int digit1 = cal_num(x1, &temp1);     // 计算x1的位数
                        int digit2 = cal_num(x2, &temp2);     // 计算x2的位数
                        if (x1)                 
                        {
                            digit2 = 5;                       // 如果高5位不为0,则低5位digit2的位数一定为5
                        } else 
                        {
                            digit1 = 0;                       // 如果高5位为0,则高5位digit1的位数一定为0
                        }
                        cnt += output_num(temp1, digit1);     // 计算输出的字符数
                        cnt += output_num(temp2, digit2);
                        break;
                    }
                    case 's':                                 // 如果下一位为s
                    {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++)
                        {
                            PUTC(str[i]);
                        }
                        break;
                    }
                }
                break;
            }
            default:
            {
                PUTC(frm[i]);
                break;
            }
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}

int main() {
    int n;
    // while (~scanf("%d", &n)) {
    //     printf(" has %d digits\n", printf("%d", n));
    //     my_printf(" has %d digits\n", printf("%d", n));
    // }
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    printf("int (a) = %d\n", 0);
    my_printf("int (a) = %d\n", 0);
    printf("int (a) = %d\n", 1000);
    my_printf("int (a) = %d\n", 1000);
    printf("int (a) = %d\n", -123);
    my_printf("int (a) = %d\n", -123);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    char str[100] = "I love China";
    printf("%s\n", str);
    my_printf("%s\n", str);

    return 0;
}