# Электронный деканат

Автоматизированная система записи студентов на учебные курсы.

Автор: Данил Шакалов.

## Языки
- C++ — папка cpp/
- Java — папка java/

## Структура
- cpp/include — заголовки
- cpp/src — исходники C++
- java/src — исходники Java
- docs — описание

## Сборка
g++ cpp/src/main.cpp -I cpp/include -o app
./app

cd java/src
javac Main.java
java Main

## Правила
Ветка main защищена. Изменения только через feature-ветку и Pull Request.
