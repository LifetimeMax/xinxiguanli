#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define NUM 100 

struct Id
{
	int nu;
	char name[20];
	char sex[20];
	int age;
}s[NUM];
int N=10;
int main()
{
	int a;
	void show(); 
	void add();
	void dele();
	void search();
	void finish();  
	while(1)
	{
		
		printf("\n\n");
		printf("                                            欢迎来到我的可执行文件(.exe)                                                \n\n"); 
		printf("**********************************************|       1.个人信息展示    |***********************************************\n\n");
		printf("**********************************************|       2.增加信息        |***********************************************\n\n");
		printf("**********************************************|       3.删除信息        |***********************************************\n\n");
		printf("**********************************************|       4.查询信息        |***********************************************\n\n");
		printf("**********************************************|       0.退出            |***********************************************\n\n\n\n");
		printf("请输入功能序号："); 
		scanf("%d",&a);
		if(a>=0 && a<=4)
		{
			switch(a)
			{
				case 1:show();
					break; 
				case 2:add();
					break; 
				case 3:dele();
					break; 
				case 4:search();
					break; 
				case 0:finish();
					break;
			}
		} 
		else
		{
			printf("输入错误,请再次输入：\n\n");	
		}
	}
	return 0;
}



void show()
{
	char a;
	int i,j[100]={-1},b,t=0;
	printf("是否录入学生信息\n");
	printf("Y表示已输入，N表示未输入\n"); 
	scanf("%s",&a);
			
	if(a=='Y') 
	{
		printf("请输入学号:");
		scanf("%d",&b);	
		for(i=0;i<N;i++)
		{ 
			if(b==s[i].nu)
			{
				j[t]=i; 
			}
		}	
	}
	else if(a=='N')
	{
		printf("请增加介绍\n");	
	}
	if(j[0]!=-1)
	{
		printf("学号：%d\t姓名：%s\t性别：%s\t年龄；%d\t",s[j[i]].nu,s[j[i]].name,s[j[i]].sex,s[j[i]].age);	
	}
}

//增加介绍
void add()
{
	system("cls");
	int num=1,i,m;
	N=0;
	printf("请输入增加介绍的数量：\n");
	scanf("%d",&num);
	N += num;
	m = num;
	printf("请输入相关信息：\n");
	for(i=0;i<num;i++)
	{
		printf("还有%d个学生信息待录入\n", m); 
		m--;	
		printf("请输入学号：");
		scanf("%d",&s[N-num+i].nu);/*给结构体变量成员赋值*/
		printf("请输入姓名：");
		scanf("%s",&s[N-num+i].name);
		printf("请输入性别：");
		scanf("%s",&s[N-num+i].sex);
		printf("请输入年龄：");
		scanf("%d",&s[N-num+i].age);
	}
	printf("已成功增加%d的信息。\n",num);
}

//删除介绍
void dele()
{
	int i,d,k,t=0;
	char ds[20];
	int j=-1;
	printf("请输入删除学生的姓名或学号\n");
	printf("1:姓名              2:学号\n");
	scanf("%d",&k);
	if(k==1)
	{
	
		printf("请输入姓名:");
		scanf("%s",ds);
		for(i=0;i<N;i++)
		{
			if(strcmp(ds,s[i].name)==0)		//strcmp函数  srting compare（字符串比较）
			{                              //string.h头文件
				j=i;
				break;
			}
		}	
	}
	else if(k==2)
	{
		
		printf("请输入学号:");
		scanf("%d",&d);
		for(i=0;i<N;i++)
		{
			if(d==s[i].nu)
			{
				j=i;
				break;
			}
		}
	}
	else
	{
		printf("你输入的有误，请重新输入\n");
		
	}
	printf("确定该学生吗？\n");
	printf(">>>按 1 继续<<<\n");
	printf(">>>按其他键返回主菜单<<<\n");
	int p;
	scanf("%d",&p);
	if (p == 1)
	{
		printf("删除中");
	}
	
	if(j!=-1 && p==1)
	{
		N=N-1;
		for(i=j;i<N;i++)
		{
			strcpy(s[i].name,s[i+1].name);    //string copy
			s[i].age=s[i+1].age;
			s[i].nu=s[i+1].nu;
			strcpy(s[i].sex,s[i+1].sex);
		}
		printf("删除成功\n"); 
		printf("\n\n继续删除吗？");
		printf(">>>按 1 继续<<<\n");
		printf(">>>按其他键返回主菜单<<<\n");
		scanf("%d", &k);
		
	}
	else if (j == -1)
	{
		printf("信息库里没有这位学生\n");
	}
}

//查询介绍
void search()
{
	int i,d,k,t=0,m,j[100]={-1};
	char ms[20];
	printf("查询：");
	printf("1:姓名              2:学号");
	printf("\n\n请输入查询选项：");
	scanf("%d",&k);
	if(k==1)
	{
		system("cls"); 
		printf("请输入姓名:");
		scanf("%s",ms);
		for(i=0;i<N;i++)
		{	
			if(strcmp(ms,s[i].name)==0)		//strcmp函数 
			{
				j[t]=i;
				t=t+1;
			}		 
		}			 
	}
	else if(k==2)
	{
		printf("请输入学号:");
		scanf("%d",&d);
		for(i=0;i<N;i++)
		{ 
			if(d==s[i].nu)
			{
				j[t]=i;
				t++;
			}
		}
	} 
	if (j[0] == -1 && t == 0)
	{
		system("cls");
		printf("信息库没有该生的信息\n");

		
	}
	if(j[0]!=-1 && t!=0)
	{
		system("cls"); 
		printf("\t姓名		\t学号		\t性别		\t年龄 \n");
		for(i=0;i<t;i++)
		{
			printf("\t%s		\t%d		\t%s		\t%d",s[j[i]].name,s[j[i]].nu,s[j[i]].sex,s[j[i]].age);
		}
	}
} 

//退出系统
void finish() 
{
	exit(0);//<stdlib.h> 头文件 
}