/*
#include <iostream> 
#include <cstring>  
using namespace std;

int main() {


    char text1[100], text2[100], result[100] = "";


    cout << "Enter the first text: ";
    cin.getline(text1, 100);

    cout << "Enter second text: ";
    cin.getline(text2, 100);


    const char* sep = " ,.!?;:";
    char* word1 = strtok(text2, sep);


    char word_text2[100][100];   // �����, �� ����� ������� - �����, ��� ����� ��������

    int count = 0;  // ˳������� ������� ���, �� ������� ��������

    // ���������� ��� ��� ������� ������ � ����� ��� ���������� ���������
    while (word1 != NULL) {
        strcpy(word_text2[count], word1);  // ������� ����� ����� � ����� wordsToRemove
        count++;  // �������� ��������
        word1 = strtok(NULL, sep);  // ���������� �� ���������� �����
    }

    // ����� ��������� ������ ����� �� �����
    char* word2 = strtok(text1, sep);  // �������� ����� ����� � ������� ������

    // ���������� ����� ����� ������� ������, �� ���� � � ������ ��� ��� ���������
    while (word2 != NULL) {
        bool toRemove = false;  // ����, �� ������� �������� �� �����

        // ����������, �� ������� �� ����� � ����� ���, �� ����� ��������
        for (int i = 0; i < count; i++) {
            if (strcmp(word2, word_text2[i]) == 0) {  // ��������� ����� � wordsToRemove[i]
                toRemove = true;  // ���� �������, ������������ ���� ��� ���������
                break;   // �������� � �����, ���� �������
            }
        }

        // ���� ����� �� ���� �������� ����� ��� ��� ���������, ������ ���� �� ����������
        if (!toRemove) {
            strcat(result, word2);  // ������ ����� �� ����������
            strcat(result, " ");    // ������ ����� ���� ����� ��� ���������
        }

        // ���������� �� ���������� ����� � ������� �����
        word2 = strtok(NULL, sep);
    }

    // �������� ��������� ���� ��������� ���
    cout << "Second text without words from the first text: " << result << endl;





    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool L(const char* word) {
    bool l[256] = { false };

    for (int i = 0; word[i] != '\0'; ++i) {
        char ch = word[i];
        if (l[ch]) {
            return false;
        }
        l[ch] = true;
    }
    return true;
}

int main() {
    char s[100];
    cout << "Enter text: ";
    cin.getline(s, sizeof(s));

    char* word = strtok(s, " ,.!?;:");
    while (word != NULL) {
        if (L(word)) {
            cout << word << " ";
        }
        word = strtok(NULL, " ,.!?;:");
    }

    return 0;
}
