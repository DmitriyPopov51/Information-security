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

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
	- spelling=modern
	- babelshorthands=true
polyglossia-otherlangs:
  name: english
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

<h1 align="center">
<p>РОССИЙСКИЙ УНИВЕРСИТЕТ ДРУЖБЫ НАРОДОВ 
<p>Факультет физико-математических и естественных наук  
<p>Кафедра прикладной информатики и теории вероятностей
<p>ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №6
<br></br>
<h2 align="right">
<p>дисциплина: Информационная безопасность
<p>Преподователь: Кулябов Дмитрий Сергеевич
<p>Студент: Попов Дмитрий Павлович
<p>Группа: НФИбд-01-19
<br></br>
<br></br>
<h1 align="center">
<p>МОСКВА
<p>2022 г.
</h1>

# Цель работы

Целью данной лабораторной работы является развить навыки администрирования ОС Linux. Получить первое практическое знакомство с технологией SELinux1. Проверить работу SELinx на практике совместно с веб-сервером
Apache.

# Подготовка лабораторного стенда и методические рекомендации

1. Установили веб-сервер Apache.
   
2. В конфигурационном файле /etc/httpd/httpd.conf задали параметр ServerName. 

3. Отключили пакетный фильтр.

# Выполнение лабораторной работы

1. Входим в систему с полученными учётными данными. Проверили, что SELinux работает в режиме enforcing политики targeted с помощью команд **getenforce** и **sestatus**. (@fig:001)
   
![Выполнение команд getenforce и sestatus](screenshots/img1.png){#fig:001 width=100%}

2. Запустили веб-сервер и обратились к нему с помощью команды (@fig:002):
service httpd status 
   
![Выполнение команды service httpd  status](screenshots/img2.png){#fig:002 width=100%}

3. Нашли веб-сервер Apache в списке процессов. Контекст безопасности - unconfined_u:unconfined_r:unconfined_t. (@fig:003)
   
![Выполнение команды ps auxZ | grep httpd](screenshots/img3.png){#fig:003 width=100%}

4. Посмотрели текущее состояние переключателей SELinux для Apache с помощью команды **sestatus -b | grep httpd**. (@fig:004)
   
![Выполнение команды sestatus -b | grep httpd](screenshots/img4.png){#fig:004 width=100%}

5. Посмотрели статистику по политике с помощью команды **seinfo**. Определили, что множество пользователей = 8; ролей = 14; типов = 5002. (@fig:005)
   
![Статистика по политике](screenshots/img5.png){#fig:005 width=100%}

6. Определили тип файлов и поддиректорий, находящихся в директории /var/www, с помощью команды **ls -lZ /var/www**. (@fig:006)
   
![Выполнение команды ls -lZ /var/www](screenshots/img6.png){#fig:006 width=100%}

7. Необходимо было определить тип файлов, находящихся в директории /var/www/html, с помощью команды **ls -lZ /var/www/html**. Но в данной директории файлов не обнаружилось. (@fig:007)
   
![Выполнение команды ls -lZ /var/www/html](screenshots/img7.png){#fig:007 width=100%}

8. Определим круг пользователей, которым разрешено создание файлов в директории /var/www/html - только root. (@fig:008)
   
![Выполнение команды ls -lZ /var/www](screenshots/img6.png){#fig:008 width=100%}

9. Создали от имени суперпользователя html-файл /var/www/html/test.html следующего содержания: (@fig:009)
   
![Содержимое файла test.html](screenshots/img9.png){#fig:009 width=100%}

10. Проверили контекст созданного файла - httpd_sys_content_t. (@fig:010)
   
![Контекст файла test.html](screenshots/img10.png){#fig:010 width=100%}

11.  Обратитились к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1/test.html и убедились, что файл был успешно отображён. (@fig:011)
   
![Обращение к файлу test.html через веб-сервер](screenshots/img11.png){#fig:011 width=100%}

12.   Изучили справку man httpd_selinux. Тип файла test.html - контекст созданного файла - httpd_sys_content_t. (@fig:012)
   
![Контекст файла test.html](screenshots/img10.png){#fig:012 width=100%}

13.  Изменили контекст файла /var/www/html/test.html с httpd_sys_content_t на samba_share_t:
chcon -t samba_share_t /var/www/html/test.html
ls -Z /var/www/html/test.html
И проверили, что контекст поменялся. (@fig:013)
   
![Изменение контекста файла /var/www/html/test.html](screenshots/img13.png){#fig:013 width=100%}

14. Пробуем ещё раз получить доступ к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1/test.html. В результате получили ошибку. (@fig:014)
   
![Обращение к файлу test.html через веб-сервер после изменения контекста](screenshots/img14.png){#fig:014 width=100%}

15.  Проанализируем ситуацию. Почему файл не был отображён, если права доступа позволяют читать этот файл любому пользователю?
ls -l /var/www/html/test.html
Просмотрим log-файлы веб-сервера Apache и системный лог-файл:
tail /var/log/messages
В системе оказались запущенны процессы **setroubleshootd** и **audtd**. (@fig:015)
   
![Вывод команд ls -l /var/www/html/test.html и tail /var/log/messages](screenshots/img15.png){#fig:015 width=100%}

16. Попробуем запустить веб-сервер Apache на прослушивание ТСР-порта 81. Для этого в файле /etc/httpd/httpd.conf находим строчку Listen 80 и заменяем её на Listen 81. (@fig:016)
   
![Запуск веб-сервера Apache на прослушивание ТСР-порта 81](screenshots/img16.png){#fig:016 width=100%}
 
17. Выполним перезапуск веб-сервера Apache. Произошёл сбой? Нет. 
18. Проанализируем лог-файлы:
tail -nl /var/log/messages
Просмотрим файлы /var/log/http/error_log,
/var/log/http/access_log и /var/log/audit/audit.log. (@fig:017)
   
![Перезапуск веб-сервера Apache](screenshots/img17.png){#fig:017 width=100%}

19. Выполним команду **semanage port -a -t http_port_t -р tcp 81**. Вылетает ValueError в связи с тем, что порт уже определен. После этого проверим список портов командой **semanage port -l | grep http_port_t** и убедились, что порт 81 появился в списке. (@fig:018)
   
![Проверка установления 81 порта tcp](screenshots/img19.png){#fig:018 width=100%}

20. Попробуем запустить веб-сервер Apache ещё раз. (@fig:019)
   
![Перезапуск веб-сервера Apache](screenshots/img20.png){#fig:019 width=100%}
  
21. Вернули контекст httpd_sys_cоntent__t к файлу /var/www/html/test.html: **chcon -t httpd_sys_content_t /var/www/html/test.html** (@fig:020)
   
![Возвращение контекста httpd_sys_cоntent__t к файлу test.html](screenshots/img21.png){#fig:020 width=100%}

После этого пробуем получить доступ к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1:81/test.html. В результате увидели содержимое файла — слово «test». (@fig:021)
   
![Обращение к файлу test.html через веб-сервер](screenshots/img21.2.png){#fig:021 width=100%}

22. Исправим обратно конфигурационный файл apache, вернув Listen 80. (@fig:022)
   
![Исправление конфигурационного файла apache](screenshots/img22.png){#fig:022 width=100%}

23. Удалим привязку http_port_t к 81 порту: **semanage port -d -t http_port_t -p tcp 81** и проверим, что порт 81 удалён. Данная команда не была выполнена. (@fig:023)
   
![Удаление привязки http_port_t к 81 порту](screenshots/img23.png){#fig:023 width=100%}

24.  Удалим файл /var/www/html/test.html: **rm /var/www/html/test.html**. (@fig:024)
   
![Удаление файла test.html](screenshots/img24.png){#fig:024 width=100%}

# Вывод

В ходе выполнения лабораторной работы мы развили навыки администрирования ОС Linux. Получили первое практическое знакомство с технологией SELinux1. Проверили работу SELinx на практике совместно с веб-сервером
Apache.

# Библиография

1. Кулябов Д. С., Королькова А. В., Геворкян М. Н. Мандатное разграничение прав в Linux [Текст] / Кулябов Д. С., Королькова А. В., Геворкян М. Н. - Москва: - 5 с. [^1]: Мандатное разграничение прав в Linux. 
2. Справочник 70 основных команд Linux: полное описание с примерами (https://eternalhost.net/blog/sozdanie-saytov/osnovnye-komandy-linux)
  