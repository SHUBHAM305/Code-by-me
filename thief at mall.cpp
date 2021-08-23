#include<iostream>
#include<vector>
using namespace  std;
struct cart
{
	vector<int> item;
	int price;
};
cart findmax(int *a,int *p,cart c,int w,int i)
{
	if(i==-1 || w==0)
	{
		c.price=0;
		return c;
	}
	cart a1,n1;
	if(a[i]<=w)
	{
		a1=findmax(a,p,c,w-a[i],i);
		a1.price+=p[i];
		a1.item.push_back(a[i]);
		n1=findmax(a,p,c,w,i-1);
		return (a1.price>n1.price)?a1:n1;
	}

	return findmax(a,p,c,w,i-1);
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,8,10,25,11};
	int p[]={182,40,575,300,2500,48000};
	int w=26;
	cart costmr;
	costmr.price=0;
	costmr=findmax(a,p,costmr,w,sizeof(a)/4-1);
	cout<<"\n\n MAX profit will be = "<<costmr.price;
	for (int i = 0; i < sizeof(a)/4; ++i)

	{
		/* code */
		cout<<"\n "<<i+1;
		cout<<" item  =  "<< costmr.item[i];
	}
	return 0;
}
