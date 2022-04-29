# Виджет матрицы для C++/Qt
___
## Структура класса MatrixWidget
1. [Конструкторы](#Конструкторы)
2. [Методы](#Методы)

___
## Конструкторы  
### Конструктор по умолчанию  
По умолчанию задает размер матрицы (1, 1)  
Отключает SrollBar'ы  
Скрывает header'ы таблицы  
___
### Входные данные
parent - ссылка на родительский виджет
```C++
MatrixWidget(QWidget *parent = nullptr);
```
___

```C++
MatrixWidget(QSize sizeWidget, QWidget *parent = nullptr);
```
___
```C++
MatrixWidget(QPoint pos, QSize sizeWidget, QWidget *parent = nullptr);
```
___
```C++
MatrixWidget(QSize sizeMatrix, QSize sizeWidget, QWidget *parent = nullptr);
```
___
```C++
MatrixWidget(QSize sizeMatrix, QPoint pos, QSize sizeWidget, QWidget *parent = nullptr);
```
___
```C++
MatrixWidget(QSize sizeMatrix, QRect geometry, QWidget *parent = nullptr);
```
___
## Методы
```C++
void setPos(QPoint);
```
```C++
void setSize(QSize);
```
```C++
void update();
```
