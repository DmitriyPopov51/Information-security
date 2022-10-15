---
# Front matter
title: "Лабораторная работа 6"
author: "Попов Дмитрий Павлович, НФИбд-01-19"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
bibliography: bib/cite.bib
csl: pandoc/csl/gost-r-7-0-5-2008-numeric.csl

### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
## Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

##### РОССИЙСКИЙ УНИВЕРСИТЕТ ДРУЖБЫ НАРОДОВ
##### Факультет физико-математических и естественных наук  
##### Кафедра прикладной информатики и теории вероятностей 
##### ПРЕЗЕНТАЦИЯ ПО ЛАБОРАТОРНОЙ РАБОТЕ №6

дисциплина: Информационная безопасность

Преподователь: Кулябов Дмитрий Сергеевич

Cтудент: Попов Дмитрий Павлович

Группа: НФИбд-01-19

МОСКВА

2022 г.

# **Цель работы**

Целью данной лабораторной работы является развить навыки администрирования ОС Linux. Получить первое практическое знакомство с технологией SELinux1. Проверить работу SELinx на практике совместно с веб-сервером Apache.

# **Выполнение лабораторной работы**

# 1. Входим в систему с полученными учётными данными. Проверили, что SELinux работает в режиме enforcing политики targeted с помощью команд **getenforce** и **sestatus**. 
![Выполнение команд getenforce и sestatus](screenshots/img1.png)

# 2. Запустили веб-сервер и обратились к нему с помощью команды service httpd status  
![Выполнение команды status](screenshots/img2.png)

# 3. Найшли веб-сервер Apache в списке процессов с помощью команды **ps auxZ | grep httpd**. Контекст безопасности - unconfined_u:unconfined_r:unconfined_t. 
![Выполнение команды ps auxZ | grep httpd](screenshots/img3.png)

# 4. Посмотрели текущее состояние переключателей SELinux для Apache с помощью команды .
![Выполнение команды sestatus -ez](screenshots/img4.png)

# 5. Определили тип файлов и поддиректорий, находящихся в директории /var/www, с помощью команды **ls -lZ /var/www**.
![Выполнение команды ls -lZ /var/www](screenshots/img6.png)

# 6. Создали от имени суперпользователя html-файл /var/www/html/test.html следующего содержания:   
![Содержимое файла test.html](screenshots/img9.png)

# 7. Проверили контекст созданного файла - httpd_sys_content_t.  
![Контекст файла test.html](screenshots/img10.png)

# 8.  Обратитились к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1/test.html и убедились, что файл был успешно отображён. 
![Обращение к файлу test.html через веб-сервер](screenshots/img11.png)

# 9.  Изменили контекст файла И проверили, что контекст поменялся.
![Изменение контекста файла /var/www/html/test.html](screenshots/img13.png)

# 10. Пробуем ещё раз получить доступ к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1/test.html. В результате получили ошибку.
![Обращение к файлу test.html через веб-сервер после изменения контекста](screenshots/img14.png)

# 11. Попробуем запустить веб-сервер Apache на прослушивание ТСР-порта 81. Для этого в файле /etc/httpd/httpd.conf находим строчку Listen 80 и заменяем её на Listen 81. 
![Запуск веб-сервера Apache на прослушивание ТСР-порта 81](screenshots/img16.png)

# 12(13). Выполним перезапуск веб-сервера Apache. Произошёл сбой? Нет. Выполним команду **semanage port -a -t http_port_t -р tcp 81**. Вылетает ValueError в связи с тем, что порт уже определен. После этого проверим список портов командой **semanage port -l | grep http_port_t** и убедились, что порт 81 появился в списке.
![Проверка установления 81 порта tcp](screenshots/img19.png)

# 14. Вернули контекст httpd_sys_cоntent_t к файлу /var/www/html/test.html: **chcon -t httpd_sys_content_t /var/www/html/test.html** 
![Возвращение контекста httpd_sys_cоntent__t к файлу test.html](screenshots/img21.png)

# После этого пробуем получить доступ к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1:81/test.html. В результате увидели содержимое файла — слово «test». 
![Обращение к файлу test.html через веб-сервер](screenshots/img21.2.png)

# 15. Исправим обратно конфигурационный файл apache, вернув Listen 80. 
![Исправление конфигурационного файла apache](screenshots/img22.png)

# 16. Удалим привязку http_port_t к 81 порту: **semanage port -d -t http_port_t -p tcp 81** и проверим, что порт 81 удалён. Данная команда не была выполнена. 
![Удаление привязки http_port_t к 81 порту](screenshots/img23.png)

# 17.  Удалим файл /var/www/html/test.html: **rm /var/www/html/test.html**.  
![Удаление файла test.html](screenshots/img24.png)

# Вывод
В ходе выполнения лабораторной работы мы развили навыки администрирования ОС Linux. Получили первое практическое знакомство с технологией SELinux1. Проверили работу SELinx на практике совместно с веб-сервером
Apache.