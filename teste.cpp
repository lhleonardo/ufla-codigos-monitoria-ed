#include <iostream>

using namespace std;

int main( ) {
    int* ptr = NULL;

    if (ptr) {
        cout << "Ponteiro nulo" << endl;
    } else {
        cout << "Ponteiro com valores" << endl;
    }
    return 0;
}