/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:46:25
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-07 15:39:39
 * @FilePath: /data_structure/src/sqlist.c
 * @brief: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#include <malloc.h>
#include "typedef.h" 
#include "my_utils.h"

 //顺序表结构体定义
typedef struct sqlist sqlist_t;
struct sqlist
{
   max_uint_t sizeof_elemtype;//顺序表中一个元素所占的字节数
   max_uint_t length;//顺序表长度
   max_uint_t max_length;//顺序表最大长度
   void *data;//顺序表的元素数组指针
};

/***************************************************************
 * @brief 初始化顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @param {max_uint_t} sizeof_elemtype 顺序表中一个元素所占的字节数
 * @param {max_uint_t} max_length 指定顺序表的最大长度，不能超过长度限制（长度限制由<sizeof_elemtype>参数自动计算得出）
 * @return {status_t} 
***************************************************************/
status_t sqlist_init(sqlist_t **list,max_uint_t sizeof_elemtype,max_uint_t max_length)
{
    max_uint_t temp = -1;//手动使无符号溢出，使其达到最大值
    temp = temp/sizeof_elemtype;//由一个元素所占的字节数计算出表的最大长度
    if(max_length>temp)//如果指定的长度超过最大长度，则对指定长度进行限制
    {
        max_length = temp;
    }
    
    *list = (sqlist_t*) malloc(sizeof(sqlist_t) + sizeof_elemtype*max_length);//为顺序表分配空间
    if(!list)
    {
        return MEMORY_ALLOCATION_ERROR; //分配空间失败
    }

    (*list)->length = 0;
    (*list)->max_length = max_length;
    (*list)->sizeof_elemtype = sizeof_elemtype;
    (*list)->data = (void*)(*list + 1);
    mem_set((*list)->data,0,sizeof_elemtype*max_length);

    return SUCCESS;
}

/***************************************************************
 * @brief 销毁顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t} 
***************************************************************/
status_t sqlist_destory(sqlist_t **list)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }

    free(*list);
    *list = NULL;
    return SUCCESS;
}

/***************************************************************
 * @brief 清空顺序表
 * @param {sqlist_t} *list 顺序表的指针
 * @return {status_t}
***************************************************************/
status_t sqlist_clear(sqlist_t *list)
{
    void *pdata = list->data;
    max_uint_t *length = (max_uint_t *)&list->length;
    max_uint_t sizeof_elemtype = list->sizeof_elemtype;

    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }
    mem_set(pdata,0,(*length)*sizeof_elemtype);
    *length = 0;
    return SUCCESS;
}

/***************************************************************
 * @brief 获得顺序表中元素个数
 * @param {sqlist_t} *list
 * @param {max_uint_t} *length
 * @return {*}
***************************************************************/
status_t sqlist_get_length(sqlist_t *list,max_uint_t *length)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }

    *length = list->length;
    return SUCCESS;
}

/***************************************************************
 * @brief 将顺序表中位置为<index>的元素赋值为<data>。
 *        注意，当表中元素个数为0时需要先使用insert函数插入才可赋值
 * @param {sqlist_t} *list [in]:  
 * @param {max_uint_t} index [in]:  
 * @param {void} *data [in]:  
 * @return {*}
***************************************************************/
status_t sqlist_set_data(sqlist_t *list,max_uint_t index,void *data)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }

    if(index<1||index>list->length)
    {
        return INDEX_OUT_OF_BOUNDS_ERROR;//越界
    }
    mem_cpy(data,(list->data + (index-1)*list->sizeof_elemtype),list->sizeof_elemtype);
    return SUCCESS;
}

/***************************************************************
 * @brief 返回顺序表中位置为<index>的元素的值。
 * @param {sqlist_t} *list 顺序表的指针
 * @param {int} index 指定位置（从1开始算起）
 * @param {void} *data 返回的值的指针 
 * @return {status_t} 
***************************************************************/
status_t sqlist_get_data(sqlist_t *list,max_uint_t index,void *data)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }

    if(index<1||index>list->length)
    {
        return INDEX_OUT_OF_BOUNDS_ERROR;//越界
    }
    mem_cpy((list->data + (index-1)*list->sizeof_elemtype),data,list->sizeof_elemtype);
    return SUCCESS;
}

/***************************************************************
 * @brief 返回顺序表中第一个值为<data>的元素的位置
 * @param {sqlist_t} *list 顺序表的指针
 * @param {sqlist_elem_t} data 想要在顺序表中查找的值
 * @param {max_uint_t} index 值为<data>的元素的位置（从1开始算起）
 * @return {status_t} 
***************************************************************/
status_t sqlist_get_position(sqlist_t *list,void *data,max_uint_t *index)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }

    void *pdata = list->data;
    max_uint_t sizeof_elemtype = list->sizeof_elemtype;

    *index = 0;
    for(max_uint_t i=0;i<list->length;i++)
    {
        if(0 == mem_cmp( ((char*)pdata + i*sizeof_elemtype),data,sizeof_elemtype) )
        {
            *index = i+1;
            return SUCCESS;
        }
    }

    return NOT_FOUND_ERROR;//没找到
}

/***************************************************************
 * @brief 在表中<index>的位置上插入元素<data>
 * @param {sqlist_t} *list 顺序表的指针
 * @param {sqlist_elem_t} data 想要在顺序表中插入的值
 * @param {max_uint_t} index 想插入的位置（从1开始算起）
 * @return {status_t} 
***************************************************************/
status_t sqlist_insert_data(sqlist_t *list,max_uint_t index,void *data)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }
    if(index<1||index>list->length+1)//  允许pos=list->length，这种情况是在表尾插入
    {
        return INDEX_OUT_OF_BOUNDS_ERROR;//越界
    }
    if(list->length==list->max_length)
    {
        return FULL_SIZE_ERROR;//表满了
    }

    void *pdata = list->data;
    max_uint_t *length = (max_uint_t *)&list->length;
    max_uint_t sizeof_elemtype = list->sizeof_elemtype;
    
    //第<index>个后的所有元素整体向右移动<sizeof_elemtype>个字节
    mem_right_shift(pdata,((*length)-index+1)*sizeof_elemtype,sizeof_elemtype);
    //向<index>位置的元素写入要插入的数据
    mem_cpy(data,((char*)pdata + (index-1)*sizeof_elemtype),sizeof_elemtype);
    (*length)++;//表长加1
    
    return SUCCESS;
}

/***************************************************************
 * @brief 删除在表中序号<index>位置的元素
 * @param {sqlist_t} *list 顺序表的指针
 * @param {max_uint_t} index 删除的位置（从1开始算起）
 * @return {status_t} 
***************************************************************/
status_t sqlist_delete_data(sqlist_t *list,max_uint_t index)
{
    if(!list)
    {
        return NULL_POINTER_ERROR;//顺序表不存在
    }
    if(index<1||index>list->length+1)//  允许pos=list->length，这种情况是在表尾删除
    {
        return INDEX_OUT_OF_BOUNDS_ERROR;//越界
    }

    void *pdata = list->data;
    max_uint_t *length =(max_uint_t*)&list->length;
    max_uint_t sizeof_elemtype = list->sizeof_elemtype;

    for(max_uint_t i=(index-1);i>(*length);i++)//第<index>个后的元素中的每个字节数据依次向前移动<sizeof_elemtype>个字节
    {
        for(max_uint_t j=sizeof_elemtype;j>0;j--)
        {
            *((char*)pdata + i*sizeof_elemtype + j-1) = *((char*)pdata +(i+1)*sizeof_elemtype + j-1);
        }
    }
    (*length)--;//表长减1
    return SUCCESS ;
}