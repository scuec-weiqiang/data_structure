/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-07 15:46:50
 * @FilePath: /data_structure/src/main.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
 ***************************************************************/
#include <stdio.h>
#include "sqlist.h"
#include "linklist.h"
#include "my_utils.h"

int main(void)
{
	// // 顺序表测试
	// sqlist_t *my_list = NULL;

	// status_t opt_status = 0; 
	// max_uint_t length = 0;
	// uint16_t data = 0;
	// max_uint_t pos = 0;

	// opt_status = sqlist_init(&my_list,sizeof(uint16_t),20);

	// data = 3;
	// opt_status = sqlist_insert_data(my_list,1,&data);
	// data = 2;
	// opt_status = sqlist_insert_data(my_list,2,&data);
	// data = 1;
	// opt_status = sqlist_insert_data(my_list,3,&data);
	// sqlist_get_length(my_list,&length);
	// printf("sqlist data:\n");
	// for(int i=1;i<=length;i++)
	// {
	// 	sqlist_get_data(my_list,i,&data);
	// 	printf("[%d]: %d\n",i,data);
	// }
	
	// data = 4;
	// opt_status = sqlist_insert_data(my_list,1,&data);
	// sqlist_get_length(my_list,&length);
	// printf("sqlist data:\n");
	// for(int i=1;i<=length;i++)
	// {
	// 	sqlist_get_data(my_list,i,&data);
	// 	printf("[%d]: %d\n",i,data);
	// }

	// data = 4;
	// opt_status = sqlist_get_position(my_list,&data,&pos);
	// data = 3;
	// opt_status = sqlist_get_position(my_list,&data,&pos);
	// data = 2;
	// opt_status = sqlist_get_position(my_list,&data,&pos);
	// data = 1;
	// opt_status = sqlist_get_position(my_list,&data,&pos);
	// data = 0;
	// opt_status = sqlist_get_position(my_list,&data,&pos);
	
	// sqlist_destory(&my_list);
	// return 0;

	// // 单链表测试
	// linklist_t list = NULL_PTR;
	// int32_t b = 0;
	// max_uint_t index = 0;
	// status_t st = 0;
	// st = linklist_init(&list,4,3);

	// b = 1;
	// st = linklist_set_data(list,1,&b);
	// b = 2;
	// st = linklist_set_data(list,2,&b);
	// b = 3;
	// st = linklist_set_data(list,3,&b);

	// st = linklist_get_data(list,1,(void*)&b);
	// st = linklist_get_data(list,2,(void*)&b);
	// st = linklist_get_data(list,3,(void*)&b);
	
	// b = 3;
	// st = linklist_get_index(list,&b,&index);
	// printf("%d\n",st);
	// b = 4;
	// st = linklist_insert_node(list,&b,4);
	// st = linklist_delete_node(list,4);
	// st = linklist_delete_node(list,5);
	// st = linklist_delete_node(list,1);
	// st = linklist_delete_node(list,1);
	// return 0;
	
}
