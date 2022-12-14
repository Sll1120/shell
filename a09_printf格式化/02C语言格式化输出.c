/* #======================================
# File name:shell_02.sh
# Author:liangliangSu
# Email:sll917@hotmail.com
# Date of writing:2022-10-06 13:24
#======================================
(一)、printf函数的一般格式
printf函数的一般格式为：
printf（格式控制字符串，输出值参数表）；
如：
*/
printf ("f=%f,c=%f\n",f,c)
//其中，f=%f,c=%f\n 是格式控制字符串，f,c 是输出值参数表。
//（1）格式控制字符串是用双引号括起来的字符串，包括三类信息：
//1.格式字符。格式字符由“%”引导，如%d、%f等。它的作用是控制输出字符的格式。
//2.转义字符。格式控制字符串里的转义字符按照转义后的含义输出，如上面printf函数双引号内的换行符“\n”,即输出回车。
//3.普通字符。普通字符即需要在输出时原样输出的字符，如上面printf函数中双引号内的“f=”和“c= ”部分。
//（2）输出值参数表是需要输出的数据项的列表，输出数据项可以是常量、变量或表达式，输出值参数之间用逗号分隔，其类型应与格式字符相匹配。每个格式字符和输出值参数表中的输出值参数一一对应，没有输出参数时，格式控制字符串中不再需要格式字符。
//(二)、格式字符
//（1）d格式字符
//输出带符号的十进制整数，正数的符号不输出。
//如：
//
//int a = 256,b = -125;
printf("%d\n%d",a,b);
//还可以在%和格式字符中间插入格式修饰符，用于指定输出数据的域宽（所占的列数），如用“%5d”，指定输出数据占5列，输出的数据在域内向右靠齐。如：
int a = 256,b = -125;
printf("%5d\n%5d",a,b);
/*
输出结果为：
其中256前面有2个空格，-125前面有一个空格。
若要输出long（长整型）数据，则在格式字符d前面加字母l（代表long），即“%ld”。
（2）f格式符
输出一个实数（包括单精度、双精度、长双精度），以小数形式输出，有以下几种用法：
1）基本型，%f
不指定输出数据的长度，由系统根据数据的实际情况决定数据所占的列数。系统处理的方法一般是：实数中的整数部分全部输出，小数部分输出6位。
如：
*/
#include<stdio.h>
int main(){
	double a = 1.0;
	printf("%f\n",a/3);
	return 0;
} 
/*
运行结果：
虽然a是double型，a/3的结果也是double型，但用 %f格式字符只能输出6位小数。
2）指定数据宽度和小数位数用%m.nf 。
其中，m表示输出数据的宽度，即占m列，n表示小数点后保留n位小数。(若不需强调输出数据宽度，可直接用%.nf)
*/
//如：
#include<stdio.h>
int main(){
	double a = 1.0;
	printf("%20.15f\n",a/3);
	return 0;
} 
//其中，在0前面有3个空格，小数点后输出了15位小数。
//注意：一个double型数只能保证15位有效数字的精确度，即使指定小数位数为50（如用%.50f），也不能保证输出的50位都是有效数值。
//3）输出的数据向左对齐，用%-m.nf。
//即在m.n前面加一个负号，能够让输出数据在域内向左靠齐。
//如：
#include<stdio.h>
int main(){
	double a = 1.0;
	printf("%-20.15f\n",a/3);
	return 0;
} 
//（3）c格式字符
//用于输出一个字符，如：
#include<stdio.h>
int main(){
	char ch = 'a';
	printf("%c",ch);
	return 0;
} 
//也可以加格式修饰符指定域宽，如：
#include<stdio.h>
int main(){
	char ch = 'a';
	printf("%5c",ch);
	return 0;
} 
//（4）s格式符
//用于输出一个字符串，如：
printf("%s","Hello!");
//3、使用printf函数时应注意的问题
//（1）格式控制字符串中没有%引导的格式字符时，不需要输出值参数表，直接输出字符串内容，转义字符按照转义后的实际意义输出，如：
#include<stdio.h>
int main(){
	printf("Hello world!");
	printf("\n");
	printf("Hello,\nworld!");
	return 0;
	}
//（2）格式控制字符串中有%引导的格式字符时，输出值参数表中的数量以及类型必须和格式字符一致，如：
#include<stdio.h>
int main(){
	int a = 123;
	double b = 35.8,c = 1.0;
	printf("a = %d,b = %d\n",a,b);
	printf("a = %d,c = %f\n",a);
	return 0;
	}
/*
分析：第一个printf函数中的输出参数b是double型，但对应的格式控制符为%d，当类型不一致时并不会进行类型转换，而会将实际转入的double型值当作需要的整形类型来理解，因此出现非预期结果；第二个printf函数中，格式控制字符串给出了两个%引导的格式字符，但是输出参数表中只有一个参数a。因此输出c的值默认为内存中a变量后面存储单元的数据值，即c的值我们不能确定。
附表1：
printf函数中用到的格式字符
格式字符	说明
d	输出带符号的十进制整数，正数的符号省略
u	以无符号的十进制整数形式输出
o	以无符号的八进制整数形式输出，不输出前导符0
x	以无符号十六进制整数形式（小写）输出，不输出前导符0x
X	以无符号十六进制整数形式（大写）输出，不输出前导符0X
f	以小数形式输出单、双精度数，隐含输出6位小数
e	以指数形式（小写e表示指数部分）输出实数
E	以指数形式（大写E表示指数部分）输出实数
g	自动选取f或e中输出宽度较小的一种使用，且不输出无意义的0
c	输出一个字符
s	输出字符串
附表2：
printf函数中用到的格式修饰符
格式修饰符	说明
英文字母l	修饰格式字符d、u、o、x时，用于输出long型数据
英文字母L	修饰格式字符f、e、g时，用于输出long double型数据
英文字母h	修饰格式字符d、o、x时，用于输出short型数据
输出域宽m（m为整数）	指定输出项输出时所占的列数
显示精度.n（n为整数）	对于实数，表示输出n位小数；对于字符串，表示截取的字符个数
-（减号）	输出数字或字符在域内向左靠
*/
