/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-03 19:57:07
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-03 18:17:24
 * @FilePath: /data_structure/src/main.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
 ***************************************************************/
#include <stdio.h>
#include "sqlist.h"
#include "linklist.h"

int main(void)
{
	//顺序表测试
	// sqlist_t my_list;
	// int a = sqlist_init(&my_list);
	// elemtype_t b = 0;
	// unsigned int c = 0;
	// printf("sqlist init: %d\n",a);
	
	// sqlist_insert_elem(&my_list,1,1);
    // sqlist_insert_elem(&my_list,2,2);
	// sqlist_insert_elem(&my_list,3,2);

	// printf("sqlist elem:\n");
	// for(int i=0;i<my_list.length;i++)
	// 	printf("[%d]: %d\n",i+1,my_list.elem[i]);
	// printf("sqlist length: %d\n",my_list.length);

	// sqlist_get_elem(&my_list,(unsigned int)2,&b);
	// printf("elem 2 is on position: %d\n",b);

    // sqlist_get_position(&my_list,(elemtype_t)3,&c);
	// printf(" pos 3 is: %d\n",c);
	// return 0;

	//单链表测试
	linklist_t p;
	status_t st = 0;
	st = linklist_init(&p,0);
	st = linklist_insert_node(p,255,10);
	st = linklist_insert_node(p,128,2);
	st = linklist_insert_node(p,64,3);
	st = linklist_delete_node(p,1);
	link_node_t *s = NULL_PTR;
	st = linklist_get_node(p,128,&s);
	int a = 0;
	st = linklist_get_elem(p,2,&a);
	st = linklist_destory(&p);
	printf("%d",st);
	return 0;
	
}
