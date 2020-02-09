#include "EzVm.h"
#include "iostream"

using namespace std;


int main(int argc, char **argv) {

    if (argc <= 1) {
        cout << "ERROR : No file input." << endl;
        return 0;
    }

    string inputFileName(argv[1]);

    int pos = inputFileName.rfind('.');

    if (pos == string::npos) {
        cout << "File format is incorrect." << endl;
        return 0;
    } else {
        string suffix = inputFileName.substr(pos + 1, inputFileName.length() - pos - 1);

        if (suffix != "EzClass") {
            cout << "File format is incorrect." << endl;
            return 0;
        }
        EzVm::ezVm->ReadSourceFile(argv[1]);
    }


}