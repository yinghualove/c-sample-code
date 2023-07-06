#include<sys/stat.h>
//#include<iostream>
#include <sys/types.h>
//using namespace std;

int main(){
    char* filepath = "/home/test/tt/";
    mode_t mode = umask(0);
    mkdir(filepath,0777);
    //do something
    umask(mode);
    //do something
    return 0;
}