#include<stdio.h>
#include<math.h>
#include<string.h>
#define NN  100
int max,P[NN][NN];
int N,n[NN][NN];
void Be1(int J)
{
    int i,j,k;
    for(i=1; i<N; i++)n[i][J]=1<<(N-J-1);//��J��colum���Ĥ@�ӤU�������O�����\��A��0
    for(i=1,j=J+1; i<N&&j<N; i++,j++)n[i][J]|=(1<<(N-j-1));//�k�U�ר������\��A��0
    for(i=1,j=J-1; i<N&&j>=0; i++,j--)n[i][J]|=(1<<(N-j-1));//���U�ר������\��A��0
    for(i=1; i<N; i++)n[i][J]=(1<<N)-1-n[i][J];//���Ħ�ƨ�NOT
}
void Qu(int I,int J,int now[],int temp)
{
    int i,j,NOW[NN];
    temp+=P[I][J];//��ثe����ֿn����
    if(I==N-1)//�p�G���Ѩ��8�ӫh��j�p
    {
        if(max<temp)max=temp;
        return 0;
    }
    memcpy(NOW,now,sizeof(int)*N);
    for(j=0; j<N; j++)//�a�|�U�@row����
        if(((n[1][J]&now[I+1])>>(N-j-1))&1)//�p�G�O�ѫh�i�J
        {
            for(i=I+1; i<N; i++)NOW[i]&=n[i-I][J];//�����ѽL���p
            Qu(I+1,j,NOW,temp);//�U�@�B
            memcpy(NOW,now,sizeof(int)*N);//�^�k�W�@�B���ѽL���A
        }
    return 0;
}
int main()
{
    int i,j,now[NN],T;
   // freopen("un123.txt","r",stdin);
    //scanf("%d",&T);//T�����
    //while(T--)
    {
        scanf("%d",&N);//�ѽL�j�p
        for(i=0;i<N;i++)for(j=0;j<N;j++)scanf("%d",&P[i][j]);//��l�v��
        memset(n,0,sizeof(n));//�k0
        for(j=0; j<N; j++)Be1(j);//��X�Ĥ@row���U�Ҧ�row�U�۪���
        j=(1<<N)-1;//�Ҧ�bit=1
        for(i=0; i<N; i++)now[i]=j;//��U�ѽL�Ҧ��ҥi�H�\��
        max=0;//max�k�s
        for(j=0; j<N; j++)Qu(0,j,now,0);//�Ĥ@row�������a�|
        printf("%d\n",max);
    }
}
