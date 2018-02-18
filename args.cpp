#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << "argc = " << argc << endl;
    for (int i=0; i<argc; i++) {
        cout << "\"" << argv[i] << "\"" <<endl;
    }
    char* fileName = argv[1];
    return 0;
}