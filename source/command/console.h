#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../boolean.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/array/arraymap.h"
#include "../ADT/map/map.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/queue/queue.h"
#include "../ADT/queuedinerdash/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/listdp/listdp.h"

#ifndef CONSOLE_H
#define CONSOLE_H

// LIST HEADER COMMAND

void CreateGame (ArrayDin* listGame, ArrayMap* listScoreboard);
/* I.S. listGame sembarang */
/* F.S. listGame bertambah dengan nama game yang diinput */

void deleteGame (ArrayDin* listGame, ArrayDin* listHistory, ArrayMap* listScoreboard, Queue Q);
/* I.S. listGame terdefinisi */
/* F.S. listGame berkurang dengan nama game yang diinput */

void help();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void invalidCommand(Word* w);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa command yang dimasukkan tidak valid */

void ListGame (ArrayDin array);
/* I.S. array terdefinisi */
/* F.S. mengembalikan output berupa daftar game yang ada dalam array */

void load (Word filename, ArrayDin* arrayGame, ArrayDin* arrayHistory, ArrayMap* arrayMap, boolean* esc);
/* I.S. array kosong */
/* F.S. array terisi dengan list nama game yang ada dalam file eksternal yang disimpan */

void loadSuceeded();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa load berhasil */

void loadFailed();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa load gagal */

void randomScore(Word game, int* score);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa score yang dihasilkan secara random */

void playGame (Queue* queueGame, ArrayDin arrayGame, ArrayDin* arrayHistory, ArrayMap* arrayMap);
/* I.S. queueGame terdefinisi, arrayHistory mungkin kosong atau sudah terdefinisi */
/* F.S. game yang berada pada head akan dimainkan dan queueGame berkurang */

void queueGame(ArrayDin listGame, Queue* Q);
/* I.S. listGame terdefinisi */
/* F.S. queueGame terisi dengan nama game yang dipilih dari listGame */

void Quit();
/* I.S. sembarang */
/* F.S. keluar dari program utama */

void save (Word filename, ArrayDin array, ArrayDin arrayHistory, ArrayMap arrayMap);
/* I.S. array terdefinisi */
/* F.S. array disimpan dalam file eksternal */

void skipGame(Queue * Q, ArrayDin arrayGame, ArrayDin* arrayHistory, ArrayMap* arrayMap, int n);
/* I.S. Q terdefinisi */
/* F.S. Q berkurang sebanyak n */

void startGame(ArrayDin * arr, ArrayMap* arrayMap);
/* I.S. arr kosong */
/* F.S. arr terisi dengan list nama game yang ada pada file config */

void loading();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa animasi loading */

void welcome();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa welcoming page BNMO */

void listHistory(ArrayDin array, int n);
/* I.S. array terdefinisi */
/* F.S. mengembalikan output berupa daftar game yang ada dalam array history */

void resetHistory(ArrayDin * arrayHistory);
/* I.S. arrayHistory terdefinisi */
/* F.S. arrayHistory kosong */

void displayScoreboard(ArrayDin arrayGame, ArrayMap arrayMap);
/* I.S. M terdefinisi */
/* F.S. mengembalikan output berupa scoreboard */

void resetScoreboard(ArrayMap* arrayMap, int n);

// LIST HEADER GAME

/* DINER DASH */

void displayOrder(QueueInt Q);
/* I.S. Q terdefinisi */
/* F.S. mengembalikan output berupa daftar pesanan yang ada pada Q */

void displayCook(Map C);
/* I.S. C terdefinisi */
/* F.S. mengembalikan output berupa daftar makanan yang sedang dimasak pada C */

void displayServe(Map C);
/* I.S. C terdefinisi */
/* F.S. mengembalikan output berupa daftar makanan yang sudah dimasak pada C */

int randomNumber(int max, int min);
/* I.S. max dan min terdefinisi */
/* F.S. mengembalikan output berupa angka random dari min sampai max */

int idxToInt(char *idx);
/* I.S. idx terdefinisi */
/* F.S. mengembalikan output berupa indeks dari makanan yang dipilih */

void sortMapAsc(Map *Map);
/* I.S. Map terdefinisi */
/* F.S. Map terurut berdasarkan indeks */

void sortMapDesc(Map *Map);
/* I.S. Map terdefinisi */
/* F.S. Map terurut berdasarkan indeks */

void welcomeDinerDash();

void dinerdash(int* score);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa game Diner Dash */

/* RNG */

int randomx();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa angka random dari 1 sampai 500 */

void welcomeRNG();

void rng(int* score);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa game RNG */

// BONUS

// TOWER OF HANOI

void PrintTower(Stack S[3], int n);
/*
I.S. Sembarang
F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
*/

void welcomeTowerOfHanoi();

void towerOfHanoi(int* score);

void printpetak(List snake, List food, List meteor, List obstacle);
/* mengeluarkan tampilan permainan snake on meteor */

int randoms();
/* menghasilkan angka random yang sesuai dengan koordinat pada matriks 5x5 */

void initsnake(List * snake);
/* inisiasi awal snake yaitu terdiri dari H, 1, dan 2, beserta dengan randomize letak awal */

void dropfood(List * snake, List * food, List * posPanas, List * obstacle);
/* meletakkan makanan pada game secara acak */

void dropmeteor(List * food, List * obstacle, List * meteor);
/* meletakkan meteor pada game secara acak */

void makan(List * snake, List * food, List * obstacle, boolean * menang);
/* bertambah panjangnya ekor snake setelah mengalami proses memakan sebuah food */

void belok(char x, List *s, List * posPanas, List * obstacle, boolean * gagal, boolean * menang);
/* pembelokan head yang diikuti badan - badan snake */

void hit(List * snake, List * meteor, location * temp);
/* snake terkena meteor dan badan akan terputus */

void dropobs(List * snake, List * food, List * obstacle);
/* meletakkan obstacle secara acak pada game pada awal permainan */

int lengthsnake(List snake);
/* menghitung panjang snake */

void welcomeSOM();

void snakeOnMeteor(int * score);
/* permainan Snake On Meteor */

void welcomeHangman();
/* welcome page untuk permainan Hangman */

void wordList(ArrayDin* listOfWord);
/*
    * I.S. : listOfWord sembarang
    * F.S. : listOfWord terisi dengan daftar kata yang ada di file
*/

Word chooseWord(ArrayDin listOfWord);
/*
    * I.S. : listOfWord terisi dengan daftar kata
    * F.S. : mengembalikan kata yang dipilih secara random dari listOfWord
*/

boolean isAlreadyGuessed(ArrayDin listOfGuess, Word guess);
/*
    * I.S. : listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : mengembalikan true jika guess sudah ada di listOfGuess
*/

void printGuess(ArrayDin listOfGuess);
/*
    * I.S. : listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : menampilkan daftar huruf yang sudah di-guess
*/

boolean win(Word word, ArrayDin listOfGuess);
/*
    * I.S. : word terisi dengan kata yang akan di-guess
    *        listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : mengembalikan true jika semua huruf pada word sudah ada di listOfGuess
*/

void addDictionary(ArrayDin* listOfWord);
/*
    * I.S. : listOfWord terisi dengan daftar kata
    * F.S. : listOfWord terisi dengan daftar kata yang sudah ditambahkan
*/

void hangman(int* totalscore);
/*
    * I.S. : sembarang
    * F.S. : permainan hangman dimulai
*/

#endif