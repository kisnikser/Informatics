//==========================================================
//                     Генератор тени
//==========================================================
//
//  В реализации проекта принимали участие:
//
//  Волков Вадим      Б01-006
//  Дорин Даниил      Б01-001
//  Киселев Никита    Б01-001
//  Отмахов Артем     Б01-008
//	Отращенко Алексей Б01-006
//
//==========================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------------------------
// Объявление структур
//----------------------------------------------------------

// Структура, содержащая информацию о точке на плоскости.
// Оси координат Ox и Oy направлены горизонтально вправо
// и вертикально вверх соответственно.
typedef struct
{
    float x; // x-координата точки
    float y; // y-координата точки
}Point;

// Структура, содержащая информацию о вертикальном отрезке.
typedef struct
{
    Point a; // Верхняя точка отрезка
    Point b; // Нижняя  точка отрезка
}Segment;

// Структура, содержащая информацию о
typedef struct
{
    float a;
    float b;
    float c;
}Line;// структура которая хранит коэффициенты a b c

// Структура, содержащая информацию о размерах изображения
// и линии горизонта.
typedef struct
{
    float m; // Высота изображения
    float n; // Ширина изображения
    float y; // y-координата линии горизонта
}Picture;

//----------------------------------------------------------
// Объявление функций
//----------------------------------------------------------

Point getPoint();
Line solveline(Point a, Point b);
Segment getsegment();
Point linecross(Line l1, Line l2, Picture pic, Point sunproj, Point lower_point);
Picture getPicture();
Point main_check(Point cross, Picture pic, Line line_down, Point sunproj, Point lower_point);
int point_in_picture(Point cross, Picture pic);
Point line_down_and_border(Line line_down, Picture pic, Point sunproj, Point lower_point);
void printPoint(Point a);

//----------------------------------------------------------

int main()
{
    printf("Введите координаты солнышка (x;y)\n");
    Point sun = getPoint();

    printf("Введите координаты верхней и нижней точек отрезка (x;y)\n");
    Segment stick = getsegment();

    printf("Введите параметры картинки (высота, ширина, y-координата линии горизонта)\n");
    Picture pic = getPicture();

    Point sunproj; // Точка -- проекция солнышка на горизонт
    sunproj.x = sun.x;
    sunproj.y = pic.y;

    Line line_up = solveline(stick.a , sun);       // Прямая, соединяющая солнце и верхнюю точку отрезка
    Line line_down = solveline(stick.b , sunproj); // Прямая, соединяющая проекцию солнца на горизонт и нижнюю точку отрезка

    Point cross = linecross(line_up, line_down, pic, sunproj, stick.b);
    cross = main_check(cross,pic, line_down, sunproj, stick.b);
    printPoint(cross);
    Segment stick_shadow;
    stick_shadow.a = cross;
    stick_shadow.b = stick.b;
    if (abs(cross.x - stick.b.x) < 0.00001 && abs(cross.y - stick.b.y) < 0.00001) // условия на то что тени нет
    {
        printf ("Shadow non-existent");
    }


    return 0;

}

//----------------------------------------------------------
// Функции
//----------------------------------------------------------

// Получает координаты точки и возвращает соответствующую структуру.
Point getPoint()
{
    Point a;
    scanf("%f %f", &a.x, &a.y);
    return a;
}

//
Line solveline(Point a, Point b) // Подсчёт коэффициентов a b c
{
    Line l;
    l.a = (a.y - b.y);
    l.b = (b.x - a.x);
    l.c = (a.x * b.y - b.x * a.y);
    return l;
}

// Получает координаты верхней и нижней точек отрезка и
// возвращает соответствующую структуру.
Segment getsegment()
{
    Segment s;
    s.a = getPoint();
    s.b = getPoint();
    return s;
}

// Находит точку пересечения двух прямых.
Point linecross(Line l1, Line l2, Picture pic, Point sunproj, Point lower_point) // находит точку пересечения двух прямых
{
    Point cross;
    if (l1.a * l2.b == l2.a * l1.b) // если прямые параллельны то в cross сразу отправим line_down_and_border(line_down, pic);
    {
        cross = line_down_and_border(l2, pic, sunproj, lower_point);
    }
    else
    {
        if(l1.a == 0)
        {
            cross.y = -l1.c / l1.b;
            cross.x = (-l2.c - l2.b * cross.y) / l2.a;
        }
        else
        {
            cross.y = (-l2.c + l1.c * l2.a / l1.a) / (l2.b - l1.b * l2.a / l1.a);
            cross.x = (-l1.c - l1.b * cross.y) / l1.a;
        }
    }

    return cross;
}

// Получает высоту, ширину изображения и y-координату линии горизонта.
Picture getPicture()
{
    Picture s;
    scanf("%f", &s.m);
    scanf("%f", &s.n);
    scanf("%f", &s.y);
    return s;
}

//
Point main_check(Point cross, Picture pic, Line line_down, Point sunproj, Point lower_point)
{
    //$#$#$#$#$$#$#тут рассматриваем случай когда точка пересечения внутри картинки$#$#$#$#$#$$#$#$
    if(point_in_picture(cross, pic) == 1)
    {
    // рассматриваем первый случай, когда прямые пересеклись ниже горизонта
        if(cross.y <= pic.y)
        {
            return cross;
        }
        else
        {
            return line_down_and_border(line_down, pic, sunproj, lower_point);
        }

    }
    //$#$#$#$#$$#$#тут рассматриваем случай когда точка пересечения вне картинки$#$#$#$#$#$$#$#$
    else
    {
        return line_down_and_border(line_down, pic, sunproj, lower_point);
    }
}
//............................................................
int point_in_picture(Point cross, Picture pic)
{
    if(cross.x >= 0 && cross.x <= pic.n && cross.y >= 0 && cross.y <= pic.m)
        return 1;
    else
        return 0;
}
//............................................................
Point line_down_and_border(Line line_down, Picture pic, Point sunproj, Point lower_point)
{
    Point cross;
    if (line_down.a == 0)
    {
        if (sunproj.x > lower_point.x)// когда солнце справа
        {
            cross.x = 0;
            cross.y = pic.y;
        }
        else
        {
            cross.x = pic.n;
            cross.y = pic.y;
        }

        return cross;
    }
    cross.y = 0; // пересечение прямой с низом
    cross.x = -line_down.c / line_down.a;
    //printf("coords of cross:\n");
    //printPoint(cross);
    if(cross.x < 0)  // если сначала пересечёт левый бок
    {
        cross.x = 0;
        cross.y = -line_down.c / line_down.b;
    }
    if(cross.x > pic.n) // если сначала пересечёт правый бок
    {
        cross.x = pic.n;
        cross.y = -(line_down.c + pic.n * line_down.a) / line_down.b;
    }
    return cross;
}
//............................................................
void printPoint(Point a)
{
    printf("x = %f\n", a.x);
    printf("y = %f\n", a.y);
}

void Print_line (Line l)
{
    printf ("a = %f, b = %f, c = %f\n", l.a, l.b, l.c);
}

void Print_segment(Segment c)
{
    printf ("higher point: x = %f, y = %f\n", c.a.x, c.a.y);
    printf ("lower point: x = %f, y = %f\n", c.b.x, c.b.y);
}
