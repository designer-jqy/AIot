# 命令

## Linux基础命令

### Linux常用命令

```shell
man    //手册命令
help   //常用命令行命令
data   //查看当前时间
cal    //查看当前日记命令
clear  //清除屏幕
pwd    //查看当前目录的绝对路径
cd     //改变工作目录
ls     //显示当前目录下的内容
--help //帮助参数
touch  //创建文件
rm     //删除文件，-r：循环删除
mkdir  //创建一个目录
rmdir  //删除一个空目录
mv     //如果是当前目录：重命名，如果是其他目录：进行文件移动
cp     //拷贝，-r：拷贝非空文件夹
cat    //查看文件内容
echo   //显示文字
>      //重定向，将本该显示到界面的信息，定向到特定的文件里
>>     //追加重定向
head   //默认显示头部10行信息，-行数
tail   //默认显示尾部10行信息，-行数
more   //按照页的方式进行展示
chmod  //改变权限：421
tree   //查看文件结构树
```

### Linux编辑

#### vim

正常模式下的命令：
`x`：剪切

1. `nx`剪切光标右边n个字符
2. `nX`剪切左边

`d`：删除

1. `dnw`剪切n个单词
2. `dnl`剪切右边n个单词
3. `dnh`剪切左边n个单词
4. `dd`剪切一行

`y`：复制

1. `ynw`复制n个单词
2. `ynl`复制右边n个单词
3. `ynh`复制左边n个单词
4. `yy`复制一行

`p`：粘贴

`r`  进入替换模式
`i`  在正常模式下，按i进入插入模式
`v`  在正常模式下，按v进入视图模式
`：` 在正常模式下，按：进入命令模式

`%！xxd`：显示二进制