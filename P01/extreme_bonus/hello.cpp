#include <iostream>
#include <string>

using namespace std;

int main(){

char *userName;
if(getenv("USER")){
    userName = getenv("USER");
} else if (getenv("USERNAME")){
        userName = getenv("USERNAME");
}

cout <<"Hello, "<< userName <<"!"<<endl;
}