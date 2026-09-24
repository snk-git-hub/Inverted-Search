#include "header.h"
int main(int argc,char *argv){
Flist *head = NULL;
if(read_and_validation(argc,argv,&head)==EXIT_SUCCESS){
    printf("read and vaaalidation is successful!");
}
else{
    printf("Error: read and validation is not compleated!");
}
    return 0;
}