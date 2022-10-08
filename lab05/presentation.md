---
# Front matter
title: "Лабораторная работа 5"
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
##### ПРЕЗЕНТАЦИЯ ПО ЛАБОРАТОРНОЙ РАБОТЕ №5

дисциплина: Информационная безопасность

Преподователь: Кулябов Дмитрий Сергеевич

Cтудент: Попов Дмитрий Павлович

Группа: НФИбд-01-19

МОСКВА

2022 г.

# **Прагматика выполнения лабораторной работы**

- работа с дополнительными атрибутами

# **Цель работы**

Изучение механизмов изменения идентификаторов, применения SetUID и Sticky-битов.

# **Выполнение лабораторной работы**

# 1. Создание программы simpleid.c. и выполнение
![simpleid](screenshots/img1.png "simpleid.c")
![compile and run](screenshots/img2.png "compile and run")

# 2.  Создание программы simpleid2.c. и выполнение
![simpleid2.c](screenshots/img3.png "simpleid2.c")
![simpleid2](screenshots/img4.png "simpleid2")

# 3. Установка новых аттрибутов и запуск simpledid2
![chmod](screenshots/img5.png "chmod")
![simpleid2 run](screenshots/img6.png "simpleid2 run")

# 4. Создание программы readfile.c
![readfile.c](screenshots/img7.png "readfile.c")

# 5. Смена владельца readfile
![chown](screenshots/img8.png "chown")
![cant read](screenshots/img9.png "cant read")

# 6. Смена владельца readfile и установил SetU’D-бит
![readfile](screenshots/img10.png "readfile")
![readfile read](screenshots/img11.png "readfile read")
![/etc/shadow read](screenshots/img12.png "/etc/shadow read")

# 7. Проверка sticky бит на категории tmp.
![sticky](screenshots/img13.png "sticky")

# 8. Выполнение различных операций от guest2
![guest2 file01](screenshots/img14.png "guest2 file01")

# 9. Снятие атрибут t (Sticky-бит) сдиректории /tmp и выполнение предыдущих шагов
![-t](screenshots/img15.png "-t")
![guest2 file01 try 2](screenshots/img16.png "guest2 file01 try 2")

# Вывод
Выполнив данную лабораторную работу, я получение практические навыков работы в консоли с дополнительными атрибутами. Рассмотрел работы механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.