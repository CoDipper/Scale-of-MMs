#include<iostream>
using namespace std;

//Прототипи на методи
void ArrOne(int One[100][100], int n);              //Зануляване на масива
void ArrZero(int Zero[100][100], int n);            //Масив от единици

//Разпечатване на краен резултат в конзолата
void Print(int Left[100][100],int Right[100][100],int Shoulder[100][100],int Middle[100][100], int n);
void PrintDashOrDot(int a);

void OutPutLeftLeg(int Left[100][100], int n);          //Метод за създаване на лявото краче на буквата
void OutPutRightLeg(int Right[100][100], int n);        //Метод за създаване на дясното краче на буквата
void OutPutShoulder(int Shoulder[100][100], int n);     //Метод за създаване на раменете на буквата
void OutPutMiddle(int Middle[100][100], int n);         //Метод за създаване на свода на буквата(средата)

int main(){
    int LeftLeg[100][100];
    int RightLeg[100][100];
    int Shoulder[100][100];
    int Middle[100][100];
    int n;
    do{
        cout<<"Enter an odd scale of Ms which is in the interval [3; 99):";
        cin>>n;
    }while(n%2!=1||(n<2||n>=99));
    OutPutLeftLeg(LeftLeg, n);
    OutPutRightLeg(RightLeg, n);
    OutPutShoulder(Shoulder, n);
    OutPutMiddle(Middle, n);
    Print(LeftLeg, RightLeg, Shoulder, Middle, n);
    return 0;
}
void ArrOne(int One[100][100], int n){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            *(*(One+i)+j)=1;
        }
    }
}
void ArrZero(int Zero[100][100], int n){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            *(*(Zero+i)+j)=0;
        }
    }
}
void Print(int Left[100][100],int Right[100][100],int Shoulder[100][100],int Middle[100][100], int n){
    cout<<endl<<"-------------------"<<endl;
    cout<<"Ms of scale "<<n<<" is:"<<endl<<endl;
    for(int i=0; i<n+1; i++){
        for(int d=2; d>0; d--){
            for(int j=0; j<n; j++){
                PrintDashOrDot(*(*(Left+i)+j));
            }
            for(int j=0; j<n; j++){
                PrintDashOrDot(*(*(Shoulder+i)+j));
            }
            for(int j=0; j<n; j++){
                PrintDashOrDot(*(*(Middle+i)+j));
            }
            for(int j=0; j<n; j++){
                PrintDashOrDot(*(*(Shoulder+i)+j));
            }
            for(int j=0; j<n; j++){
                PrintDashOrDot(*(*(Right+i)+j));
            }
        }
        cout<<endl;
    }
}
void PrintDashOrDot(int a){
    if(a==1){
        cout<<"*";
    }else{
        cout<<"-";
    }
}
void OutPutLeftLeg(int Left[100][100], int n){
    ArrZero(Left, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            if(i+j>=n){
                *(*(Left+i+1)+j-1)=1;
            }
        }
    }
}
void OutPutRightLeg(int Right[100][100], int n){
    ArrZero(Right, n);
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            if(i>j){
                *(*(Right+i)+j)=1;
            }
        }
    }
}
void OutPutShoulder(int Shoulder[100][100], int n){
    ArrOne(Shoulder, n);
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            if((i>=n-j)&&(i+j)>=n){
                *(*(Shoulder+i)+j)=0;
            }
            if(j==i||j>i){
                *(*(Shoulder+i)+j)=1;
            }
        }
    }
}
void OutPutMiddle(int Middle[100][100], int n){
    ArrOne(Middle, n);
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            if((i<n-j)&&(i+j)<n){
                *(*(Middle+i)+j)=0;
            }
            if(j<i){
                *(*(Middle+i)+j)=1;
            }
        }
    }
}
