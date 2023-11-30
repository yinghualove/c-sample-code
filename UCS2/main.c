#include <string.h>
#include "myiconv.h"
#include "log_level.h"


int main()
{
    char options[20];
    memset(options,0,strlen(options));

    INFO_LOG("input your option:\n");
    scanf("%s",&options);

    if(strncmp(options,"encoding",10) == 0)
        encoding();                          //执行编码
    if(strncmp(options,"decode",8) == 0)
        decode();                           //执行解码
    
    return 0;
}
