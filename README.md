# 🎯 Assault Cube Memory Reader

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

Bu proje, C dili ve **Windows API** (`windows.h`) kütüphaneleri kullanılarak açık kaynaklı **Assault Cube** oyununun bellek alanından (process memory) oyuncu değerlerini (Sağlık, Zırh, Mermi, Bomba vb.) okumak amacıyla **fientix** tarafından geliştirilmiş **eğitim odaklı** bir yazılımdır.

---

## 📌 Projenin Amacı ve Öğrenim Çıktıları

Bu proje, C dilinde düşük seviye sistem programlama ve Windows işletim sistemi mimarisini anlamak için yazılmıştır. Kod içerisinde aşağıdaki temel kavramlar uygulanmıştır:

- **Windows API Süreç Yönetimi:** `FindWindow` ile hedef pencere tespiti ve `GetWindowThreadProcessId` ile Process ID (PID) alma.
- **Bellek Yetkilendirme:** `OpenProcess` ile hedef sürece güvenli erişim sağlama.
- **Süreç Belleği Okuma:** `ReadProcessMemory` fonksiyonu kullanarak bellek adreslerindeki değerleri (integer) C değişkenlerine aktarma.
- **Sistem Kaynak Yönetimi:** İşlemci yükünü optimize etmek için `Sleep` kontrolü ve `CloseHandle` ile kaynak temizliği.

---

## 🛠️ Gereksinimler

- **İşletim Sistemi:** Windows (7 / 10 / 11)
- **Derleyici:** GCC (MinGW), MSVC (Visual Studio) veya Clang
- **Hedef Uygulama:** Assault Cube (v1.2 veya v1.3)

---

## 🚀 Derleme ve Çalıştırma

### 1. Derleme (GCC / MinGW)
Terminali açıp proje dizininde şu komutu çalıştırın:

```bash
gcc memoryRead.c -o MemoryReader.exe
