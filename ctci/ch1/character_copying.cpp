#include <iostream>

int replace_chars(char str[], int len, int tlen)
{   int sp_count=0;
    for (int i = 0; i<len; i++ )
        if (str[i] == ' ' )
            sp_count++;
    int nlen = sp_count*2 + len;
    str[nlen] = '\0';
    std::cout << nlen;
    for (int i =len-1; i>=0; i--)
    {
        if (str[i] != ' ')
        {
            //then copy to newlen
            str[nlen-1] = str[i];
            nlen--;    
        }
        else
        {   
            str[nlen-1] = '%';
            str[nlen-2] = '2';
            str[nlen-3] = '0';
            
            nlen = nlen -3;
        }

    }
    return sp_count*2+len;
}

void print_str(char str[], int nlen)
{
    for (int i = 0; i<nlen;i++)
        std::cout << str[i];
    std::cout <<std::endl;
}
int main()
{
    char str[40]={'a', ' ', 'b', ' '};
    print_str(str, 4);
    int len = 4;
    int nlen = replace_chars(str, len, 40);
    print_str( str, nlen);
       
}

