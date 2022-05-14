#include <stdio.h>

// Ручки и карандаши

int main() {
    int t;  // Количество входных данных
    scanf("%d", &t);

    int a;  // Количество лекций
    int b;  // Количество практических
    int c;  // на с лекций хватит одной ручки
    int d;  // на d практических хватит одного карандаша
    int k;  // Вместимость пенала
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);

        // Количество ручек, необходимых для лекций
        int pen = a / c + (a % c != 0);
        // Количество карандашей, необходимых для практических
        int pencil = b / d + (b % d != 0);

        // Вывод
        if (pen + pencil > k) {
            printf("-1\n");
        } else {
            printf("%d %d\n", pen, pencil);
        }
    }

    return 0;
}