#include<iostream>
#include<fstream>

using namespace std;

void caesar_encrypt(char& c, int n) {
    int c_int = c;
    c = (c_int+=n)%127;
}

void caesar_decrypt(char& c, int n) {
    int c_int = c;
    c_int -= n;

    if (c_int < 0) c = (128+c_int);
    else c = c_int;
}

int main() {
    cout << "Do you want to encrypt or decrypt a file? ([E]ncrypt, [D]ecrypt)" << endl << "Choice: ";
    char choice;
    cin >> choice;

    if (choice == 'E') {
        string input_file_name;
        cout << "Enter input file name: ";
        cin >> input_file_name;

        string output_file_name;
        cout << "Enter output file name: ";
        cin >> output_file_name;

        fstream InputFileName, OutputFileName;
        InputFileName.open(input_file_name, ios::in);
        OutputFileName.open(output_file_name, ios::out);

        cout << "Starting to read from file" << endl;

        char x;
        while (1) {
            InputFileName>>x;
            if(InputFileName.eof()) break;

            caesar_encrypt(x, 10);

            OutputFileName<<x;
        }

        InputFileName.close();
        OutputFileName.close();
    }

    else {
        cout << "Work in progress..." << endl;
    }

    return 0;
}