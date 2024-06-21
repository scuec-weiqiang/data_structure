/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:43:52
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-21 22:39:59
 * @FilePath: /data_structure/inc/sqlist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef SQLIST_H
#define SQLIST_H

#include "typedef.h"  

 //顺序表结构体定义
typedef struct sqlist
{
    max_uint_t elem_size;//顺序表中一个元素所占的字节数
    max_uint_t max_length;//顺序表最大长度
    max_uint_t length;//顺序表长度

    status_t (*clear)(const struct sqlist *list);
    status_t (*get_elem)(const struct sqlist *list,max_uint_t pos,void **elem);
    status_t (*get_pos)(const struct sqlist *list,void *elem,max_uint_t *pos);
    status_t (*insert)(const struct sqlist *list,void *elem,max_uint_t pos);
    status_t (*delete)(const struct sqlist *list,max_uint_t pos);
    void *elem;//顺序表的元素数组指针
}sqlist_t;

extern status_t sqlist_init(sqlist_t **list,max_uint_t elem_size,max_uint_t max_length);
extern status_t sqlist_destory(sqlist_t **list);

#endif