/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-06-25 13:43:04
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-03 14:51:30
 * @FilePath: /data_structure/inc/typedef.h
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/
#ifndef TYPEDEF_H
#define TYPEDEF_H

    #define SYSTEM_BITS 64

    #if 64==SYSTEM_BITS
        typedef char int8_t;
        typedef unsigned char uint8_t;
        typedef short int16_t;
        typedef unsigned short uint16_t;       
        typedef int int32_t;
        typedef unsigned int uint32_t;
        typedef long int64_t;
        typedef unsigned long uint64_t;
        typedef uint64_t max_uint_t;
    #endif 

    #if 32==SYSTEM_BITS
        typedef char int8_t;
        typedef unsigned char uint8_t;
        typedef short int16_t;
        typedef unsigned short uint16_t;       
        typedef int int32_t;
        typedef unsigned int uint32_t;
        typedef uint32_t max_uint_t;
    #endif 

    #if 16==SYSTEM_BITS
        typedef char int8_t;
        typedef unsigned char uint8_t;
        typedef short int16_t;
        typedef unsigned short uint16_t;       
        typedef uint16_t max_uint_t;
    #endif  

    #define NULL_PTR ((void *)0)

    typedef enum
    {
        SUCCESS,//成功
        NOT_FOUND_ERROR,//未找到匹配的数据
        FULL_SIZE_ERROR,//表/缓冲区已满
        INDEX_OUT_OF_BOUNDS_ERROR,//标号索引越界
        MEMORY_ALLOCATION_ERROR,//内存分配错误
        NULL_POINTER_ERROR,//空指针
        TIMEOUT_ERROR,//超时
    }status_t;
    
#endif 