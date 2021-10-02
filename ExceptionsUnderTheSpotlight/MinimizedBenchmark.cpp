#include <stdexcept>
#include <chrono>
#include <iostream>

#define ITERS 10000

using namespace std;

void ThrowingFunc1() {
    throw length_error("Wrong length");
}
void ThrowingFunc2() {
    throw domain_error("Wrong domain");
}
void ThrowingFunc3() {
    throw overflow_error("Wrong overflow");
}

int ErrorCodeFunc1() {
    return -1;
}
int ErrorCodeFunc2() {
    return -2;
}
int ErrorCodeFunc3() {
    return -3;
}


int main()
{
    const auto BeforeThrow = chrono::steady_clock::now();
    for (int i = 0 ; i < ITERS ; i++) {
        try {
            if (i%3 == 0) 
                ThrowingFunc1();
            if (i%3 == 1)
                ThrowingFunc2();
            if (i%3 == 2)
                ThrowingFunc3();
        }   catch (const length_error &e) {;
        //    cout << "got logic_error in the iter " << i << '\n';
        }   catch (const domain_error &e) {;
        //    cout << "got domain_error in the iter " << i << '\n';
        }   catch (const overflow_error &e) {;
        //    cout << "got overflow_error in the iter " << i << '\n';
        }
    }
    const auto AfterThrow = chrono::steady_clock::now();

    const auto BeforeReturn = chrono::steady_clock::now();
    int ret;
    for (int i = 0 ; i < ITERS ; i++) {
        if (i%3 == 0) 
            ret = ErrorCodeFunc1();
        if (i%3 == 1)
            ret = ErrorCodeFunc2();
        if (i%3 == 2)
            ret = ErrorCodeFunc3();
        
        if (ret == -1) {
        //    cout << "got -1 in the iter " << i << ": " << ret << '\n';
        }
        if (ret == -2) {
        //    cout << "got -2 in the iter " << i << ": " << ret << '\n';
        }
        if (ret == -3) {
        //    cout << "got -3 in the iter " << i << ": " << ret << '\n';
        }
    }
    const auto AfterReturn = chrono::steady_clock::now();

    cout << "Time throw: " << chrono::duration_cast<chrono::nanoseconds>(AfterThrow - BeforeThrow).count() / ITERS << " ns \n";
    cout << "Time Return: " << chrono::duration_cast<chrono::nanoseconds>(AfterReturn - BeforeReturn).count() / ITERS << " ns \n";
}
