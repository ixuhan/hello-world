#include <stdio.h> 
#include <stdlib.h> 
#include "tslib.h" 
 
#define DEV_NAME "/dev/input/event0" 
 
int getTsXY() 
{    
    struct tsdev *ts; 
    struct ts_sample sample; 
    int ret; 
    ts = ts_open(DEV_NAME, 0); 
    if(!ts) 
    { 
        perror("Open error!\n"); 
        exit(1); 
    } 
    if(ts_config(ts)) 
    { 
        perror("ts_config\n"); 
        exit(1); 
    } 
    while(1) 
    { 
        ret = ts_read(ts , &sample, 1); 
        if (ret < 0)  
        { 
            perror("ts_read"); 
            exit(1); 
        } 
        printf("x = %d\ty = %d\t press = %u\n",sample.x,sample.y,sample.pressure); 
    } 
    ts_close(ts); 
    return 0; 
} 
int main(int argc,char **argv) 
{    
    getTsXY(); 
    return 0; 
}
