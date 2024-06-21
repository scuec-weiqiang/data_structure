/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:46:25
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-20 11:33:15
 * @FilePath: /data_structure/src/sqlist.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#include <malloc.h>
#include "sqlist.h"  


 //顺序表结构体定义
typedef struct sqlist
{
   max_uint_t elem_size;//顺序表中一个元素所占的字节数
   max_uint_t length;//顺序表长度
   max_uint_t max_length;//顺序表最大长度
   void *elem;//顺序表的元素数组指针
}sqlist_t;


/***************************************************************
 * @description: 初始化顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @param {max_uint_t} elem_size 顺序表中一个元素所占的字节数
 * @param {max_uint_t} max_length 指定顺序表的最大长度，不能超过长度限制（长度限制由<elem_size>参数自动计算得出）
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_init(sqlist_t **list,max_uint_t elem_size,max_uint_t max_length)
{
    max_uint_t temp = -1;
    temp = temp/elem_size;//由一个元素所占的字节数计算出表的最大长度
    if(max_length>temp)//如果指定的长度超过最大长度，则对指定长度进行限制
    {
        max_length = temp;
    }
    
    *list = (sqlist_t*) malloc(sizeof(sqlist_t) + elem_size*max_length);//为顺序表分配空间
    if(!list)
    {
        return OVERFLOW; //分配空间失败
    }

    (*list)->length = 0;
    (*list)->max_length = max_length;
    (*list)->elem_size = elem_size;
    (*list)->elem = (void*)(*list + 1);
    
    return OK;
}


/***************************************************************
 * @description: 销毁顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_destory(sqlist_t **list)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }

    free(*list);
    *list = NULL;
    return OK;
}


/***************************************************************
 * @description: 清空顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 返回操作状态 <1>:成功  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_clear(const sqlist_t *list)
{
    void *pelem = list->elem;
    max_uint_t *length = (max_uint_t *)&list->length;
    max_uint_t elem_size = list->elem_size;

    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }

    for(max_uint_t i=0;i<((*length)*elem_size);i++)
    {
        *((char*)pelem + i) = 0;
    }
    *length = 0;
    return OK;
}


/***************************************************************
 * @description: 获得顺序表中元素个数
 * @param {sqlist_t} *list
 * @param {max_uint_t} *length
 * @return {*}
***************************************************************/
status_t sqlist_get_length(const sqlist_t *list,max_uint_t *length)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }

    *length = list->length;
    return OK;
}


/***************************************************************
 * @description: 返回顺序表中位置为<pos>的元素的值。
 * @param {sqlist_t} *list 顺序表的指针
 * @param {int} pos 指定位置（从1开始算起）
 * @param {void} *elem 返回的值的指针 
 * @return {status_t} 返回操作状态 <1>:成功  <0>:越界  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_get_elem(const sqlist_t *list,max_uint_t pos,void **elem)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }

    if(pos<1||pos>list->length)
    {
        return ERRO;//越界
    }
    (*elem) = (list->elem + (pos-1)*list->elem_size);
    return OK;
}


/***************************************************************
 * @description: 返回顺序表中第一个值为<elem>的元素的位置
 * @param {sqlist_t} *list 顺序表的指针
 * @param {sqlist_elem_t} elem 想要在顺序表中查找的值
 * @param {max_uint_t} pos 值为<elem>的元素的位置（从1开始算起）
 * @return {status_t} 返回操作状态 <1>:成功  <0>:失败  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_get_position(const sqlist_t *list,void *elem,max_uint_t *pos)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }

    void *pelem = list->elem;
    max_uint_t elem_size = list->elem_size;
    max_uint_t cnt = 0;
    
    for(max_uint_t i=0;i<list->length;i++)
    {
        cnt = 0;
        for(max_uint_t j=0;j<elem_size;j++)
        {
            if( *((char*)pelem + i*elem_size + j) == *((char*)elem + j) )
            {
                cnt++;
            }  
        }
        if(list->elem_size == cnt)
        {
            *pos = i+1;
            return OK;
        }
    }

    return ERRO;//没找到
}


/***************************************************************
 * @description: 在表中<pos>的位置上插入元素<elem>
 * @param {sqlist_t} *list 顺序表的指针
 * @param {sqlist_elem_t} elem 想要在顺序表中插入的值
 * @param {max_uint_t} pos 想插入的位置（从1开始算起）
 * @return {status_t} 返回操作状态 <1>:成功  <0>:失败  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_insert_elem(const sqlist_t *list,void *elem,max_uint_t pos)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }
    if(pos<1||pos>list->length+1)//  允许pos=list->length，这种情况是在表尾插入
    {
        return ERRO;//越界
    }
    if(list->length==list->max_length)
    {
        return OVERFLOW;//表满了
    }

    void *pelem = list->elem;
    max_uint_t *length = (max_uint_t *)&list->length;
    max_uint_t elem_size = list->elem_size;
    
    for(max_uint_t i=(*length);i>(pos-1);i--)//第<pos>个后的元素中的每个字节数据依次向后移动<elem_size>个字节
    {
        for(max_uint_t j=elem_size;j>0;j--)
        {
            *((char*)pelem + i*elem_size + j-1) = *((char*)pelem +(i-1)*elem_size + j-1);
        }
    }
    
    for(max_uint_t j=elem_size;j>0;j--)//向<pos>位置的元素写入要插入的数据
    {
        *((char*)pelem + (pos-1)*elem_size + j-1) = *((char*)elem + j-1);
    }

    (*length)++;//表长加1
    return OK;
}


/***************************************************************
 * @description: 在表中<pos>的位置上插入元素<elem>
 * @param {sqlist_t} *list 顺序表的指针
 * @param {max_uint_t} pos 删除的位置（从1开始算起）
 * @return {status_t} 返回操作状态 <1>:成功  <0>:失败  <-2>:顺序表不存在或已满
***************************************************************/
status_t sqlist_delete_elem(const sqlist_t *list,max_uint_t pos)
{
    if(!list)
    {
        return OVERFLOW;//顺序表不存在
    }
    if(pos<1||pos>list->length+1)//  允许pos=list->length，这种情况是在表尾删除
    {
        return ERRO;//越界
    }

    void *pelem = list->elem;
    max_uint_t *length =(max_uint_t*)&list->length;
    max_uint_t elem_size = list->elem_size;

    for(max_uint_t i=(pos-1);i>(*length);i++)//第<pos>个后的元素中的每个字节数据依次向前移动<elem_size>个字节
    {
        for(max_uint_t j=elem_size;j>0;j--)
        {
            *((char*)pelem + i*elem_size + j-1) = *((char*)pelem +(i+1)*elem_size + j-1);
        }
    }
    (*length)--;//表长减1
    return OK;
}