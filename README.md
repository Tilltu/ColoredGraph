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

