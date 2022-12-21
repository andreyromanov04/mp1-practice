#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h>
#include <profileapi.h>
#define n 300
#define _WIN32_WINNT 0x0400
int getfiles();
void merge(unsigned long* size, int beg, int end, int* nums);
void mergesort(unsigned long* size, int beg, int end, int* nums);
void choicesort(int len);
void qsort(unsigned long* size, int beg, int end, unsigned long* num);
typedef struct _FIND_DATA
{
    DWORD nFileSize;
    WCHAR cFileName[n];
}FIND_DATA;
FIND_DATA* files;
unsigned long Size[n];
unsigned long size[n];
unsigned long num[n];
unsigned long nim[n];
void main()
{
	int r, i, k, z, time1, time2;
	i=getfiles();
    
    do
    {
        printf("Choose type of sort: 1 - quicksort, 2 -  mergesort, 3 - choicesort. Enter 5, if you want finish sorting\n"); 
        scanf("%d", &z);
        switch (z)
        {
        case 1:
        {
            time1 = 0;
            time2 = 0;
            
            for (r = 0; r < i; r++)
            {
                num[r] = r;
            }
            QueryPerformanceCounter(&time1);
            qsort(Size, 0, (i - 1), num);
            QueryPerformanceCounter(&time2);
            for (r = 0; r < i; r++)
            {
                for (k = 0; k < i; k++)
                {
                    if (Size[r] == files[k].nFileSize)
                    {
                        printf("%s      %u\n", files[k].cFileName, Size[r]);
                    }
                }
            }
            printf("Time of sorting - %d milisec\n", time2 - time1);
            break;
        }
        case 2:
        {
            time1 = 0;
            time2 = 0;
            for (r = 0; r < i; r++)
            {
                nim[r] = r;
            }
            QueryPerformanceCounter(&time1);
            mergesort(size, 0, i-1, nim, i);
            QueryPerformanceCounter(&time2);
            for (r = 0; r < i; r++)
            {
                for (k = 0; k < i; k++)
                {
                    if (size[r] == files[k].nFileSize)
                    {
                        printf("%s      %u\n", files[k].cFileName, size[r]);
                    }
                }
            }
            printf("Time of sorting - %d milisec\n", time2 - time1);
            break;
        }
        case 3:
        {
            time1 = 0;
            time2 = 0;
            QueryPerformanceCounter(&time1);
            choicesort(i);
            QueryPerformanceCounter(&time2);
            printf("Time of sorting - %d milisec\n", time2-time1);
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    } while (z != 5);
}
int getfiles()
{
    int x;
    char path[100];
    printf("Enter the path of directory\n");
    gets(path);
    strcat(path, "/*");
    files = (FIND_DATA*)malloc(sizeof(FIND_DATA) * 10000);
    WIN32_FIND_DATAA FindFileData;
    HANDLE hFind = FindFirstFileA(path, &FindFileData);
    int i = 0;
    FindNextFileA(hFind, &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        do
        {
            printf("Invalid path. Please, try again \n");
            gets(path);
            strcat(path, "/*");
            hFind = FindFirstFileA(path, &FindFileData);
            FindNextFileA(hFind, &FindFileData);
        } while (hFind == INVALID_HANDLE_VALUE);
    }
   while (FindNextFileA(hFind, &FindFileData) != 0)
   {
        files[i].nFileSize = FindFileData.nFileSizeLow;
        size[i]= FindFileData.nFileSizeLow;
        Size[i] = FindFileData.nFileSizeLow;
        strcpy(files[i].cFileName, FindFileData.cFileName); 
        i++;
   }
   FindClose(hFind);
   for (x = 0; x < i; x++)
   {
       printf("%s      %u\n", files[x].cFileName, files[x].nFileSize);
   }
   return i;
}
void choicesort(int len)
{
    int s, m;
    WCHAR dvp;
    unsigned long nums[n];
    typedef struct _DATA
    {
        DWORD Size;
        WCHAR Name[n];
    }DATA;
    DATA* file;
    file = (DATA*)malloc(sizeof(DATA) * 10000);
    for (s = 0; s < len; s++)
    {
        strcpy(file[s].Name, files[s].cFileName);
        file[s].Size = files[s].nFileSize;
    }
    for (s = 0; s < len; s++)
    {
        nums[s] = s;
    }
    for (int st = 0; st < len - 1; st++)
    {
        int MinPos = st, buf, buf0;
        for (int j = st + 1; j < len; j++)
        {
            if (file[j].Size < file[MinPos].Size)
            {
                MinPos = j;
            }
        }
        buf = file[MinPos].Size;
        buf0 = nums[MinPos];
        file[MinPos].Size = file[st].Size;
        nums[MinPos] = nums[st];
        file[st].Size = buf;
        nums[st] = buf0;
    }
    for (s = 0; s < len; s++)
    {
        for (m = 0; m < len; m++)
        {
            if (file[s].Size == files[m].nFileSize)
            {
                printf("%s      %u\n", files[m].cFileName, file[s].Size);
            }
        }
    }
}
void qsort(unsigned long* size, int beg, int end, unsigned long* num)
{
    int s, m, tmp, tmp0, j = end, g = beg;
    unsigned long piv;
    piv = size[(beg + end) / 2];
    do 
    {
        while (size[g] < piv) 
        {
            g++;
        }
        while (size[j] > piv) 
        {
            j--;
        }
        if (g <= j) 
        {
            if (size[g] > size[j]) 
            {
                tmp = size[g];
                size[g] = size[j];
                size[j] = tmp;
                tmp0 = num[g];
                num[g] = num[j];
                num[j] = tmp0;
            }
            g++;
            if (j > 0) 
            {
                j--;
            }
        }
    } while (g <= j);

    if (g < end) 
    {
        qsort(size, g, end, num);
    }
    if (j > beg) 
    {
        qsort(size, beg, j, num);
    }
}
void merge(unsigned long* size, int beg, int end, int* nums)
{
    int i0 = 0, i1 = 0, i2 = beg, mid=(beg+end)/2;
    int* b = (int*)malloc(sizeof(int) * 10000);
    int* c = (int*)malloc(sizeof(int) * 10000);
    while ((i0 < (mid - beg + 1)) && (i1 < (end - mid))) 
    {
        if (size[beg + i0] <= size[mid + i1 + 1]) 
        {
            b[i2] = size[beg + i0];
            c[i2] = nums[beg + i0];
            i0++;
        }
        else 
        {
            b[i2] = size[mid + i1 + 1];
            c[i2] = nums[mid + i1 + 1];
            i1++;
        }
        i2++;
    }
    while (i0 < (mid - beg + 1)) 
    {
        b[i2] = size[beg + i0];
        c[i2] = nums[beg + i0];
        i0++;
        i2++;
    }
    while (i1 < (end - mid)) 
    {
        b[i2] = size[mid + i1 + 1];
        c[i2] = nums[mid + i1 + 1];
        i1++;
        i2++;
    }
    for (int j = beg; j < i2; j++) 
    {
        size[j] = b[j];
        nums[j] = c[j];
    }
    free(b);
    free(c);
}
void mergesort(unsigned long* size, int beg, int end, int* nums)
{
    int s, m;
    if (beg < end) 
    {
        int mid= (beg + end) / 2;
        mergesort(size, beg, mid, nums);
        mergesort(size, mid + 1, end, nums);
        merge(size, beg, end, nums);
    }
}
