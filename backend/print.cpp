//**********************************************//
//** 本题可用贪心算法解决，即用一种颜色尽可能 **//
//** 多的对所有不相邻的点进行着色，然后换另一 **//
//** 种颜色，直至所有点都着色为止。本题的图为 **//   
//** 邻接矩阵                                 **//
//**********************************************//

#include <iostream>
#include "PaintMap.h"

using namespace std;

int main(){
	int i,j,vexNum;
	int matrix[MaxLen][MaxLen];

	cout<<"请输入图的点个数:";
	cin>>vexNum;

	cout<<"请输入邻接矩阵(0表示未连接，1表示连接)"<<endl;
	for(i=0;i<vexNum;i++){
		for(j=0;j<vexNum;j++)
			cin>>matrix[i][j];
	}

	PaintMap pmap(vexNum,matrix);
	pmap.paintColor();
	pmap.display();

	return 0;
}
