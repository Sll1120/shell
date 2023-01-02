#!/bin/bash
# **********************************************************
# * Author : liangliangSu
# * Email : sll917@hotmail.com
# * Create time : 2023-01-02 17:15
# * Filename : 56批量添加扩展名.sh
# **********************************************************
#下面的示例将对目录中的所有文件应用自定义扩展名。创建一个新目录并将一些文件放在那里以进行演示。我的文件夹共有五个文件，每个文件名为 test 后跟 (0-4)。我已将此脚本编程为在文件末尾添加（ .UP） 。你可以添加任何你想要的扩展。
#!/bin/bash
dir=$1 
for file in `ls $1/*`
do 
mv $file $file.UP
done
