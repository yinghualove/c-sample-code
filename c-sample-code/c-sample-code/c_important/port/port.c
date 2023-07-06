#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv)
{

    DIR *dp;
    struct dirent *dirp;

    char filedir[] = "/dev/";
    if ((dp = opendir(filedir)) == NULL)
        printf("Can't open %s\n", filedir);

    char tempfiledir[70];

    while ((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) /// current dir OR parrent dir
            continue;

//        char tempfiledir[70];
        strcpy(tempfiledir, filedir);
        strcat(tempfiledir, dirp->d_name);
        printf("%s\n",tempfiledir);
        if(strncmp(tempfiledir,"/dev/cdc-wdm",12)==0)
            break;
        else if(strncmp(tempfiledir,"/dev/ttyCMBIM0",14)==0)
            break;
    }
    printf("port name=%s\n",tempfiledir);

    closedir(dp);

    return 0;
}