#!/bin/bash
# **********************************************************
# * Author : liangliangSu
# * Email : sll917@hotmail.com
# * Create time : 2023-02-04 16:04
# * Filename : 09case语句.sh
# **********************************************************
: '
case ... esac 与其他语言中的 switch ... case 语句类似，是一种多分枝选择结构。
case 语句匹配一个值或一个模式，如果匹配成功，执行相匹配的命令。case 语句格式如下：
case 值 in
模式1)
command1
command2
command3
;;
模式2）
command1
command2
command3
;;
*)
command1
command2
command3
;;
esac
case 工作方式如上所示。
1.取值后面必须为关键字 in
2.每一模式必须以右括号结束。取值可以为变量或常数
3.匹配发现取值符合某一模式后，其间所有命令开始执行直至 ;;
4.;; 与其他语言中的 break 类似，意思是跳到整个 case 语句的最后
取值将检测匹配的每一个模式。一旦模式匹配，则执行完匹配模式相应命令后不再继续其他模式
如果无一匹配模式，使用星号 * 捕获该值，再执行后面的命令。
下面的脚本提示输入1到4，与每一种模式进行匹配：
'
echo 'Input a number between 1 to 4'
echo 'Your number is:\c'
read aNum
case $aNum in
1)
	echo 'You select 1'
	;;
2)
	echo 'You select 2'
	;;
3)
	echo 'You select 3'
	;;
4)
	echo 'You select 4'
	;;
*)
	echo 'You do not select a number between 1 to 4'
	;;
esac
#输入不同的内容，会有不同的结果，例如：
#Input a number between 1 to 4
#Your number is:3
#You select 3
#再举一个例子：
#!/bin/bash
option="${1}"
case ${option} in
-f)
	FILE="${2}"
	echo "File name is $FILE"
	;;
-d)
	DIR="${2}"
	echo "Dir name is $DIR"
	;;
*)
	echo "$(basename ${0}):usage: [-f file] | [-d directory]"
	exit 1 # Command to come out of the program with status 1
	;;
esac
#运行结果：
#$./test.sh
#test.sh: usage: [ -f filename ] | [ -d directory ]
#$ ./test.sh -f index.htm
#$ vi test.sh
#$ ./test.sh -f index.htm
#File name is index.htm
#$ ./test.sh -d unix
#Dir name is unix
#$

read -p "请输入你要查询的城市房价排名名次:" number
case $number in
1)
	echo "2021年全国城市房价排行第1是:深圳  "
	;;
2)
	echo "2021年全国城市房价排行第2是:北京  "
	;;
3)
	echo "2021年全国城市房价排行第3是:上海  "
	;;
4)
	echo "2021年全国城市房价排行第4是:广州  "
	;;
5)
	echo "2021年全国城市房价排行第5是:杭州  "
	;;
6)
	echo "2021年全国城市房价排行第6是:三亚  "
	;;
7)
	echo "2021年全国城市房价排行第7是:南京  "
	;;
8)
	echo "2021年全国城市房价排行第8是:天津  "
	;;
9)
	echo "2021年全国城市房价排行第9是:珠海  "
	;;
*)
	echo "2021年全国城市房价排行第10是:东莞 "
	;;
esac

