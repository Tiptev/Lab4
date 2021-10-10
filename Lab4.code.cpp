#include <iostream>
 int N;
 int price[2][1000];
 int way_distance[2][1000];
 int addit_array[3][1000];

using namespace std;

int sorting_dist(int way_distance[2][1000], int N)
{
    for (int s = 0; s < N-1; s++){
        for (int i = 0; i < N-1; i++){
             if (way_distance[2][i] >= way_distance[2][i+1])
             {
                 swap(way_distance[2][i],way_distance[2][i+1]);
                 swap(way_distance[1][i],way_distance[1][i+1]);
             }
        }  
    }
  return 0;
}

int sorting_price(int price[2][1000], int N)
{
    for (int s = 0; s < N-1; s++){
        for (int i = 0; i < N-1; i++){
             if (price[2][i] <= price[2][i+1])
             {
                 swap(price[2][i],price[2][i+1]);
                 swap(price[1][i],price[1][i+1]);
             }
        }  
    }
  return 0;
}

int data_entry_dist(int way_distance[2][1000],int N)
{
    for (int i = 0; i < N; i++)
        {
           cout << "Введите расстояние сотрудника № " << i+1<<" от места работы до дома  - ";
           cin >> way_distance[2][i];   
           way_distance[1][i] = i + 1;
        }
        
    return 0;
}

int data_entry_price(int price[2][1000],int N)
{
    for (int i = 0; i < N; i++)
        {
           cout << "Введите тариф за проезд одного километра в такси №" << i+1<<" - ";
           cin >> price[2][i];
           price[1][i] = i + 1; 
        }
    return 0;
}

int price_calcul(int price[2][1000],int way_distance[2][1000],int addit_array[3][1000],int N)
{
    for (int f = 0; f < N; f++)
        {
            addit_array[3][f]=way_distance[2][f]*price[2][f];
            addit_array[2][f]=price[1][f];
            addit_array[1][f]=way_distance[1][f];
        }
        
    for(int s = 0; s < N-1; s++)
        {
            for (int i = 0; i < N-1; i++)
                {
                    if(addit_array[1][i] > addit_array[1][i+1])
                     {
                         swap(addit_array[1][i],addit_array[1][i+1]);
                         swap(addit_array[2][i],addit_array[2][i+1]);
                         swap(addit_array[3][i],addit_array[3][i+1]);
                     }
                }   
        } 
        
    for (int d = 0; d < N; d++)
        cout << "Сотрудник №" << addit_array[1][d] << " сядет в такси №" << addit_array[2][d] << " и стоимость проезда(в рублях) будет равна = " << addit_array[3][d]<<"."<<endl;
    return 0;  
}

int main()
{
    cout << "Введите кол-во сотрудников - N, для которых нужно вызвать такси. N = ";
    cin >> N;
    data_entry_dist(way_distance, N);    
    sorting_dist(way_distance ,N); 
    data_entry_price(price, N);    
    sorting_price(price ,N); 
    price_calcul(price, way_distance, addit_array, N);
    
    return 0;
}