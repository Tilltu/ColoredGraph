//
// Created by parallels on 12/8/18.
//

#ifndef COLOREDGRAPH_PAINTMAP_H
#define COLOREDGRAPH_PAINTMAP_H

#endif //COLOREDGRAPH_PAINTMAP_H



#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef int INT32;

#define  ERROR         1;
#define  OK            0;
#define  NOTFOUND      -1;
#define  FOUND         1;
#define  error         false;
#define  ok            true;
#define  Is_Print(a, b) if(a) printf b;
#define  If_Choose(a, b, c) a ? printf b : printf c;
#define  If_CChoose(a, b, c) a ? cout << b << endl : cout << c << endl;
#define  Is_Cout(a, b) if(a) cout<< b << endl;

using namespace std;

const INT32 MaxLen = 10;

//**********************************************//
//** 本题可用贪心算法解决，即用一种颜色尽可能 **//
//** 多的对所有不相邻的点进行着色，然后换另一 **//
//** 种颜色，直至所有点都着色为止。本题的图为 **//
//** 邻接矩阵                                 **//
//**********************************************//


string to_string(INT32 a)
{
   ostringstream ostr;
   ostr << a;
   string astr = ostr.str();
   //cout << astr <<endl;
   return astr ;
}






class Color {
public:
    string color;
    bool occupied;

    Color() {
        occupied = false;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setoccupied() {
        occupied = true;
    }
};

Color colornode[10];


void resetIfOccupied() {
    INT32 i;

    for (i = 0; i < 10; i++) {
        colornode[i].occupied = false;
    }
}

void occupyExistingColor(string inputcolor) {
    for (INT32 i = 0; i < 10; i++) {
        if (inputcolor == colornode[i].color) {
            colornode[i].setoccupied();
        }
    }
}

INT32 getNearestColor() {
    for (INT32 i = 0; i < 10; i++) {
        if (!colornode[i].occupied) {
            return i;
        }
    }
    return -1;
}

class Vertex {
public:
    string name;
    string color;

    Vertex() {
        color = "null";
    }
};


class PaintMap {

protected:
    INT32 matrix[MaxLen][MaxLen];  //邻接矩阵，0表示不连接，1表示连接
    INT32 colors[MaxLen];          //颜色数组，表示每个点的着色情况，0为未着色，n表示着第n种颜色
    Vertex vertices[MaxLen];      //vertex array
    INT32 vexNum;                  //图的点数
    INT32 colorNum;                //最小着色数
    vector<string> counter;

public:
    PaintMap(INT32 vnum, INT32 mat[][MaxLen]) {
        INT32 i, j;
        vexNum = vnum;

        for (i = 0; i < vexNum; i++) {
            for (j = 0; j < vexNum; j++)
                matrix[i][j] = mat[i][j];
            colors[i] = 0;      //颜色数组初始化，0表示没有着色
        }

        for (i = 0; i < vexNum; i++) {
            for (j = 0; j < vexNum; j++) {
                if (matrix[i][j] == 1) {
                    matrix[j][i] = 1;
                }
            }
        }
    }


    string getVexColor(INT32 index) {
        return vertices[index].color;
    }


    string coloring() {
        colornode[0].color = "green";
        colornode[1].color = "red";
        colornode[2].color = "blue";
        colornode[3].color = "yellow";
        colornode[4].color = "orange";
        colornode[5].color = "black";
        colornode[6].color = "cyan";
        colornode[7].color = "magenta";
        colornode[8].color = "grey";
        colornode[9].color = "pink";


        INT32 i, j;



        vertices[0].color = colornode[0].color;
        counter.push_back(vertices[0].color);
        for (i = 1; i < vexNum; i++) {
            for (j = 0; j < vexNum; j++) {
                if (matrix[i][j] == 1) {
                    string res = getVexColor(j);
                    if (res != "null") {
                        occupyExistingColor(res);
                    }

                }
            }
            vertices[i].color = colornode[getNearestColor()].color;
            if (!isColorInCounter(vertices[i].color)) {
                counter.push_back(vertices[i].color);
            }
            resetIfOccupied();
        }

        cout << "[ The Chromatic Number Is ] : " << counter.size() << endl;
        colorNum = static_cast<INT32> (counter.size());

        string result = "";

        for (i = 0; i < vexNum; i++) {
            //string portion =  "Vertex " + to_string(i + 1) + "'s Color Is " + vertices[i].color + "\n";
            string portion;

            if (i != vexNum - 1) {
              portion = to_string(i + 1) + "-" + vertices[i].color + "-";
            } else {
              portion = to_string(i + 1) + "-" + vertices[i].color;
            }

            result+=portion;
        }

        //cout << result;

        return result;

    }


    bool isColorInCounter(string color) {
        INT32 i;
        if (counter.size() == 0) {
            return false;
        }

        for (i = 0; i < counter.size(); i++) {
            if (color == counter[i]) {
                return true;
            }
        }

        return false;
    }


    void display() {
        INT32 i, j;

        cout << "矩阵为：" << endl;
        for (i = 0; i < vexNum; i++) {
            for (j = 0; j < vexNum; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "最小着色数为：" << colorNum << endl;

        cout << "着色情况为：" << endl;
        for (i = 0; i < vexNum; i++) {
            cout << "第" << (i + 1) << "个点为第" << colors[i] << "种颜色" << endl;
        }
    }


    int getColorNum() {
        return this->colorNum;
    }
};
