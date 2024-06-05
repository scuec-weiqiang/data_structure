/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-05 23:27:18
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
	sqlist_t my_list;
	int a = sqlist_init(&my_list);
	printf("sqlist init: %d\n",a);
	
	sqlist_insert_elem(&my_list,1,1);
    sqlist_insert_elem(&my_list,2,2);
	sqlist_insert_elem(&my_list,3,2);

	printf("sqlist elem:\n");
	for(int i=0;i<my_list.length;i++)
		printf("[%d]: %d\n",i+1,my_list.elem[i]);
	printf("sqlist length: %d\n",my_list.length);

	sqlist_get_elem(&my_list,2,&a);
	printf("get elem: %d\n",a);

    sqlist_get_position(&my_list,3,&a);
	printf("get pos: %d\n",a);
	return 0;
	
}
