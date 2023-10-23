#include <iostream>
#include <vector>

using namespace std;

string encryptRailFence(string str, int key)
{
	vector<vector<char>> res(key, vector<char>(str.length()));


    int row = 0;
    int step = 1;

    for (int i = 0; i < str.length(); i++) {
        res[row][i] = str[i];

        if (row == key - 1)
            step = -1;
        else if (row == 0)
            step = 1;

        row += step;
    }

    string result;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < str.length(); j++) {
            if (res[i][j] != 0)
                result += res[i][j];
        }
    }

    return result;
}


string decryptRailFence(string str, int key) {
    vector<vector<char>> res(key, vector<char>(str.length()));

    int row = 0;
    int step = 1;

    for (int i = 0; i < str.length(); i++) {
        res[row][i] = '*';

        if (row == key - 1)
            step = -1;
        else if (row == 0)
            step = 1;

        row += step;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < str.length(); j++) {
            if (res[i][j] == '*' && index < str.length()) {
                res[i][j] = str[index++];
            }
        }
    }

    string result;
    row = 0;
    step = 1;

    for (int i = 0; i < str.length(); i++) {
        result += res[row][i];

        if (row == key - 1)
            step = -1;
        else if (row == 0)
            step = 1;

        row += step;
    }

    return result;
}


void RailFenceHandler()
{
    int action;
    string incrypted;
    string decrypted;
    int key;
    system("cls");
    do {
        cout << "Actions:\n[0] Encrypt string\n[1] Decrypt string\n[2] Exit" << endl;
        cin >> action;
        switch (action)
        {
        case 0:
            system("cls");
            cout << "Enter string:" << endl;
            cin >> incrypted;

            cout << "Enter key:" << endl;
            cin >> key;
            decrypted = encryptRailFence(incrypted, key);
            cout << "Result: " << encryptRailFence(incrypted, key) << endl;
            break;
        case 1:
            cout << "Decrypted: " << decryptRailFence(decrypted, key) << endl;
            break;
        case 2:
            system("cls");
            exit;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (true);
}