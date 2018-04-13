#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define block_size 0x4000

typedef struct {
    char s[block_size];
    int row;
} BWTcode_t;

BWTcode_t *BWT (char *s);

int main()  {
    int i;
    BWTcode_t *r;
    char s[block_size] = {0};
    scanf("%s", s); // это условно
    r = BWT(s);
    printf("%s\n%i\n", r->s, r->row);
    free (r);
    return 0;
}

BWTcode_t *BWT (char *s)  {
    int length = strlen(s);
    BWTcode_t *result;
    int h; // увеличивающийся (каждый раз вдвое) параметр метода
    int pos[block_size];
        // целевой массив: pos[i] - номер слова A[i] в H-порядке
        // A[i] - слово, начинающееся в s[i], i=0..length-1
    int bucket[block_size];
        // bucket[i] - в какое по порядку ведро попадает слово A[i]
    int start[block_size];
        // start[k] - с какого по порядку слова начинается k-е ведро
    int nbucket;
        // номер последнего ведра (количество ведер - 1)
    int chars[256] = {0};
       // cчётчик символов - используется для инициализации
       // масива pos номерами слов в 1-порядке
    int tmp[block_size];
    int i, j, k;
    /*  заполняем массив chars  */
    for (i=0; i<length; i++)  chars[s[i]]++;
    /*  сейчас chars[i] хранит количество символов #i в блоке s  */

    for (i=1; i<256; i++)  chars[i] += chars[i-1];
    /*  а теперь chars[i] хранит порядковый номер последнего
        слова, начинающегося на символ #i, в 1-порядке  */

    /*  заполняем массив pos номерами слов в 1-порядке;  */
    /*  двигаемся по каждому 1-ведру справа налево       */
    for (i=0; i<length; i++)  pos[--chars[s[i]]] = i;
    /*  массив chars нам больше не нужен  */

    /*  расставляем  номера ведер  */
    nbucket = 0;         // начинаем с 0-го ведра
    bucket[pos[0]] = 0;  // самое первое в 1-порядке слово лежит в ведре #0,
    start[0] = 0;        // которое начинается с наименьшего слова
    for (i=1; i<length; i++)  {
        if (s[pos[i]]!=s[pos[i-1]])  {
            nbucket++;
            start[nbucket] = i;
        }
        bucket[pos[i]] = nbucket;
    }
    h = 1;
    /*  инициализация завершена. все параметры
        установлены в соответствии c 1-порядком  */

    while ((h<length) && (nbucket+1 < length))  {
    /*  массив pos соответствует  h-сортировке - переходим к 2h-сортировке  */

        /*  в массиве tmp собираем новый pos  */
        for (i=0; i<length; i++)  {
            j = pos[i]-h;
            if (j<0)  j += length;
            /*  слово A[j] надо передвинуть в начало своего ведра  */
            tmp[start[bucket[j]]++] = j;
        }
        for (i=0; i<length; i++)  {
            pos[i] = tmp[i];
        }


        /*  Пересчитываем распределение по вёдрам - теперь в 2h-порядке  */
        /*  Для хранения новых вёдер используем массив tmp  */
        nbucket = 0;         // начинаем с 0-го ведра
        tmp[pos[0]] = 0;  // самое первое в 1-порядке слово лежит в ведре #0,
        start[0] = 0;        // которое начинается с наименьшего слова
        for (i=1; i<length; i++)  {
            if (bucket[pos[i]] != bucket[pos[i-1]])  {
            /*  текущий сдвиг и раньше (в h-порядке)
                лежал не в том ведре, что и предыдущий  */
               start[++nbucket] = i;
            }
            else {
            /*  текущий сдвиг раньше (в h-порядке) лежал
                в том же ведре, что и предыдущий, ...  */
                j = pos[i-1] + h;
                if (j>=length) j -= length;
                k = pos[i] + h;
                if (k>=length) k -= length;
                if (bucket[j] != bucket[k])  {
                /* ... а их h-последователи лежали в разных вёдрах  */
                   start[++nbucket] = i;
                }
            }
            tmp[pos[i]] = nbucket;
        }

        /*  обновляем массив bucket  */
        for (i=0 ; i<length; i++)  {
            bucket[i] = tmp[i];
        }
        /*  переходим к следующему шагу: массив pos соответствует 2h-сортировке  */
        h *= 2;

    }
    /*  собираем результат  */
   result = (BWTcode_t *) malloc( sizeof(BWTcode_t));
   for (i=0; i<length; i++)  {
        if (pos[i] == 0)  {
           result->s[i] = s[length-1];
           result->row = i;
        }
        else  {
           result->s[i] = s[pos[i]-1];
        }
    }
    result->s[length] = 0;

    return result;
}
