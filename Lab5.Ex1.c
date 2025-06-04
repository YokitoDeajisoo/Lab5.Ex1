#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int choice;

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1 — Ввести масив вручну\n");
        printf("2 — Згенерувати масив випадковими числами [-100; 100]\n");
        printf("3 — Вийти\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            int n;
            printf("Введiть кiлькiсть елементiв масиву: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Неприпустима довжина масиву.\n");
                continue;
            }

            int a[1000]; // обмеження, замість dynamic malloc

            if (choice == 1) {
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }
            }
            else if (choice == 2) {
                srand((unsigned int)time(NULL));
                printf("Згенерований масив:\n");
                for (int i = 0; i < n; i++) {
                    a[i] = rand() % 201 - 100;
                    printf("a[%d] = %d\n", i, a[i]);
                }
            }

            int min = a[0], max = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] < min) min = a[i];
                if (a[i] > max) max = a[i];
            }

            int diff = abs(max - min);
            printf("Максимум = %d, Мiнiмум = %d\n", max, min);
            printf("Модуль рiзницi мiж мiнiмальним i максимальним: %d\n", diff);
        }
        else if (choice == 3) {
            printf("Завершення програми.\n");
        }
        else {
            printf("Невiрний вибiр. Спробуйте ще раз.\n");
        }
    } while (choice != 3);

    return 0;
}

