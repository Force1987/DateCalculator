#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    int d, m, y, d2, m2, y2, counter = 0, YearsInInterval, leap = 0;
    cout << "Введите последовательно день, месяц и год для даты 1: ";
    cin >> d >> m >> y;
    if (m < 1 || m>12 || (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31 || (m == 4 || m == 6 || m == 9 || m == 11) && d > 30 || m == 2 && (y % 4 == 0) && d > 29 || m == 2 && (y % 4 != 0) && d > 28 || d <= 0) cout << "Некорректная дата"; else {
        cout << "Введите последовательно день, месяц и год для даты 2: ";
        cin >> d2 >> m2 >> y2;
        if (m2 < 1 || m2>12 || (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12) && d2 > 31 || (m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11) && d2 > 30 || m2 == 2 && (y2 % 4 == 0) && d2 > 29 || m2 == 2 && (y2 % 4 != 0) && d2 > 28 || d2 <= 0) cout << "Некорректная дата"; else {
            if (y > y2 || y == y2 && m > m2 || y == y2 && m == m2 && d > d2) { swap(d, d2); swap(m, m2); swap(y, y2); }
            else if (y == y2 && m == m2 && d == d2) {
                cout << "Ошибка! Вы ввели одинаковые даты для диапазона"; y = y2 + 2; m = 0; d = 0;
            }
            if (y == y2 && m == m2) counter = d2 - d;
            else {
                if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) counter = 31 - d;
                else if (m == 4 || m == 6 || m == 9 || m == 11) counter = 30 - d;
                else if (y % 4 == 0) counter = 29 - d;
                else counter = 28 - d;

                m++;
                if (m > 12) { m = 1; y += 1; }
                if (y < y2) {
                    if (m == 1 && y % 4 == 0) counter += 366; else if (m == 1 && y % 4 != 0) counter += 365; else
                        if (m == 2 && y % 4 == 0) counter += 335; else if (m == 2 && y % 4 != 0) counter += 334; else
                            if (m == 3) counter += 306; else if (m == 4) counter += 275; else
                                if (m == 5) counter += 245; else if (m == 6) counter += 214; else
                                    if (m == 7) counter += 184; else if (m == 8) counter += 153; else
                                        if (m == 9) counter += 122; else if (m == 10) counter += 92; else
                                            if (m == 11) counter += 61; else if (m == 12) counter += 31;
                    y++;
                    YearsInInterval = y2 - y;
                    if ((y2 - y) > 3) {
                        if (y % 4 == 0)  leap = (((y2 - y) / 4) + 1);
                        else if ((y + 1) % 4 == 0) leap = (((y2 - (y + 1)) / 4) + 1);
                        else if ((y + 2) % 4 == 0) leap = (((y2 - (y + 2)) / 4) + 1);
                        else if ((y + 3) % 4 == 0) leap = (((y2 - (y + 3)) / 4) + 1);
                    }
                    else if (y != y2) { if (y % 4 == 0) leap = 1; else if ((y + 1) % 4 == 0) leap == 1; else if ((y + 2) % 4 == 0); }
                    counter += YearsInInterval * 365 + leap;
                }
                if (m != m2) {
                    m = m2 - 1;
                    if (m != 0) {
                        if (m == 1) counter += 31; else if (m == 2 && y2 % 4 == 0) counter += 60; else if (m == 2 && y2 % 4 != 0) counter += 59; else
                            if (m == 3 && y2 % 4 == 0) counter += 91; else if (m == 3 && y2 % 4 != 0) counter += 90; else
                                if (m == 4 && y2 % 4 == 0) counter += 121; else if (m == 4 && y2 % 4 != 0) counter += 120; else
                                    if (m == 5 && y2 % 4 == 0) counter += 152; else if (m == 5 && y2 % 4 != 0) counter += 151; else
                                        if (m == 6 && y2 % 4 == 0) counter += 182; else if (m == 6 && y2 % 4 != 0) counter += 181; else
                                            if (m == 7 && y2 % 4 == 0) counter += 213; else if (m == 7 && y2 % 4 != 0) counter += 212; else
                                                if (m == 8 && y2 % 4 == 0) counter += 244; else if (m == 8 && y2 % 4 != 0) counter += 243; else
                                                    if (m == 9 && y2 % 4 == 0) counter += 274; else if (m == 9 && y2 % 4 != 0) counter += 273; else
                                                        if (m == 10 && y2 % 4 == 0) counter += 305; else if (m == 10 && y2 % 4 != 0) counter += 304; else
                                                            if (m == 11 && y2 % 4 == 0) counter += 335; else if (m == 11 && y2 % 4 != 0) counter += 334;
                    }
                }counter += d2;
            }
            if (y != y2 + 2) cout << "Между этими датами " << counter;
            if ((counter % 10 == 1) && !(counter % 100 == 11)) {
                cout << " день\n";
            }
            else if (((counter % 10 == 2) || (counter % 10 == 3) || (counter % 10 == 4)) && !(counter % 100 == 12) && !(counter % 100 == 13) && !(counter % 100 == 14)) {
                cout << " дня\n";
            }
            else {
                cout << " дней\n";
            }
        }
    }
}