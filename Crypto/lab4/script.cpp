rewrite this on python: 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string file1, file2;
    cout << "Enter the name of the first file: ";
    cin >> file1;
    cout << "Enter the name of the second file: ";
    cin >> file2;

    ifstream inFile1(file1);
    ifstream inFile2(file2);

    if (!inFile1 || !inFile2)
    {
        cout << "Error opening files" << endl;
        return 1;
    }

    char ch1, ch2;
    int count = 0, match = 0;

    while (inFile1.get(ch1) && inFile2.get(ch2))
    {
        count++;
        if (ch1 == ch2)
            match++;
    }

    double percent = (double)match / count * 100;
    cout << "Percentage of matching letters: " << percent << "%" << endl;

    inFile1.close();
    inFile2.close();

    return 0;
}
