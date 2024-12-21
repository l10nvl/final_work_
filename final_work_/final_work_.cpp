#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//Палитра цветов
namespace Color {
    const string RESET = "\033[0m"; //сброс
    const string RED = "\033[1m\033[31m"; //красный 
    const string GREEN = "\033[1m\033[32m";//зеленый
    const string YELLOW = "\033[1m\033[33m"; //желтый
    const string BLUE = "\033[1m\033[34m";//синий
    const string MAGENTA = "\033[1m\033[35m";// пурпурный
    const string CYAN = "\033[1m\033[36m";// голубой
    const string BLACK = "\033[1m\033[30m";// черный
    const string WHITE = "\033[1m\033[37m"; // белый

    void Red(const string& text) {
        cout << RED << text << RESET << endl;
    }
    void Green(const string& text) {
        cout << GREEN << text << RESET << endl;
    }
    void Yellow(const string& text) {
        cout << YELLOW << text << RESET << endl;
    }
    void Blue(const string& text) {
        cout << BLUE << text << RESET << endl;
    }
    void Magenta(const string& text) {
        cout << MAGENTA << text << RESET << endl;
    }
    void Cian(const string& text) {
        cout << CYAN << text << RESET << endl;
    }
    void Black(const string& text) {
        cout << BLACK << text << RESET << endl;
    }
    void White(const string& text) {
        cout << WHITE << text << RESET << endl;
    }

}
using namespace Color;
using namespace chrono;



//###################################### 2 ЛАБА
void bubble_sort(int res[100])
{
    bool swapped = false;
    for (int i = 0; i < 100; i++)
    {
        swapped = false;
        for (int j = 0; j < 100 - i - 1; j++)
        {
            if (res[j] > res[j + 1])
            {
                std::swap(res[j], res[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
//Сортировка шейкер
void shaker_sort(int res[100])
{
    bool swapped = true;
    while (swapped != false)
    {
        swapped = false;
        bool AorB = true;
        if (AorB)
        {
            for (int i = 0; i < 99; i++)
            {
                if (res[i] > res[i + 1])
                {
                    std::swap(res[i], res[i + 1]);
                    swapped = true;
                    AorB = false;
                }
            }
        }
        else
        {
            for (int j = 99; j > 0; j--)
            {
                if (res[j - 1] > res[j])
                {
                    std::swap(res[j], res[j - 1]);
                    swapped = true;
                    AorB = true;
                }
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
//Бинарный поиск
bool BinarySearch(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return 1;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}
//Сортировка расческой
void CombSort(int res[100])
{
    int step = 100;
    bool isSwaps = true;
    while (step > 1 and isSwaps == true)
    {
        step = int(step / 1.247);
        isSwaps = false;
        for (int i = 0; i < 100 - step; i++)
        {
            if (res[i] > res[i + step])
            {
                swap(res[i], res[i + step]);
                isSwaps = true;
            }
        }
    }
}
//Сортировка вставками
void InsertSort(int res[100])
{
    for (int j = 1; j < 100; j++)
    {
        int bufer = res[j];
        int i = j - 1;
        while (i >= 0 && res[i] > bufer)
        {
            res[i + 1] = res[i];
            i--;
        }
        res[++i] = bufer;
    }
}
//Быстрая сортировка
void quickSort(vector<int>& res, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = res[(left + right) / 2];

        // Разделяем массив на две части
        while (left <= right) {
            // Ищем элементы, которые нужно поменять местами
            while (res[left] < middle) {
                left++;
            }
            while (res[right] > middle) {
                right--;
            }
            if (left <= right) {
                swap(res[left], res[right]);
                left++;
                right--;
            }
        }
        if (first < right) {
            quickSort(res, first, right);
        }
        if (left < last) {
            quickSort(res, left, last);
        }
    }
}

int BinarySearch1(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    int k = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return middle;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}
//Сортировка Шелла
void shellSort(int res[100]) {
    // Начинаем с большого интервала и уменьшаем его
    for (int gap = 100 / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками для текущего интервала
        for (int i = gap; i < 100; i++) {
            int temp = res[i];
            int j;
            for (j = i; j >= gap && res[j - gap] > temp; j -= gap) {
                res[j] = res[j - gap];
            }
            res[j] = temp;
        }
    }
}

//############################## 3 ЛАБА

const int rows = 6; // Количество строк
const int cols = 6; // Количество столбцов


void bubbleSort(int (*arr)[cols], int rows) {
    int Elements = rows * cols;

    for (int i = 0; i < Elements - 1; ++i)
    {
        for (int j = 0; j < Elements - i - 1; ++j)
        {
            int* current = *arr + j;
            int* next = *arr + j + 1;

            if (*current > *next)
            {
                swap(*current, *next);
            }
        }
    }
}

void fillSpiral(int arr[rows][cols]) {
    int* end = *(arr + rows * cols - 1);
    for (int* ptr = *arr; ptr <= end; ptr++)
    {
        *ptr = 1 + rand() % (rows * cols);
    }
}

void printSpiral(int (*arr)[cols]) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Вывод верхней строки
        for (int i = left; i <= right; i++) {
            coord.X = i * 3;
            coord.Y = top;
            SetConsoleCursorPosition(hStdout, coord);
            cout << *(*(arr + top) + i) << " ";
            Sleep(150);
        }
        top++;

        // Вывод правого столбца
        for (int i = top; i <= bottom; i++) {
            coord.X = right * 3;
            coord.Y = i;
            SetConsoleCursorPosition(hStdout, coord);
            cout << *(*(arr + i) + right) << " ";
            Sleep(150);
        }
        right--;

        // Вывод нижней строки
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                coord.X = i * 3;
                coord.Y = bottom;
                SetConsoleCursorPosition(hStdout, coord);
                cout << *(*(arr + bottom) + i) << " ";
                Sleep(150);
            }
            bottom--;
        }

        // Вывод левого столбца
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                coord.X = left * 3;
                coord.Y = i;
                SetConsoleCursorPosition(hStdout, coord);
                cout << *(*(arr + i) + left) << " ";
                Sleep(150);
            }
            left++;
        }
    }

    coord.X = 0;
    coord.Y = rows + 1;
    SetConsoleCursorPosition(hStdout, coord);
}

void printZmeika(int (*arr)[cols]) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;

    for (int col = 0; col < cols; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                coord.X = col * 3;
                coord.Y = row;
                SetConsoleCursorPosition(hStdout, coord);
                cout << *(*(arr + row) + col) << " ";
                Sleep(150);
            }
        }
        else {
            for (int row = rows - 1; row >= 0; row--) {
                coord.X = col * 3;
                coord.Y = row;
                SetConsoleCursorPosition(hStdout, coord);
                cout << *(*(arr + row) + col) << " ";
                Sleep(150);
            }
        }
    }
    coord.X = 0;
    coord.Y = rows + 1;
    SetConsoleCursorPosition(hStdout, coord);
}

void change_A(int (*arr)[cols])
{
    int blockSize = rows / 2;

    int temp[rows][cols];

    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            // Блок 1 (верхний левый) -> Блок 2 (верхний правый)
            *(*(temp + i) + (j + blockSize)) = *(*(arr + i) + j);

            // Блок 2 (верхний правый) -> Блок 3 (нижний правый)
            *(*(temp + (i + blockSize)) + (j + blockSize)) = *(*(arr + i) + (j + blockSize));

            // Блок 3 (нижний правый) -> Блок 4 (нижний левый)
            *(*(temp + (i + blockSize)) + j) = *(*(arr + (i + blockSize)) + (j + blockSize));

            // Блок 4 (нижний левый) -> Блок 1 (верхний левый)
            *(*(temp + i) + j) = *(*(arr + (i + blockSize)) + j);
        }
    }

    // Копируем новые значения обратно в оригинальную матрицу
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            *(*(arr + i) + j) = *(*(temp + i) + j);
        }
    }
}

void change_B(int (*matrix)[cols]) {
    int blockSize = rows / 2;
    int temp[rows][cols];

    // Блок 1 -> Блок 4
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i + blockSize) + (j + blockSize)) = *(*(matrix + i) + j); // Блок 1 в Блок 4
        }
    }

    // Блок 2 -> Блок 3
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i + blockSize) + j) = *(*(matrix + i) + (j + blockSize)); // Блок 2 в Блок 3
        }
    }

    // Блок 3 -> Блок 2
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i) + (j + blockSize)) = *(*(matrix + (i + blockSize)) + j); // Блок 3 в Блок 2
        }
    }

    // Блок 4 -> Блок 1
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i) + j) = *(*(matrix + (i + blockSize)) + (j + blockSize)); // Блок 4 в Блок 1
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(*(matrix + i) + j) = *(*(temp + i) + j);
        }
    }
}

void change_C(int (*matrix)[cols]) {
    int blockSize = rows / 2;
    int temp[rows][cols];

    // Блок 1 -> Блок 3
    for (int i = 0; i < blockSize; ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            *(*(temp + i + blockSize) + j) = *(*(matrix + i) + j);
        }
    }

    // Блок 3 -> Блок 1
    for (int i = 0; i < blockSize; ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            *(*(temp + i) + j) = *(*(matrix + (i + blockSize)) + j);
        }
    }

    // Блок 2 -> Блок 4
    for (int i = 0; i < blockSize; ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            *(*(temp + i) + (j + blockSize)) = *(*(matrix + (i + blockSize)) + (j + blockSize));
        }
    }

    // Блок 4 -> Блок 2
    for (int i = 0; i < blockSize; ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            *(*(temp + i + blockSize) + (j + blockSize)) = *(*(matrix + i) + (j + blockSize));
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            *(*(matrix + i) + j) = *(*(temp + i) + j);
        }
    }
}

void change_D(int (*matrix)[cols]) {
    int blockSize = rows / 2;
    int temp[rows][cols];

    // Блок 1 -> Блок 2
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i) + (j + blockSize)) = *(*(matrix + i) + j);
        }
    }

    // Блок 2 -> Блок 1
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + i) + j) = *(*(matrix + i) + (j + blockSize));
        }
    }

    // Блок 3 -> Блок 4
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + (i + blockSize)) + (j + blockSize)) = *(*(matrix + (i + blockSize)) + j);
        }
    }

    // Блок 4 -> Блок 3
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            *(*(temp + (i + blockSize)) + j) = *(*(matrix + (i + blockSize)) + (j + blockSize));
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(*(matrix + i) + j) = *(*(temp + i) + j);
        }
    }
}

void printMatrix(int (*matrix)[cols])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void printMatrixA(int (*matrix)[cols], int a) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(matrix + i) + j) + a << " ";
        }
        cout << "\n";
    }
}

void printMatrixB(int (*matrix)[cols], int a) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(matrix + i) + j) - a << " ";
        }
        cout << "\n";
    }
}

void printMatrixC(int (*matrix)[cols], int a) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(matrix + i) + j) * a << " ";
        }
        cout << "\n";
    }
}

void printMatrixD(int (*matrix)[cols], int a) {
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(matrix + i) + j) / a << " ";
        }
        cout << endl;
    }
}

void printMatrixD_1(float (*matrix)[cols], int a)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] > 0)
            {
                float pop = 1.0;
                cout << pop / a << " ";
            }
            else
            {
                float pop = -1.0;
                cout << pop / a << " ";
            }
        }
        cout << endl;
    }
}
//ИДЗ##########################################

void fillSpiral_2(int arr[3][3])
{
    int* end = *(arr + rows * cols - 1);
    for (int* ptr = *arr; ptr <= end; ptr++)
    {
        *ptr = rand() % 61 - 30;
    }
}

void printMatrix_2(int (*matrix)[3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}




//############################## 4 ЛАБА

//boyerMoore
void spaces(char text[]) {
    int i = 0, j = 0;
    bool in_word = false;

    while (text[i] != '.') {
        if (text[i] == ' ') {
            if (in_word)
            {
                text[j++] = ' ';
                in_word = false;
            }
        }
        else {
            text[j++] = text[i];
            in_word = true;
        }
        i++;
    }

    if (j > 0 && text[j - 1] == ' ') {
        j--;
    }

    text[j] = '\0';
}

void punctuation(char text[]) {
    int i = 0, j = 0;
    bool in_punctuation = false;

    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ';' || text[i] == ':') {
            if (!in_punctuation) {
                text[j++] = text[i];
                in_punctuation = true;
            }
        }
        else {
            text[j++] = text[i];
            in_punctuation = false;
        }
        i++;
    }

    text[j] = '\0';
}

void correct_case(char text[]) {
    bool new_sentence = true;
    int i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '.')
            break;
        if (new_sentence && text[i] != 0 && text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
            new_sentence = false;
        }
        else if (!new_sentence && text[i] >= 'A' && text[i] <= 'Z') {
            text[i] += 32;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            new_sentence = true;
        }

        i++;
    }
}

void print_reverse(char text[]) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        cout << text[i];
    }
    cout << endl;
}

void replace_digits_with_letters(char text[]) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '.')
            break;
        if (text[i] >= '0' && text[i] <= '9') {
            text[i] = 'a' + (text[i] - '0');
        }
        i++;
    }
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

void boyerMoore(const char text[], const char pattern[]) {
    int n = 0;
    while (text[n] != '\0') n++;
    int m = 0;
    while (pattern[m] != '\0') m++;

    bool found = false;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (to_lower(text[i + j]) != to_lower(pattern[j])) {
                break;
            }
        }
        if (j == m) {
            cout << "Подстрока найдена в позиции: " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Подстрока не найдена" << endl;
    }
}

void input_and_process(char text[]) {
    char c;
    int i = 0;

    Green("\nВыберите, как вы хотите передавать данные");
    cout << "1. Ввод с клавиатуры\n";
    cout << "2. Ввод с файла (input.txt)\n";

    int file_or_text;
    cin >> file_or_text;

    if (file_or_text == 1) {
        cout << "Введите текст оканчивающийся точкой:\n";
        while (true) {
            cin.get(c);
            if (c == '.') {
                text[i++] = c;
                text[i] = '\0';
                break;
            }
            text[i++] = c;
        }
    }
    else if (file_or_text == 2) {
        ifstream infile("input.txt");
        if (!infile) {
            cout << "Ошибка открытия файла!" << endl;
        }


        while (infile.get(c)) {
            text[i++] = c;
            if (c == '.')
                break;
        }
        infile.close();
    }
    else {
        cout << "Неверный выбор!" << endl;
        return;
    }
}

void countChar(const char inputText[]) {
    const int maxWords = 500; // Максимальное количество слов
    const int maxWordLength = 100; // Максимальная длина слова
    char words[maxWords][maxWordLength]; // Статический массив для хранения слов
    int wordCount = 0;
    int start = -1; // Начальная позиция слова

    // Проходим по строке и ищем слова
    for (int i = 0; i <= strlen(inputText); i++) {
        // Если текущий символ пробел или конец строки
        if (i == strlen(inputText) || inputText[i] == ' ') {
            // Если слово найдено
            if (start != -1) {
                int end = i - 1; // Конечная позиция слова
                int charCount = end - start + 1; // Количество символов в слове
                cout << charCount << " "; // Выводим количество символов
                start = -1; // Сбрасываем начальную позицию
            }
        }
        else {
            // Если это не пробел, запоминаем начало слова
            if (start == -1) {
                start = i;
            }
        }
    }

    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    //ДЛЯ ВТОРОЙ ЛАБЫ
    while (true)
    {
        //Меню
        cout << "\033[1m\033[31m";
        Red("Выберите пункт (1-4) или 0 для выхода\n");
        cout << "\033[0m";
        cout << "1. 1 Лабораторная - Типы данных, определяемые пользователем. Структуры\n";
        cout << "2. 2 Лабораторная - Одномерные статические массивы.\n";
        cout << "3. 3 Лабораторная - Двумерные статические массивы. Указатели.\n";
        cout << "4. 4 Лабораторная - Работа с текстовыми строками.\n";
        cout << "0. Выход\n";
        int number;
        cin >> number;
        if (number == 0) 
        {
            cout << "\nПрограмма завершила свою работу" << endl;
            break;
        }
        switch (number)
        {
        case 1:
        {
            cout << "Введите номер задания: ";
            int start;
            cin >> start;
            switch (start)
            {
            case 1:
            {
                cout << "Введите тип данных, для которого необходимо вывести объем занимаемой памяти: 1 - int, 2 - short, 3 - long, 4 - char и т.д." << endl;
                while (true) {
                    int ans;
                    cin >> ans;
                    if (ans == 1) {
                        cout << "Размер int: " << sizeof(int) << " байт" << endl;
                    }
                    else if (ans == 2) {
                        cout << "Размер short: " << sizeof(short) << " байт" << endl;
                    }
                    else if (ans == 3) {
                        cout << "Размер long: " << sizeof(long) << " байт" << endl;
                    }
                    else if (ans == 4) {
                        cout << "Размер float: " << sizeof(float) << " байт" << endl;
                    }
                    else if (ans == 5) {
                        cout << "Размер double: " << sizeof(double) << " байт" << endl;
                    }
                    else if (ans == 6) {
                        cout << "Размер long double: " << sizeof(long double) << " байт" << endl;
                    }
                    else if (ans == 7) {
                        cout << "Размер char: " << sizeof(char) << " байт" << endl;
                    }
                    else if (ans == 8) {
                        cout << "Размер bool: " << sizeof(bool) << " байт" << endl;
                    }
                    else if (ans == 0) {
                        break;
                    }
                }
            }
                case 2:
                {
                    while (true) {
                        int a;
                        cout << "Введите число: ";
                        cin >> a;

                        HANDLE h;
                        h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                        cout << "Двоичное представление в памяти типа int:";
                        cout << "\033[0m";
                        cout << " ";

                        unsigned int mask = 1 << (sizeof(int) * 8 - 1);

                        // Список для change битов
                        int res[32] = {};
                        for (int i = 1; i <= (sizeof(int) * 8); i++, mask >>= 1) {
                            if (i == 1) {
                                cout << "\033[1m\033[37m";
                                putchar(a & mask ? '1' : '0');
                                cout << "\033[0m";
                            }
                            else if (i > 1) {
                                cout << "\033[1m\033[31m";
                                putchar(a & mask ? '1' : '0');
                                cout << "\033[0m";
                            }
                            if (i == 1 or i % 8 == 0) {
                                cout << " ";
                            }
                            if (a & mask)
                                res[i - 1] = 1;
                            else
                                res[i - 1] = 0;

                        }
                        cout << endl;
                        cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                        int chek;
                        cin >> chek;
                        if (chek == 0) {
                            break;
                        }
                        //меняем  биты пока не будет введено 0
                        int finish = 2;
                        while (finish != 0) {
                            if (chek == 1) {
                                cout << "Введите номер первого бита: ";
                                int first_bit;
                                cin >> first_bit;
                                cout << endl;
                                cout << "Введите номер второго бита: ";
                                int second_bit;
                                cin >> second_bit;
                                cout << endl;

                                int bufer;
                                bufer = res[first_bit - 1];

                                res[first_bit - 1] = res[second_bit - 1];
                                res[second_bit - 1] = bufer;
                                for (int l = 1; l <= 32; l++) {
                                    if (l == 1) {
                                        cout << "\033[1m\033[37m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    else if (l > 1) {
                                        cout << "\033[1m\033[31m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l == 1 or l % 8 == 0) {
                                        cout << " ";
                                    }
                                }
                                cout << endl;
                                cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                                break;
                                cin >> finish;
                            }
                            cout << endl;
                            break;
                        }
                    }
                }
                case 3:
                {
                    while (true) {
                        union {
                            float val1;
                            unsigned int b;
                        };
                        cout << "Введите число: ";
                        cin >> val1;

                        HANDLE h;
                        h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                        cout << "Двоичное представление в памяти типа float:";
                        cout << "\033[0m";
                        cout << " ";


                        unsigned int mask = 1 << (sizeof(float) * 8 - 1);
                        // Список для change битов
                        int res[32] = {};
                        for (int i = 1; i <= sizeof(float) * 8; i++, mask >>= 1) {
                            if (i == 1) {
                                cout << (b & mask ? '1' : '0') << " ";
                            }
                            else if (i >= 2 && i <= 8) {
                                cout << "\033[34m";
                                putchar(b & mask ? '1' : '0');
                                cout << "\033[0m";
                                if (i == 8) {
                                    cout << " ";
                                }
                            }
                            else {
                                cout << "\033[1m\033[31m";
                                putchar(b & mask ? '1' : '0');
                                cout << "\033[0m";
                                if (i % 8 == 0) {
                                    cout << " ";
                                }
                            }
                            if (b & mask)
                                res[i - 1] = 1;
                            else
                                res[i - 1] = 0;
                        }
                        cout << endl;
                        cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                        int chek;
                        cin >> chek;
                        if (chek == 0) {
                            break;
                        }
                        //меняем  биты пока не будет введено 0
                        int finish = 2;
                        while (finish != 0) {
                            if (chek == 1) {
                                cout << "Введите номер первого бита: ";
                                int first_bit;
                                cin >> first_bit;
                                cout << endl;
                                cout << "Введите номер второго бита: ";
                                int second_bit;
                                cin >> second_bit;
                                cout << endl;

                                int bufer;
                                bufer = res[first_bit - 1];

                                res[first_bit - 1] = res[second_bit - 1];
                                res[second_bit - 1] = bufer;
                                for (int l = 1; l <= 32; l++) {
                                    if (l == 1) {
                                        cout << "\033[1m\033[37m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l >= 2 and l <= 8) {
                                        cout << "\033[34m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l > 8) {
                                        cout << "\033[31m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l == 1 or l % 8 == 0) {
                                        cout << " ";
                                    }
                                }
                                cout << endl;
                                cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                                cin >> finish;
                            }
                            cout << endl;
                        }
                        cout << endl;
                        break;
                    }
                }
                case 4:
                {
                    while (true) 
                    {
                        union {
                            double val1;
                            int b[2];
                        };
                        cout << "Введите число: ";
                        cin >> val1;

                        int now_bit = 0;


                        HANDLE h;
                        h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                        cout << "Двоичное представление в памяти типа double:";
                        cout << "\033[0m";
                        cout << " ";

                        // Список для change битов
                        int res[64] = {};

                        for (int i = 1; i >= 0; i--) {
                            unsigned int mask = 1 << (sizeof(float) * 8 - 1);
                            for (int j = 1; j <= sizeof(float) * 8; j++, mask >>= 1) {
                                now_bit += 1;
                                if (now_bit == 1) {
                                    cout << "\033[1m\033[37m";
                                    putchar(b[i] & mask ? '1' : '0');
                                    cout << "\033[0m";
                                }
                                if (now_bit >= 2 and now_bit <= 12) {
                                    cout << "\033[1m\033[34m";
                                    putchar(b[i] & mask ? '1' : '0');
                                    cout << "\033[0m";
                                }
                                if (now_bit >= 13 and now_bit <= 64) {
                                    cout << "\033[1m\033[31m";
                                    putchar(b[i] & mask ? '1' : '0');
                                    cout << "\033[0m";
                                }
                                if (now_bit == 1 or now_bit == 12)
                                    cout << " ";
                                if (i == 1) {
                                    if (b[i] & mask)
                                        res[j - 1] = 1;
                                    else
                                        res[j - 1] = 0;
                                }
                                else {
                                    if (b[i] & mask)
                                        res[32 + j - 1] = 1;
                                    else
                                        res[32 + j - 1] = 0;
                                }
                            }
                        }
                        cout << endl;
                        cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                        int chek;
                        cin >> chek;
                        if (chek == 0) {
                            continue;
                        }
                        //меняем  биты пока не будет введено 0
                        int finish = 2;
                        while (finish != 0) {
                            if (chek == 1) {
                                cout << "Введите номер первого бита: ";
                                int first_bit;
                                cin >> first_bit;
                                cout << endl;
                                cout << "Введите номер второго бита: ";
                                int second_bit;
                                cin >> second_bit;
                                cout << endl;

                                int bufer;
                                bufer = res[first_bit - 1];

                                res[first_bit - 1] = res[second_bit - 1];
                                res[second_bit - 1] = bufer;
                                for (int l = 1; l <= 63; l++) {
                                    if (l == 1) {
                                        cout << "\033[1m\033[37m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l >= 2 and l <= 12) {
                                        cout << "\033[34m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l > 12) {
                                        cout << "\033[31m";
                                        cout << res[l - 1];
                                        cout << "\033[0m";
                                    }
                                    if (l == 1 or l == 12) {
                                        cout << " ";
                                    }
                                }
                                cout << endl;
                                cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                                cin >> finish;
                            }
                            cout << endl;
                        }
                        cout << endl;
                    }
                
                }
                default:
                    break;
                }

        }
        case 2:
        {
            time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end, start1, end1;
            nanoseconds result, result1;
            int yop;

            int key;

            int choice = 0;
            int res[100];

            int mini = 101;
            int maxi = -101;

            while (true) {
                //Меню
                cout << "\033[1m\033[31m";
                Red("Выберите пункт (1-8) или 0 для выхода\n");
                cout << "\033[0m";
                cout << "1. Пункт 1. Массив размерности N = 100\n";
                cout << "2. Пункт 2. Отсортировать\n";
                cout << "3. Пункт 3. Найти максимальный и минимальный элемент\n";
                cout << "4. Пункт 4. Выводит среднее значение\n";
                cout << "5. Пункт 5. Меньше числа a\n";
                cout << "6. Пункт 6. Больше числа b\n";
                cout << "7. Пункт 7. Есть ли введенное пользователем число\n";
                cout << "8. Пункт 8. Меняет местами элементы массива\n";
                cout << "9. Пункт 9. Сортировка шелла\n";
                cout << "0. Выход\n";

                cin >> choice;

                if (choice == 0) {
                    cout << "\nПрограмма завершила свою работу" << endl;
                    break;
                }
                switch (choice) {
                case 1:
                    while (true)
                    {
                        cout << "\033[1m\033[31m";
                        Green("Вы выбрали пункт 1");
                        cout << "\033[0m";
                        Cian("\nНесортированный список: ");
                        start = steady_clock::now();
                        for (int l = 0; l < 100; l++)
                        {
                            int random1 = rand() % 200 - 100;
                            res[l] = random1;
                            if (random1 < mini)
                            {
                                mini = random1;
                            }
                            if (random1 > maxi)
                            {
                                maxi = random1;
                            }
                            cout << res[l] << " ";
                        }
                        end = steady_clock::now();
                        result = duration_cast<nanoseconds>(end - start);
                        key = result.count();
                        cout << endl;
                        char finish;
                        cout << "Хотите выйти из 1 пункта?: y/n: ";
                        cin >> finish;
                        if (finish == 'y' || finish == 'Y' || finish == 'н')
                            break;
                    }
                case 2:
                    while (true)
                    {
                        Green("\nВы выбрали пункт 2");
                        cout << "\nСейчас вы можете выбрать тип сортировки:\n";
                        cout << "1: bubble_sort\n";
                        cout << "2: shaker_sort\n";
                        cout << "3: CombSort\n";
                        cout << "4: InsertSort\n";
                        cout << "5: quickSort\n";
                        cout << "0: Выход из второго пункта\n";
                        int sorty;
                        cin >> sorty;
                        if (sorty == 1) {
                            start = steady_clock::now();
                            bubble_sort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 2) {
                            start = steady_clock::now();
                            shaker_sort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 3) {
                            start = steady_clock::now();
                            CombSort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 4) {
                            start = steady_clock::now();
                            InsertSort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 5)
                        {
                            vector<int> arr(100);
                            for (int l = 0; l < 100; l++)
                            {
                                int random1 = rand() % 200 - 100;
                                arr[l] = random1;
                            }
                            cout << endl;
                            start = steady_clock::now();
                            quickSort(arr, 0, 99);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << arr[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 0)
                            break;
                    }

                case 3:
                    while (true)
                    {
                        Green("Вы выбрали пункт 3\n");
                        cout << "min элемент массива : " << mini << endl;
                        cout << "max элемент массива : " << maxi << endl;
                        Yellow("Время затраченное на поиск минимального и максимального элемента в НЕсортированном массиве: ");
                        cout << key << endl;
                        Yellow("Время затраченное на поиск минимального и максимального элемента в Сортированном массиве: ");
                        start = steady_clock::now();
                        int a = res[0], b = res[99];
                        end = steady_clock::now();
                        result = duration_cast<nanoseconds>(end - start);
                        cout << result.count() << "\n";
                        break;
                    }
                case 4:
                    while (true)
                    {
                        Green("Вы выбрали пункт 4\n");
                        int srednee = int((mini + maxi) / 2);
                        cout << "Среднее значение min и max: " << srednee << endl;
                        int count = 0;
                        int indexi[50];
                        int o = 0;
                        for (int l = 0; l < 100; l++)
                        {
                            if (res[l] == srednee)
                            {
                                count += 1;
                            }
                        }
                        Cian("Количество элементов равных среднему значению: ");
                        cout << count << endl;
                        cout << "\033[1m\033[36m";
                        cout << "Индексы данных элементов: ";
                        cout << "\033[00m";
                        bool found = false;
                        start = steady_clock::now();
                        for (int i = 0; i < 100; ++i)
                        {
                            if (res[i] == srednee)
                            {
                                cout << i << " ";
                                found = true;
                            }
                        }
                        end = steady_clock::now();
                        result = duration_cast<nanoseconds>(end - start);
                        if (!found) {
                            Red("Нет элементов, равных среднему значению.");
                        }
                        cout << endl;
                        cout << "Время поиска: " << result.count() << "\n";
                        break;
                    }
                case 5:
                    while (true)
                    {
                        shaker_sort(res);
                        Green("Вы выбрали пункт 5\n");
                        Blue("Введите число, чтобы найти количество элементов меньших a");
                        int a;
                        cout << "a = ";
                        cin >> a;
                        cout << "Количество элементов меньших a: ";
                        int fin = BinarySearch1(res, a);
                        if (fin != 0) {
                            cout << "Количество элементов меньших " << a << ": " << fin << endl;
                        }
                        else {
                            cout << "Число " << a << " нет в списке." << endl;
                        }
                        break;
                    }
                case 6:
                    while (true)
                    {
                        shaker_sort(res);
                        Green("Вы выбрали пункт 6\n");
                        Blue("Введите число, чтобы найти количество элементов больших a");
                        int a;
                        cout << "a = ";
                        cin >> a;
                        int fin = 100 - BinarySearch1(res, a);
                        if (fin != 0) {
                            cout << "Количество элементов больших " << a << ": " << fin << endl;
                        }
                        else {
                            cout << "\033[1m\033[31m";
                            cout << "Число " << a << " нет в списке." << endl;
                            cout << "\033[00m";
                        }
                        break;
                    }
                case 7:
                    while (true)
                    {
                        Green("Вы выбрали пункт 7\n");
                        Blue("Введите число, которое хотите найти в списке");
                        int choice;
                        cout << "choice = ";
                        cin >> choice;
                        start = steady_clock::now();
                        int otvet = BinarySearch(res, choice);
                        end = steady_clock::now();
                        result = duration_cast<nanoseconds>(end - start);
                        if (otvet != 0) {
                            cout << "Значение " << choice << " есть в массиве" << endl;
                        }
                        else {
                            cout << "\033[1m\033[31m";
                            cout << "Числа " << choice << " нет в списке." << endl;
                            cout << "\033[00m";
                        }
                        cout << "Время работы бинарного поиска: " << result.count() << endl;
                        start1 = steady_clock::now();
                        for (int i = 0; i < 100; i++)
                        {
                            if (res[i] == choice)
                                return 1;
                            else
                                break;
                        }
                        end1 = steady_clock::now();
                        result1 = duration_cast<nanoseconds>(end1 - start1);
                        break;
                    }
                case 8:
                    Green("\nВы выбрали пункт 8\n");
                    Cian("Сейчас необходимо поочередно ввести индексы элементов, нуждаяющихся в замене.");
                    int a, b;
                    cout << "Введите число A: ";
                    cin >> a;
                    cout << "Введите число B: ";
                    cin >> b;
                    int bufer;
                    start = steady_clock::now();
                    bufer = res[a];
                    res[a] = res[b];
                    res[b] = bufer;
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\nВот измененный массив: ";
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    Blue("\nВремя смены элементов с данными индексами: ");
                    cout << result.count() << endl;
                case 9:
                    while (true)
                    {
                        Green("Вы выбрали пункт 9. Сортировка Шелла\n");
                        Blue("Cейчас мы наглядно увидим разницу между сортировкой Шелла и Bubble_Sort");
                        Cian("Введите 1 - бабл, 2 - сортировка шелла или 0-выход");
                        int sorty;
                        cin >> sorty;
                        if (sorty == 1) {
                            start = steady_clock::now();
                            bubble_sort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 2) {
                            start = steady_clock::now();
                            shellSort(res);
                            Blue("Cортированный список: ");
                            for (int i = 0; i < 100; i++)
                                cout << res[i] << " ";
                            end = steady_clock::now();
                            result = duration_cast<nanoseconds>(end - start);
                            cout << "\033[1m\033[33m";
                            cout << "\n" << "Время работы: " << result.count() << "\n";
                            cout << "\033[0m";
                        }
                        if (sorty == 0)
                            break;
                    }
                default:
                    cout << "Неверный выбор. Пожалуйста, выберите от 0 до 8\n";
                }
            }
        }
        case 3:
            Blue("Чтобы выйти из какого - либо пункта вводить 0");
            int array[rows][cols];
            fillSpiral(array);
            while (true)
            {
                //Меню
                cout << "\033[1m\033[31m";
                Red("Выберите пункт (1-4) или 0 для выхода\n");
                cout << "\033[0m";
                cout << "1. Пункт 1. Заполнение матрицы\n";
                cout << "2. Пункт 2. Переставление блоков \n";
                cout << "3. Пункт 3. Сортировка\n";
                cout << "4. Пункт 4. Работа с элементами матрицы\n";
                cout << "5. ИДЗ найти определитель матрицы 3*3\n";
                cout << "0. Выход\n";

                int choice;
                cin >> choice;

                if (choice == 0) {
                    cout << "\nПрограмма завершила свою работу" << std::endl;
                    break;
                }
                switch (choice)
                {
                case 1:
                    while (true)
                    {
                        cout << "\033[1m\033[31m";
                        Green("\nВы выбрали пункт 1");
                        cout << "\033[0m";
                        Blue("Выберите какую схему заполнения матрицы вы хотите увидеть: ");
                        cout << "1. Спиральная\n";
                        cout << "2. Змейка\n";
                        int exs;
                        cout << "Введите число: ";
                        cin >> exs;
                        switch (exs)
                        {
                        case 1:
                            system("cls");
                            printSpiral(array);
                            break;
                        case 2:
                            system("cls");
                            printZmeika(array);
                            break;
                        default:
                            break;
                        }
                        if (exs == 0)
                            break;
                    }
                case 2:
                    while (true)
                    {
                        cout << "\033[1m\033[31m";
                        Green("\nВы выбрали пункт 2");
                        cout << "\033[0m";
                        Blue("Выберите какую схему переставления блоков вы хотите увидеть: ");
                        cout << "1. a\n";
                        cout << "2. b\n";
                        cout << "3. c\n";
                        cout << "4. d\n";
                        int j;
                        cout << "Введите число: ";
                        cin >> j;
                        switch (j)
                        {
                        case 1:
                            system("cls");
                            Cian("Схема A");
                            cout << "Матрица: " << endl;
                            printMatrix(array);
                            cout << endl;
                            cout << "Матрица после изменений: " << endl;
                            change_A(array);
                            printMatrix(array);
                            break;
                        case 2:
                            system("cls");
                            Cian("Схема B");
                            cout << "Матрица: " << endl;
                            printMatrix(array);
                            cout << endl;
                            cout << "Матрица после изменений: " << endl;
                            change_B(array);
                            printMatrix(array);
                            break;
                        case 3:
                            system("cls");
                            Cian("Схема C");
                            cout << "Матрица: " << endl;
                            printMatrix(array);
                            cout << endl;
                            cout << "Матрица после изменений: " << endl;
                            change_C(array);
                            printMatrix(array);
                            break;
                        case 4:
                            system("cls");
                            Cian("Схема D");
                            cout << "Матрица: " << endl;
                            printMatrix(array);
                            cout << endl;
                            cout << "Матрица после изменений: " << endl;
                            change_D(array);
                            printMatrix(array);
                            break;
                        default:
                            break;
                        }
                        if (j == 0)
                            break;
                    }
                case 3:
                    Green("Несортированный массив: ");
                    printMatrix(array);
                    Green("Cортированный массив: ");
                    bubbleSort(array, cols);
                    printMatrix(array);
                case 4:
                    while (true)
                    {
                        float matrix1[rows][cols];
                        for (int p = 0; p < rows; p++)
                        {
                            for (int j = 0; j < cols; j++)
                            {
                                matrix1[p][j] = array[p][j];
                            }
                        }
                        cout << "\033[1m\033[31m";
                        Green("\nВы выбрали пункт 4");
                        cout << "\033[0m";
                        Blue("Выберите какое действие с матрицей вы хотите выполнить: ");
                        cout << "1. Увеличить на число a каждый элемент\n";
                        cout << "2. Уменьшить на число a каждый элемент\n";
                        cout << "3. Умножить на число a каждый элемент\n";
                        cout << "4. Поделить на число a каждый элемент\n";
                        int p;
                        cout << "Введите число: ";
                        cin >> p;
                        int a;
                        cout << "Введите число для работы с матрицей: ";
                        cin >> a;
                        switch (p)
                        {
                        case 1:
                            system("cls");
                            Cian("Увеличить на a");
                            Yellow("Матрица: ");
                            printMatrix(array);
                            cout << endl;
                            Yellow("Матрица после изменений: ");
                            printMatrixA(array, a);
                            break;

                        case 2:
                            system("cls");
                            Cian("Уменьшить на a");
                            Yellow("Матрица: ");
                            printMatrix(array);
                            cout << endl;
                            Yellow("Матрица после изменений: ");
                            printMatrixB(array, a);
                            break;
                        case 3:
                            system("cls");
                            Cian("Умножить на a");
                            Yellow("Матрица: ");
                            printMatrix(array);
                            cout << endl;
                            Yellow("Матрица после изменений: ");
                            printMatrixC(array, a);
                            break;

                        case 4:
                            system("cls");
                            Cian("Поделить на a");

                            Yellow("Матрица: ");
                            printMatrix(array);
                            cout << endl;
                            Yellow("Матрица после изменений: ");
                            printMatrixD_1(matrix1, a);
                            break;

                        default:
                            break;
                        }
                        if (p == 0)
                            break;
                    }
                case 5:
                    int matrica[3][3];
                    fillSpiral_2(matrica);
                    system("cls");
                    Cian("Исходная матрица: ");
                    printMatrix_2(matrica);
                    Green("Нахождение определителя методом треугольника: ");
                    Yellow("Схема вычисления определителя: ");
                    cout << "(a11*a22*a33)+(a12*a23*a31)+(a13*a21*a32) - ((a11*a23*a32) + (a12*a21*a33) + (a13*a22*a31))" << endl;
                    Yellow("Промежуточные вычисления : ");
                    cout << "(" << matrica[0][0] * matrica[1][1] * matrica[2][2]
                        << ") + (" << matrica[0][1] * matrica[1][2] * matrica[2][0]
                        << ") + (" << matrica[0][2] * matrica[1][0] * matrica[2][1]
                        << ") - ((" << matrica[0][0] * matrica[1][2] * matrica[2][1]
                        << ") + (" << matrica[0][1] * matrica[1][0] * matrica[2][2]
                        << ") + (" << matrica[0][2] * matrica[1][1] * matrica[2][0] << "))" << endl;

                    cout << "Определитель матрицы = " << (matrica[0][0] * matrica[1][1] * matrica[2][2]
                        ) + (matrica[0][1] * matrica[1][2] * matrica[2][0]
                            ) + (matrica[0][2] * matrica[1][0] * matrica[2][1]
                                ) - ((matrica[0][0] * matrica[1][2] * matrica[2][1]
                                    ) + (matrica[0][1] * matrica[1][0] * matrica[2][2]
                                        ) + (matrica[0][2] * matrica[1][1] * matrica[2][0])) << endl;
                }
            }
        case 4:
            while (true) {
                int a;
                char text[1000];
                //Меню
                Red("Выберите пункт (1-4) или 0 для выхода\n");
                cout << "1. Пункт 1. Ввод последовательности слов\n";
                cout << "2. Пункт 2. Отредактировать входной текст \n";
                cout << "3. Пункт 3. Вывести на экран слова последовательности в обратном порядке.\n";
                cout << "4. Пункт 4. Вывести на экран количество символов в каждом слове исходной последовательности.\n";
                cout << "5. Пункт 5. Алгоритм Бойера-Мура\n";
                cout << "0. Выход\n";
                cin >> a;
                cin.ignore();
                switch (a)
                {
                case 1: {
                    input_and_process(text);
                    break;
                }
                case 2: {
                    spaces(text);
                    punctuation(text);
                    correct_case(text);
                    Cian("Текст после исправлений: ");
                    cout << text;
                    cout << endl;
                    break;
                }
                case 3: {
                    Cian("Текст в обратном порядке: ");
                    print_reverse(text);
                    break;
                }
                case 4: {
                    cout << "Количество символов в каждом слове: " << endl;
                    countChar(text);
                    cout << endl;
                    break;
                }
                case 5: {
                    char pattern[100];
                    cout << "Введите подстроку для поиска: ";
                    cin.getline(pattern, 100);
                    boyerMoore(text, pattern);
                    break;
                }
                default:
                    cout << "Неверный выбор!" << endl;
                }
                if (a == 0)
                    break;
            }
        default:
            cout << "Неверный выбор. Пожалуйста, выберите от 0 до 4\n";
        }
    }
}
