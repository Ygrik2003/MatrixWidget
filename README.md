# Виджет матрицы для C++/Qt
___
## Структура класса MatrixWidget
1. [Конструкторы](#Конструкторы)
2. [Методы](#Методы)

## Конструкторы  
___
### Конструктор по умолчанию  
По умолчанию задает размер матрицы (1, 1)  
Отключает SrollBar'ы  
Скрывает header'ы таблицы  
___
### Входные данные
*parent - ссылка на родительский виджет*
```C++
MatrixWidget(QWidget *parent = nullptr);
```
___ 
### Конструктор с заданием размера виджета  
Вызывает конструктор по умолчанию
___
### Входные данные
*sizeWidget - размер виджета в пикселях  
parent - ссылка на родительский виджет*
```C++
MatrixWidget(QSize sizeWidget, QWidget *parent = nullptr);
```
___ 
### Конструктор с заданием позиции и размера виджета  
Вызывает конструктор по умолчанию
___
### Входные данные
*pos - позиция верхнего левого угла в пикселях относительно позиции родительского виджета  
sizeWidget - размер виджета в пикселях  
parent - ссылка на родительский виджет*
```C++
MatrixWidget(QPoint pos, QSize sizeWidget, QWidget *parent = nullptr);
```
___ 
### Конструктор с заданием размера матрицы и виджета  
Вызывает конструктор по умолчанию  
___
### Входные данные
*sizeMatrix - количество строк и столбцов матрицы  
sizeWidget - размер виджета в пикселях  
parent - ссылка на родительский виджет* 
```C++
MatrixWidget(QSize sizeMatrix, QSize sizeWidget, QWidget *parent = nullptr);
```
### Конструктор с заданием размера матрицы и позиции и размера виджета  
Вызывает конструктор по умолчанию
___
### Входные данные
*sizeMatrix - количество строк и столбцов матрицы  
pos - позиция верхнего левого угла в пикселях относительно позиции родительского виджета  
sizeWidget - размер виджета в пикселях  
parent - ссылка на родительский виджет*
```C++
MatrixWidget(QSize sizeMatrix, QPoint pos, QSize sizeWidget, QWidget *parent = nullptr);
```
### Конструктор с заданием размера матрицы и геометрии виджета  
Вызывает конструктор по умолчанию
___
### Входные данные
*sizeMatrix - количество строк и столбцов матрицы  
geometry - геометрия виджета
parent - ссылка на родительский виджет*
```C++
MatrixWidget(QSize sizeMatrix, QRect geometry, QWidget *parent = nullptr);
```
___
## Методы
___
### Установить позицию виджета
Устанавливает позицию верхнего левого угла в пикселях относительно позиции родительского виджета  
___
### Входные данные
*pos - позиция виджета*
```C++
void setPos(QPoint pos);
```
### Установить размер виджета
Устанавливает размер виджета в пикселях  
___
### Входные данные
*sizeWidget - размер виджета*
```C++
void setSize(QSize sizeWidget);
```
### Обновление таблицы
Обновляет размерность и данные таблицы
```C++
void update();
```
