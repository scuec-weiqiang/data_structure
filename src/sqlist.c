/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:46:25
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-05 23:25:41
 * @FilePath: /data_structure/src/sqlist.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#include "sqlist.h"
#include "malloc.h"

/***************************************************************
 * @description: 初始化顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_init(sqlist_t *list)
{
    list->elem = (elemtype_t *)malloc(sizeof(elemtype_t)*MAXSIZE);//为顺序表分配空间
    if(!list->elem)
    {
        return OVERFLOW; //分配空间失败
    }

    list->length = 0;
    return OK;
}

/***************************************************************
 * @description: 销毁顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_destory(sqlist_t *list)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }

    free(list->elem);
    return OK;
}

/***************************************************************
 * @description: 清空顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_clear(sqlist_t *list)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }

    for(unsigned int i=0;i<list->length;i++)
    {
        list->elem[i] = 0;
    }
    list->length = 0;
    return OK;
}

/***************************************************************
 * @description: 返回顺序表中位置为<pos>的元素的值。
 * @param {sqlist_t} *list 顺序表的指针
 * @param {int} pos 指定位置（从1开始算起）
 * @param {elemtype_t} *data 返回的值的指针 
 * @return {status_t} 返回操作状态 <1>:成功  <0>:越界  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_get_elem(sqlist_t *list,unsigned int pos,elemtype_t *data)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }

    if(pos<1||pos>list->length)
    {
        return ERRO;//越界
    }
    *data = list->elem[pos-1];
    return OK;
}

/***************************************************************
 * @description: 返回顺序表中第一个值为<data>的元素的位置
 * @param {sqlist_t} *list 顺序表的指针
 * @param {elemtype_t} data 想要在顺序表中查找的值
 * @param {unsigned int} pos 值为<data>的元素的位置（从1开始算起）
 * @return {status_t} 返回操作状态 <1>:成功  <0>:失败  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_get_position(sqlist_t *list,elemtype_t data,unsigned int *pos)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }

    for(unsigned int i=0;i<list->length;i++)
    {
        if (list->elem[i]==data)
        {
            *pos = i+1;
            return OK; //找到了
        }
    }
    return ERRO;//没找到
}

/***************************************************************
 * @description: 在表中<pos>的位置上插入元素<data>
 * @param {sqlist_t} *list 顺序表的指针
 * @param {elemtype_t} data 想要在顺序表中插入的值
 * @param {unsigned int} pos 想插入的位置（从1开始算起）
 * @return {status_t} 返回操作状态 <1>:成功  <0>:失败  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_insert_elem(sqlist_t *list,elemtype_t data,unsigned int pos)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }
    if(pos<1||pos>list->length+1)//  允许pos=list->length，这种情况是在表尾插入
    {
        return ERRO;//越界
    }
    if(list->length==MAXSIZE)
    {
        return OVERFLOW;//表满了
    }

    for(unsigned int i=list->length;i>pos-1;i--)//第<pos>个后的元素依次向后移动
    {
        list->elem[i] = list->elem[i-1];
    }
    list->elem[pos-1] = data;
    list->length++;//表长加1
    return OK;
}

status_t sqlist_delete_elem(sqlist_t *list,unsigned int pos)
{
    if(!list->elem)
    {
        return OVERFLOW;//顺序表不存在
    }
    if(pos<1||pos>list->length+1)//  允许pos=list->length，这种情况是在表尾删除
    {
        return ERRO;//越界
    }

    for(unsigned int i=pos-1;i>list->length;i++)//第<pos>个后的元素依次向前移动
    {
        list->elem[i] = list->elem[i+1];
    }
    list->length--;//表长减1
    return OK;
}