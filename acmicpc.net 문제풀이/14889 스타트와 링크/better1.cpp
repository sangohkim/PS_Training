// hgc950909님의 소스 코드
// 나중에 한번 이해해봐야 겠다
#include<stdio.h>
#include<stdlib.h>

int table[22][22];
int r[22];
int c[22];
int min_num = 0x7fffffff;
int teams[22];
int n;
void dfs(int idx,int cnt,int total){
    if(cnt==n/2){
        if(min_num>abs(total)){
            min_num = abs(total);
        }
        return;
    }
    if(idx == n)return;
    dfs(idx+1, cnt+1,total -r[idx] - c[idx]);
    dfs(idx+1,cnt,total);
        
    
}
int main(){
    int tot=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&table[i][j]);
            tot+=table[i][j];
            c[i]+=table[i][j];
            r[j]+=table[i][j];
        }
    }
    dfs(1,1,tot-r[0]-c[0]);
    printf("%d",min_num);
    return 0;
}
