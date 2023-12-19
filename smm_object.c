//
//  smm_node.c
//  SMMarble
//
//  Created by Daeun Jung on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define MAX_NODE        100


// 각 객체의 정보를 저장하는 구조체
/*typedef struct smmObject {
    char name[MAX_CHARNAME];
    smmObjType_e objType;
    int type;
    int credit;
    int energy;
    smmObjGrade_e grade;
} smmObject_t; */

// 다양한 노드의 이름을 저장하는 배열 
static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME] = {
       "강의",
       "식당",
       "실험실",
       "집",
       "실험실로이동",
       "음식찬스",
       "축제시간"
};

// 객체 생성 함수
/*void* smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade)
{
    smmObject_t* ptr = (smmObject_t*)malloc(sizeof(smmObject_t));

    strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;

    return ptr;
} */

/*
//노드의 이름을 반환하는 함수 
char* smmObj_getTypeName(int type)
{
      return (char*)smmNodeName[type];
}

// 노드의 타입을 반환하는 함수
int smmObj_getNodeType(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->type;
}

// 노드의 학점을 반환하는 함수
int smmObj_getNodeCredit(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->credit;
}

// 노드의 에너지를 반환하는 함수
int smmObj_getNodeEnergy(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->energy;
} 
*/

typedef enum smmObjGrade {
    smmObjGrade_Ap = 0,
    smmObjGrade_A0,
    smmObjGrade_Am,
    smmObjGrade_Bp,
    smmObjGrade_B0,
    smmObjGrade_Bm,
    smmObjGrade_Cp,
    smmObjGrade_C0,
    smmObjGrade_Cm
} smmObjGrade_e;

//1. 구조체 형식 정의
typedef struct smmObject {
       char name[MAX_CHARNAME];
       smmObjType_e objType; 
       int type;
       int credit;
       int energy;
       smmObjGrade_e grade;
} smmObject_t;

//static smmObject_t smm_node[MAX_NODE];
//static int smmObj_noNode = 0;

//3. 관련 함수 변경 
//object generation
void* smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade)
{    
    smmObject_t* ptr;
    
    ptr = (smmObject_t*)malloc(sizeof(smmObject_t));
    
    strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    return ptr;
}

//3. 관련 함수 변경 
char* smmObj_getNodeName(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    
    return ptr->name;
}

//3. 관련 함수 변경 
int smmObj_getNodeType(int node_nr)
{
    return smm_node[node_nr].type;
}

int smmObj_getNodeCredit(int node_nr)
{
    return smm_node[node_nr].credit;
}

int smmObj_getNodeEnergy(int node_nr)
{
    return smm_node[node_nr].energy;
}
