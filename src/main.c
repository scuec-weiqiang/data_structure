/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-21 22:50:53
 * @FilePath: /data_structure/src/main.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
 ***************************************************************/
#include <stdio.h>
#include "sqlist.h"

int main(void)
{
	//顺序表测试
	sqlist_t *my_list = NULL;

	status_t opt_status = 0; 
	uint16_t data = 0;
	uint16_t *pdata = NULL;
	max_uint_t pos = 0;

	opt_status = sqlist_init(&my_list,sizeof(uint16_t),20);
	printf("sqlist init: %d\n",opt_status);

	data = 0;
	opt_status = my_list->insert(my_list,&data,1);
	printf("sqlist insert: %d\n",opt_status);

	data = 1;
	opt_status = my_list->insert(my_list,&data,1);
	printf("sqlist insert: %d\n",opt_status);

	data = 2;
	opt_status = my_list->insert(my_list,&data,1);
	printf("sqlist insert: %d\n",opt_status);

	printf("sqlist data:\n");
	for(int i=1;i<=my_list->length;i++)
	{
		my_list->get_elem(my_list,i,(void*)&pdata);
		printf("[%d]: %d\n",i,*pdata);
	}
	
	data = 5;
	my_list->clear(my_list);
	opt_status = my_list->insert(my_list,&data,1);
	printf("sqlist data:\n");

	for(int i=1;i<=my_list->length;i++)
	{
		my_list->get_elem(my_list,i,(void*)&pdata);
		printf("[%d]: %d\n",i,*pdata);
	}
	
	sqlist_destory(&my_list);
	return 0;
	 
}
