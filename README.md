# Задание
Написать программу, подсчитывающую контрольную сумму CRC32 (не Adler32) для файлов, превышающих
по объёму оперативную память без многократного вызова read. Сторонние библиотеки не использовать.

# Сложность
★★☆☆☆

# Цель задания
Получить навык обработки файлов, превышающих по объёму оперативную память.

# Критерии успеха
- Создано приложение, принимающее аргументами командной строки путь к файлу.
- Приложение корректно подсчитывает CRC32 для заданного файла (файл для проверки прилагается).
- Приложение корректно обрабатывает ошибки доступа к файлам.
- Код компилируется без предупреждений с ключами компилятора -Wall -Wextra -Wpedantic -std=c11.
- Далее успешность определяется ревью кода.
