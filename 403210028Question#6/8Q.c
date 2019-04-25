#include<stdio.h>
#include<math.h>
#include<string.h>
#define NN  100
int max,P[NN][NN];
int N,n[NN][NN];
void Be1(int J)
{
    int i,j,k;
    for(i=1; i<N; i++)n[i][J]=1<<(N-J-1);//第J個colum除第一個下全部都是不能擺放，為0
    for(i=1,j=J+1; i<N&&j<N; i++,j++)n[i][J]|=(1<<(N-j-1));//右下斜角不能擺放，為0
    for(i=1,j=J-1; i<N&&j>=0; i++,j--)n[i][J]|=(1<<(N-j-1));//左下斜角不能擺放，為0
    for(i=1; i<N; i++)n[i][J]=(1<<N)-1-n[i][J];//有效位數取NOT
}
void Qu(int I,int J,int now[],int temp)
{
    int i,j,NOW[NN];
    temp+=P[I][J];//到目前為止的累積分數
    if(I==N-1)//如果有解到第8個則比大小
    {
        if(max<temp)max=temp;
        return 0;
    }
    memcpy(NOW,now,sizeof(int)*N);
    for(j=0; j<N; j++)//窮舉下一row的解
        if(((n[1][J]&now[I+1])>>(N-j-1))&1)//如果是解則進入
        {
            for(i=I+1; i<N; i++)NOW[i]&=n[i-I][J];//紀錄棋盤情況
            Qu(I+1,j,NOW,temp);//下一步
            memcpy(NOW,now,sizeof(int)*N);//回歸上一步的棋盤狀態
        }
    return 0;
}
int main()
{
    int i,j,now[NN],T;
   // freopen("un123.txt","r",stdin);
    //scanf("%d",&T);//T比測資
    //while(T--)
    {
        scanf("%d",&N);//棋盤大小
        for(i=0;i<N;i++)for(j=0;j<N;j++)scanf("%d",&P[i][j]);//格子權重
        memset(n,0,sizeof(n));//歸0
        for(j=0; j<N; j++)Be1(j);//找出第一row對其下所有row各自的解
        j=(1<<N)-1;//所有bit=1
        for(i=0; i<N; i++)now[i]=j;//當下棋盤所有皆可以擺放
        max=0;//max歸零
        for(j=0; j<N; j++)Qu(0,j,now,0);//第一row為首做窮舉
        printf("%d\n",max);
    }
}
