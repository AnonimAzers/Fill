#include <iostream>
#include <random>

template<typename T>
void show_mas(T** mas, int M, int N) {
    std::cout << ' ';
    for (int i = 0; i < M; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < M; i++) {
        std::cout << i;
        for (int j = 0; j < N; j++) {
            std::cout << mas[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
void fill(T **mas, int M, int N, int X, int Y, char Symbol) {
    if (mas[X][Y] == Symbol) {
        mas[X][Y] = (Symbol == 'X') ? ' ' : 'X';
    }
    else {
        return;
    }
        
    if (X - 1 >= 0) {
        fill(mas, M, N, X - 1, Y, Symbol);
    }
    if (X + 1 < M) {
        fill(mas, M, N, X + 1, Y, Symbol);
    }
    if (Y - 1 >= 0) {
        fill(mas, M, N, X, Y - 1, Symbol);
    }
    if (Y + 1 < N) {
        fill(mas, M, N, X, Y + 1, Symbol);
    }
}


char** char_createmas(int M, int N) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 1);
    char** mas = new char* [M];
    for (int i = 0; i < M; i++) {
        mas[i] = new char[N];
        for (int j = 0; j < N; j++) {
            mas[i][j] = distrib(gen) ? ' ' : 'X';
        }
    }

    show_mas<char>(mas, M, N);

    return mas;
}

int main()
{
    int M, N;
    std::cout << "Input M: ";
    std::cin >> M;
    std::cout << "Input N: ";
    std::cin >> N;

    char** mas = char_createmas(M, N);
    
    int X, Y;
    std::cout << "Select X: ";
    std::cin >> X;
    std::cout << "Select Y: ";
    std::cin >> Y;

    fill<char>(mas, M, N, X, Y, mas[X][Y]);
    std::cout << std::endl;
    show_mas<char>(mas, M, N);

    for (int i = 0; i < M; i++)
        delete [] mas[i];
    delete[] mas;
}
