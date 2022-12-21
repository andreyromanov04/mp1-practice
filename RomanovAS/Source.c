#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
//#define _WIN32_WINNT 
#define _WIN32_WINNT 0x0400
int getfiles();
typedef struct _FIND_DATA
{
    DWORD nFileSize;
    WCHAR cFileName[260];
}FIND_DATA;

typedef struct
{
    char* name;
    int size;
}arr;
arr a[300]; 
void main()
{
    int len, i;
    len = getfiles();
    for (i = 0; i < len; i++)
    {
        printf("%s   %u\n",[i].cFileName, O.A[i].nFileSize);
    }
    //qsort(len);
    //printf("%d", len);
    return 0;
}
int getfiles()
{
    char path[100];
    printf("Enter the path of directory\n");
    fgets(path, 99, stdin);
    //printf("%s", path);
    FIND_DATA* files;
    files = (FIND_DATA*)malloc(sizeof(FIND_DATA) * 10000);
    WIN32_FIND_DATAA FindFileData;
    HANDLE hFind = FindFirstFileA(path, &FindFileData);
    int i = 0, k;
    FindNextFileA(hFind, &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        do
        {
            printf("Invalid path. Please, try again \n");
            fgets(path, 99, stdin);
            FindNextFileA(hFind, &FindFileData);
        } while (hFind == INVALID_HANDLE_VALUE);
    }
    while (FindNextFileA(hFind, &FindFileData) != 0)
    {
        files[i].nFileSize = FindFileData.nFileSizeLow;
        for (int j = 0; FindFileData.cFileName != '\0'; j++)
        {
            O.A[i].cFileName[j] = FindFileData.cFileName[j];
        }


        //strcpy(O.A[i].cFileName, FindFileData.cFileName);
        O.A[i].nFileSize = FindFileData.nFileSizeLow;
        //printf("%u\n", FindFileData.nFileSizeLow);
        i++;
    }
    FindClose(hFind);
    for (k = 0; k < i; k++)
    {
        //printf("%s      %u\n", files[k].cFileName, files[k].nFileSize);
    }
    return i;
}
