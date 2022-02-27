#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    char dirname[10];
    struct dirent *d;
    DIR *p;
    printf("Enter directory name: ");
    scanf("%s", dirname);
    p = opendir(dirname);
    if(p == NULL)
    {
        printf("Cannot find directory\n");
        exit(-1);
    }
    while(d = readdir(p))
        printf("%s\n", d->d_name);
    return 0;
}