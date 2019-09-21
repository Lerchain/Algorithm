s = input()
l = s.split('.')
r = s.split(':')
m = len(r)
n = len(l)
if n < m:
    n = m
    l = r
if n == 4:
    flag = 0
    for x in l:
        xl = len(x)
        intex = int(x)
        intl = len(str(intex))
        if intl != xl or intex<0 or intex >= 256:
            flag = 1
            print('Neither')
            break
    if flag == 0:
        print('IPv4')
elif n == 8:
    flag = 0
    for x in l:
        x = x.lower()
        xlen = len(x)
        if xlen >4:
            flag = 1
            print('Neither')
            break
        for y in x:
            if not((y>='0' and y<='9')or(y>='a' and y <= 'f')):
                flag = 1
                print('Neither')
                break
    if flag == 0:
        print('IPV6')
else:
    print('Neither')

    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }
    int tar = sum/2;
    sort(v.begin(),v.end());
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt += v[i];
        if(cnt >= tar)
        {
            if(cnt == tar)
                cout<<0;
            else
            {
                cout<<min(cnt-(sum-cnt),sum-2*(cnt-v[i-1]));
            }
            break;
        }
    }
}