/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-20 12:02:33
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
	max_uint_t length = 0;
	uint16_t data = 3;
	uint16_t *pdata = NULL;
	max_uint_t pos = 0;

	opt_status = sqlist_init(&my_list,sizeof(uint16_t),20);
	printf("sqlist init: %d\n",opt_status);

	opt_status = sqlist_insert_elem(my_list,&data,1);

	sqlist_get_length(my_list,&length);

	printf("sqlist data:\n");
	for(int i=1;i<=length;i++)
	{
		sqlist_get_elem(my_list,i,(void*)&pdata);
		printf("[%d]: %d\n",i,*pdata);
	}
	sqlist_clear(my_list);
	opt_status = sqlist_insert_elem(my_list,&data,1);
	printf("sqlist data:\n");

	sqlist_destory(&my_list);
	return 0;
	 
}
