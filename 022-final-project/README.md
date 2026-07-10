# 022 — Final Project: Aplikasi Terminal Modular

**Fase:** 8 · Final Project | **Prasyarat:** Semua modul 001-021 | **Estimasi waktu:** 10-15 jam

> 🚧 **Coming Soon** — Akan diisi setelah semua modul 001-021 selesai.

## 🎯 Tujuan
Mengaplikasikan SEMUA konsep yang telah dipelajari di modul 001-021 dalam satu project utuh.

## 📋 Requirement
- Clean architecture: pisah `include/`, `src/`, `Makefile` di root
- Pakai minimal: struct, dynamic memory, linked list, file I/O, error handling
- Data harus persist ke disk (file)
- Modular: header terpisah, multiple .c files
- Compilable tanpa warning dengan `-Wall -Wextra -Wpedantic`
- Berjalan di terminal (macOS, Linux, Windows via MSYS2)

## 💡 Ide Project
1. **To-Do List CLI** — CRUD task, persist ke file, filter by status
2. **Contact Book** — simpan nama, telepon, email, search, persist ke file
3. **Inventory Manager** — produk, stok, harga, laporan, file persistence

## 📁 Struktur Project
```
022-final-project/
├── include/
│   ├── app.h
│   ├── data.h
│   └── utils.h
├── src/
│   ├── main.c
│   ├── app.c
│   ├── data.c
│   └── utils.c
├── data/
│   └── (file persistence di sini)
├── Makefile
└── README.md
```
