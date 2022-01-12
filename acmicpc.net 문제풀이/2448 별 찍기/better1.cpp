// 어떤 원리인지 탐구해보기
#include<iostream>
#include<string.h>
void triangle(int s,int x,int y,char*arr,int w){
	if(s==3){
        char* p=arr+y*w+x;
		*(p+2)=42;
        p+=w;
		*(p+1)=42;*(p+3)=42;
		memset(p+w,42,5);
		return;
	}
	int hS=s/2;
	triangle(hS,x+hS,y,arr,w);
	triangle(hS,x,y+hS,arr,w);
	triangle(hS,x+s,y+hS,arr,w);
}
int main()
{
	int s;
	std::cin>>s;
	int dS=s*2;
	int dSS=dS*s;
	char* arr=new char[dSS];
	memset(arr,32,dSS);
	for(int i=0;i<s-1;i++) arr[(i+1)*dS-1]=10;
	arr[dSS-1]=0;
	triangle(s,0,0,arr,dS);
	std::cout<<arr;
}
