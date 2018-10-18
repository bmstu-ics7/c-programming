#include "assert.h"

int err_cnt = 0;

/*
 * Сравнивает два целых числа 
 *
 * @param expected [in]
 * @param recieved [in]
 * @param test_name [in]
 *
 * @return возвращает SUCCESS в случае равных оидаемого
 * и полученного результатов и WRONG иначе
*/

int assert(const int expected, const int recieved, const char *const test_name)
{
    if (expected == recieved)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n" 
                WHITE "expected: %d, recieved: %d\n", test_name, expected, recieved);
        
        printf(WHITE "");
        return WRONG;
    }
}

/*
 * Сравнивает два массива
 * 
 * @param expected [in]
 * @param recieved [in]
 * @param size [in]
 * @param test_name [in]
 *
 * @return возвращает SUCCESS в случае равных оидаемого
 * и полученного результатов и WRONG иначе
*/

int assert_array(const int *const expected, const int *const recieved, const int size, const char *const test_name)
{
    int count_right = 0;

    for (int i = 0; i < size; i++)
        if (expected[i] == recieved[i])
            count_right++;

    if (count_right == size)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n"        
                WHITE "expected: ", test_name);

        for (int i = 0; i < size; i++)
            printf("%d ", expected[i]);

        printf("\nrecieved: ");

        for (int i = 0; i < size; i++)
            printf("%d ", recieved[i]);

        printf(WHITE "\n\n");
                
        return WRONG;
    }
}

/*
 * Сравнивает две матрицы
 * 
 * @param expected [in]
 * @param recieved [in]
 * @param n [in]
 * @param m [in]
 * @param test_name [in]
 *
 * @return возвращает SUCCESS в случае равных оидаемого
 * и полученного результатов и WRONG иначе
*/

int assert_matrix(double **expected, double **recieved, const int n, const int m, const char *const test_name)
{
    if (expected == NULL && recieved == NULL)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }

    int count_false = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fabs(expected[i][j] - recieved[i][j]) > 1e-8)
            {
                count_false++;
                break;
            }

    if (count_false == 0)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n" WHITE "expected:\n", test_name);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%lf ", expected[i][j]);

            printf("\n");
        }

        printf("\nrecieved:\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%lf ", recieved[i][j]);

            printf("\n");
        }

        printf(WHITE "\n\n");
        return WRONG;
    }
}

/*
 * Выводит результат тестирования
 *  
 * @param test_name [in]
*/

void print_errors(const char *const test_name)
{
    printf(WHITE "%d %s %s\n", err_cnt, err_cnt ? RED "FAILED" : GREEN "OK", test_name);
    printf(WHITE "\n");
    err_cnt = 0;
}

