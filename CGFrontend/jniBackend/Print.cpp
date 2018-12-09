//**********************************************//
//** 本题可用贪心算法解决，即用一种颜色尽可能 **//
//** 多的对所有不相邻的点进行着色，然后换另一 **//
//** 种颜色，直至所有点都着色为止。本题的图为 **//   
//** 邻接矩阵                                 **//
//**********************************************//


#define TRUE (bool (1))


#include <iostream>
#include <jni.h>
#include <math.h>
#include "Input.h"
#include "PaintMap.h"


//using namespace std;

void  print(int vex_num, int adj_matrix[MaxLen][MaxLen]){
	int i, j;
	int matrix[MaxLen][MaxLen];

	for (i = 0;i < vex_num;i++) {
	   for (j = 0;j < vex_num;j++) {
	      matrix[i][j] = adj_matrix[i][j];
	   }
	}

	PaintMap pmap(vex_num, matrix);
	pmap.paintColor();
	pmap.display();

}


/*
 * Class:     Input
 * Method:    MapPrint
 * Signature: ([I)V
 */
JNIEXPORT jint JNICALL Java_Input_MapPrint
  (JNIEnv *env, jclass class_, jintArray adj_matrix) {

     //printf("[ Receiving Data From Java ]");
     jboolean isCopy = TRUE;

     jint* receivedint = env->GetIntArrayElements(adj_matrix, &isCopy);
     int vex_num = (int) env->GetArrayLength(adj_matrix);
     vex_num = sqrt(vex_num);
     //printf("[ Receiving Data From Java ]");

     int i, j;

     int **matrix;
     matrix = new int*[vex_num];
     for (i = 0;i < vex_num;i++) {
        matrix[i] = new int[vex_num];
     }

     for (i = 0; i < vex_num; i++) {
        for (j = i;j < (i + vex_num);j++) {
           matrix[i][j % vex_num] = (int) receivedint[j];
        }
     }



    //int i, j;
	int m[MaxLen][MaxLen];

	for (i = 0;i < vex_num;i++) {
	   for (j = 0;j < vex_num;j++) {
	      m[i][j] = matrix[i][j];
	   }
	}

	PaintMap pmap(vex_num, m);
	pmap.paintColor();
	//pmap.display();



     for(i = 0;i < vex_num;i++) {
        delete[] matrix[i];
     }
     delete matrix;

     env->ReleaseIntArrayElements(adj_matrix, receivedint, 0);

     return (jint) pmap.getColorNum();

}
