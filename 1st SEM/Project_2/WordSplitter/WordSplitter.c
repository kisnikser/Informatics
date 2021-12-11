//==============================================================================
//                               WordSplitter
//==============================================================================

//==============================================================================
// Библиотеки и константы
//==============================================================================

/*! \mainpage Программа делающая мягкие переносы
 *
 * \section authors Авторы
 *
 * Над проектом работали:
 *
 * Отращенко Алексей Б01-006
 *
 * Волков Вадим Б01-006
 *
 * Киселев Никита Б01-001
 *
 * Дорин Даниил Б01-001
 *
 * \section soul Суть программы
 *
 * Данная программа получает на вход файл input с текстом
 * (в строке текста должно быть меньше 10000 символов) и выдает
 * файл output с расставленными мягкими переносами
 */

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include  <wchar.h>
#include <wctype.h>
#include  <errno.h>

/// Максимальная длина строки с текстом
#define N 10000

//==============================================================================
// Объявление функций
//==============================================================================

void work_with_files(char** argv);

wchar_t* split_string(wchar_t* string);
wchar_t* split_word(wchar_t* word);
wchar_t* sample_word (wchar_t* word);

int* rules(wchar_t* word, wchar_t* sampled_word, int* k);
int problem(wchar_t* sampled_word);
int* double_sounds(wchar_t* word, int* n);
int* open_sounds(wchar_t* sampled_word, int* n);
int* exceptions(wchar_t* sampled_word, int* n);
int* close_sounds(wchar_t* sampled_word, int* n);
int* super_sounds(wchar_t* sampled_word, int* n);
int* ultraclose_sounds(wchar_t* sampled_word, int* n);
int int_comparing(const void* pa, const void * pb);

//==============================================================================

int main(int argc, char** argv)
{
    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    switch(argc)
    {
        case 1:
            printf("Введите имена файлов для чтения и записи!\n");
            break;
        case 2:
            printf("Введите имена файлов для чтения и записи!\n");
            break;
        default:
            work_with_files(argv); // Чтение из файла argv[1], запись в файл argv[2] (work_with_files)
            break;
    }

    return 0;
}

//==============================================================================
// Реализация функций
//==============================================================================

//------------------------------------------------------------------------------
// Функция работы с файлом
//------------------------------------------------------------------------------

/*!
 * \brief Работа с файлами
 *
 * Функция получает на вход аргументы main(название файла с текстом и название файла куда выводить)
 * Берет очередную строку, расставляет в ней переносы и печатает полученную строку в выводимый файл
 *
 * \param argv - аргументы консолной строки
 *
 * \warning Программа никак не очищает текст от мусора
 */
void work_with_files(char** argv)
{
    FILE *fin, *fout;

    fin  = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    if (errno)  // проверка открылся ли файл
        printf("ERROR");

    wchar_t* string = calloc(N + 1, sizeof(wchar_t)); // выделяем память на очередную строку из файла (туда передаем строку из файла)

    while (fgetws(string, N, fin) != NULL) // получаем строку из файла пока можем
        fputws(split_string(string), fout);  // обрабатываем её с помощью Split_string и загружаем в файл

    free(string); // освобождаем выделенную память
    fclose(fin);
    fclose(fout);
}

//------------------------------------------------------------------------------
// Функции алгоритма расстановки переносов
//------------------------------------------------------------------------------

/*!
 *  \brief Функция расстановки переносов в строке
 *
 *  Функция получает на вход строку, смотрит на очередное слово, и посылает это слово в split_word
 *
 *  \param string - изначальная строка с текстом
 *
 *  основа функции - \ref split_word
 *
 */
wchar_t* split_string(wchar_t* string)
{
    wchar_t* find; //  указатель на новые слова
    wchar_t* part = string; //  указатель, на строку
    wchar_t* splitted_string = (wchar_t*)calloc(wcslen(string) * 3, sizeof(wchar_t)); //  итоговая строка с переносами;

    for (int i = 0; (find = wcsstr(part, L" ")) != NULL; i++)
    {
        find[0] = L'\0';
        wcscat(splitted_string, split_word(part)); // вставляем слово со сделанными переносами
        wcscat(splitted_string, L" "); //ставит после слова пробел
        part = find + 1; // смотрим на следующее слово
    }

    wcscat(splitted_string, split_word(part)); // вставляем последнее слово со сделанными переносами

    return splitted_string;
}

/*!
 * \brief Функция расстановки переносов в слове
 *
 * Функция берет слово, выделяет место для слова с переносами
 *
 * \param word - слово в котором расставляем переносы
 *
 * правила расстановки слов - \ref rulse
 */

wchar_t* split_word(wchar_t* word)
{
    int i = 0; // перебор в цикле
    int n = 0; // количество переносов в слове
    int tmp = 0; // место где нужно поставить перенос
    wchar_t* part = word; // массив со словом
    wchar_t* split = L"\\-";// перенос
    wchar_t* sampled_word = (wchar_t*)calloc(wcslen(word) + 1, sizeof(wchar_t)); // шаблон слова (функция sample_word отвечает за его создание)
    wchar_t* splitted_word = (wchar_t*)calloc(wcslen(word) * 3, sizeof(wchar_t)); // слово с переносами

    sampled_word = sample_word(word);

    int* places = rules(word, sampled_word, &n); // получаем массив мест где нужно поставить переносы

    if (n == 0) // если переносы ставить не надо то просто возвращает слово
        return word;

    while (places[tmp] == 0) // смещаем номер символа на который смотрим, если не надо ставить перенос
        tmp++;

    wcsncat(splitted_word, part, places[tmp] + 1); // вставляем в слово все символы где не нужно ставить переносы
    wcscat(splitted_word, split); // вставляем значок переноса

    for (i = tmp + 1; i < n; i++)
    {
        wcsncat(splitted_word, part + places[i - 1] + 1, places[i] - places[i - 1]); // копируем часть строки до следующего переноса
        wcscat(splitted_word, split); // вставляем значок переноса
    }

    wcscat(splitted_word, part + places[n - 1] + 1); // вставляем остаток слова

    free(sampled_word);
    free(places);
    return splitted_word;
}

/*!
 *    \brief Приводит слово к шаблону
 *
 *    \details Берем данное слово и создаем его шаблон:
 *    В шаблоне:
 *    Вместо каждой гласной стоит "Г" или "г" (в зависимости от заглавности буквы)
 *    Вместо каждой согласной стоит "С" или "с" (в зависимости от заглавности буквы)
 *    й, ъ, ь копируются в шаблон как есть
 *    Если в слове присутсвует не буква, то она также просто копируется в шаблон
 */
wchar_t* sample_word(wchar_t* word)
{
    wchar_t* sampled_word = (wchar_t*)calloc(wcslen(word) + 1, sizeof(wchar_t));

    for (int i = 0; i < wcslen(word); i++)
    {
        if (iswalpha(word[i]))
        {
            switch(word[i])
            {
                case L'A': case L'Е': case L'Ё': case L'И': case L'О': case L'У':
                case L'Ы': case L'Э': case L'Ю': case L'Я':
                    wcscat(sampled_word, L"Г"); // вместо лю
                    break;
                case L'а': case L'е': case L'ё': case L'и': case L'о': case L'у':
                case L'ы': case L'э': case L'ю': case L'я':
                    wcscat(sampled_word, L"г");
                    break;
                case L'Ъ': case L'ъ': case L'Ь': case L'ь': case L'Й': case L'й':
                    wcsncat(sampled_word, word + i, 1);
                    break;
                default:
                    if (iswupper(word[i])) // проверка на заглавность буквы
                        wcscat(sampled_word, L"С");
                    else
                        wcscat(sampled_word, L"с");
                    break;
            }
        }
        else
            wcsncat(sampled_word, word + i, 1);
    }

    return sampled_word;
}

/*!
 * \brief Распределение приоритетов между правилами и нахожжение мест где нужно поставить перенос
 *
 * \param word - слово в котором нужно поставить переносы
 * \param sampled_word - шаблон слова
 * \param k - указатель на ячейку, где будет хранится кол-во переносов
 *
 * \note Возможно неполнота набора правил
 *
 */
int* rules(wchar_t* word, wchar_t* sampled_word, int* k)
{
    int* places = (int*)calloc(wcslen(word) * 10, sizeof(int)); // массив упорядоченных позиций в слове, в которых нужно поставить перенос

    int** options = (int**)calloc(wcslen(word) * 10, sizeof(int*)); // 2 - мерный массив, строка i которого - массив places для i - ого правила

    int* n = (int*)calloc(10, sizeof(int)); // < массив количества переносов из-за данного правила
    int nmax = 0; // < общее число поставленных переносов

    if (problem(sampled_word))
    {
        *k = 0;
        return places;
    }

    options[0] = double_sounds(word, n);
    options[1] = open_sounds(sampled_word, n + 1);
    options[2] = close_sounds(sampled_word, n + 2);
    options[3] = exceptions(sampled_word, n + 3);
    options[4] = super_sounds(sampled_word, n + 4);
    options[5] = ultraclose_sounds(sampled_word, n + 5);

    for (int i = 0; i < 6; i++) // перебираем по всем правилам в порядке приоритетов
    {
        for (int j = 0; j < n[i]; j++) // перебираем по позициям где нужно поставить перенос
        {
            places[nmax + j] = options[i][j]; // ставим в places переносы с данного правила
        }
        nmax += n[i]; // смещаем указатель на количество поставленных переносов по i - ому правилу
    }

    for (int i = 0; i < nmax - 1; i++) // проверяем на отсутствие совпадений мест где нужно поставить перенос i - номер рассматриваемого правила
    {
        for (int j = i + 1; j < nmax; j++) // смотрим на все правила после i - ого: если какое - то j - ое
                                           //из них ставит перенос в месте, где правило i уже поставило перенос, убираем его
        {
            if (places[j] == places[i])
                places[j] = 0;
        }
    }

    qsort(places, nmax, sizeof(int), int_comparing); // сортируем места где поставим переносы в порядке возрастания

    *k = nmax;

    free(options);
    free(n);
    return places;
}



/*!
 * \brief Проверка на возможность постановки переносов в слове
 *
 * Если слово меньше чем из 4 букв или меньше чем с 2 гласными, аббревиатуры, числа, смесь чисел с буквами либо другими символами
 * Перенос нельзя поставить
 * Возвращает 1, если в слове нельзя поставить перенос, иначе 0
 * \param sampled_word Шаблон слова, в котором расставляются переносы
 */
int problem(wchar_t* sampled_word)
{
	int k = 0; // флаг на гласные
	int m = 0; // флаг на заглавные
	int h = 0; // флаг на цифры
    int i;

	for(i = 0; i < wcslen(sampled_word); i++)
	{
		if(iswdigit(sampled_word[i])) // проверка что символ - число
			h++;
        if(iswupper(sampled_word[i])) // проверка что символ заглавный
    		m++;
        if((sampled_word[i] == L'г') || (sampled_word[i] == L'Г')) // проверка что символ - гласная
    		k++;
	}

	if((wcslen(sampled_word) < 4) || (k < 2) || (m > 1) || (h > 0))
		return 1;
    else
        return 0;
}



/*!
 * Сдвоенные буквы
 */
int* double_sounds(wchar_t* word, int* n)
{
    int* places = (int*)calloc(wcslen(word), sizeof(int));

	int k = 0; // количетсво переносов из-за двойных букв в данном слове
    int i = 0;

	for(i = 1; i < wcslen(word) - 2; i++) // перебор от 2 буквы (1 букву нельзя на строке оставить) и до предпредпоследней
                                          // (так как нельзя перенести 1 букву)
	{
		if (word[i] == word[i + 1])
		{
			places[k] = i; // номер после которого ставим
			k++;
		}
	}

    *n = k;

	return places;
}

/// Открытые слоги: например, моЛО-ко
int* open_sounds(wchar_t* sampled_word, int* n)
{
	int* places = (int*)calloc(wcslen(sampled_word), sizeof(int));

	int k = 0; // количетсво переносов из-за открытых слогов в данном слове
    int i = 0;

	for (i = 1; i < (wcslen(sampled_word) - 2); i++)
	{
		if ( ( (sampled_word[i - 1] == L'С') || (sampled_word[i - 1] == L'с') || (sampled_word[i - 1] == L'Й') || (sampled_word[i - 1] == L'й') )
            && (sampled_word[i] == L'г') && ((sampled_word[i + 1] == L'с') || (sampled_word[i] == L'й')) && (sampled_word[i + 2] == L'г'))
        {
			places[k] = i; // номер после которого ставим
			k++;
		}
	}

    *n = k;

	return places;
}

/// й, ъ, ь например: наЙ-дется
int* exceptions(wchar_t* sampled_word, int* n)
{
	int* places = (int*)calloc(wcslen(sampled_word), sizeof(int));

	int k = 0; // количетсво переносов из-за открытых слогов в данном слове
	int i = 0;

	for (i = 2; i < (wcslen(sampled_word) - 2); i++)
	{
		if ( ( (sampled_word[i] == L'ь') || (sampled_word[i] == L'ъ') ) && (iswalpha(sampled_word[i + 1]) ) ) // зачем iswalpha??
		{
			places[k] = i; //номер после которого ставим
			k++;
		}
	}

    for (i = 1; i < (wcslen(sampled_word) - 2); i++)
	{
		if (sampled_word[i] == L'й')
		{
			places[k] = i; //номер после которого ставим
			k++;
		}
	}

    *n = k;

	return places;
}

/// Закрытые слоги например ОК-НО
int* close_sounds(wchar_t* sampled_word, int* n)
{
	int* places = (int*)calloc(wcslen(sampled_word), sizeof(int));

	int k = 0;
	int i = 0;

	for (i = 1; i < (wcslen(sampled_word)); i++)
	{
		if ( ( (sampled_word[i - 1] == L'Г') || (sampled_word[i - 1] == L'г'))
        && ( (sampled_word[i] == L'с') || (sampled_word[i] == L'й') ) && (sampled_word[i + 1] == L'с') && ((sampled_word[i + 2] == L'г') ) )
		{
			places[k] = i; //номер после которого ставим
			k++;
		}
	}

    *n = k;

	return places;
}

/// более двух согласных подряд ОТ-КРытый
int* super_sounds(wchar_t* sampled_word, int* n)
{
	int* places = (int*)calloc(wcslen(sampled_word), sizeof(int));

	int k = 0;

	for (int i = 1; i < (wcslen(sampled_word) - 2); i++)
	{
		if (((sampled_word[i - 1] == L'Г') || (sampled_word[i - 1] == L'г')) && (sampled_word[i] == L'с') && (sampled_word[i + 1] == L'с') && (sampled_word[i + 2] == L'с'))
		{
			places[k] = i;
			k++;
		}
	}

    *n = k;

	return places;
}

/// две гласные подряд(в общем случае разбиваются)
/// например аббреВИ-АТура
int* ultraclose_sounds(wchar_t* sampled_word, int* n)
{
	int* places = (int*)calloc(wcslen(sampled_word), sizeof(int));

	int k = 0;
	int i = 0;

	for (i = 1; i < (wcslen(sampled_word) - 2); i++)
	{
		if ( ( (sampled_word[i - 1] == L'С') || (sampled_word[i - 1] == L'с') ) && (sampled_word[i] == L'г')
            && (sampled_word[i + 1] == L'г') && ((sampled_word[i + 2] == L'с') || (sampled_word[i + 2] == L'й')))
		{
			places[k] = i;
			k++;
		}
	}

    *n = k;

	return places;
}

/// Сравнение целых чисел (возрастание)
int int_comparing(const void* pa, const void * pb)
{
    return *(int*)pa - *(int*)pb;
}
