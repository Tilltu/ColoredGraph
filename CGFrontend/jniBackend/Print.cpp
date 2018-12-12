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


using namespace std;



/*
 * Class:     Input
 * Method:    MapPrint
 * Signature: ([I)V
 */
JNIEXPORT jint

JNICALL Java_Input_MapPrint
        (JNIEnv *env, jclass class_, jintArray adj_matrix) {

    //printf("[ Receiving Data From Java ]");
    jboolean isCopy = TRUE;

    jint * receivedint = env->GetIntArrayElements(adj_matrix, &isCopy);
    INT32 vex_num = (INT32) env->GetArrayLength(adj_matrix);
    vex_num = sqrt(vex_num);
    //printf("[ Receiving Data From Java ]");

    INT32 i, j;

    INT32 **matrix;
    matrix = new INT32 *[vex_num];
    for (i = 0; i < vex_num; i++) {
        matrix[i] = new INT32[vex_num];
    }

    INT32 flag = 0;
    for (i = 0; i < vex_num; i++) {
        for (j = i; j < (i + vex_num); j++) {
            matrix[i][j % vex_num] = (INT32) receivedint[flag++];
        }
    }

    for (i = 0; i < vex_num; i++) {
        for (j = 0; j < vex_num; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    //int i, j;
    INT32 m[MaxLen][MaxLen];

    for (i = 0; i < vex_num; i++) {
        for (j = 0; j < vex_num; j++) {
            m[i][j] = matrix[i][j];
        }
    }

    PaintMap pmap(vex_num, m);
    pmap.coloring();
    //pmap.display();



    for (i = 0; i < vex_num; i++) {
        delete[] matrix[i];
    }
    delete matrix;

    env->ReleaseIntArrayElements(adj_matrix, receivedint, 0);

    return (jint)
    pmap.getColorNum();

}
