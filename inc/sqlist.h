/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 20:43:52
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-12 17:39:19
 * @FilePath: /data_structure/inc/sqlist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef SQLIST_H
#define SQLIST_H

#include "typedef.h"  

typedef struct sqlist sqlist_t;//顺序表声明

status_t sqlist_init(sqlist_t **list,max_uint_t sizeof_elemtype,max_uint_t max_length);
status_t sqlist_destory(sqlist_t **list);
status_t sqlist_clear(sqlist_t *list);
status_t sqlist_get_length(sqlist_t *list,max_uint_t *length);
status_t sqlist_set_data(sqlist_t *list,max_uint_t index,void *data);
status_t sqlist_get_data(sqlist_t *list,max_uint_t index,void *data);
status_t sqlist_get_index(sqlist_t *list,void *data,max_uint_t *index);
status_t sqlist_insert_data(sqlist_t *list,max_uint_t index,void *data);
status_t sqlist_delete_data(sqlist_t *list,max_uint_t index);

#endif