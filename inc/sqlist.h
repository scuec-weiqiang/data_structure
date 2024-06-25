/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:43:52
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-25 15:08:51
 * @FilePath: /data_structure/inc/sqlist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/

#ifndef SQLIST_H
#define SQLIST_H

#include "typedef.h"

#define MAXSIZE 50 //顺序表中元素的最大个数

typedef int elemtype_t;//顺序表中数据的数据类型

 //顺序表结构体定义
typedef struct sqlist
{
    elemtype_t *elem;//顺序表的数组指针
    max_uint_t length;//顺序表长度
}sqlist_t;

status_t sqlist_init(sqlist_t *list);
status_t sqlist_destory(sqlist_t *list);
status_t sqlist_clear(sqlist_t *list);
status_t sqlist_get_elem(sqlist_t *list,max_uint_t pos,elemtype_t *data);
status_t sqlist_get_position(sqlist_t *list,elemtype_t data,max_uint_t *pos);
status_t sqlist_insert_elem(sqlist_t *list,elemtype_t data,max_uint_t pos);
status_t sqlist_delete_elem(sqlist_t *list,max_uint_t pos);

#endif