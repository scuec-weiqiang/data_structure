/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:43:52
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-20 11:22:49
 * @FilePath: /data_structure/inc/sqlist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef SQLIST_H
#define SQLIST_H

#include "typedef.h"  

typedef struct sqlist sqlist_t;//顺序表声明

status_t sqlist_init(sqlist_t **list,max_uint_t data_size,max_uint_t max_length);
status_t sqlist_destory(sqlist_t **list);
status_t sqlist_clear(const sqlist_t *list);
status_t sqlist_get_length(const sqlist_t *list,max_uint_t *length);
status_t sqlist_get_elem(const sqlist_t *list,max_uint_t pos,void **elem);
status_t sqlist_get_position(const sqlist_t *list,void *elem,max_uint_t *pos);
status_t sqlist_insert_elem(const sqlist_t *list,void *elem,max_uint_t pos);
status_t sqlist_delete_elem(const sqlist_t *list,max_uint_t pos);

#endif