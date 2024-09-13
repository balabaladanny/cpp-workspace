#include <stdio.h>
#include <stdlib.h>

int *dyarr;
int *ans;
int *pos;
int n;
int top = 0;
void solve(){
	for(int i = 1 ; i <= n ; i++){
		if(top != 0){
			while(top != 0 && dyarr[pos[top]] >= dyarr[i]){
				top--;
			}
		}
		ans[i] = (top == 0)? 0 : pos[top];
		top++;
		pos[top] = i;
	}
}

int main(){
	scanf("%d",&n);
	dyarr = malloc(sizeof(int)*(n+1));
	ans = malloc(sizeof(int)*(n+1));
	pos = malloc(sizeof(int)*(n+1));
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&dyarr[i]);
	}
	solve();
	for(int i = 1 ; i <= n ; i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}