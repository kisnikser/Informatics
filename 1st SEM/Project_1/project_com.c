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

//==========================================================
// Библиотеки и константы
//==========================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALMOSTZERO 0.00001

//==========================================================
// Объявление структур
//==========================================================

// Структура, содержащая информацию о точке на плоскости.
// Оси координат Ox и Oy направлены горизонтально вправо
// и вертикально вверх соответственно.
typedef struct
{
    float x; // x-координата точки
    float y; // y-координата точки
}Point;

// Структура, содержащая информацию об отрезке.
typedef struct
{
    Point a; // Верхняя точка отрезка 
    Point b; // Нижняя  точка отрезка
}Segment;

// Структура, содержащая информацию о прямой, заданной
// уравнением Ax + By + C = 0.
typedef struct
{
    float a; // Коэффициент A
    float b; // Коэффициент B
    float c; // Коэффициент C
}Line;

// Структура, содержащая информацию о размерах изображения
// и линии горизонта.
typedef struct
{
    float m; // Высота изображения
    float n; // Ширина изображения
    float y; // y-координата линии горизонта
}Picture;

// Структура, содержащая информацию о прямоугольнике,
// для которого заданы левая и правая стороны.
typedef struct
{
    Segment left;  // Левая  сторона прямоугольника
    Segment right; // Правая сторона прямоугольника
}Box;

//==========================================================
// Объявление функций
//==========================================================

Point getPoint();
Segment getsegment();
Line solveline(Point a, Point b);
Picture getPicture();
Box getBox();

Segment get_stick_shadow (Segment stick, Picture pic, Point sun, Point sunproj);
Box get_box_shadow (Box box, Point sun, Point sunproj, Picture pic);

Point linecross(Line l1, Line l2, Picture pic, Point sunproj, Point lower_point);
Point main_check(Point cross, Picture pic, Line line_down, Point sunproj, Point lower_point);
int point_in_picture(Point cross, Picture pic);
Point line_down_and_border(Line line_down, Picture pic, Point sunproj, Point lower_point);

void printPoint(Point a);
void Print_segment(Segment c);
void Print_line (Line l);
void Print_Box (Box box);

int float_if_equal(float a, float b);
int if_points_coincide(Point a, Point b);
int if_segment_exists (Segment seg);
int if_box_exists (Box box);
void sortSegment (Segment* stick);
void sortBox (Box* box);

//==========================================================

int main()
{
    int flag_stick = 0, flag_box = 0; // Флажки для определения -- отрезок / прямоугольник

    printf("Введите координаты солнышка (x;y)\n");
    Point sun = getPoint();

    printf("Введите параметры картинки (высота, ширина, y-координата линии горизонта)\n");
    Picture pic = getPicture();

    Point sunproj; // Точка - проекция солнышка на горизонт
    sunproj.x = sun.x;
    sunproj.y = pic.y;

    printf ("Вы хотите найти тень своего отрезка?\n");
    printf ("1 - если да, 0 - если нет\n");

    scanf ("%d", &flag_stick);

    if (flag_stick) // Получение информации об отрезке
    {
        printf("Введите координаты вертикального отрезка (x;y).\n");
        Segment stick = getsegment();

        Segment stick_shadow = get_stick_shadow(stick, pic, sun, sunproj);

        if ( if_segment_exists(stick_shadow) ) // Проверка на отсутствие тени
        {
            Print_segment(stick_shadow);
        }
        else
            printf ("Тень не существует.\n"); // Вывод в случае отсутствия тени
        exit(1); // Завершение программы // !!!
    }

    printf ("Вы хотите найти тень своего прямоугольника?\n");
    printf ("1 - если да, 0 - если нет\n");

    scanf ("%d", &flag_box);

    if (flag_box) // Получение информации о прямоугольнике
    {
        printf("Введите координаты левой и правой сторон прямоугольника (x;y).\n");
        Box box = getBox();

        Box box_shadow = get_box_shadow(box, sun, sunproj, pic);

        if (if_box_exists (box_shadow)) // Проверка на отсутствие тени
        {
            Print_Box (box_shadow);
        }
        else
        {
            printf("Тень не существует.\n"); // Вывод в случае отсутствия тени
        }


    }

    return 0;

}

//==========================================================
// Реализация функций
//==========================================================

//----------------------------------------------------------
// Функции ввода
//----------------------------------------------------------

// Получает координаты точки и возвращает соответствующую структуру.
Point getPoint()
{
    Point a;
    scanf("%f %f", &a.x, &a.y);
    return a;
}

// Получает координаты верхней и нижней точек отрезка и
// возвращает соответствующую структуру.
Segment getsegment()
{
    Segment s;
    s.a = getPoint();
    s.b = getPoint();
    sortSegment(&s);
    return s;
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

// Получает координаты верхних и нижних точек левой и правой
// сторон прямоугольника и возвращает соответствующую структуру.
Box getBox()
{
    Box box;
    box.left = getsegment();
    box.right = getsegment();
    sortBox(&box);
    return (box);
}

//----------------------------------------------------------
// Функции генерации тени
//----------------------------------------------------------

// Получает на вход:
// 1. Переменную типа Box     - прямоугольник
// 2. Переменную типа Point   - солнышко
// 3. Переменную типа Point   - проекцию солнышка на горизонт
// 4. переменную типа Picture - изображение
// Возвращает переменную типа Box - тень прямоугольника
Box get_box_shadow (Box box, Point sun, Point sunproj, Picture pic)
{
    Box box_shadow;
    box_shadow.left = get_stick_shadow(box.left, pic, sun, sunproj);   // Тень для левой  стороны
    box_shadow.right = get_stick_shadow(box.right, pic, sun, sunproj); // Тень для правой стороны
    return (box_shadow);
}

// Получает на вход:
// 1. Переменную типа Segment - отрезок
// 2. Переменную типа Picture - изображение
// 3. Переменную типа Point   - солнышко
// 4. Переменную типа Point   - проекцию солнышка на горизонт
// Возвращает переменную типа Box - тень прямоугольника.
Segment get_stick_shadow (Segment stick, Picture pic, Point sun, Point sunproj)
{
    Line line_up = solveline(stick.a, sun);       // Верхняя прямая тени
    Line line_down = solveline(stick.b, sunproj); // Нижняя  прямая тени

    Point cross = linecross(line_up, line_down, pic, sunproj, stick.b); // Точка пересечения прямых
    cross = main_check(cross, pic, line_down, sunproj, stick.b);        // Проверка точки пересечения
    //printPoint(cross);
    Segment stick_shadow;
    stick_shadow.a = cross;
    stick_shadow.b = stick.b;
    return (stick_shadow);
}

//----------------------------------------------------------
// Функции работы с прямыми
//----------------------------------------------------------

// Получает на вход:
// 1. Переменную типа Point - первую точку
// 2. Переменную типа Point - вторую точку
// Возвращает переменную типа Line - прямую, проходящую через обе точки.
Line solveline(Point a, Point b)
{
    Line l;
    l.a = (a.y - b.y);
    l.b = (b.x - a.x);
    l.c = (a.x * b.y - b.x * a.y);
    return l;
}

// Получает на вход:
// 1. Переменную типа Line    - верхнюю прямую тени
// 2. Переменную типа Line    - нижнюю  прямую тени
// 3. Переменную типа Picture - изображение
// 4. Переменную типа Point   - проекцию солнышка на горизонт
// 5. Переменную типа Point   - нижнюю точку отрезка
// Возвращает переменную типа Point - точку пересечения двух прямых тени.
Point linecross(Line l1, Line l2, Picture pic, Point sunproj, Point lower_point)
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

//----------------------------------------------------------
// Функции для работы с тенью
//----------------------------------------------------------

// Получает на вход:
// 1. Переменную типа Point   - точку пересечения прямых тени
// 2. Переменную типа Picture - изображение
// 3. Переменную типа Line    - нижнюю прямую тени
// 4. Переменную типа Point   - проекцию солнышка на горизонт
// 5. Переменную типа Point   - нижнюю точку отрезка 
// Возвращает переменную типа Point - точку тени.
Point main_check(Point cross, Picture pic, Line line_down, Point sunproj, Point lower_point)
{
    if(point_in_picture(cross, pic) == 1) // Случай, когда точка пересечения находится внутри изображения
    {
        if(cross.y <= pic.y) // Случай, когда прямые пересеклись ниже горизонта
        {
            return cross;
        }
        else
        {
            return line_down_and_border(line_down, pic, sunproj, lower_point);
        }

    }
    else // Случай, когда точка пересечения находится за границами изображения
    {
        return line_down_and_border(line_down, pic, sunproj, lower_point);
    }
}

// Получает на вход:
// 1. Переменную типа Point   - точку пересечения прямых тени
// 2. Переменную типа Picture - изображение
// Возвращает 1, если точка находится внутри изображения, иначе - 0
int point_in_picture(Point cross, Picture pic)
{
    if(cross.x >= 0 && cross.x <= pic.n && cross.y >= 0 && cross.y <= pic.m)
        return 1;
    else
        return 0;
}

// Получает на вход:
// 1. Переменную типа Line    - нижнюю прямую тени
// 2. Переменную типа Picture - изображение
// 3. Переменную типа Point   - проекцию солнышка на горизонт
// 4. Переменную типа Point   - нижнюю точку отрезка 
// Возвращает переменную типа Point - точку пересечения двух прямых тени.
Point line_down_and_border(Line line_down, Picture pic, Point sunproj, Point lower_point)
{
    Point cross; // Точка пересечения прямых тени
    if (line_down.a == 0) // Случай, когда прямая параллельна оси Ox
    {
        if (sunproj.x > lower_point.x) // Случай, когда солнце находится правее нижней точки отрезка
        {
            cross.x = 0;
            cross.y = pic.y;
        }
        else // Случай, когда солнце находится левее нижней точки отрезка
        {
            cross.x = pic.n;
            cross.y = pic.y;
        }
        return cross;
    }
    cross.y = 0; // Прямая пересекает нижнюю границу изображения
    cross.x = -line_down.c / line_down.a;
    //printf("coords of cross:\n");
    //printPoint(cross);
    if(cross.x < 0) // Случай, когда точка пересечения прямых тени находится левее левой границы изображения
    {
        cross.x = 0;
        cross.y = -line_down.c / line_down.b;
    }
    if(cross.x > pic.n) // Случай, когда точка пересечения прямых тени находится правее правой границы изображения
    {
        cross.x = pic.n;
        cross.y = -(line_down.c + pic.n * line_down.a) / line_down.b;
    }
    return cross;
}

//----------------------------------------------------------
// Функции вывода
//----------------------------------------------------------

// Получает на вход:
// Переменную типа Point - точку
// Печатает координаты точки
void printPoint(Point a) // !!!
{
    printf("(%0.3f;%0.3f)\n", a.x, a.y);
}

// Получает на вход:
// Переменную типа Line - прямую
// Печатает коэффициенты A, B, C прямой
void Print_line (Line l) // !!!
{
    printf ("A = %0.3f, B = %0.3f, C = %0.3f\n", l.a, l.b, l.c);
}

// Получает на вход:
// Переменную типа Segment - тень отрезка
// Печатает координаты точек отрезка тени
void Print_segment(Segment c) // !!!
{
    printf ("Отрезок тени: (%0.3f;%0.3f), (%0.3f;%0.3f)\n", c.b.x, c.b.y, c.a.x, c.a.y);
}

// Получает на вход:
// Переменную типа Box - тень прямоугольника
// Печатает координаты точек отрезков тени
void Print_Box (Box box) // !!!
{
    printf("Левая сторона:\n");
    Print_segment(box.left);
    printf("Правая сторона:\n");
    Print_segment(box.right);
}

//----------------------------------------------------------
// Функции проверки условия / существования
//----------------------------------------------------------

// Получает на вход:
// 1. Переменную типа float - первое действительное число
// 2. Переменную типа float - второе действительное число
// Возвращает 1, если числа примерно равны, иначе - 0
int float_if_equal(float a, float b)
{
    if (fabs(a - b) < ALMOSTZERO)
        return 1;
    else
        return 0;
}

// Получает на вход:
// 1. Переменную типа Point - первую точку
// 2. Переменную типа Point - вторую точку
// Возвращает 1, если точки совпадают, иначе - 0
int if_points_coincide(Point a, Point b)
{
    if (float_if_equal(a.x, b.x) && float_if_equal(a.y, b.y))
        return 1;
    else
        return 0;
}

// Получает на вход:
// Переменную типа Segment - отрезок
// Возвращает 0, если отрезок является точкой, иначе - 1
int if_segment_exists (Segment seg)
{
    if ( if_points_coincide (seg.a, seg.b) )
        return 0;
    else
        return 1;
}

// Получает на вход:
// Переменную типа Box - прямоугольник
// Возвращает 0, если две стороны являются точками, иначе - 1
int if_box_exists (Box box)
{
    if (if_segment_exists(box.left) && if_segment_exists(box.right))
        return 1;
    else
        return 0;
}

// Получает на вход:
// Переменную типа Segment - отрезок
// Меняет порядок точек в отрезке так, чтобы верхней точкой была
// точка a, нижней - точка b
void sortSegment (Segment* stick) // !!!
{
    if (stick->a.y < stick->b.y)
    {
        Segment tmp;
        tmp.a = stick->b;
        stick->b = stick->a;
        stick->a = tmp.a;
    }
}

// Получает на вход:
// Переменную типа Box - прямоугольник
// Меняет порядок сторон в прямоугольнике так, чтобы левой стороной
// была сторона left, правой - right
void sortBox (Box* box) // !!!
{
    if (box->left.a.x > box->right.a.x)
    {
        Box tmp;
        tmp.left = box->right;
        box->right = box->left;
        box->left = tmp.left;
    }
    sortSegment(&box->left);
    sortSegment(&box->right);
}
