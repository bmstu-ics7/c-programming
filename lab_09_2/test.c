#include "my_string.h"
#include "assert.h"

void test_len_positive(void)
{
    char *test1 = "12345";
    char *test2 = "";
    char *test3 = "kek";

    assert(5, len(test1), "positive test #1 LEN");
    assert(0, len(test2), "positive test #1 LEN");
    assert(3, len(test3), "positive test #1 LEN");
}

void test_len_negative(void)
{
    assert(LEN_ERROR, len(NULL), "negative test LEN");
}

void test_getline_positive(void)
{
    char *res = NULL;
    size_t n = 0;
    FILE *file = NULL;

    char *res_right = NULL;
    size_t n_right = 0;
    FILE *file_right = NULL;

    file = fopen("test/1.in", "r");
    file_right = fopen("test/1.in", "r");

    assert(my_getline(&res, &n, file), getline(&res_right, &n_right, file_right), "return values test #1 GETLINE");

    assert_string(res, res_right, "result values test #1 GETLINE");

    fclose(file);
    fclose(file_right);

    file = fopen("test/2.in", "r");
    file_right = fopen("test/2.in", "r");

    assert(my_getline(&res, &n, file), getline(&res_right, &n_right, file_right), "return values test #2 GETLINE");

    assert_string(res, res_right, "result values test #2 GETLINE");

    fclose(file);
    fclose(file_right);

    file = fopen("test/only_enter.in", "r");
    file_right = fopen("test/only_enter.in", "r");

    assert(my_getline(&res, &n, file), getline(&res_right, &n_right, file_right), "return values test only_enter GETLINE");

    assert_string(res, res_right, "result values test only_enter GETLINE");

    fclose(file);
    fclose(file_right);
    free_string(res);
    free_string(res_right);
}

void test_getline_negative(void)
{
    char *res = NULL;
    size_t n = 0;
    FILE *file = NULL;

    char *res_right = NULL;
    size_t n_right = 0;
    FILE *file_right = NULL;

    file = fopen("test/void.in", "r");
    file_right = fopen("test/void.in", "r");

    assert(my_getline(&res, &n, file), getline(&res_right, &n_right, file_right), "return values negative test GETLINE");

    fclose(file);
    fclose(file_right);
    free_string(res);
    free_string(res_right);
}

void test_replace_positive(void)
{
    char *source = NULL;
    char *search = NULL;
    char *replace = NULL;
    char *result = NULL;

    source = "kek";
    search = "k";
    replace = "kek";

    result = str_replace(source, search, replace);
    assert_string(result, "kekekek", "positive test #1 STR_REPLACE");

    free_string(result);

    source = "lol";
    search = "lo";
    replace = "l";

    result = str_replace(source, search, replace);
    assert_string(result, "ll", "positive test #2 STR_REPLACE");

    free_string(result);

    source = "Its not a Faris!";
    search = "Faris";
    replace = "Alexander";

    result = str_replace(source, search, replace);
    assert_string(result, "Its not a Alexander!", "positive test #3 STR_REPLACE");

    free_string(result);
}

void test_replace_negative(void)
{
    char *result = str_replace(NULL, NULL, NULL);
    assert_string(result, NULL, "negative test STR_REPLACE");
}

int test_len(void)
{
    test_len_positive();
    test_len_negative();

    return print_errors("len test");
}

int test_getline(void)
{
    test_getline_positive();
    test_getline_negative();

    return print_errors("getline test");
}

int test_replace(void)
{
    test_replace_positive();
    test_replace_negative();

    return print_errors("replase test");
}

int main(void)
{
    if (test_len() == WRONG)
        return WRONG;

    if (test_getline() == WRONG)
        return WRONG;

    if (test_replace() == WRONG)
        return WRONG;

    return SUCCESS;
}
