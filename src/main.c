/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-12 20:19:39
 * @FilePath: /data_structure/src/main.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
 ***************************************************************/
#include <stdio.h>
#include "sqlist.h"
#include "linklist.h"
#include "my_utils.h"

typedef struct pid
{
	float p;
	float i;
	float d;
	int32_t err;
	int32_t last_err;
	int32_t output;
}pid_t;

typedef struct car
{
	uint64_t id;
	char name[6];
}car_t;

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
	// st = linklist_init(&list);

	// b = 10;
	// st = linklist_insert_node(list,&b,1,sizeof(uint32_t));
	// b = 20;
	// st = linklist_insert_node(list,&b,2,sizeof(uint32_t));
	// b = 30;
	// st = linklist_insert_node(list,&b,3,sizeof(uint32_t));

	// st = linklist_get_data(list,1,(void*)&b);
	// st = linklist_get_data(list,2,(void*)&b);
	// st = linklist_get_data(list,3,(void*)&b);
	
	// b = 30;
	// st = linklist_get_index(list,&b,&index);
	// printf("%d\n",st);
	// b = 40;
	// st = linklist_insert_node(list,&b,4,sizeof(uint32_t));
	// st = linklist_delete_node(list,4);
	// st = linklist_delete_node(list,5);
	// st = linklist_delete_node(list,1);
	// st = linklist_delete_node(list,1);
	// return 0;

	// linklist_t device = NULL;
	// status_t st = 0;
	// pid_t car_pid = {0};
	// car_t car = {0};
	// car_t car_1 = {0};
	// car.id = 1;
	// car.name[0] = 'm';
	// car.name[1] = 'y';
	// car.name[2] = 'c';
	// car.name[3] = 'a';
	// car.name[4] = 'r';
	// linklist_init(&device);
	// linklist_insert_node(device,&car,1,sizeof(car_t));

	// car_pid.p = 1;
	// car_pid.i = 0;
	// car_pid.d = 2;
	// linklist_insert_node(device,&car_pid,2,sizeof(pid_t));

	// linklist_get_data(device,1,&car_1);
	// return 	0;



}
