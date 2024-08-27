/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-07-03 21:03:29
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-12 18:03:47
 * @FilePath: /data_structure/src/linklist.c
 * @Description: 
 * 这是一个基于c语言的单链表，支持存储任何数据类型。
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#include <malloc.h>
#include "typedef.h"
#include "my_utils.h"

typedef struct link_node *linklist_t,link_node_t;
struct link_node
{   
    link_node_t *next;
    max_uint_t sizeof_elemtype;
    uint8_t data[0];
};

/***************************************************************
 * @brief 创建单链表（只创建头节点）
 * @param {linklist_t} *list [in]:  链表头节点指针（本质上是个二级指针）
 * @param {max_uint_t} sizeof_elemtype [in]:  一个元素占几个字节（宽度）
 * @param {max_uint_t} num [in]:  需要初始化节点的个数（为0就只初始化头节点）
 * @return {status_t} 
***************************************************************/
status_t linklist_init(linklist_t *list)
{
    (*list) = (link_node_t*)malloc(sizeof(link_node_t));//申请头节点内存
    if(!(*list))    return MEMORY_ALLOCATION_ERROR;
    (*list)->next = NULL_PTR;
    (*list)->sizeof_elemtype = 0;//头节点的元素宽度用来存链表长度

    return SUCCESS;
}

/***************************************************************
 * @brief 释放链表占用所有内存并清空头指针
 * @param {linklist_t} *list [in]:  链表头指针
 * @return {status_t}
***************************************************************/
status_t linklist_destory(linklist_t *list)
{
    link_node_t *p = NULL_PTR;
    while((*list))
    {
        p = (*list);
        free(p);
        if((p)) return MEMORY_FREE_ERROR;

        (*list) = (*list)->next;
    }
    if((*list)) return MEMORY_FREE_ERROR;
    return SUCCESS;
}

/***************************************************************
 * @brief 在序号为<index>的位置插入值为<data>的节点
 * @param {linklist_t} list [in]:  
 * @param {void} *data [in]:  
 * @param {max_uint_t} index [in]:  
 * @return {*}
***************************************************************/
status_t linklist_insert_node(linklist_t list,void *data,max_uint_t index,max_uint_t sizeof_elemtype)
{
    max_uint_t *list_length = &(list->sizeof_elemtype);//头节点的sizeof_elemtype存储了表长
    
    if(!list) return NULL_POINTER_ERROR;
    if(index<1||index>(*list_length)+1) return INDEX_OUT_OF_BOUNDS_ERROR;
    
    link_node_t *p = list;
    for (max_uint_t i = 1; i < index; i++)
    {
        p = p->next;
    }
    link_node_t *s = (link_node_t *)malloc(sizeof(link_node_t)+sizeof_elemtype);
    if(!s) return MEMORY_ALLOCATION_ERROR;

    s->sizeof_elemtype = sizeof_elemtype;
    mem_cpy(data,s->data,sizeof_elemtype);
    s->next = p->next;
    p->next = s;

    (*list_length)++;//表长+1
    return SUCCESS;
}

/***************************************************************
 * @brief 删除序号为<index>的节点
 * @param {linklist_t} list [in]:  
 * @param {max_uint_t} index [in]:  
 * @return {*}
***************************************************************/
status_t linklist_delete_node(linklist_t list,max_uint_t index)
{
    max_uint_t *list_length = &(list->sizeof_elemtype);//头节点的sizeof_elemtype存储了表长
    
    if(!list) return NULL_POINTER_ERROR;
    if(index<1||index>(*list_length)) return INDEX_OUT_OF_BOUNDS_ERROR;

    link_node_t *p = list;
    
    for (max_uint_t i = 1; i < index; i++)
    {
        p = p->next;
    }
    link_node_t *s = p->next;
    p->next = s->next;
    free(s);
     (*list_length)--;//表长-1
    return SUCCESS;

}

/***************************************************************
 * @brief 按值查找，返回对应序号。
 * @param {linklist_t} list [in]:  链表头指针
 * @param {void} *data [in]:  需要查找的值的指针
 * @param {max_uint_t} *index [out]:  返回的序号
 * @return {status_t}
***************************************************************/
status_t linklist_get_index(linklist_t list,void *data,max_uint_t *index)
{
    if((!list)|(!data)) return NULL_POINTER_ERROR;
    
    link_node_t *p = list;
    max_uint_t cnt = 0;
    (*index) = 0;

    while(p)
    {   
        p = p->next;//指向下一个节点
        if(!p) return NOT_FOUND_ERROR;

        if(0 == mem_cmp(p->data,data,p->sizeof_elemtype) )
        {
            (*index) = cnt+1;
            return SUCCESS;
        }
        cnt++;//记录一下序号
    }
    return NOT_FOUND_ERROR;
}

/***************************************************************
 * @brief 根据序号给已存在的节点赋值
 * @param {linklist_t} list [in]:  链表头指针
 * @param {max_uint_t} index [in]:  序号
 * @param {void} *data [in]:  值的指针
 * @return {status_t}
***************************************************************/
status_t linklist_set_data(linklist_t list,max_uint_t index,void *data)
{
    max_uint_t list_length = list->sizeof_elemtype;//头节点的sizeof_elemtype存储了表长
    
    if(!list) return NULL_POINTER_ERROR;
    if(index<1||index>list_length) return INDEX_OUT_OF_BOUNDS_ERROR;

    link_node_t *p = list;
    for(max_uint_t i=0;i<index;i++)
    {
        p = p->next;
    }
    mem_cpy(data,p->data,p->sizeof_elemtype);
    return SUCCESS;
}

/***************************************************************
 * @brief 根据序号取值
 * @param {linklist_t} list [in]:  链表头指针
 * @param {max_uint_t} index [in]:  序号
 * @param {void} **data [out]:  值的二重指针
 * @return {status_t}
***************************************************************/
status_t linklist_get_data(linklist_t list,max_uint_t index,void *data)
{
    max_uint_t list_length = list->sizeof_elemtype;//头节点的sizeof_elemtype存储了表长

    if(!list) return NULL_POINTER_ERROR;
    if(index<1||index>list_length) return INDEX_OUT_OF_BOUNDS_ERROR;

    link_node_t *p = list;
    for(max_uint_t i=0;i<index;i++)
    {
        p = p->next;
    }
    mem_cpy(p->data,data,p->sizeof_elemtype);
    return SUCCESS;
}

