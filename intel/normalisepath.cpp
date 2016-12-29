#include <stdio.h>
#include <string.h>
int find_prev_folder_start(char* str, int curr)
{
    // curr is at '/'
    //                     -Curr
    // example:  one/two/../
    int ret = curr-1;
    while (curr >= 0  && str[ret]!='/')
    {
            ret--;   
    }
    return ret;
}
int getNextToken(char*str, int* ip, char*resp, int start  )
{
    char res[80];
    int start_res = 0;
    int i = *ip;
   
    resp[start++] =  str [i++];
    while (str[i]!='/' && str[i]!='\0')
    {
            resp[start] = str[i];
            res[start_res] = str[i];
            i++;
            start++;
            start_res++;
    }

    res[start_res]='\0';
    int resp_start = start;
    printf("\ntoken %s : ", res);

    if (strcmp(res,"..") == 0){
        resp_start =find_prev_folder_start(str,i);
        resp_start = find_prev_folder_start(str,resp_start);
        printf("\nafter %d : ", resp_start);
    }
    if (strcmp (res, ".") == 0){
        resp_start =find_prev_folder_start(str,i);
        printf("\n after %d :", resp_start);
    }
    printf("\nresp : %s" , resp);
    printf("\nresp start :%d", resp_start);
    *ip = i;
    return resp_start;
}
void normalise (char *str)
{
    char res[80];
    int end = 0;
    int start = 0;
    int i = 0;
    while (str[i]!='\0')
    {
        while (str[i]==' ')
            i++;
        //res[start++] = str[i++];

        start = getNextToken (str, &i, res, start); 
        printf("\nres : %s" , res);
        printf("\ni  :%d"  , i);

    }
    printf("\n printing output");
    for(int k = 0;  k < start ; k++)
        printf("%c", res[k]);
}
int main ()
{
    char str[] = "/one/two/../three";
    normalise (str);
}