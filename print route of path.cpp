#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;

	cout<<"No of nodes in graph ";cin>>n;
	int ***a;
	int k[n+1];
	a=(int ***)malloc(n*sizeof(int **));
	for(int i=0;i<n;i++)
	{
		int nodes;
		cout<<"No of connected nodes ";cin>>nodes;
		a[i]=(int **)malloc(nodes*sizeof(int*));
		k[i]=nodes;
		for(int j=0;j<nodes;j++)
		{
			a[i][j]=(int *)malloc(2*sizeof(int ));
			cout<<"Enter nodes name";cin>>a[i][j][0];
			cout<<"Enter nodes weight";cin>>a[i][j][1];
		}
	}
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	int src,destn;
	cout<<"\n Enter the source ";cin>>src;
	cout<<"\n Enter the destination ";cin>>destn;

	stack<int>s;
	s.push(src);
	int weight=0;
	string path="";
	string sm="";
	int smw=1<<28;
	stack<int> pathweight;
	pathweight.push(0);
	int current;
    while(!s.empty())
	{
        current=s.top();
        if(current==destn)
		{

        //    cout<<"\n path for destination "<<path<<" Weight of path "<<pathweight.top();
			if(smw>pathweight.top())
			{
				smw=pathweight.top();
				sm=path+to_string(current);
			}
        //    cout<<"\n deletion "<<pathweight.top()<<" current "<<current;
			pathweight.pop();
		//	cout<<"\nYes there is path for dest from src";
			s.pop();
			visited[current]=false;
		}
		else if(visited[current]==true)
		{
			s.pop();
			visited[current]=false;
           // cout<<"\n deletion "<<pathweight.top()<<" pcurrent "<<current;
			pathweight.pop();
            path.erase(path.size() -1 ,1);
		}
		else
        {
            visited[current]=true;
            path+=to_string(current);

            int lasti=0;
            int m=pathweight.top();
			for(int i=0;i<k[current];i++)
			{
				if(!visited[a[current][i][0]])
				{
                    s.push(a[current][i][0]);
					lasti=i;
				  //  cout<<endl<<"element enter in to the stack  =  "<<a[current][i][0];
				    pathweight.push(m+a[current][lasti][1]);
                //cout<<"\n Sum on add "<<pathweight.top()<<" pcurrent "<<current;



				}

			}



        }


	}
	cout<<"\n\n value of smw "<<smw<<" Path to destination "<<sm;

	return 0;
}
