//codeforces educational round 98 Div 2
//C. Two Brackets
//https://codeforces.com/contest/1452/problem/C

#include<bits/stdc++.h>
using namespace std;
void test_case()
{
    stack<char> s;
    stack<char> s2;
    string input;
    cin >> input;
    int par = 0, square = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '(')
            s.push(input[i]);
        else if(input[i] == ')')
        {
            if(s.empty() == true)
            {
                //puts("NO");
                //exit(0);
            }
            else 
            {
                s.pop();
                par++;
            }
        }
        else if(input[i] == '[')
            s2.push(input[i]);

        else if(input[i] == ']') {
            if(s2.empty() == true)
            {
                //puts("NO");
                //exit(0);
            }
            else
            {
                s2.pop();
                square++;
            }
        }
 
    } 
    cout << par + square << endl;
   /*if(s.empty() == true && s2.empty() == true)
         puts("YES");
    else
        puts("NO");*/
}
int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)
    test_case();
    return 0;
}
