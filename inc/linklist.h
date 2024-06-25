/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-25 13:59:34
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-25 17:56:18
 * @FilePath: /data_structure/inc/linklist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include "typedef.h"

typedef int elemtype_t;//链表中数据的数据类型

 //链表结构体定义
typedef struct link_node *linklist_t,link_node_t;

struct link_node
{
    elemtype_t elem;//链表数据域
    // link_node_t *prior;//前驱指针
    link_node_t *next;//后继指针
};

status_t linklist_init(linklist_t list,max_uint_t num);
status_t linklist_get_elem(linklist_t list,max_uint_t pos,elemtype_t *elem);
status_t linklist_get_node(linklist_t list,elemtype_t elem,link_node_t **node);
status_t linklist_insert_node(linklist_t list,elemtype_t elem,max_uint_t pos);
// status_t sqlist_init(sqlist_t *list);
// status_t sqlist_destory(sqlist_t *list);
// status_t sqlist_clear(sqlist_t *list);
// status_t sqlist_get_elem(sqlist_t *list,unsigned int pos,elemtype_t *data);
// status_t sqlist_get_position(sqlist_t *list,elemtype_t data,unsigned int *pos);
// status_t sqlist_insert_elem(sqlist_t *list,elemtype_t data,unsigned int pos);
// status_t sqlist_delete_elem(sqlist_t *list,unsigned int pos);

#endif