/**  
* memcpy - Copy one area of memory to another  
* @dest: Where to copy to  
* @src: Where to copy from  
* @count: The size of the area.  
*  
* You should not use this function to access IO space, use memcpy_toio()  
* or memcpy_fromio() instead.  
*/ 

//当内存出现重叠时使用该函数会出错 
void *memcpy(void *dest, const void *src, size_t count)  
{  
        char *tmp = dest;  
        const char *s = src;  
  
        while (count--)  
                *tmp++ = *s++;  
        return dest;  
}  
 
/**  
* memmove - Copy one area of memory to another  
* @dest: Where to copy to  
* @src: Where to copy from  
* @count: The size of the area.  
*  
* Unlike memcpy(), memmove() copes with overlapping areas.  
*/ 

//解决内存出现重叠时的情况 
void *memmove(void *dest, const void *src, size_t count)  
{  
        char *tmp;  
        const char *s;  
  
        if (dest <= src) {  
                tmp = dest;  
                s = src;  
                while (count--)  
                        *tmp++ = *s++;  
        } else {  
                tmp = dest;  
                tmp += count;  
                s = src;  
                s += count;  
                while (count--)  
                        *--tmp = *--s;  
        }  
        return dest;  
}  