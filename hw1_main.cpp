#include <iostream>
#include"hw1_list.cpp"

using namespace std;

int main (int argc, char** argv){
    int N,M,K;
    int joker;
    cin >> N >> M >> K;
    List *people;
    people = new List[N+1];
    for(int i=1;i<=N;i++)
        people[i].AddNode(M);
    for(int i=0;i<K;i++){
        cin >> joker;
        people[joker].AddNode(0);
        people[joker].Joker = 1;
    }
    int a,b,j=1,j_next;
    while(1){
        cin >> a >> b;
        if(a==-1&&b==-1){
            for(int i=1;i<=N;i++){
                if(!people[i].Joker){
                    people[i].print();
                    break;
                }
            }
            break;
        }
        if(j==N+1) j = j-N;
        if(j==N) j_next = 1;
        else     j_next = j+1;
        people[j++].MoveNode(a,b,&people[j_next]);
    }
}