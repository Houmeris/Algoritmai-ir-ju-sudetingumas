#include <iostream>
#include <string.h>
using namespace std;

int lygink (const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
void apkeisk (char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int rask (char str[], char pirmas, int l, int h)
{
    int ceilindex = l;
    for(int i = l+1; i<= h; i++)
        if(str[i] > pirmas && str[i] < str[ceilindex])
            ceilindex = i;
    return ceilindex;

}
void keliniai (char str[])
{
    int kiek = 0;
    int size = strlen(str);
    qsort(str, size, sizeof(str[0]), lygink);
    bool baigti = false;
    while(!baigti)
    {
        kiek++;
        cout<<str<<endl;
        int i;
        for(i = size - 2; i >= 0; --i)
            if(str[i] < str[i+1])
                break;
        if(i == -1)
            baigti = true;
        else
        {
            int ceilindex = rask(str, str[i], i+1, size - 1);
            swap(str[i], str[ceilindex]);
            qsort(str + i + 1, size -i - 1, sizeof(str[0]), lygink);
        }
    }
    cout<<endl;
    cout<<"Is viso yra "<<kiek<<" rinkiniu"<<endl;
}
int main()
{
    char str[] = "ABCDEF";
    keliniai(str);
    return 0;
}
