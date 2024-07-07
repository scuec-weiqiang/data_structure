/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-07-06 15:49:26
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-07 10:35:49
 * @FilePath: /data_structure/inc/my_utils.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef MY_UTILS_H
#define MY_UTILS_H

int clip(int low,int x,int up);
unsigned int abs_int(int x);
float abs_float(float x);
unsigned int quick_sqrt(unsigned int x);
float quick_arctan(float y,float x);
void* mem_set(void *src, char value,unsigned int n);
void* mem_cpy( void *src,void *dest,unsigned int size);
void* mem_right_shift(void *src,unsigned int size,unsigned int shift_count);
void* mem_left_shift(void *src,unsigned int size,unsigned int shift_count);
int mem_cmp(void *mem1,void *mem2,unsigned int size);

#endif