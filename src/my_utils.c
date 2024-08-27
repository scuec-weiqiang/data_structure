/***************************************************************
 * @Author: scuec-weiqiang scuec_weiqiang@qq.com
 * @Date: 2024-07-06 15:29:01
 * @LastEditors: scuec-weiqiang scuec_weiqiang@qq.com
 * @LastEditTime: 2024-07-12 17:38:47
 * @FilePath: /data_structure/src/my_utils.c
 * @Description: 
 * @
 * @Copyright (c) 2024 by scuec-weiqiang, All Rights Reserved. 
***************************************************************/

/***************************************************************
 * @brief 限幅，使输入<x>不低于<low>，不高于<up>
 *        本函数不负责检查参数合法性。 
 * @param {int} low [in]:  最小值
 * @param {int} x [in]:  输入的值
 * @param {int} up [in]:  最大值
 * @return {int}
***************************************************************/
int clip(int low,int x,int up)
{
    if(up>=low)
    {
        return x >= up ? up : x <= low ? low : x;
    }
    else
    {
        return 0;
    }
}

/***************************************************************
 * @brief 整形取绝对值
 *        本函数不负责检查参数合法性。
 * @param {int} x [in]:  
 * @return {unsigned int}
***************************************************************/
unsigned int abs_int(int x)
{
    return x>=0?x:-x;
}

/***************************************************************
 * @brief 浮点型取绝对值
 *        本函数不负责检查参数合法性。
 * @param {float} x [in]:  输入
 * @return {float}
***************************************************************/
float abs_float(float x)
{
    return x>0?x:-x;
}

/***************************************************************
 * @brief 快速开平方，精度有限
 *        本函数不负责检查参数合法性。 
 * @param {unsigned int} x [in]:  输入
 * @return {*}
***************************************************************/
unsigned int quick_sqrt(unsigned int x)
{
    unsigned int ans=0,p=0x80;
    while(p!=0)
    {
        ans+=p;
        if(ans*ans>x)
        {
            ans-=p;
        }
        p=(unsigned int)(p>>1);
    }
    return ans;
}

/***************************************************************
 * @brief 快速反正切，返回角度值
 *        本函数不负责检查参数合法性。
 * @param {float} y [in]: 对边长度
 * @param {float} x [in]:  邻边长度
 * @return {float} 角度值
***************************************************************/
float quick_arctan(float y,float x)
{
    float r = y/x;
    return r/(1+0.28125*r*r);
}

/***************************************************************
 * @brief 将指针<src>指向的内存区域的<size>个字节设置为<value>。
 *        本函数不负责检查参数合法性。
 * @param {void} *src [in]:  源地址
 * @param {int} value [in]:  值
 * @param {int} size [in]:  字节个数
 * @return {*}
***************************************************************/
void* mem_set(void *src, char value, unsigned int size)
{
    // 将 void 指针转换为 char 指针，方便按字节操作
    char *char_src = (char *)src;
    // 循环设置每个字节的值
    while (size > 0) {
        // 将当前位置的字节设置为 value
        *char_src = (char)value;
        // 移动指针到下一个字节
        char_src++;
        // 减少剩余字节数
        size--;
    }
    // 返回修改后的原始指针 src
    return src;
}

/***************************************************************
 * @brief 将指针<src>指向的内存区域的 n 个字节复制到指针<dest>指向的内存区域。
 *        两个地址之间重叠的数据会被覆盖。
 *        本函数不负责检查参数合法性。
 * @param {void} *src [in]: 源地址
 * @param {void} *dest [in]:  目的地址  
 * @param {unsigned int} size [in]:  大小
 * @return {*}
***************************************************************/
void* mem_cpy(void *src,void *dest, unsigned int size)
 {
    // 将 void 指针转换为 char 指针，方便按字节操作
    char *byte_dest = (char *)dest;
    char *byte_src = (char *)src;

    //为了防止内存重叠导致复制错误，要分情况讨论
    //从低地址复制到高地址时，从最高地址开始复制
    //从高地址复制到低地址时，从最低地址开始复制

    if(byte_src < byte_dest)//低到高
    {
        byte_src = byte_src + size-1;//指向源内存最高地址
        byte_dest = byte_dest + size-1;//指向目的内存最高地址

        for(unsigned int i=0;i<size;i++)
        {
            *byte_dest = *byte_src;
            byte_dest--;
            byte_src--;
        }
    }
    else if(byte_src > byte_dest)//高到低
    {
        //指针默认指向低地址，不需要重新赋值

        for(unsigned int i=0;i<size;i++)
        {
            *byte_dest = *byte_src;
            byte_dest++;
            byte_src++;
        }
    }
    else
    {

    }

    return byte_dest;
}

/***************************************************************
 * @brief 将一段大小为<size>个字节的内存向高地址移<shift_count>个字节
 *        并返回移位后的地址。它只会改动数据的位置，不会覆盖任何数据。
 *        本函数不负责检查参数合法性。
 * @param {void} *src [in]:  
 * @param {unsigned int} size [in]:  
 * @param {unsigned int} shift_count [in]:  
 * @return {*}
***************************************************************/
void* mem_right_shift(void *src,unsigned int size,unsigned int shift_count)
{
    char *byte_src = (char *)src;
    char *byte_dest = (void*)0x00;
    char temp = 0;

    byte_src = byte_src + size-1;//指向内存末尾
    byte_dest = byte_src + shift_count;

    for(unsigned int i=0;i<size;i++)
    {
        temp = *byte_dest;
        *byte_dest = *byte_src;
        *byte_src = temp;
        byte_dest--;
        byte_src--;
    }
    return byte_dest;
   
}

/***************************************************************
 * @brief 将一段大小为<size>个字节的内存向低地址移<shift_count>个字节
 *        并返回移位后的地址。它只会改动数据的位置，不会覆盖任何数据。
 *        本函数不负责检查参数合法性。
 * @param {void} *src [in]:  
 * @param {unsigned int} size [in]:  
 * @param {unsigned int} shift_count [in]:  
 * @return {*}
***************************************************************/
void* mem_left_shift(void *src,unsigned int size,unsigned int shift_count)
{
    char *byte_src = (char *)src;
    char *byte_dest = (void*)0x00;
    char temp = 0;

    byte_src = byte_src;//指向内存末尾
    byte_dest = byte_src - shift_count;

    for(unsigned int i=0;i<size;i++)
    {
        temp = *byte_dest;
        *byte_dest = *byte_src;
        *byte_src = temp;
        byte_dest++;
        byte_src++;
    }
    return byte_dest;
   
}

/***************************************************************
 * @brief 比较两段内存中的值是否相同,相同返回0，不同返回1
 *        本函数不负责检查参数合法性。
 * @param {void} *mem1 [in]:  地址1
 * @param {void} *mem2 [in]:  地址2
 * @param {unsigned int} size [in]:  需要比较的内存字节大小
 * @return {*}
***************************************************************/
int mem_cmp(void *mem1,void *mem2,unsigned int size) 
{
    // 将 void 指针转换为 char 指针，方便按字节操作
    char *byte_mem1 = (char *)mem1;
    char *byte_mem2 = (char *)mem2;
    
    while (size > 0)
    {
        if((*byte_mem1) != (*byte_mem2))
        {
            return 1;
        }
        byte_mem1++;
        byte_mem2++;
        size--;
    }
    
    return 0;
}