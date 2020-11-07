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

# 配置

在目录/etc/vim/下面，会有名为vimrc的文件，这是系统公共的vim配置文件，对**所有的用户**都是有效的。 如果只是希望对本用户有效，也可以在当前用户的家目录(~)下建立.vimrc文件

```shell
set autoindent           # 自动缩进
set smartindent          # 为C语言提供自动缩进
set number               # 显示行号
set langmenu=zh_CN.UTF-8
set helplang=cn          # 语言设置
set tabstop=4            # Tab键的宽度
set softtabstop=4        # 统一缩进为4
set foldenable           # 用空格键来开关折叠
```

```shell
"进行版权声明的设置
"添加或更新头
map <F5> :call TitleComment()<cr>'s
function AddTitleForC()
    call append(0,"/*==========================================================")
    call append(1,"# Author             :Jiaq.yang")
    call append(2,"# Email              :thinklook1@outlook.com")
    call append(3,"# Create time        :".strftime("%Y-%m-%d %H:%M"))
    call append(4,"# Last modified      :".strftime("%Y-%m-%d %H:%M"))
    call append(5,"# Filename: ".expand("%:t"))
    call append(6,"# Description: ")
    call append(7,"==========================================================*/")
    echohl WarningMsg | echo "Successful in adding the copyright." | echohl None
endf
"更新最近修改时间和文件名
function UpdateTitle()
    normal m'
    execute '/# *Last modified:/s@:.*$@\=strftime(":\t%Y-%m-%d %H:%M")@'
    normal ''
    normal mk
    execute '/# *Filename:/s@:.*$@\=":\t\t".expand("%:t")@'
    execute "noh"
    normal 'k
    echohl WarningMsg | echo "Successful in updating the copy right." | echohl None
endfunction
"判断前10行代码里面，是否有Last modified这个单词，
"如果没有的话，代表没有添加过作者信息，需要新添加；
"如果有的话，那么只需要更新即可
function TitleComment()
    let n=1
    "默认为添加
    while n < 10
        let line = getline(n)
        if line =~ '^\#\s*\S*Last\smodified:\S*.*$'
            call UpdateTitle()
            return
        endif
        let n = n + 1
    endwhile  
    call AddTitleForC()
endfunction
```



[vim配置]:https://www.cnblogs.com/zlhao/archive/2012/02/01/2335081.html
[vim一键添加注释]:https://www.cnblogs.com/mfryf/p/3643349.html
[vim个性化设置]: https://blog.51cto.com/thedream/1873060

