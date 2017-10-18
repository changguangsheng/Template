#include<iostream>
#include<cstring>
using namespace std;
const int maxn=50010;   //�ַ����������ֵ
int GETNEXT(char *str,int *next)
{
    int i=0,j,po,len=strlen(str);
    next[0]=len;//��ʼ��next[0]
    while(str[i]==str[i+1]&&i+1<len)//����next[1]
    i++;
    next[1]=i;
    po=1;//��ʼ��po��λ��
    for(i=2;i<len;i++)
    {
        if(next[i-po]+i<next[po]+po)//��һ�����������ֱ�ӵõ�next[i]��ֵ
        next[i]=next[i-po];
        else//�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ
        {
            j=next[po]+po-i;
            if(j<0)j=0;//���i>po+next[po],��Ҫ��ͷ��ʼƥ��
            while(i+j<len&&str[j]==str[j+i])//����next[i]
            j++;
            next[i]=j;
            po=i;//����po��λ��
        }
        if(i+next[i]==len) return i;
    }
    return -1;
}
void asd(char *a,int *next,int len) //KMP��ʧ������
{
	next[0]=-1;
	int j=-1;
	for(int i=0;i<len;)
	{
		if(j==-1||a[i]==a[j])
		{
			j++;
			i++; 
			if(a[i]==a[j]) next[i] = next[j];  
			else next[i]=j;
		}
		else j=next[j];
	}
}
void asd1(char *a,int *next,int len) //������ʧ������ 
{
	next[0]=-1;
	int j=-1;
	for(int i=0;i<len;)
	{
		if(j==-1||a[i]==a[j])
		{
			j++;
			i++; 
			if(a[i]==a[j]) next[i] = j; 
			else next[i]=-1;
		}
		else j=next[j];
	}
}
int kmp(int *next,char *T,char *S) 
{
	int i=-1,j=-1;
	while(j<(int)strlen(S)&&i<(int)strlen(T))
	{
		if(-1==j||T[i]==S[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j==strlen(S)&&i!=strlen(T)) return 1;//ƥ��ɹ��Ҳ��Ǻ�׺ 
	else return 0;
}
int main()
{
	char a[50010];
	while(cin>>a)
	{
		int next[maxn];
		int i=GETNEXT(a,next);
		if(i!=-1)
		{
			int next1[maxn];
			asd(a+i,next1,next[i]);
			if(kmp(next1,a+1,a+i))
			{
				cout<<next[i]<<endl;
			}
			int next2[maxn];
			asd1(a+i,next2,next[i]);
			int k=next2[next[i]-1];
			while(k!=-1)
			{
				cout<<k+1<<endl;
				k=next2[k];	
			}
		}
	}
	return 0;
} 
