
#include "stdafx.h"
#include "Measurement.h"
#include <stdio.h>

clock_t Res[measurements_number];

void MeasurementProcessing()
{
    long int Sum,Min1,Min2,Min3,Max1,Max2,Max3;
    int imin1,imin2,imin3,imax1,imax2,imax3;

/////////////////////////////////////////////////////////////
// Завдяки цим операторам виводу ви можете зрозуміти навіщо
// потрібне таке обчислення результатів виміру
    printf("Measurement Results:\n");
    for (int i = 0; i< measurements_number; i++)
        printf("   %ld",Res[i]);
    printf("\n\n");
// У курсовій роботі ці оператори виводу потрібно видалити
/////////////////////////////////////////////////////////////

// Два перших виміри (0-й та 1-й) відкидаються
// Серед інших елементів знаходимо три мінімальних та три максимальних
// елементи і віднімаємо їх значення із загальної суми

// Знаходимо мінімальний та максимальний елементи і виключаємо їх з наступних
// пошуків, встановивши їм значення -1
    Sum = Res[2]; Min1 = Res[2]; Max1 = Res[2]; imin1 = 2; imax1 = 2;
    for (int i = 3; i < measurements_number; i++)
    {
        Sum = Sum + Res[i];
        if (Res[i] > Max1) { Max1 = Res[i]; imax1 = i; }
        else if (Res[i] < Min1) { Min1 = Res[i]; imin1 = i; }
    }
    Res[imin1]=-1; Res[imax1]=-1;

// Знаходимо другий мінімальний та другий максимальний елементи
// і виключаємо їх з наступних пошуків, встановивши їм значення -1
    if (Res[2] == -1) {Min2 = Res[3]; imin2 = 3;}
    else {Min2 = Res[2]; imin2 = 2;}
    Max2 = Res[2]; imax2 = 2;
    for (int i = 3; i < measurements_number; i++)
    {
        if (Res[i] > Max2) { Max2 = Res[i]; imax2 = i; }
        else if (Res[i]<Min2 && Res[i]!=-1) { Min2 = Res[i]; imin2 = i; }
    }
    Res[imin2]=-1; Res[imax2]=-1;

// Знаходимо третій мінімальний та третій максимальний елементи
    if (Res[2] == -1)
        if (Res[3] == -1) {Min3 = Res[4]; imin3 = 4;}
        else {Min3 = Res[3]; imin3 = 3;}
    else {Min3 = Res[2]; imin3 = 2;}
    Max3 = Res[2]; imax3 = 2;
    for (int i = 3; i < measurements_number; i++)
    {
        if (Res[i] > Max3) { Max3 = Res[i]; imax3 = i; }
        else if (Res[i]<Min3 && Res[i]!=-1) { Min3 = Res[i]; imin3 = i; }
    }

// Сума всіх вимірів мінус три максимальних та три мінімальних значення буде записана до 0-го елемента масива Res
    Res[0] = Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;

/////////////////////////////////////////////////////////////
// Завдяки цим операторам виводу ви можете зрозуміти навіщо
// потрібне таке обчислення результатів виміру
    printf("Sum = %ld;\n", Sum);
    printf("Min1 = %ld; Min2 = %ld; Min3 = %ld\n", Min1, Min2, Min3);
    printf("Max1 = %ld; Max2 = %ld; Max3 = %ld\n", Max1, Max2, Max3);
    printf("Res[0] = %ld\n", Res[0]);
    printf("Res[0]/20 = %10.1f \n\n\n",(float)Res[0]/20);
// У курсовій роботі ці оператори виводу потрібно видалити
/////////////////////////////////////////////////////////////
}

