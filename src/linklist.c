/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-25 14:28:39
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-03 18:13:06
 * @FilePath: /data_structure/src/linklist.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#include <malloc.h>
#include "linklist.h"

/***************************************************************
 * @description: 单链表取值
 * @param {linklist_t} list 单链表头指针
 * @param {unsigned int} pos 被取值的元素的序号
 * @param {elemtype_t} *data 返回的元素
 * @return {status_t} 返回操作状态 <0>:越界  <1>:成功  <-2>:链表不存在或已满
***************************************************************/
status_t linklist_get_elem(linklist_t list,max_uint_t pos,elemtype_t *data)
{
    if(!list)   return NULL_POINTER_ERROR;//链表不存在

    link_node_t *p = list->next;
    if(!p)  return INDEX_OUT_OF_BOUNDS_ERROR;//越界

    for(max_uint_t i=1;i<pos;i++)//遍历,如果能找到，最后应该i==pos
    {
        p = p->next;
        if(!p)  return NOT_FOUND_ERROR;//都遍历到尾节点了还没退出循环说明没找到
    }
    *data = p->data;
    return SUCCESS;
}

/***************************************************************
 * @description: 在单链表中查找值为<data>的元素，并返回其地址
 * @param {linklist_t} list 单链表头指针
 * @param {elemtype_t} data 需要查找的值
 * @param {link_node_t} *node 返回对应的地址
 * @return {*}
***************************************************************/
status_t linklist_get_node(linklist_t list,elemtype_t data,link_node_t **node)
{
    if(!list) return NULL_POINTER_ERROR;//链表不存在

    link_node_t *p = list->next;
    while(p)
    {
        if(data == p->data)
        {
            *node = p;
            return SUCCESS;
        }
        p = p->next;
    }
    return NOT_FOUND_ERROR;
}

/***************************************************************
 * @description: 单链表向序号为<pos>的位置插入元素<data>
 * @param {linklist_t} list 单链表头指针
 * @param {elemtype_t} data 需要插入的值
 * @param {max_uint_t} pos 需要插入的位置
 * @return {*}
***************************************************************/
status_t linklist_insert_node(linklist_t list,elemtype_t data,max_uint_t pos)
{
    if(!list)   return NULL_POINTER_ERROR;//链表不存在
    if(pos<1)   return INDEX_OUT_OF_BOUNDS_ERROR;//越界

    link_node_t *p = list;
    for (max_uint_t i = 1; i < pos-1; i++)
    {
        p = p->next;
        if(!p)  return INDEX_OUT_OF_BOUNDS_ERROR;
    }
    
    link_node_t *s = (link_node_t *)malloc(sizeof(link_node_t));
    if(!s) return MEMORY_ALLOCATION_ERROR;

    s->data = data;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}

/***************************************************************
 * @description: 删除单链表中序号为<pos>的元素
 * @param {linklist_t} list
 * @param {max_uint_t} pos
 * @return {*}
***************************************************************/
status_t linklist_delete_node(linklist_t list,max_uint_t pos)
{
    if(!list)   return NULL_POINTER_ERROR;//链表不存在
    if(pos<1)   return INDEX_OUT_OF_BOUNDS_ERROR;//越界

    link_node_t *p = list;
    for (max_uint_t i = 1; i < pos; i++)
    {
        p = p->next;
        if(!p)  return INDEX_OUT_OF_BOUNDS_ERROR;
    }
    link_node_t *s = p->next;
    p->next = s->next;
    free(s);
    return SUCCESS;
}

/***************************************************************
 * @description: 
 * @param {linklist_t} *list
 * @return {*}
***************************************************************/
status_t linklist_destory(linklist_t *list)
{
    link_node_t *p = NULL_PTR;
    while((*list))
    {
        p = (*list);
        (*list) = (*list)->next;
        free(p);
    }
    return SUCCESS;
}

/***************************************************************
 * @description: 创建单链表并初始化为0(前插法)
 * @param {linklist_t} list 单链表头指针
 * @param {max_uint_t} num 需要初始化的节点个数，若为0则只创建一个头节点。
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:链表不存在或已满
***************************************************************/
status_t linklist_init(linklist_t *list,max_uint_t num)
{
    (*list) = (link_node_t*)malloc(sizeof(link_node_t));//创建头节点
    if(!(*list))   return NULL_POINTER_ERROR;//创建失败
    (*list)->data = 0;
    (*list)->next = NULL_PTR;

    link_node_t *p = NULL_PTR;
    for(max_uint_t i=0;i<num;i++)
    {
        p = (link_node_t*)malloc(sizeof(linklist_t));//创建节点
        if(!p) 
        {
            linklist_destory((linklist_t *)(*list));
            return MEMORY_ALLOCATION_ERROR;
        }
        p->data = 0;
        p->next = (*list)->next;
        (*list)->next = p;
    }
    return SUCCESS;
}