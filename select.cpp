#include<iostream>
#include<algorithm>
using namespace std;

int select(int a[],int low,int high,int k)
{
    int p=high-low+1;
    if(p<6) {sort(a+low,a+high+1);return a[k];}
    int q=p/5;
    int b[1000];
    int bnum=1;
    for(int i=low;i<=5*q;i+=5)
    {
        sort(a+i,a+i+5);
        b[bnum++]=a[(i+i+5)/2];
    }
    int s=(q%2==1?q/2+1:q/2);
    int middle=select(b,1,bnum-1,s);
    int s1[500],s2[500],s3[500];
    int n1=1,n2=1,n3=1;
    for(int i=low;i<=high;i++)
    {
        if(a[i]<middle) s1[n1++]=a[i];
        else if(a[i]==middle) s2[n2++]=a[i];
        else s3[n3++]=a[i];
    }
    if(n1-1>=k) return select(s1,1,n1-1,k);
    else if(n1+n2-2>=k) return middle;
    else return select(s3,1,n3-1,k-n1-n2+2);
}

int main()
{
    int n,k;
    int a[1000];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x=select(a,1,n,k);
    cout<<x<<endl;
    return 0;
}
