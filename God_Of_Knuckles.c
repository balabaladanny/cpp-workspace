#include <stdio.h>
int ans[500];
int main(){
  long long int n;
  scanf("%lld", &n);
  int flag = 0;
  for(long long int i=0;i<n;i++){
    char c=0;
    scanf(" %c", &c);
    int k = (int)c;
    if(ans[k] == 0)
      ans[k]++;
    else{
      flag = 1;
      break;
    }
  }
  if(flag == 1 || n == 1)
    printf("I'm the god of Knuckles!");
  else
    printf("Different makes perfect");
  printf("\n");
}