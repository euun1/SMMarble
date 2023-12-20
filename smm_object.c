//
//  smm_object.c
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

struct {
    int type;
    int credit;
    int energy;
} smm_node[MAX_NODES];

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
int smmObj_getNodeType(void* obj) //노드 타입 반환
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->type;
}

int smmObj_getNodeCredit(void* obj) //학점 반환
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->credit;
}

int smmObj_getNodeEnergy(void* obj) //에너지 반환
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->energy;
}

char* smmObj_getTypeName(int type) //노드 이름 반환 
{
    return smmNodeName[type];
}

smmObjGrade_e smmObj_getNodeGrade(void* obj) //노드 등급 반환 
{
    smmObject_t* ptr = (smmObject_t*)obj;
    return ptr->grade;
}
