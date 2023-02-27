#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kiek = 0;
void print(char *rezultatas, int len)
{
    kiek++;
    for(int i = 0; i<= len; i++)
        cout<<rezultatas[i];
    cout<<endl;
}
void stringcombo(char rezultatas[], char str[], int count[], int level, int size, int length)
{
    if(level == size)
        return;
    for(int i = 0; i< length; i++)
    {
        if(count[i] == 0)
            continue;
        count[i]--;
        rezultatas[level] = str[i];
        print(rezultatas, level);
        stringcombo(rezultatas, str, count, level + 1, size, length);
        count[i]++;
    }
}
void deriniai(string str)
{
    map<char, int> mp;
    for(int i = 0; i < str.size(); i++)
    {
        if(mp.find(str[i]) != mp.end())
            mp[str[i]] = mp[str[i]] + 1;
        else
            mp[str[i]] = 1;
    }
    char *input = new char [mp.size()];
    int *count = new int [mp.size()];
    char *rezultatas = new char [str.size()];
    map<char, int>::iterator it = mp.begin();
    int i = 0;
    for(it; it != mp.end(); it++)
    {
        input[i] = it->first;
        count[i] = it->second;
        i++;
    }
    int length = mp.size();
    int size = str.size();
    stringcombo(rezultatas, input, count, 0, size, length);
}
int main()
{
    string str = "ABCD";
    deriniai(str);
    cout<<"Is viso yra "<<kiek<<" deriniu"<<endl;
    return 0;
}
