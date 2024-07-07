/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-06 15:08:25
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-07 10:37:15
 * @FilePath: /data_structure/inc/linklist.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include "typedef.h"

typedef struct link_node       
    link_node_t,*linklist_t;

status_t linklist_insert_node(linklist_t list,void *data,max_uint_t index);
status_t linklist_delete_node(linklist_t list,max_uint_t index);
status_t linklist_get_index(linklist_t list,void *data,max_uint_t *index);
status_t linklist_set_data(linklist_t list,max_uint_t index,void *data);
status_t linklist_get_data(linklist_t list,max_uint_t pos,void *data);
status_t linklist_destory(linklist_t *list);
status_t linklist_init(linklist_t *list,max_uint_t sizeof_elemtype,max_uint_t num);

#endif