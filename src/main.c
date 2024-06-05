/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-06-06 00:23:36
 * @FilePath: /data_structure/src/main.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
 ***************************************************************/
#include <stdio.h>
#include "./inc/sqlist.h"

int main(void)
{
	//顺序表测试
	sqlist_t my_list;
	int a = sqlist_init(&my_list);
	elemtype_t b = 0;
	unsigned int c = 0;
	printf("sqlist init: %d\n",a);
	
	sqlist_insert_elem(&my_list,1,1);
    sqlist_insert_elem(&my_list,2,2);
	sqlist_insert_elem(&my_list,3,2);

	printf("sqlist elem:\n");
	for(int i=0;i<my_list.length;i++)
		printf("[%d]: %d\n",i+1,my_list.elem[i]);
	printf("sqlist length: %d\n",my_list.length);

	sqlist_get_elem(&my_list,(unsigned int)2,&b);
	printf("elem 2 is on position: %d\n",b);

    sqlist_get_position(&my_list,(elemtype_t)3,&c);
	printf(" pos 3 is: %d\n",c);
	return 0;
	
}
