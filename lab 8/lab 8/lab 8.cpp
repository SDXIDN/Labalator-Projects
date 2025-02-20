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


    char word_text2[100][100];   // Масив, де кожен елемент - слово, яке треба видалити

    int count = 0;  // Лічильник кількості слів, які потрібно видалити

    // Збереження всіх слів другого тексту у масив для подальшого видалення
    while (word1 != NULL) {
        strcpy(word_text2[count], word1);  // Копіюємо кожне слово в масив wordsToRemove
        count++;  // Збільшуємо лічильник
        word1 = strtok(NULL, sep);  // Переходимо до наступного слова
    }

    // Тепер розбиваємо перший текст на слова
    char* word2 = strtok(text1, sep);  // Отримуємо перше слово з першого тексту

    // Перевіряємо кожне слово першого тексту, чи воно є у списку слів для видалення
    while (word2 != NULL) {
        bool toRemove = false;  // Флаг, чи потрібно видаляти це слово

        // Перевіряємо, чи входить це слово у масив слів, які треба видалити
        for (int i = 0; i < count; i++) {
            if (strcmp(word2, word_text2[i]) == 0) {  // Порівнюємо слово з wordsToRemove[i]
                toRemove = true;  // Якщо знайшли, встановлюємо флаг для видалення
                break;   // Виходимо з циклу, якщо знайшли
            }
        }

        // Якщо слово не було знайдено серед слів для видалення, додаємо його до результату
        if (!toRemove) {
            strcat(result, word2);  // Додаємо слово до результату
            strcat(result, " ");    // Додаємо пробіл після слова для розділення
        }

        // Переходимо до наступного слова у першому тексті
        word2 = strtok(NULL, sep);
    }

    // Виводимо результат після видалення слів
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
