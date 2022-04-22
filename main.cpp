//amir mahdi salamat mehraban
//negar fayezpoor

#include <iostream>

using namespace std;

int coins[5] = {1, 2, 5, 10, 50};

int coin_changing (int num, int* arr,int index){

    if (num == 0)
       {return 1;}

    int count = 0;

    for (int j = 0; j < 5; j++){

        if (coins[j] > num)
        {continue;}

        if (index != 0 && coins[j] > arr[index - 1])
        {continue;}

        arr[index] = coins[j];
        count += coin_changing(num - coins[j], arr, index + 1);
    }
    return count;
}

int main(){
    int N;
    cout<<"enter amount of your money:";
    cin>>N;
    int *array = new int[N];

    cout <<"the number of conditions:"<< coin_changing(N, array,0);

    cout << '\n';
}
