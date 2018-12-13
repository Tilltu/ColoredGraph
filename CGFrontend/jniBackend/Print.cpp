//**********************************************//
//** 本题可用贪心算法解决，即用一种颜色尽可能 **//
//** 多的对所有不相邻的点进行着色，然后换另一 **//
//** 种颜色，直至所有点都着色为止。本题的图为 **//   
//** 邻接矩阵                                 **//
//**********************************************//


#define TRUE (bool (1))


#include <iostream>
#include <jni.h>
#include <string>
#include <string.h>
#include <memory>
#include <math.h>
#include "Input.h"
#include "PaintMap.h"


using namespace std;

static string result;

/*
 * Class:     Input
 * Method:    getColorInfo
 * Signature: ([I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Input_getColorInfo
        (JNIEnv *env, jclass class_, jintArray adj_matrix) {

    jboolean isCopy = TRUE;

    jint * receivedint = env->GetIntArrayElements(adj_matrix, &isCopy);
    INT32 vex_num = (INT32) env->GetArrayLength(adj_matrix);
    vex_num = sqrt(vex_num);

    INT32 i, j;

    INT32 **matrix;
    matrix = new INT32 *[vex_num];
    for (i = 0; i < vex_num; i++) {
        matrix[i] = new INT32[vex_num];
    }

    INT32 flag = 0;
    for (i = 0; i < vex_num; i++) {
        for (j = 0; j <  vex_num; j++) {
            matrix[i][j] = (INT32) receivedint[flag++];
        }
    }

    for (i = 0; i < vex_num; i++) {
        for (j = 0; j < vex_num; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    INT32 m[MaxLen][MaxLen];

    for (i = 0; i < vex_num; i++) {
        for (j = 0; j < vex_num; j++) {
            m[i][j] = matrix[i][j];
        }
    }

    PaintMap pmap(vex_num, m);
    string result = pmap.coloring();



    for (i = 0; i < vex_num; i++) {
        delete[] matrix[i];
    }
    delete matrix;

    env->ReleaseIntArrayElements(adj_matrix, receivedint, 0);


   result = to_string(pmap.getColorNum()) + "-" + result;
   //cout << "[ RESULT IS ]   " << result << endl;
   const char * res = result.c_str();
   //cout << "[ RES IS ]      " << res << endl;
   jstring rtstr = env->NewStringUTF(res);
   return rtstr;



}



