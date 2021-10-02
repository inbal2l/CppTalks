#include <stdexcept>
#include <chrono>
#include <iostream>


#define ITERS 10000
using namespace std;

void ThrowingFunc() {
    throw logic_error("Wrong logic");
}

int ErrorCodeFunc() {
    return -1;
}


int main()
{
    const auto BeforeThrow = chrono::steady_clock::now();
    for (int i = 0 ; i < ITERS ; i++) {
        try {
            ThrowingFunc();
        } catch (const logic_error &e) {
            // cout << "iter " << i << ": " << e.what() << '\n';
        }
    }
    const auto AfterThrow = chrono::steady_clock::now();

    const auto BeforeReturn = chrono::steady_clock::now();
    for (int i = 0 ; i < ITERS ; i++) {
        int ret = ErrorCodeFunc();
        if (ret == -1) {
            ;
            // cout << "iter " << i << ": " << ret << '\n';
        }
    }
    const auto AfterReturn = chrono::steady_clock::now();
    cout << "Time throw: " << chrono::duration_cast<chrono::nanoseconds>(AfterThrow - BeforeThrow).count() / ITERS << " ns \n";
    cout << "Time Return: " << chrono::duration_cast<chrono::nanoseconds>(AfterReturn - BeforeReturn).count() / ITERS << " ns \n";
}