#include <iostream>
#include <string>
#include <fstream>
#include "pixel.h"
#include "image.h"

using namespace std;

int main(int argc, char** argv){
    ifstream fs;
    if(argc != 3){
        cout << "Usage: [input file] [output file]" << endl;
        return 1;
    }
    
    char* filename = argv[1];
    char* output = argv[2];

    Image pix(filename);
    Image copy_pix(pix);

    pix.save(filename);
    copy_pix.save(output);

    return 0;
}