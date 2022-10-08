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
<p>ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №5
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

# **Цель работы**

Изучение механизмов изменения идентификаторов, применения SetUID и Sticky-битов.


# **Выполнение лабораторной работы**

1. Создал программу simpleid.c (Рис [@fig:1]).

![simpleid](screenshots/img1.png "simpleid.c"){ #fig:1 width=90% }

2. Скомпилировал и выполнил программу. Сравнил с id. Как видим, результат работы команд - одинаковый (Рис [@fig:2]).

![compile and run](screenshots/img2.png "compile and run"){ #fig:2 width=90% }

3. Усложнил программу, добавив вывод действительных идентификаторов (Рис [@fig:3]). 

![simpleid2.c](screenshots/img3.png "simpleid2.c"){ #fig:3 width=90% }

4. Скомпилировал и запустил simpleid2.c (Рис [@fig:4]). 

![simpleid2](screenshots/img4.png "simpleid2"){ #fig:4 width=90% }

5. От имени суперпользователя выполнил команды  (Рис [@fig:5])

![chmod](screenshots/img5.png "chmod"){ #fig:5 width=90% }

6. Запустил simpleid2 и id (Рис [@fig:6])

![simpleid2 run](screenshots/img6.png "simpleid2 run"){ #fig:6 width=90% }

7. Создал программу readfile.c: (Рис [@fig:7])

![readfile.c](screenshots/img7.png "readfile.c"){ #fig:7 width=90% }

8. Сменил владельца у файла readfile.c  и изменил права так, чтобы только суперпользователь (root) мог прочитать его, a guest не мог (Рис [@fig:8]).

![chown](screenshots/img8.png "chown"){ #fig:8 width=90% }

9. guest не может прочитать файл readfile.c (Рис [@fig:9])

![can not read](screenshots/img9.png "can not read"){ #fig:9 width=90% }

10. Сменил у программы readfile владельца и установил SetU’D-бит (Рис [@fig:10])

![readfile](screenshots/img10.png "readfile"){ #fig:10 width=90% }

11. Проверил прочитать файл readfile и /etc/shadow (Рис [@fig:11] и [@fig:12])

![readfile read](screenshots/img11.png "readfile read"){ #fig:11 width=90% }

![/etc/shadow read](screenshots/img12.png "/etc/shadow read"){ #fig:12 width=90% }

12. readfile удалось прочитать, /etc/shadow - тоже удалось

13. Проверил sticky бит на категории tmp. Создал файл в tmp от guest и посмотерл атрибуты (Рис [@fig:13]).

![sticky](screenshots/img13.png "sticky"){ #fig:13 width=90% }

14. От guest2 попробовал выполнить различные операции (Рис [@fig:14])

![guest2 file01](screenshots/img14.png "guest2 file01"){ #fig:14 width=90% }

15. Не удалось выполнить только rm

16. Снял атрибут t (Sticky-бит) сдиректории /tmp (Рис [@fig:15])

![-t](screenshots/img15.png "-t"){ #fig:15 width=90% }

17. Повторил предыдущие шаги. rm теперь работает (Рис [@fig:16])

![guest2 file01 try 2](screenshots/img16.png "guest2 file01 try 2"){ #fig:16 width=90% }


# Вывод

Выполнив данную лабораторную работу, я получение практические навыков работы в консоли с дополнительными атрибутами. Рассмотрел работы механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.

# Список литературы

1. Кулябов, Д.С. - Лабораторная работа № 5. Дискреционное разграничение прав в Linux.  Исследование влияния дополнительных атрибутов
https://esystem.rudn.ru/pluginfile.php/1651889/mod_resource/content/2/005-lab_discret_sticky.pdf
