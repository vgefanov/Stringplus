#include "s21_string.h"

#include <check.h>

#define MESSAGE_S "ERROR test %i ('%s'), we expected '%s', but got      '%s'"
#define MESSAGE_D "ERROR test %i, we expected '%i', but got      '%i'"

char actual_buf[1024], expected_buf[1024];
char hs[1024] = "Hello school 21!";
char hello[1024] = "Hello\n";
char hay[1024] = "How are you";
char space[1024] = " ";
char emp[1024] = "";
char enter[1024] = "\n";
char zero[1024] = "\0";
char hex_zero[1024] = "\0x00";

int s21_test(int sg) {
  int ret = 0;
  if (sg < 0) ret = -1;
  if (sg > 0) ret = 1;
  return ret;
}

START_TEST(check_memchr) {
  ck_assert_ptr_eq(s21_memchr(hs, '\n', 7), memchr(hs, '\n', 7));
  ck_assert_ptr_eq(s21_memchr(hs, 's', 3), memchr(hs, 's', 3));
  ck_assert_ptr_eq(s21_memchr(hs, 'H', 7), memchr(hs, 'H', 7));
  ck_assert_ptr_eq(s21_memchr(hs, 'c', 7), memchr(hs, 'c', 7));
  ck_assert_ptr_eq(s21_memchr(hs, '\0', 16), memchr(hs, '\0', 16));
  ck_assert_ptr_eq(s21_memchr(hs, '1', 0), memchr(hs, '1', 0));
  ck_assert_ptr_eq(s21_memchr(emp, 'o', 7), memchr(emp, 'o', 7));
}
END_TEST

START_TEST(check_memcmp) {
  ck_assert_int_eq(s21_test(s21_memcmp(hs, enter, 16)),
                   s21_test(memcmp(hs, enter, 16)));
  ck_assert_int_eq(s21_test(s21_memcmp(hs, enter, 0)),
                   s21_test(memcmp(hs, enter, 0)));
  ck_assert_int_eq(s21_test(s21_memcmp(space, emp, 1)),
                   s21_test(memcmp(space, emp, 1)));
  ck_assert_int_eq(s21_test(s21_memcmp(hs, enter, 17)),
                   s21_test(memcmp(hs, enter, 17)));
  ck_assert_int_eq(s21_test(s21_memcmp(hs, hello, 17)),
                   s21_test(memcmp(hs, hello, 17)));
  ck_assert_int_eq(s21_test(s21_memcmp(hs, "H", 17)),
                   s21_test(memcmp(hs, "H", 17)));
  ck_assert_int_eq(s21_test(s21_memcmp(hay, enter, 17)),
                   s21_test(memcmp(hay, enter, 17)));
  ck_assert_int_eq(s21_test(s21_memcmp("abcdefgh", "abcdefgh", 8)),
                   s21_test(memcmp("abcdefgh", "abcdefgh", 8)));
  ck_assert_int_eq(s21_test(s21_memcmp("abcdefgh", "abcdefgl", 8)),
                   s21_test(memcmp("abcdefgh", "abcdefgl", 8)));
}
END_TEST

START_TEST(check_memcpy) {
  ck_assert_ptr_eq(s21_memcpy(actual_buf, hs, 3), memcpy(actual_buf, hs, 3));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, emp, 15),
                   memcpy(actual_buf, emp, 15));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, enter, 0),
                   memcpy(actual_buf, enter, 0));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, zero, 1),
                   memcpy(actual_buf, zero, 1));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, hex_zero, 10),
                   memcpy(actual_buf, hex_zero, 10));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, hay, 15),
                   memcpy(actual_buf, hay, 15));
  ck_assert_ptr_eq(s21_memcpy(actual_buf, hello, 3),
                   memcpy(actual_buf, hello, 3));
}
END_TEST

START_TEST(check_memmove) {
  ck_assert_ptr_eq(s21_memmove(actual_buf, hs, 3), memmove(actual_buf, hs, 3));
  ck_assert_ptr_eq(s21_memmove(actual_buf, emp, 15),
                   memmove(actual_buf, emp, 15));
  ck_assert_ptr_eq(s21_memmove(actual_buf, enter, 0),
                   memmove(actual_buf, enter, 0));
  ck_assert_ptr_eq(s21_memmove(actual_buf, zero, 1),
                   memmove(actual_buf, zero, 1));
  ck_assert_ptr_eq(s21_memmove(actual_buf, hex_zero, 10),
                   memmove(actual_buf, hex_zero, 10));
  ck_assert_ptr_eq(s21_memmove(actual_buf, hay, 15),
                   memmove(actual_buf, hay, 15));
  ck_assert_ptr_eq(s21_memmove(actual_buf, hello, 3),
                   memmove(actual_buf, hello, 3));
}
END_TEST

START_TEST(check_memset) {
  ck_assert_ptr_eq(s21_memset(actual_buf, '0', 3), memset(actual_buf, '0', 3));
  ck_assert_ptr_eq(s21_memset(actual_buf, '\0', 3),
                   memset(actual_buf, '\0', 3));
  ck_assert_ptr_eq(s21_memset(actual_buf, '.', 10),
                   memset(actual_buf, '.', 10));
  ck_assert_ptr_eq(s21_memset(actual_buf, '\n', 100),
                   memset(actual_buf, '\n', 100));
  ck_assert_ptr_eq(s21_memset(actual_buf, 'x', 1023),
                   memset(actual_buf, 'x', 1024));
}
END_TEST

START_TEST(check_strcat) {
  ck_assert_ptr_eq(s21_strcat(hs, emp), strcat(hs, emp));
  ck_assert_ptr_eq(s21_strcat(hay, hs), strcat(hay, hs));
  ck_assert_ptr_eq(s21_strcat(space, enter), strcat(space, enter));
  ck_assert_ptr_eq(s21_strcat(enter, hay), strcat(enter, hay));
  ck_assert_ptr_eq(s21_strcat(emp, hay), strcat(emp, hay));
}
END_TEST

START_TEST(check_strncat) {
  ck_assert_ptr_eq(s21_strncat(hs, emp, 3), strncat(hs, emp, 3));
  ck_assert_ptr_eq(s21_strncat(hay, hs, 1), strncat(hay, hs, 1));
  ck_assert_ptr_eq(s21_strncat(space, enter, 1023),
                   strncat(space, enter, 1023));
  ck_assert_ptr_eq(s21_strncat(enter, hay, 7), strncat(enter, hay, 7));
  ck_assert_ptr_eq(s21_strncat(emp, hay, 0), strncat(emp, hay, 0));
}
END_TEST

START_TEST(check_strchr) {
  ck_assert_ptr_eq(s21_strchr(hs, 'H'), strchr(hs, 'H'));
  ck_assert_ptr_eq(s21_strchr(hs, 'o'), strchr(hs, 'o'));
  ck_assert_ptr_eq(s21_strchr(hs, 's'), strchr(hs, 's'));
  ck_assert_ptr_eq(s21_strchr(hs, 'd'), strchr(hs, 'd'));
  ck_assert_ptr_eq(s21_strchr(hs, '\0'), strchr(hs, '\0'));
  ck_assert_ptr_eq(s21_strchr(hs, '1'), strchr(hs, '1'));
  ck_assert_ptr_eq(s21_strchr(emp, '2'), strchr(emp, '2'));
}
END_TEST

START_TEST(check_strcmp) {
  ck_assert_int_eq(s21_test(s21_strcmp(hs, hello)),
                   s21_test(strcmp(hs, hello)));
  ck_assert_int_eq(s21_test(s21_strcmp(hs, enter)),
                   s21_test(strcmp(hs, enter)));
  ck_assert_int_eq(s21_test(s21_strcmp(enter, hs)),
                   s21_test(strcmp(enter, hs)));
  ck_assert_int_eq(s21_test(s21_strcmp(hs, "l")), s21_test(strcmp(hs, "l")));
  ck_assert_int_eq(s21_test(s21_strcmp(hs, "d")), s21_test(strcmp(hs, "d")));
  ck_assert_int_eq(s21_test(s21_strcmp(hs, "\0")), s21_test(strcmp(hs, "\0")));
  ck_assert_int_eq(s21_test(s21_strcmp(emp, "1")), s21_test(strcmp(emp, "1")));
  ck_assert_int_eq(s21_test(s21_strcmp(emp, "")), s21_test(strcmp(emp, "")));
}
END_TEST

START_TEST(check_strncmp) {
  ck_assert_int_eq(s21_test(s21_strncmp(hs, enter, 6)),
                   s21_test(strncmp(hs, enter, 6)));
  ck_assert_int_eq(s21_test(s21_strncmp(hs, hay, 0)),
                   s21_test(strncmp(hs, hay, 0)));
  ck_assert_int_eq(s21_test(s21_strncmp(hs, space, 2)),
                   s21_test(strncmp(hs, space, 2)));
  ck_assert_int_eq(s21_test(s21_strncmp(hs, emp, 1)),
                   s21_test(strncmp(hs, emp, 1)));
  ck_assert_int_eq(s21_test(s21_strncmp(space, emp, 2)),
                   s21_test(strncmp(space, emp, 2)));
  ck_assert_int_eq(s21_test(s21_strncmp(hs, enter, 20)),
                   s21_test(strncmp(hs, enter, 20)));
  ck_assert_int_eq(s21_test(s21_strncmp(space, "", 20)),
                   s21_test(strncmp(space, "", 20)));
}
END_TEST

START_TEST(check_strcpy) {
  ck_assert_ptr_eq(s21_strcpy(actual_buf, hs), strcpy(actual_buf, hs));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, emp), strcpy(actual_buf, emp));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, enter), strcpy(actual_buf, enter));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, zero), strcpy(actual_buf, zero));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, hex_zero),
                   strcpy(actual_buf, hex_zero));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, hay), strcpy(actual_buf, hay));
  ck_assert_ptr_eq(s21_strcpy(actual_buf, hello), strcpy(actual_buf, hello));
}
END_TEST

START_TEST(check_strncpy) {
  ck_assert_ptr_eq(s21_strncpy(actual_buf, hs, 3), strncpy(actual_buf, hs, 3));
  ck_assert_ptr_eq(s21_strncpy(actual_buf, space, 2),
                   strncpy(actual_buf, space, 2));
  ck_assert_ptr_eq(s21_strncpy(actual_buf, enter, 15),
                   strncpy(actual_buf, enter, 15));
  ck_assert_ptr_eq(s21_strncpy(actual_buf, zero, 100),
                   strncpy(actual_buf, zero, 100));
  ck_assert_ptr_eq(s21_strncpy(actual_buf, hay, 15),
                   strncpy(actual_buf, hay, 15));
  ck_assert_ptr_eq(s21_strncpy(actual_buf, hello, 10),
                   strncpy(actual_buf, hello, 10));
}
END_TEST

START_TEST(check_strcspn) {
  ck_assert_uint_eq(s21_strcspn(hs, emp), strcspn(hs, emp));
  ck_assert_uint_eq(s21_strcspn(hay, hs), strcspn(hay, hs));
  ck_assert_uint_eq(s21_strcspn(space, enter), strcspn(space, enter));
  ck_assert_uint_eq(s21_strcspn(enter, hay), strcspn(enter, hay));
  ck_assert_uint_eq(s21_strcspn(emp, hay), strcspn(emp, hay));
}
END_TEST

START_TEST(check_strerror) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(1), strerror(1));
  ck_assert_str_eq(s21_strerror(2), strerror(2));
  ck_assert_str_eq(s21_strerror(3), strerror(3));
  ck_assert_str_eq(s21_strerror(4), strerror(4));
  ck_assert_str_eq(s21_strerror(100), strerror(100));
}
END_TEST

START_TEST(check_strlen) {
  ck_assert_int_eq(s21_strlen(hs), strlen(hs));
  ck_assert_int_eq(s21_strlen(hay), strlen(hay));
  ck_assert_int_eq(s21_strlen(space), strlen(space));
  ck_assert_int_eq(s21_strlen(enter), strlen(enter));
  ck_assert_int_eq(s21_strlen(emp), strlen(emp));
}
END_TEST

START_TEST(check_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk(hs, "hello"), strpbrk(hs, "hello"));
  ck_assert_ptr_eq(s21_strpbrk(hs, hay), strpbrk(hs, hay));
  ck_assert_ptr_eq(s21_strpbrk(hs, "9"), strpbrk(hs, "9"));
  ck_assert_ptr_eq(s21_strpbrk(space, emp), strpbrk(space, emp));
  ck_assert_ptr_eq(s21_strpbrk(emp, emp), strpbrk(emp, emp));
  ck_assert_ptr_eq(s21_strpbrk(emp, hs), strpbrk(emp, hs));
}
END_TEST

START_TEST(check_strrchr) {
  ck_assert_ptr_eq(s21_strrchr(hs, 'H'), strrchr(hs, 'H'));
  ck_assert_ptr_eq(s21_strrchr(hs, 'o'), strrchr(hs, 'o'));
  ck_assert_ptr_eq(s21_strrchr(hs, 'l'), strrchr(hs, 'l'));
  ck_assert_ptr_eq(s21_strrchr(hs, 'd'), strrchr(hs, 'd'));
  ck_assert_ptr_eq(s21_strrchr(hs, '\0'), strrchr(hs, '\0'));
  ck_assert_ptr_eq(s21_strrchr(hs, '1'), strrchr(hs, '1'));
  ck_assert_ptr_eq(s21_strrchr(emp, '2'), strrchr(emp, '2'));
}
END_TEST

START_TEST(check_strspn) {
  ck_assert_uint_eq(s21_strspn(hs, hello), strspn(hs, hello));
  ck_assert_uint_eq(s21_strspn(hs, hay), strspn(hs, hay));
  ck_assert_uint_eq(s21_strspn(hs, space), strspn(hs, space));
  ck_assert_uint_eq(s21_strspn(hs, emp), strspn(hs, emp));
  ck_assert_uint_eq(s21_strspn(space, emp), strspn(space, emp));
}
END_TEST

START_TEST(check_strstr) {
  ck_assert_ptr_eq(s21_strstr(hs, hello), strstr(hs, hello));
  ck_assert_ptr_eq(s21_strstr(hs, hay), strstr(hs, hay));
  ck_assert_ptr_eq(s21_strstr(hs, space), strstr(hs, space));
  ck_assert_ptr_eq(s21_strstr(hs, emp), strstr(hs, emp));
  ck_assert_ptr_eq(s21_strstr(space, emp), strstr(space, emp));
}
END_TEST

START_TEST(check_strtok) {
  ck_assert_ptr_eq(s21_strtok(hs, emp), strtok(hs, emp));
  ck_assert_ptr_eq(s21_strtok(hs, space), strtok(hs, space));
  ck_assert_ptr_eq(s21_strtok(hay, space), strtok(hay, space));
  ck_assert_ptr_eq(s21_strtok(emp, hay), strtok(emp, hay));
}
END_TEST

START_TEST(check_to_upper) {
  char hs1[1024] = "Hello school 21!";
  char hello1[1024] = "Hello\n";
  char space1[1024] = " ";
  char emp1[1024] = "";
  char zero1[1024] = "\0";
  char *buf = s21_to_upper(hs1);
  ck_assert_str_eq(buf, "HELLO SCHOOL 21!");
  char *buf1 = s21_to_upper(hello1);
  ck_assert_str_eq(buf1, "HELLO\n");
  char *buf2 = s21_to_upper(space1);
  ck_assert_str_eq(buf2, " ");
  char *buf3 = s21_to_upper(emp1);
  ck_assert_str_eq(buf3, "");
  char *buf4 = s21_to_upper(zero1);
  ck_assert_str_eq(buf4, "\0");
  free(buf);
  free(buf1);
  free(buf2);
  free(buf3);
  free(buf4);
}
END_TEST

START_TEST(check_to_lower) {
  char hs2[1024] = "Hello school 21!";
  char hello2[1024] = "Hello\n";
  char space2[1024] = " ";
  char emp2[1024] = "";
  char zero2[1024] = "\0";
  char *buf = s21_to_lower(hs2);
  ck_assert_str_eq(buf, "hello school 21!");
  char *buf1 = s21_to_lower(hello2);
  ck_assert_str_eq(buf1, "hello\n");
  char *buf2 = s21_to_lower(space2);
  ck_assert_str_eq(buf2, " ");
  char *buf3 = s21_to_lower(emp2);
  ck_assert_str_eq(buf3, "");
  char *buf4 = s21_to_lower(zero2);
  ck_assert_str_eq(buf4, "\0");
  free(buf);
  free(buf1);
  free(buf2);
  free(buf3);
  free(buf4);
}
END_TEST

START_TEST(check_insert) {
  char hs3[1024] = "Hello school 21!";
  char hay3[1024] = "How are you";
  char space3[1024] = " ";
  char emp3[1024] = "";
  char enter3[1024] = "\n";
  char *buf = s21_insert(hs3, space3, 4);
  ck_assert_str_eq(buf, "Hell o school 21!");
  char *buf1 = s21_insert(hay3, enter3, 5);
  ck_assert_str_eq(buf1, "How a\nre you");
  char *buf2 = s21_insert(space3, emp3, 1);
  ck_assert_str_eq(buf2, " ");
  char *buf3 = s21_insert(emp3, space3, 0);
  ck_assert_str_eq(buf3, " ");
  free(buf);
  free(buf1);
  free(buf2);
  free(buf3);
}
END_TEST

START_TEST(check_trim) {
  char hs4[1024] = "Hello school 21!";
  char hay4[1024] = "How are you";
  char *buf = s21_trim(hs4, " 21!");
  ck_assert_str_eq(buf, "Hello school");
  char *buf1 = s21_trim(hay4, "Howyou");
  ck_assert_str_eq(buf1, " are ");
  char hs5[1024] = "--- Hello school 21! ---";
  char *buf2 = s21_trim(hs5, "- ");
  ck_assert_str_eq(buf2, "Hello school 21!");
  char hs6[1024] = "Hello school 21! &*f.,";
  char *buf3 = s21_trim(hs6, " .,*&f");
  ck_assert_str_eq(buf3, "Hello school 21!");
  char hs7[1024] = "";
  char *buf4 = s21_trim(hs7, "");
  ck_assert_str_eq(buf4, "");
  char *hs8 = s21_NULL;
  char *buf5 = s21_trim(hs8, "jfj 6");
  ck_assert_ptr_eq(buf5, s21_NULL);
  char hs9[1024] = "--- --- ";
  char *buf6 = s21_trim(hs9, " -");
  ck_assert_str_eq(buf6, "");
  free(buf);
  free(buf1);
  free(buf2);
  free(buf3);
  free(buf4);
  free(buf5);
  free(buf6);
}
END_TEST

// s21_sprintf

// %c specifier

struct test_packc_struct {
  char fmt[50];
  char c;
};
struct test_packc_struct test_packc[] = {
    {"[TEST %c]\n", 'A'},      {"[TEST %20c]\n", 'A'},
    {"[TEST %-20c]\n", 'A'},   {"[TEST %20.2c]\n", 'A'},
    {"[TEST %-20.2c]\n", 'A'},
};

START_TEST(s21_sprintf_test_packc) {
  s21_sprintf(actual_buf, test_packc[_i].fmt, test_packc[_i].c);
  sprintf(expected_buf, test_packc[_i].fmt, test_packc[_i].c);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i + 1,
                test_packc[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_c1) {
  char fmt[] = "AAA%cBBB%20cCCC";
  s21_sprintf(actual_buf, fmt, 'X', 'Y');
  sprintf(expected_buf, fmt, 'X', 'Y');
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i + 1, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %s specifier

struct test_packs_struct {
  char fmt[50];
  char str[50];
};
struct test_packs_struct test_packs[] = {
    {"TEST %s\n", "A"},
    {"TEST %s\n", "IS OK!"},
    {"TEST %2s\n", "IS OK!"},
    {"TEST %20s\n", "IS OK!"},
    {"TEST %2.s\n", "IS OK!"},
    {"TEST %2.2s\n", "IS OK!"},
    {"TEST %20.2s\n", "IS OK!"},
    {"TEST %20.20sXXX\n", "IS OK!"},
    {"TEST %-20.20sXXX\n", "IS OK!"},
    {"TEST %-+ 20.20sXXX\n", "IS OK!"},
};

START_TEST(s21_sprintf_test_packs) {
  s21_sprintf(actual_buf, test_packs[_i].fmt, test_packs[_i].str);
  sprintf(expected_buf, test_packs[_i].fmt, test_packs[_i].str);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packs[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_s1) {
  char fmt[] = "AAA%sBBB%20.2sCCC%10.12sDDD";
  s21_sprintf(actual_buf, fmt, "XXXXX", "YYYYY", "ZZZZZ");
  sprintf(expected_buf, fmt, "XXXXX", "YYYYY", "ZZZZZ");
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %d/i specifier

struct test_packd_struct {
  char fmt[200];
  long int num;
};
struct test_packd_struct test_packd[] = {
    {"%u\n", LONG_MAX},
    {"%hu\n", LONG_MAX},
    {"%lu\n", LONG_MAX},
    {"%u\n", LONG_MIN},
    {"%hu\n", LONG_MIN},
    {"%lu\n", LONG_MIN},
    {"%+1u\n", 100000000000},
    {"%+hu\n", 100000000000},
    {"%+lu\n", 100000000000},
    {"% u\n", 100000000000},
    {"% hu\n", 100000000000},
    {"% lu\n", 100000000000},

    {"%i\n", LONG_MAX},
    {"%hi\n", LONG_MAX},
    {"%li\n", LONG_MAX},
    {"%i\n", LONG_MIN},
    {"%hi\n", LONG_MIN},
    {"%li\n", LONG_MIN},

    {"%d", 0},
    {"%d", 156},
    {"%i", 0},
    {"%+i", LONG_MIN},
    {"%-i", LONG_MAX},
    {"% i", 2444},
    {"%+ i", 2555},
    {"%- i", 2666},
    {"%+-i", 2777},
    {"%+- i", 2888},

    {"%2i", 2111},
    {"%+2i", 2222},
    {"%-2i", 2333},
    {"% 2i", 2444},
    {"%+ 2i", 2555},
    {"%- 2i", 2666},
    {"%+-2i", 2777},
    {"%+- 2i", 2888},

    {"%20i", 2111},
    {"%+20i", 2222},
    {"%-20i", 2333},
    {"% 20i", 2444},
    {"%+ 20i", 2555},
    {"%- 20i", 2666},
    {"%+-20i", 2777},
    {"%+- 20i", 2888},

    {"%+- 20.2i", 2888},
    {"%+03i", 0},
    {"E%+03i", 1},
    {"%+020i", 2888},
    {"%+020i", -2888},

    {"%.5d", 777},
    {"%0.0d", 0},
    {"%0.0u", 0},
};

START_TEST(s21_sprintf_test_packd) {
  s21_sprintf(actual_buf, test_packd[_i].fmt, test_packd[_i].num);
  sprintf(expected_buf, test_packd[_i].fmt, test_packd[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packd[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_d1) {
  char fmt[] = "%0*x";
  s21_sprintf(actual_buf, fmt, 8, 15);
  sprintf(expected_buf, fmt, 8, 15);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %f specifier

struct test_packf_struct {
  char fmt[50];
  double num;
};
struct test_packf_struct test_packf[] = {
    {"%10f\n", 13. / 7.},
    {"%10.f\n", 13. / 7.},
    {"%1.1f\n", 13. / 7.},
    {"%15.1f\n", 13. / 7.},
    {"%15.15f\n", 13. / 7.},
    {"%1.1f\n", -13. / 7.},
    {"%15f\n", -13. / 7.},
    {"%15.f\n", -13. / 7.},
    {"%15.0f\n", -13. / 7.},
    {"%15.1f\n", -13. / 7.},
    {"%-15.6f\n", -13. / 7.},
    {"%-15.6f\n", -13. / 7.},
    {"%2.6f", 2. / 3.},
    {"%-15.5f\n", -13.399998},
    {"%-15.5f\n", -19.999998},
    {"%-15.5f\n", -99.999998},
    {"%f", 1. / 0.},   // Infinity
    {"%f", -1. / 0.},  // −Infinity
    {"%f", INFINITY},
    {"%f", NAN},
    {"%f", 0. / 0.},  // Nan
    {"%f", 1},
    {"%f.", 1},
    {"%10.2f", 10.004},
    {"%5.5lf", 171346.1273791},
};

START_TEST(s21_sprintf_test_packf) {
  s21_sprintf(actual_buf, test_packf[_i].fmt, test_packf[_i].num);
  sprintf(expected_buf, test_packf[_i].fmt, test_packf[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packf[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_f1) {
  char fmt[] = "%0*.*f";
  s21_sprintf(actual_buf, fmt, 8, 4, 15. / 7.);
  sprintf(expected_buf, fmt, 8, 4, 15. / 7.);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_f2) {
  char fmt[] = "%.*lf";
  s21_sprintf(actual_buf, fmt, 2, 452354.4563453);
  sprintf(expected_buf, fmt, 2, 452354.4563453);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %e specifier

struct test_packe_struct {
  char fmt[1024];
  double num;
};
struct test_packe_struct test_packe[] = {
    {"%e", 0},
    {"%E\n", 13. / 7.},
    {"%e\n", 13. / 7.},
    {"%e\n", 7. / 13.},
    {"%e\n", 11111111111. / 13.},
    {"%10e\n", 13. / 7.},
    {"%10.e\n", 13. / 7.},
    {"%1.1e\n", 13. / 7.},
    {"%15.1e\n", 13. / 7.},
    {"%15.6e\n", 13. / 7.},
    {"%1.1e\n", -13. / 7.},
    {"%15e\n", -13. / 7.},
    {"%15.e\n", -13. / 7.},
    {"%15.0e\n", -13. / 7.},
    {"%15.1e\n", -13. / 7.},
    {"%-15.6e\n", -13. / 7.},
    {"%-15.6e\n", -13. / 7.},
    {"%2.6e", 2. / 3.},
    {"%-15.5e\n", -13.399998},
    {"%-15.5e\n", -19.999998},
    {"%-15.5e\n", -99.999998},
    {"%e", NAN},
};

START_TEST(s21_sprintf_test_packe) {
  s21_sprintf(actual_buf, test_packe[_i].fmt, test_packe[_i].num);
  sprintf(expected_buf, test_packe[_i].fmt, test_packe[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packe[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_e1) {
  char fmt[] = "AAA%0.2eBBB%10.0ECCC%-2.30eDDD\n";
  s21_sprintf(actual_buf, fmt, 8., 4., 15. / 7.);
  sprintf(expected_buf, fmt, 8., 4., 15. / 7.);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %g specifier

struct test_packg_struct {
  char fmt[50];
  double num;
};
struct test_packg_struct test_packg[] = {
    {"%G", 0.},
    {"%G\n", 13. / 7.},
    {"%g\n", 13. / 7.},
    {"%g\n", 7. / 13.},
    {"%g\n", 11111111111. / 13.},
    {"%10g\n", 13. / 7.},
    {"%10.g\n", 13. / 7.},
    {"%1.1g\n", 13. / 7.},
    {"%15.1g\n", 13. / 7.},
    {"%15.6g\n", 13. / 7.},
    {"%1.1g\n", -13. / 7.},
    {"%15g\n", -13. / 7.},
    {"%15.g\n", -13. / 7.},
    {"%15.0g\n", -13. / 7.},
    {"%15.2g\n", -13. / 7.},
    {"%-15.6g\n", -13. / 7.},
    {"%-15.6g\n", -13. / 7.},
    {"%2.6g", 2. / 3.},
    {"%-15.5g\n", -13.399998},
    {"%10.2g", 10.004},
    {"%20.3G", 100.0000},
    {"%20.4G", 1100.000},
    {"%-15.5e\n", -19.999998},
    {"%-15.5e\n", -99.999998},
};

START_TEST(s21_sprintf_test_packg) {
  s21_sprintf(actual_buf, test_packg[_i].fmt, test_packg[_i].num);
  sprintf(expected_buf, test_packg[_i].fmt, test_packg[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packg[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_g1) {
  char fmt[] = "AAA%0.2GBBB%10.0gCCC%-2.30GDDD\n";
  s21_sprintf(actual_buf, fmt, 8., 4., 15. / 7.);
  sprintf(expected_buf, fmt, 8., 4., 15. / 7.);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %x specifier

struct test_packx_struct {
  char fmt[50];
  unsigned long num;
};
struct test_packx_struct test_packx[] = {
    {"%x\n", 256},
    {"%X\n", 234567890},
    {"%x\n", ULONG_MAX},
    {"%hx\n", ULONG_MAX},
    {"%lx\n", ULONG_MAX},
    {"%x\n", 0},
    {"%hx\n", 0},
    {"%lx\n", 0},
    {"%+1x\n", 100000000000},
    {"%+hx\n", 100000000000},
    {"%+lx\n", 100000000000},
    {"% x\n", 100000000000},
    {"% hx\n", 100000000000},
    {"% lx\n", 100000000000},
    {"%#x\n", 234567890},
    {"%#X\n", 234567890},
    {"%0.0x", 0},
    {"%-+#2.30x\n", 0x33333333},
};

START_TEST(s21_sprintf_test_packx) {
  s21_sprintf(actual_buf, test_packx[_i].fmt, test_packx[_i].num);
  sprintf(expected_buf, test_packx[_i].fmt, test_packx[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packx[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_x1) {
  char fmt[] = "AAA%0.2hxBBB%10.0XCCC%-2.30lxDDD\n";
  s21_sprintf(actual_buf, fmt, 11111, 22222222, 33333333);
  sprintf(expected_buf, fmt, 11111, 22222222, 33333333);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %o specifier

struct test_packo_struct {
  char fmt[50];
  unsigned long num;
};
struct test_packo_struct test_packo[] = {
    {"[%o]\n", 256},
    {"[%o]\n", 234567890},
    {"[%o]\n", ULONG_MAX},
    {"[%ho]\n", ULONG_MAX},
    {"%lo\n", ULONG_MAX},
    {"[%o]", 0},
    {"[%ho]\n", 0},
    {"[%lo]\n", 0},
    {"%+1o\n", 100000000000},
    {"%+ho\n", 100000000000},
    {"%+lo\n", 100000000000},
    {"% o\n", 100000000000},
    {"% ho\n", 100000000000},
    {"% lo\n", 100000000000},
    {"%#o\n", 256},
    {"%#020o\n", 256},
    {"%0.0o", 0},
    {"[%#0.0o]", 0},
};

START_TEST(s21_sprintf_test_packo) {
  s21_sprintf(actual_buf, test_packo[_i].fmt, test_packo[_i].num);
  sprintf(expected_buf, test_packo[_i].fmt, test_packo[_i].num);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packo[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_o1) {
  char fmt[] = "AAA%0.2hoBBB%10.0oCCC%-2.30loDDD\n";
  s21_sprintf(actual_buf, fmt, 11111, 22222222, 33333333);
  sprintf(expected_buf, fmt, 11111, 22222222, 33333333);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// %p specifier

struct test_packp_struct {
  char fmt[200];
  int *ptr;
};
struct test_packp_struct test_packp[] = {
    {"%p\n", (int *)0x12345699},
    {"%20p\n", (int *)0x12345678},
    {"%0.0p", (int *)0},
};

START_TEST(s21_sprintf_test_packp) {
  s21_sprintf(actual_buf, test_packp[_i].fmt, test_packp[_i].ptr);
  sprintf(expected_buf, test_packp[_i].fmt, test_packp[_i].ptr);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i,
                test_packp[_i].fmt, expected_buf, actual_buf);
}
END_TEST

START_TEST(s21_sprintf_test_p1) {
  char fmt[] = "AAA%0.2pBBB%10.0pCCC%2.30pDDD\n";
  s21_sprintf(actual_buf, fmt, 0x11111111, 0x22222222, 0x33333333);
  sprintf(expected_buf, fmt, 0x11111111, 0x22222222, 0x33333333);
  ck_assert_msg(strcmp(actual_buf, expected_buf) == 0, MESSAGE_S, _i, fmt,
                expected_buf, actual_buf);
}
END_TEST

// return test

START_TEST(s21_sprintf_test_return) {
  int actual_ret = s21_sprintf(actual_buf, "% 20.20f", -13. / 7.);
  int expected_ret = sprintf(expected_buf, "% 20.20f", -13. / 7.);
  ck_assert_int_eq(actual_ret, expected_ret);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf = 0;

  tcase_add_test(tc1_1, check_memchr);
  tcase_add_test(tc1_1, check_memcmp);
  tcase_add_test(tc1_1, check_memcpy);
  tcase_add_test(tc1_1, check_memmove);
  tcase_add_test(tc1_1, check_memset);
  tcase_add_test(tc1_1, check_strcat);
  tcase_add_test(tc1_1, check_strncat);
  tcase_add_test(tc1_1, check_strchr);
  tcase_add_test(tc1_1, check_strcmp);
  tcase_add_test(tc1_1, check_strncmp);
  tcase_add_test(tc1_1, check_strcpy);
  tcase_add_test(tc1_1, check_strncpy);
  tcase_add_test(tc1_1, check_strcspn);
  tcase_add_test(tc1_1, check_strerror);
  tcase_add_test(tc1_1, check_strlen);
  tcase_add_test(tc1_1, check_strpbrk);
  tcase_add_test(tc1_1, check_strrchr);
  tcase_add_test(tc1_1, check_strspn);
  tcase_add_test(tc1_1, check_strstr);
  tcase_add_test(tc1_1, check_strtok);
  tcase_add_test(tc1_1, check_to_upper);
  tcase_add_test(tc1_1, check_to_lower);
  tcase_add_test(tc1_1, check_insert);
  tcase_add_test(tc1_1, check_trim);

  // s21_sprintf

  // %c/% specifier
  int packc_size = sizeof(test_packc) / sizeof(test_packc[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packc, 0, packc_size);
  tcase_add_test(tc1_1, s21_sprintf_test_c1);

  // %s specifier
  int packs_size = sizeof(test_packs) / sizeof(test_packs[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packs, 0, packs_size);
  tcase_add_test(tc1_1, s21_sprintf_test_s1);

  // %d/i specifier
  int packd_size = sizeof(test_packd) / sizeof(test_packd[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packd, 0, packd_size);
  tcase_add_test(tc1_1, s21_sprintf_test_d1);

  // %f specifier
  int packf_size = sizeof(test_packf) / sizeof(test_packf[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packf, 0, packf_size);
  tcase_add_test(tc1_1, s21_sprintf_test_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_f2);

  // %e specifier
  int packe_size = sizeof(test_packe) / sizeof(test_packe[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packe, 0, packe_size);
  tcase_add_test(tc1_1, s21_sprintf_test_e1);

  // %g specifier
  int packg_size = sizeof(test_packg) / sizeof(test_packg[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packg, 0, packg_size);
  tcase_add_test(tc1_1, s21_sprintf_test_g1);

  // %x specifier
  int packx_size = sizeof(test_packx) / sizeof(test_packx[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packx, 0, packx_size);
  tcase_add_test(tc1_1, s21_sprintf_test_x1);

  // %o specifier
  int packo_size = sizeof(test_packo) / sizeof(test_packo[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packo, 0, packo_size);
  tcase_add_test(tc1_1, s21_sprintf_test_o1);

  // %p specifier
  int packp_size = sizeof(test_packp) / sizeof(test_packp[0]);
  tcase_add_loop_test(tc1_1, s21_sprintf_test_packp, 0, packp_size);
  tcase_add_test(tc1_1, s21_sprintf_test_p1);

  // return test
  tcase_add_test(tc1_1, s21_sprintf_test_return);

  suite_add_tcase(s1, tc1_1);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
