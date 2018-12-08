//**********************************************//
//** 本题可用贪心算法解决，即用一种颜色尽可能 **//
//** 多的对所有不相邻的点进行着色，然后换另一 **//
//** 种颜色，直至所有点都着色为止。本题的图为 **//   
//** 邻接矩阵                                 **//
//**********************************************//

#include <iostream>

using namespace std;

const int MaxLen = 20;

class PaintMap{

protected:
	int matrix[MaxLen][MaxLen];  //邻接矩阵，0表示不连接，1表示连接
	int colors[MaxLen];          //颜色数组，表示每个点的着色情况，0为未着色，n表示着第n种颜色
	int vexNum;                  //图的点数
	int colorNum;                //最小着色数
public:
	PaintMap(int vnum,int mat[][MaxLen]){
		int i,j;
		vexNum = vnum;

		for(i=0;i<vexNum;i++){
			for(j=0;j<vexNum;j++)
				matrix[i][j] = mat[i][j];
			colors[i] = 0;      //颜色数组初始化，0表示没有着色
		}
	}
	bool isOk(int index,int nowColor){  //判断该点是否可以进行着色
		int i;
		//出于可能为有向图，用 matrix[index][i] == 1 || matrix[i][index] == 1
		for(i=0;i<vexNum;i++){
			if(matrix[index][i] == 1 || matrix[i][index] == 1 && colors[i] == nowColor && index!=i) //与该点相邻的点颜色为要着的颜色,则该点不能进行着色
				return false;
		}
		return true;
	}
	void paintColor(){
		int i,nowColor;
		bool  flag = true;   //判断是否还有未着色的点，若都已着色，则flag为false
		colors[0] = 1; //第一个点着色为第一种颜色
		nowColor = 0;  //目前要着的颜色
		
		while(flag){
			nowColor++;     //每一次循环就着一种颜色

			for(i=0;i<vexNum;i++){  //对所有点进行判断，符合条件则着色
				if(colors[i]!=0)  //该点已着色
					continue;
				else{
					if(isOk(i,nowColor))
						colors[i] = nowColor;
				}
			}

			for(i=0;i<vexNum;i++){
				if(colors[i] == 0)   //还有点未着色
					break;
			}

			if(i == vexNum){   //全部着色
				colorNum = nowColor;
				flag = false;
			}
			
		}
	}
	void display(){
		int i,j;

		cout<<"矩阵为："<<endl;
		for(i=0;i<vexNum;i++){
			for(j=0;j<vexNum;j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}

		cout<<"最小着色数为："<<colorNum<<endl;

		cout<<"着色情况为："<<endl;
		for(i=0;i<vexNum;i++){
			cout<<"第"<<(i+1)<<"个点为第"<<colors[i]<<"种颜色"<<endl;
		}
	}
} ;

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
