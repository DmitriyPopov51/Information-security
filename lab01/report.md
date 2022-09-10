---
# Front matter
title: "Информационная безопасность. Отчет по лабораторной работе №1"
subtitle: "Установка и конфигурация операционной системы на виртуальную машину"
author: "Попов Дмитрий Павлович"
group: NFIbd-01-19
institute: RUDN University, Moscow, Russian Federation

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
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

# Цель работы
Целью данной работы является приобретение практических навыков
установки операционной системы на виртуальную машину.
Анализ последовательности загрузки системы через консоль [1]. 

# Выполнение лабораторной работы
##Домашнее задание
Дождитесь загрузки графического окружения и откройте терминал. В окне
терминала проанализируйте последовательность загрузки системы, выполнив команду dmesg. Можно просто просмотреть вывод этой команды: dmesg | less [@fig:1] [2].

![Последовательность загрузки ОС](screenshots/img1.png){#fig:1 width=100%}

Можно использовать поиск с помощью grep: dmesg | grep -i "то, что ищем".
Получите следующую информацию.
1. Версия ядра Linux (Linux version) [@fig:2].
2. Частота процессора (Detected Mhz processor) [@fig:3].
3. Модель процессора (CPU0) [@fig:4].
4. Объем доступной оперативной памяти (Memory available) [@fig:5].
5. Тип обнаруженного гипервизора (Hypervisor detected) [@fig:6].
6. Тип файловой системы корневого раздела [@fig:7].
7. Последовательность монтирования файловых систем [@fig:8].

![Версия ядра Linux](screenshots/img2.png){#fig:2 width=100%}

![Частота процессора](screenshots/img3.png){#fig:3 width=100%}

![Модель процессора](screenshots/img4.png){#fig:4 width=100%}

![Объем доступной оперативной памяти](screenshots/img5.png){#fig:5 width=100%}

![Тип обнаруженного гипервизора](screenshots/img6.png){#fig:6 width=100%}

![Тип файловой системы корневого раздела](screenshots/img7.png){#fig:7 width=100%}

![Последовательность монтирования файловых систем](screenshots/img8.png){#fig:8 width=100%}


# Выводы
Приобретены практические навыки установки операционной системы на виртуальную машину, навыки анализа последовательности загрузки системы через консоль.

# Список литературы
1. Методические материалы курса
2. Задание к лабораторной работе № 1
