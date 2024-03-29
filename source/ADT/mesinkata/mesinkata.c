#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord ;
Word currentWord ;
Word currentCommand;

void IgnoreBlanks() 
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK || currentChar == ENTER) {
        ADV() ;
    }
}

void IgnoreDots() {
    while (currentChar == BLANK || currentChar == '.') {
        advTerminal() ;
    }
}

void startWFile(char * file)
/* */
{
    finish = false;
    startFromFile(file);
    copywFile();
}

void copywFile()
/* */
{
    int i = 0;
    while(currentChar != ENTER && !finish) {
        if(i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
            advFile();
        }
    }
    if(i > NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

void igBlankFile()
/* */
{
    while(currentChar == BLANK) {
        advFile();
    }
}

void advNewlineFile()
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == ENTER){
        EndWord = false;
        advFile();
        copywFile();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks() ;
    if (currentChar == MARK) {
            EndWord = true;
    } 
    else {
        EndWord = false;
        ADVWORD() ;
    }
}

void ADVWORD() 
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

{
    IgnoreBlanks () ;
    if (currentChar == MARK && !EndWord) {
        EndWord = true ;
    }
    else {
        CopyWord() ;
        IgnoreBlanks();
    }
}

void CopyWord() 
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i; 
    i = 0; 
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != ENTER)) {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar ;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}

void advNewline()
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == MARK){
        EndWord = false;
        ADV();
        CopyWord();
    }
}

Word concatWord(Word w1, Word w2)
{
    Word ans;
    ans.Length = w1.Length + w2.Length;
    int i;
    for(i = 0; i < w1.Length; i++){
        ans.TabWord[i] = w1.TabWord[i];
    }
    for(i = 0; i < w2.Length;i++){
        ans.TabWord[i+w1.Length] = w2.TabWord[i];
    }
    return ans;
}

boolean isWordEqual(Word a, Word b)
{
    if(a.Length != b.Length){
        return false;
    }
    else{
        int i = 0;
        boolean flag = true;
        while(i < a.Length && flag){
            if(a.TabWord[i] != b.TabWord[i]){
                flag = false;
            }
            i++;
        }
        return flag;
    }
}

void displayWord(Word w)
{
    int i;
    for(i = 0; i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

void copyWordFromWord(Word w1, Word *w2)
{
    w2->Length = w1.Length;
    for(int i = 0; i < w1.Length; i++){
        w2->TabWord[i] = w1.TabWord[i];
    }
}

void STARTCOMMAND () {
    START();
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND () {
    IgnoreDots();
    if (currentChar == ENTER && !EndWord) {
        EndWord = true;
    } else {
        CopyCommand();
        IgnoreDots();
    }
}

void CopyCommand () {
    int i;
    i = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER)) {
        if (i < NMax) {
            currentCommand.TabWord[i] = currentChar;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}

void STARTGAMENAME () {
    START();
    IgnoreDots();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVGAMENAME();
    }
}

void ADVGAMENAME () {
    IgnoreDots();
    if (currentChar == ENTER && !EndWord) {
        EndWord = true;
    } else {
        CopyGameName();
        IgnoreDots();
    }
}

void CopyGameName () {
    int i;
    i = 0;
    while ((currentChar != ENTER)) {
        if (i < NMax) {
            currentCommand.TabWord[i] = currentChar;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}

int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

Word stringToWord(char *str)
{
    Word word;
    int i;
    
    word.Length = stringLength(str);
    for (i = 0; i < word.Length; i++)
    {
        word.TabWord[i] = str[i];
    }

    word.TabWord[i] = '\0';

    return word;
}

char* wordToString(Word word)
{
    char *str = (char *)malloc(sizeof(char) * word.Length);
    for (int i = 0; i < word.Length; i++)
    {
        str[i] = word.TabWord[i];
        if (i == word.Length - 1)
        {
            str[i + 1] = '\0';
        }
    }
    return str;
}

int wordToInt(Word word) {
    int num, i;
    
    num = 0;

    for (i = 0; i < word.Length; i++)
    {
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num;
}

Word intToWord(int n) {
    Word word;
    int i, j, temp;
    
    i = 0;
    temp = n;

    while (temp != 0)
    {
        temp /= 10;
        i++;
    }

    word.Length = i;

    for (j = i - 1; j >= 0; j--)
    {
        word.TabWord[j] = (n % 10) + '0';
        n /= 10;
    }

    return word;
}

int commandWord(Word w) {
    int i;

    i = 0;

    while (!EndWord) {
        ADVCOMMAND();
        i++;
    }

    return i;
}

Word lowerWord (Word w) {
    Word lower;
    int i;

    lower.Length = w.Length;

    for (i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= 'A' && w.TabWord[i] <= 'Z') {
            lower.TabWord[i] = w.TabWord[i] + 32;
        } else {
            lower.TabWord[i] = w.TabWord[i];
        }
    }

    return lower;
}

Word upperWord (Word w) {
    Word upper;
    int i;

    upper.Length = w.Length;

    for (i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= 'a' && w.TabWord[i] <= 'z') {
            upper.TabWord[i] = w.TabWord[i] - 32;
        } else {
            upper.TabWord[i] = w.TabWord[i];
        }
    }

    return upper;
}

Word charToWord(char c) {
    Word word;
    word.Length = 1;
    word.TabWord[0] = c;
    return word;
}

char wordToChar(Word w) {
    return w.TabWord[0];
}