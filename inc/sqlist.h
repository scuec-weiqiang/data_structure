/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:43:52
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-06 00:09:29
 * @FilePath: /data_structure/inc/sqlist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/

#ifndef SQLIST_H
#define SQLIST_H

#define OK 1            
#define ERRO 0          
#define OVERFLOW -2     

#define MAXSIZE 50 //顺序表中元素的最大个数

typedef int status_t;
typedef int elemtype_t;//顺序表中数据的数据类型

 //顺序表结构体定义
typedef struct sqlist
{
    elemtype_t *elem;//顺序表的数组指针
    unsigned int length;//顺序表长度
}sqlist_t;

status_t sqlist_init(sqlist_t *list);
status_t sqlist_destory(sqlist_t *list);
status_t sqlist_clear(sqlist_t *list);
status_t sqlist_get_elem(sqlist_t *list,unsigned int pos,elemtype_t *data);
status_t sqlist_get_position(sqlist_t *list,elemtype_t data,unsigned int *pos);
status_t sqlist_insert_elem(sqlist_t *list,elemtype_t data,unsigned int pos);
status_t sqlist_delete_elem(sqlist_t *list,unsigned int pos);

#endif