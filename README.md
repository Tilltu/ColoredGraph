# ColoredGraph
Data Structure Project By Group 11


Step1:
下载一个Ubuntu虚拟机并安装

Step2:
打开终端输入 sudo apt-get install gcc, sudo apt-get install g++, sudo apt-get install git, sudo apt-get install openjdk-8-jdk

Step3:
安装一个IntelliJ IDEA

Step4:
打开终端， 
a). cd ~
b). git clone https://github.com/Tilltu/ColoredGraph
c). cd ColoredGraph

Step5:
（可选）
打开IDEA，打开ColoredGraph目录，在File -- Setting 中的Tools中设置External Tools添加两个Tools

1）GenerateHeader
Program: /usr/bin/javah
Arguments: -jni -classpath $OutputPath$ -d ./CGFrontend/jniBackend $FileClass$
Working Directory: $ProjectFileDir$

2)GenerateSOCPP
Program: /usr/bin/g++
Arguments: -fPIC -I"/usr/lib/jvm/java-8-openjdk-amd64/include" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux" -shared -o ./CGFrontend/lib/lib$FileNameWithoutExtension$.so ./CGFrontend/jniBackend/$FileNameWithoutExtension$.cpp
Working Directory: $ProjectFileDir$

Step6:
使用GenerateHeader来生成Java的JNI的.h文件，然后在c++中实现方法后使用GenerateSOCPP来生成.so文件

Step7:
运行Java文件时，在Edit Configuration中的VM options中添加 -Djava.library.path=/home/parallels/ColoredGraph/CGFrontend/lib 后可运行





******************************************************************************************************************************
******************************************************************************************************************************
******************************************************************************************************************************
******************************************************************************************************************************

核心算法：

1. 对每个顶点遍历，发现其所在行的邻接矩阵存在为1的时候就去找该点对应的列的顶点的颜色，如果不是”null“的话就把颜色数组colornode的那个颜色置为occupied，表明该颜色已存在，不能上这种颜色。
2. 当这一行的矩阵遍历完时，在colornode中寻找最先找到的未occupied的颜色给该顶点上色，上色完后重置colornode的occupied状态，并判断该颜色在颜色计数器counter中有没有，没有就加入该颜色。
3. counter的size就是最少需要的颜色数。

注意：

目前
1. 最大颜色数为10， 留待改进。
2. 顶点最大数为10， 留待改进。

![RESULTS](https://github.com/Tilltu/ColoredGraph/raw/master/assets/CG.png)

