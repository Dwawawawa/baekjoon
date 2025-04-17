#include<iostream>

using namespace std;

int main (){

    

    int l, r, k;

    cin >> l >>r >>k;

    int count = 0;

    switch (k)

    {

    case 2:

        for(int i = 3; i <= r; i++){

            if(i >= l){

                count++;

            }

        }

        break;

    case 3:

        for(int i = 2; 3*i <= r; i++){

            if(3*i >= l){

                count++;

            }

        }

        break;

    case 4:

    

       if(10 >= l && 10<= r){

            count++;

       }

       for(int i = 7; 2*i <= r; i++){

            if(2*i >= l){

                count++;

            }

       }

       break;

    case 5:

       for(int i = 3; 5*i <= r; i++){

            if(5*i >= l){

                count++;

            }

       }

       break;

    }

    

    

    cout << count;

    

    return 0;

}