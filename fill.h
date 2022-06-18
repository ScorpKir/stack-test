#pragma once
#include <fstream>
#include <codecvt>
#include <locale>
#include <string>
#include <cstdlib>
#include <vector>
#include "convert.h"
#include "split.h"

namespace {
    const double STANDART = 301.26;
    const double COUNT = 1.52;
}

void fillAccruals() {
    // создаём локаль для адекватного чтения и записи строк в кодировке utf8
    const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>);

    // открываем потоки ввода из файла с абонентами и ввода в файл с начислениями
    std::wifstream iwstream(L"абоненты.csv");
    std::wofstream owstream(L"Начисления_абоненты.csv");

    // присваиваем нашим потокам локаль для чтения/записи в utf8
    iwstream.imbue(utf8_locale);
    owstream.imbue(utf8_locale);

    // в эту строку мы будем считывать строки из файла
    std::wstring tmpLine;

    // считываем первую строку, добавляем столбец "Начислено" записываем с файл с начислениями заголовок таблицы
    std::getline(iwstream, tmpLine);
    owstream << tmpLine << convertToWstring(";Начислено") << std::endl;

    // пока в нашем файле есть строки считываем их и производим следующие действия
    while(std::getline(iwstream, tmpLine)) {
        // разбиваем строку на элементы из столбцов
        std::vector<std::wstring> temp = split(tmpLine, L";");
        // если тип начисления равен 1, то присваиваем нашему начислению стандартную величину, иначе присваиваем произведение счетчика на разность показаний
        double accural = (temp[5] == L"1") ? STANDART : (stof(temp[7]) - stof(temp[6])) * COUNT;
        // добавляем в конец к строке наше начисление
        tmpLine += L';' + convertToWstring(std::to_string(accural));
        // записываем в файл
        owstream << tmpLine << std::endl;
    }

    // закрываем потоки ввода/вывода
    iwstream.close();
    owstream.close();
}