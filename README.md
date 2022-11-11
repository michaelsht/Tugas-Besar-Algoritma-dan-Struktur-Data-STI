# Tugas Besar 1 ── BNMO
## IF2111 Algoritma dan Struktur Data STI

> Program membantu Indra dan Doni untuk memprogram 
> robot video game console kesayangan mereka

Dibuat oleh Kelompok 08 K02

- Michael Sihotang (18221054)
- Muhammad Dastin Fauzi (18221062)
- Imanuel Raditya (18221112)
- Miralistya Cahya Fatimah (18221116)
- Seren Elizabeth Siahaan (18221160)

## Deskripsi Singkat Laporan
BNMO (dibaca: Binomo) adalah sebuah robot video game console yang dimiliki oleh Indra dan Doni. Dua bulan yang lalu, ia mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki ia justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Indra dan Doni mencari programmer lain yang lebih handal untuk ulang memprogram robot video game console kesayangannya. Buatlah sebuah permainan berbasis CLI (command-line interface). Sistem ini dibuat dalam bahasa C dengan menggunakan struktur data yang sudah kalian pelajari di mata kuliah ini. 

## Cara Kompilasi Program
> gcc main.c source/command/console.c source/ADT/queue/queue.c source/ADT/queuedinerdash/queue.c source/ADT/stack/stack.c source/ADT/map/map.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/array/arraydin.c -o a

## Configuration File yang Tersedia
> data/config.txt

## Save File yang Tersedia
> data/save.txt
> data/save2.txt
> data/save6.txt

## Struktur Program
```
.
│
├── README.md
├── main.c				# main program
├── data
│   ├─── bnmo.txt 			# file berisi banner yang akan dibaca sebagai welcome page
│   ├─── config.txt			# file konfigurasi awal yang akan dibaca pada START
│   ├─── drivermesinkata.txt		# file yang akan dibaca pada driver mesin kata
│   ├─── save.txt			# file yang disimpan oleh user 1
│   ├─── save2.txt			# file yang disimpan oleh user 2
│   └─── save6.txt            # file yang disimpan oleh user 3
│ 
├── source
│   ├─── boolean.h
│   ├─── ADT				# folder berisikan main
│   │      ├─── array
│   │      │       ├─── arraydin.h
│   │      │       ├─── araydin.c
│   │      │       └─── driver_arraydin.c
│   │      │
│   │      ├─── map
│   │      │       ├─── map.h
│   │      │       ├─── map.c
│   │      │       └─── driver_map.c
│   │      │
│   │      ├─── mesinkarakter
│   │      │       ├─── mesinkarakter.h
│   │      │       ├─── mesinkarakter.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── mesinkata
│   │      │       ├─── mesinkata.h
│   │      │       ├─── mesinkata.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── queue
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      ├─── queuedinerdash
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      └─── stack
│   │              ├─── stack.h
│   │              ├─── stack.c
│   │              └─── driver_stack.c
│   │
│   └─── command
│          ├─── console.h
│          └─── console.c
│
│
└── docs 
     ├─── Spesifikasi Tugas Besar 1 IF2111 2022_2023.docx
     ├─── IF2111_TB1_02_08.pdf
     └─── Form Asistensi Tugas Besar_TB1_02_08.pdf
 ```
