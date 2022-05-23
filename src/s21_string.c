#include "s21_string.h"

// 1. memchr - поиск первого вхождения указанного символа в массиве
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *str_s = (unsigned char *)str;
  unsigned char *char_find = s21_NULL;
  while ((str != s21_NULL) && (n--)) {
    if (*str_s != (unsigned char)c) {
      str_s++;
    } else {
      char_find = str_s;
      break;
    }
  }
  return char_find;
}

// 2. memcmp - сравнение массивов
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int count = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*s1 == *s2) {
      s1++;
      s2++;
      continue;
    }
    if (*s1 > *s2) {
      if (*s2 == '\0') {
        count = (*s1 - '0') - ('\0' - '0');
      } else {
        count = ((*s1) - '0') - ((*s2) - '0');
      }
    } else {
      if (*s1 == '\0') {
        count = -1 * ((*s2 - '0') - ('\0' - '0'));
      } else {
        count = -1 * (((*s2) - '0') - ((*s1) - '0'));
      }
    }
    break;
  }
  return count;
}

// 3. memcpy – копирование непересекающихся массивов
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != s21_NULL && src != s21_NULL) {
    if (dest <= src) {
      for (s21_size_t i = 0; i < n; i++) {
        ((char *)dest)[i] = ((char *)src)[i];
      }
    } else {
      for (s21_size_t i = n; i > 0; i--) {
        ((char *)dest)[i - 1] = ((char *)src)[i - 1];
      }
    }
  }
  return dest;
}

// 4. memmove – копирование массивов (в том числе пересекающихся)
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  void *out = s21_NULL;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    out = dest;
    char *f_dest = (char *)dest;
    char *f_src = (char *)src;
    char *buf = malloc(n * sizeof(char));
    for (s21_size_t i = 0; i < n; i++) buf[i] = *(f_src + i);
    for (s21_size_t i = 0; i < n; i++) *(f_dest + i) = buf[i];
    free(buf);
  }
  return out;
}

// 5. memset – заполнения массива указанными символами
void *s21_memset(void *str, int c, s21_size_t n) {
  for (size_t i = 0; i < n && str; i++) {
    ((char *)str)[i] = (char)c;
  }
  return str;
}

// 6. strcat - объединение строк
char *s21_strcat(char *dest, const char *src) {
  int i, j;
  for (j = 0, i = (int)s21_strlen(dest); j <= (int)(s21_strlen(src)); i++, j++)
    *(dest + i) = *(src + j);
  return dest;
}

// 7. strncat – объединение строк c ограничением длины добавляемой строки
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int i, j;
  for (j = 0, i = (int)s21_strlen(dest); j < (int)(n); i++, j++)
    *(dest + i) = *(src + j);
  return dest;
}

// 8. strchr - поиск первого вхождения символа в строку
char *s21_strchr(const char *str, int c) {
  char *str_s = (char *)str;
  char *char_find = s21_NULL;
  if (str_s != s21_NULL) {
    do {
      if (*str_s == (char)c) {
        char_find = str_s;
        break;
      }
    } while (*str_s++);
  }
  return char_find;
}

// 9. strcmp – сравнение строк
int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  int result = *str1 - *str2;
  return result;
}

// 10. strncmp – сравнение строк с ограничением количества сравниваемых символов
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  char *nulled = "";
  if (str1 == s21_NULL) str1 = nulled;
  if (str2 == s21_NULL) str2 = nulled;
  s21_size_t i = 0;
  for (; *str1 && *str2 && *str1 == *str2 && i < n; str1++, str2++, i++) {
  }
  return i < n ? *str1 - *str2 : 0;
}

// 11. strcpy – копирование строк
char *s21_strcpy(char *dest, const char *src) {
  char *out = s21_NULL;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    out = dest;
    char *f_src = (char *)src;
    while (*f_src) *dest++ = *f_src++;
    *dest = '\0';
  }
  return out;
}

// 12. strncpy – копирование строк c ограничением длины
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *out = s21_NULL;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    out = dest;
    char *f_src = (char *)src;
    while (n--) *dest++ = *f_src++;
  }
  return out;
}

// 13. strcspn – определение длины участка строки не содержащего указанные
// символы
unsigned int s21_strcspn(const char *str1, const char *str2) {
  unsigned int len = 0;
  unsigned int flag = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      break;
    } else {
      str1++;
      len++;
      flag = len;
    }
  }
  return flag;
}

#ifdef __APPLE__
const char *err_mes = "Unknown error: ";
char ER_MAC_OS[][80] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
};
#else
const char *err_mes = "Unknown error ";
char ERR_GNU_LINUX[][80] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",
};
#endif

// перевод числа в строку для strerror
void int_to_char(char *result, int number) {
  int flag = number > 0 ? 1 : -1;
  number *= flag;
  int i = 0;
  while (number > 9) {
    result[i++] = number % 10 + '0';
    number /= 10;
  }
  result[i] = number + '0';
  if (flag == -1) {
    i += 1;
    result[i] = '-';
  }
  for (int b = 0; b <= i / 2; ++b) {
    int temp = result[b];
    result[b] = result[i - b];
    result[i - b] = temp;
  }
  result[i + 1] = '\0';
}

// 14. strerror – формирование сообщения об ошибке по коду ошибки
char *s21_strerror(int errnum) {
  char *result = "";
  static char temp[1000] = {0};
  static char sborka[1000] = {0};
  for (int i = 0; i < 1000; i++) {
    temp[i] = '\0';
    sborka[i] = '\0';
  }
  int_to_char(temp, errnum);

#ifdef __APPLE__
  if (errnum >= 0 && errnum < ERROR_LIMIT) {
    result = ER_MAC_OS[errnum];
  }
#else
  if (errnum >= 0 && errnum < ERROR_LIMIT) {
    result = ERR_GNU_LINUX[errnum];
  }
#endif
  if (errnum < 0 || errnum >= ERROR_LIMIT) {
    result = s21_strcat(s21_strcat(sborka, err_mes), temp);
  }
  return result;
}

// 15. strlen – определение длины строки
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; *(str + length); length++) {
  }
  return length;
}

// 16. strpbrk – поиск первого вхождения в строку символа из указанного
// множества
char *s21_strpbrk(const char *str1, const char *str2) {
  char *count1 = (char *)str1;
  int check = 0;
  while (*count1 != '\0') {
    char *count2;
    count2 = (char *)str2;
    while (*count2 != '\0') {
      if (*count1 == *count2) {
        check = 1;
        break;
      }
      count2++;
    }
    if (check) break;
    count1++;
  }
  if (check == 0) count1 = NULL;
  return count1;
}

// 17. поиск последнего вхождения символа в строку
char *s21_strrchr(const char *str, int c) {
  char *str_s = (char *)str;
  char *char_find = s21_NULL;
  if (str_s != s21_NULL) {
    do {
      if (*str_s == (char)c) char_find = str_s;
    } while (*str_s++);
  }
  return char_find;
}

// 18. определение максимальной длины участка строки, содержащего только
// указанные символы
s21_size_t s21_strspn(const char *str1, const char *str2) {
  unsigned int len = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 && s21_strchr(str2, *str1++)) len++;
  }
  return len;
}

// 19. поиск первого вхождения строки А в строку В
char *s21_strstr(const char *haystack, const char *needle) {
  const char *a;
  const char *b;
  char *c = 0;
  b = needle;
  if (*b == 0) c = (char *)haystack;
  for (; *haystack != 0; haystack += 1) {
    if (*haystack != *b) continue;
    a = haystack;
    while (1) {
      if (*b == 0) {
        c = (char *)haystack;
        break;
      }
      if (*a++ != *b++) {
        b = needle;
        break;
      }
    }
  }
  return c;
}

// 20. strtok – разбиение строки на части по указанному разделителю
char *s21_strtok(char *str, const char *delim) {
  static char *start;
  char *step;
  if (str) {
    start = str;
    while (s21_strchr(delim, *start) && *start) {
      *start = 0;
      start++;
    }
  }
  if (*start) {
    step = start;
    while (s21_strchr(delim, *start) == s21_NULL && *start) start++;
    while (s21_strchr(delim, *start) && *start) {
      *start = 0;
      start++;
    }
  } else {
    step = s21_NULL;
  }
  return step;
}

// 21. to_upper - возвращает соответствующий верхнему регистру эквивалент
// символа ch
void *s21_to_upper(const char *str) {
  char *out = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t length = s21_strlen(str);
    out = malloc((length + 1) * sizeof(char));
    char *f_str = (char *)str;
    for (s21_size_t i = 0; i < length; i++) {
      out[i] =
          ((f_str[i] >= 97) && (f_str[i] <= 122)) ? f_str[i] - 32 : f_str[i];
    }
    out[length] = '\0';
  }
  return out;
}

// 22. to_lower - возвращает соответствующий нижнему регистру эквивалент символа
// ch
void *s21_to_lower(const char *str) {
  char *out = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t length = s21_strlen(str);
    out = malloc((length + 1) * sizeof(char));
    char *f_str = (char *)str;
    for (s21_size_t i = 0; i < length; i++) {
      out[i] =
          ((f_str[i] >= 65) && (f_str[i] <= 90)) ? f_str[i] + 32 : f_str[i];
    }
    out[length] = '\0';
  }
  return out;
}

// 23. insert - возвращает новую строку, в которой указанная строка (str)
// вставлена в указанную позицию (start_index) в данной строке (src)
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *out = s21_NULL;
  if ((src != s21_NULL) && (str != s21_NULL)) {
    s21_size_t src_len = s21_strlen(src);
    if (start_index <= src_len) {
      s21_size_t str_len = s21_strlen(str);
      out = malloc((src_len + str_len + 1) * sizeof(char));
      char *f_src = (char *)src;
      char *f_str = (char *)str;
      for (s21_size_t i = 0; i < start_index; i++) {
        out[i] = *(f_src++);
      }
      for (s21_size_t i = start_index; i < start_index + str_len; i++) {
        out[i] = *(f_str++);
      }
      for (s21_size_t i = start_index + str_len; i < str_len + src_len; i++) {
        out[i] = *(f_src++);
      }
      out[src_len + str_len] = '\0';
    }
  }
  return out;
}

// определение максимальной длины участка строки, содержащего только
// указанные символы с конца
s21_size_t s21_str_back_spn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  for (int i = s21_strlen(str1) - 1; i >= 0 && s21_strchr(str2, str1[i]);
       i--, res++) {
  }
  return res;
}

// 24. trim - возвращает новую строку, в которой удаляются все начальные и
// конечные вхождения набора заданных символов (trim_chars) из данной строки
// (src)
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src) {
    if (trim_chars == s21_NULL) {
      trim_chars = "";
    }
    s21_size_t trim_start_len = s21_strspn(src, trim_chars);
    s21_size_t trim_end_len =
        s21_str_back_spn(src + trim_start_len, trim_chars);
    res = calloc(s21_strlen(src) + 1, sizeof(char));
    s21_memcpy(res, src + trim_start_len,
               s21_strlen(src) - trim_start_len - trim_end_len);
  }
  return res;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  parsing pars;
  int len_add = 0;
  char *str_add;
  str_add = (char *)malloc(1024 * sizeof(char));
  int length = 0;
  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      pars.special_letter = 0;
      pars.minus = 0;
      pars.plus = 0;
      pars.space = 0;
      pars.width = 0;
      pars.point = 0;
      pars.precision = 0;
      pars.length_mod = 0;
      pars.grid = 0;
      pars.zero = 0;
      pars.star = 0;
      format++;
      int flag = 1;
      for (int i = 0; i < 1024; i++) str_add[i] = '\0';
      len_add = 0;
      while (flag) {
        if (*format == ' ' && pars.plus == 0) pars.space = 1;
        if (*format == '0' && pars.width == 0 && pars.point == 0) pars.zero = 1;
        if (*format == '+') {
          pars.plus = 1;
          pars.space = 0;
        }
        if (*format == '#') pars.grid = 1;
        if (*format == '.') {
          pars.point = 1;
          format++;
          if (*format == '*') {
            pars.precision = va_arg(args, int);
            format++;
            continue;
          } else {
            int len = 0;
            pars.precision = form_number(format, &len);
            format = format + len;
            continue;
          }
        }
        if (*format == '*') {
          pars.star = 1;
          pars.width = va_arg(args, int);
          if ((pars.width < 0)) {
            pars.width = (-1) * pars.width;
            pars.minus = 1;
            pars.zero = 0;
          }
        }
        if (def_number(*format)) {
          if (pars.star == 1) {
            pars.width = 0;
            continue;
          } else {
            int len = 0;
            pars.width = form_number(format, &len);
            format = format + len;
            continue;
          }
        }
        if (length_mod(*format)) pars.length_mod = *format;
        if (*format == '-') {
          pars.minus = 1;
          pars.zero = 0;
        }
        if (specifiers(*format)) {
          pars.special_letter = *format;
          flag = 0;
        }
        format++;
      }
      calling_function(pars, args, &len_add, str_add, length);
      s21_memmove(str + length, str_add, len_add);
      length += len_add;
    } else {
      *(str + length) = *format;
      length++;
      format++;
      continue;
    }
  }
  *(str + length) = '\0';
  va_end(args);
  free(str_add);
  return length;
}

int form_number(const char *str, int *len) {
  int factor = 0;
  const char *tmp = str;
  int len1 = 0;
  while (def_number(*tmp)) {
    factor = (factor * 10) + (*tmp) - 48;
    tmp++;
    len1++;
  }
  *len = len1;
  return factor;
}

int def_number(char c) {
  int result = 0;
  if (c >= '0' && c <= '9') result = 1;
  return result;
}

int length_mod(char c) {
  int result = 0;
  if (c == 'h' || c == 'l' || c == 'L') result = 1;
  return result;
}

int specifiers(char c) {
  int result = 0;
  const int code[16] = {37,  69,  71,  88,  99,  100, 101, 102,
                        103, 105, 110, 111, 112, 115, 117, 120};
  for (int i = 0; i < 16; i++) {
    if (c == code[i]) result = code[i];
  }
  return result;
}

void calling_function(parsing pars, va_list args, int *len_buf, char *str_add,
                      int length) {
  long double number = 0.0;
  int from_g_grid = 0;
  switch (pars.special_letter) {
    case 'c':
      c_or_percent_func(pars, args, len_buf, str_add);
      break;
    case 'd':
      d_or_i_func(pars, args, len_buf, str_add);
      break;
    case 'i':
      d_or_i_func(pars, args, len_buf, str_add);
      break;
    case 'f':
      number = (long double)va_arg(args, double);
      f_func(pars, len_buf, str_add, number, from_g_grid);
      break;
    case 's':
      s_func(pars, args, len_buf, str_add);
      break;
    case 'u':
      u_func(pars, args, len_buf, str_add);
      break;
    case '%':
      c_or_percent_func(pars, args, len_buf, str_add);
      break;
    case 'g':
      number = (long double)va_arg(args, double);
      g_or_G_func(pars, len_buf, str_add, number);
      break;
    case 'G':
      number = (long double)va_arg(args, double);
      g_or_G_func(pars, len_buf, str_add, number);
      break;
    case 'e':
      number = (long double)va_arg(args, double);
      e_or_E_func(pars, len_buf, str_add, number, from_g_grid);
      break;
    case 'E':
      number = (long double)va_arg(args, double);
      e_or_E_func(pars, len_buf, str_add, number, from_g_grid);
      break;
    case 'x':
      x_or_X_func(pars, args, len_buf, str_add);
      break;
    case 'X':
      x_or_X_func(pars, args, len_buf, str_add);
      break;
    case 'o':
      o_func(pars, args, len_buf, str_add);
      break;
    case 'n':
      n_func(args, length);
      break;
    case 'p':
      p_func(pars, args, len_buf, str_add);
      break;
  }
}

void c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str) {
  char c;
  if (pars.special_letter == '%') {
    c = '%';
  } else {
    c = va_arg(args, int);
  }
  if (pars.width == 0) pars.width = 1;
  if (pars.minus) {
    str[0] = c;
    for (int i = 1; i < pars.width; i++) str[i] = ' ';
    str[pars.width] = '\0';
  } else {
    if (pars.zero) {
      for (int i = 0; i < pars.width - 1; i++) str[i] = '0';
    } else {
      for (int i = 0; i < pars.width - 1; i++) str[i] = ' ';
    }
    str[pars.width - 1] = c;
    str[pars.width] = '\0';
  }
  if (pars.width) {
    *len_buf = pars.width;
  } else {
    *len_buf = 1;
  }
}

void d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {
  if (pars.point && pars.precision >= 0) pars.zero = 0;
  long int number = va_arg(args, long int);
  if (pars.length_mod == 0) {
    number = (int)number;
  } else if (pars.length_mod == 'h') {
    number = (short int)number;
  }
  char sign = sign_func_whole(&number, &pars.plus, &pars.space);
  int i = form_number_d(pars, number, str);
  int len = consider_precision_d(pars, i, sign, str, &pars.precision);
  format_d(pars, len, str, sign, len_buf);
}

char sign_func_whole(long int *number, int *plus, int *space) {
  char c;
  if (*number < 0) {
    *number = -*number;
    c = '-';
    *plus = 1;
    *space = 0;
  } else {
    c = '+';
  }
  return c;
}

int form_number_d(parsing pars, long int number, char *str) {
  int i = 0;
  int buff[1024];
  if (number) {
    while (number) {
      buff[i] = labs(number % 10);
      number = number / 10;
      i++;
    }
  } else {
    if (pars.precision < 0 || pars.point == 0) {
      buff[i] = 0;
      i++;
    }
  }
  for (int j = 0; j < i; j++) {
    str[j] = buff[i - j - 1] + 48;
  }
  str[i] = '\0';
  return i;
}

int consider_precision_d(parsing pars, int i, char sign, char *str,
                         int *precision) {
  if (pars.precision > i) {
    s21_memmove(str + pars.precision - i, str, i);
    for (int j = 0; j < pars.precision - i; j++) str[j] = '0';
  } else {
    *precision = i;
    pars.precision = i;
  }
  int len;
  if (pars.plus || pars.space) {
    len = pars.precision + 1;
  } else {
    len = pars.precision;
  }
  if (pars.plus) {
    s21_memmove(str + 1, str, pars.precision);
    str[0] = sign;
    str[pars.precision + 1] = '\0';
  } else {
    if (pars.space) {
      s21_memmove(str + 1, str, pars.precision);
      str[0] = ' ';
      str[pars.precision + 1] = '\0';
    } else {
      str[pars.precision] = '\0';
    }
  }
  return len;
}

void format_d(parsing pars, int len, char *str, char sign, int *len_buf) {
  if (pars.width > len) {
    if (!pars.minus) {
      s21_memmove(str + pars.width - len, str, len);
      if (pars.zero) {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = '0';
        if (pars.plus) {
          str[0] = sign;
        } else if (pars.space) {
          str[0] = ' ';
        }
      } else {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = ' ';
        if (pars.plus) {
          str[pars.width - pars.precision - 1] = sign;
        }
      }
    } else {
      for (int j = len; j < pars.width; j++) {
        str[j] = ' ';
      }
      str[pars.width] = '\0';
    }
    *len_buf = pars.width;
  } else {
    *len_buf = len;
  }
}

void f_func(parsing pars, int *len_buf, char *str, long double number,
            int from_g_grid) {
  if (number == INFINITY || number == -INFINITY || number != number) {
    if (number == INFINITY) {
      s21_strcpy(str, "inf");
    } else if (number == -INFINITY) {
      s21_strcpy(str, "-inf");
    } else if (number != number) {
      s21_strcpy(str, "nan");
    }
    *len_buf = s21_strlen(str);
  } else {
    char sign = sign_func_subst(&number, &pars.plus, &pars.space);
    if (!pars.point && pars.precision <= 0) pars.precision = 6;
    int *buff = (int *)malloc(1024 * sizeof(int));
    int whole = whole_part(number, buff);
    fraction_part(pars.precision, number, buff, whole);
    int *buff1 = (int *)malloc(1024 * sizeof(int));
    round_number(buff, whole + pars.precision, buff1, &whole);
    int len = str_form(pars, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_grid);
    int len1 = *len_buf;
    format_f(pars, len1, len, sign, str, len_buf);
    free(buff);
    free(buff1);
  }
}

char sign_func_subst(long double *number, int *plus, int *space) {
  char c;
  if (*number < 0) {
    *number = -*number;
    c = '-';
    *plus = 1;
    *space = 0;
  } else {
    c = '+';
  }
  return c;
}

int whole_part(long double number, int *buff) {
  long double buf;
  modfl(number, &buf);
  long int buf1 = (long int)buf;
  int buff1[1024], i = 0;
  if (buf1) {
    while (buf1) {
      buff1[i] = buf1 % 10;
      buf1 = buf1 / 10;
      i++;
    }
  } else {
    buff1[i] = 0;
    i++;
  }
  for (int j = 0; j < i; j++) buff[j] = buff1[i - j - 1];
  return i;
}

void fraction_part(int shortage, long double number, int *buff, int whole) {
  long double buf, ost = modfl(number, &buf);
  for (int j = 0; j <= shortage; j++) {
    ost = ost * 10.0;
    ost = modfl(ost, &buf);
    buff[whole + j] = (int)buf;
  }
}

void round_number(int *buff, int len, int *buff1, int *whole) {
  int i = len;
  if (buff[len] >= 5) {
    int flag = 1;
    while (flag) {
      i--;
      if (i == -1) flag = 0;
      buff[i]++;
      if (buff[i] > 9 && i != 0) {
        buff[i] = 0;
        continue;
      } else {
        flag = 0;
      }
    }
  }
  if (buff[0] > 9) {
    buff1[0] = 1;
    buff1[1] = 0;
    for (int j = 1; j < len; j++) buff1[j + 1] = buff[j];
    *whole += 1;
  } else {
    for (int j = 0; j < len; j++) buff1[j] = buff[j];
  }
}

int str_form(parsing pars, const int *buff1, int whole, char c, char *str,
             int *len_str) {
  for (int j = 0; j < whole; j++) str[j] = buff1[j] + 48;
  if (pars.precision == 0 && pars.grid == 0) {
    str[whole] = '\0';
    *len_str = whole;
  } else {
    str[whole] = '.';
    for (int j = 0; j < pars.precision; j++) {
      str[whole + 1 + j] = buff1[whole + j] + 48;
    }
    str[whole + pars.precision + 1] = '\0';
    *len_str = whole + pars.precision + 1;
  }
  int len = *len_str;
  if (pars.plus) {
    s21_memmove(str + 1, str, *len_str);
    str[0] = c;
    str[*len_str + 1] = '\0';
    *len_str += 1;
  } else {
    if (pars.space) {
      s21_memmove(str + 1, str, *len_str);
      str[0] = ' ';
      str[*len_str + 1] = '\0';
      *len_str += 1;
    }
  }
  return len;
}

char consider_g(char *str, int *len_str, int *len, int from_g_grid) {
  int count = 0;
  while (*str != '\0' && *str != '.') {
    str++;
    count++;
  }
  if (*str == '\0') {
    str = str - count;
  } else {
    str -= count;
    if ((from_g_grid == 1)) {
      while (str[*len_str - 1] == 48) {
        str[*len_str - 1] = '\0';
        *len_str -= 1;
        *len -= 1;
      }
      if (str[*len_str - 1] == '.') {
        str[*len_str - 1] = '\0';
        *len_str -= 1;
        *len -= 1;
      }
    }
  }
  return *str;
}

void format_f(parsing pars, int len1, int len, char c, char *str,
              int *len_buf) {
  if (pars.width > len) {
    if (!pars.minus) {
      s21_memmove(str + pars.width - len1, str, len1);
      if (pars.zero) {
        for (int j = 0; j < pars.width - len; j++) str[j] = '0';
        if (pars.plus) {
          str[0] = c;
        } else if (pars.space) {
          str[0] = ' ';
        }
      } else {
        for (int j = 0; j < pars.width - len; j++) str[j] = ' ';
        if (pars.plus) {
          str[pars.width - len - 1] = c;
        }
      }
    } else {
      for (int j = len1; j < pars.width; j++) {
        str[j] = ' ';
      }
    }
    *len_buf = pars.width;
    str[pars.width] = '\0';
  } else {
    *len_buf = len1;
  }
}

void s_func(parsing pars, va_list args, int *len_buf, char *str) {
  if (pars.length_mod == 0) {
    char *src;
    src = va_arg(args, char *);
    s21_strcat(str, src);
  }
  if (pars.precision >= (int)s21_strlen(str) ||
      (pars.precision == 0 && pars.point == 0) || pars.precision < 0)
    pars.precision = (int)s21_strlen(str);
  str[pars.precision] = '\0';
  if (pars.width > pars.precision) {
    if (!pars.minus) {
      s21_memmove(str + pars.width - pars.precision, str, pars.precision);
      if (pars.zero) {
        for (int i = 0; i < pars.width - pars.precision; i++) str[i] = '0';
      } else {
        for (int i = 0; i < pars.width - pars.precision; i++) str[i] = ' ';
      }
    } else {
      for (int i = pars.precision; i < pars.width; i++) str[i] = ' ';
    }
    str[pars.width] = '\0';
    *len_buf = pars.width;
  } else {
    *len_buf = pars.precision;
  }
}

void u_func(parsing pars, va_list args, int *len_buf, char *str) {
  if (pars.point && pars.precision >= 0) {
    pars.zero = 0;
  }
  long unsigned int number = va_arg(args, long unsigned int);
  if (pars.length_mod == 0) {
    number = (unsigned int)number;
  } else if (pars.length_mod == 'h') {
    number = (short unsigned int)number;
  }
  long unsigned int buf = number;
  int i = 0;
  int buff[1024];
  if (buf) {
    while (buf) {
      buff[i] = buf % 10;
      buf = buf / 10;
      i++;
    }
  } else {
    if (pars.precision != 0 || pars.point == 0) {
      buff[i] = 0;
      i++;
    }
  }
  for (int j = 0; j < i; j++) {
    str[j] = buff[i - j - 1] + 48;
  }
  str[i] = '\0';
  if (pars.precision > i) {
    s21_memmove(str + pars.precision - i, str, i);
    for (int j = 0; j < pars.precision - i; j++) {
      str[j] = '0';
    }
  } else {
    pars.precision = i;
  }
  int len = pars.precision;
  str[pars.precision] = '\0';
  if (pars.width > len) {
    if (!pars.minus) {
      s21_memmove(str + pars.width - len, str, len);
      if (pars.zero) {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = '0';
      } else {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = ' ';
      }
    } else {
      for (int j = len; j < pars.width; j++) {
        str[j] = ' ';
      }
      str[pars.width] = '\0';
    }
    *len_buf = pars.width;
  } else {
    *len_buf = len;
  }
}

void g_or_G_func(parsing pars, int *len_buf, char *str, long double number) {
  int len_e = 0;
  char *str_e = s21_NULL;
  str_e = (char *)malloc(1024 * sizeof(char));
  if (pars.special_letter == 'g') {
    pars.special_letter = 'e';
  } else {
    pars.special_letter = 'E';
  }
  if (pars.point && pars.precision == 0) pars.precision = 1;
  if (!pars.point) pars.precision = 6;
  int power = e_or_E_func(pars, &len_e, str_e, number, pars.grid + 1);
  if (power >= -4 && pars.precision > power) {
    pars.precision -= (power + 1);
    f_func(pars, &len_e, str_e, number, pars.grid + 1);
    *len_buf = len_e;
    s21_strcat(str, str_e);
  } else {
    pars.precision -= 1;
    e_or_E_func(pars, &len_e, str_e, number, pars.grid + 1);
    *len_buf = len_e;
    s21_strcat(str, str_e);
  }
  free(str_e);
}

int e_or_E_func(parsing pars, int *len_buf, char *str, long double number,
                int from_g_grid) {
  int power = 0, whole, len;
  if (number == INFINITY || number == -INFINITY || number != number) {
    if (number == INFINITY) {
      s21_strcpy(str, "inf");
    } else if (number == -INFINITY) {
      s21_strcpy(str, "-inf");
    } else if (number != number) {
      s21_strcpy(str, "nan");
    }
    *len_buf = s21_strlen(str);
  } else {
    long double const_zero = pow(10, -50);
    *len_buf = 0;
    char e = pars.special_letter,
         sign = sign_func_subst(&number, &pars.plus, &pars.space);
    if (!pars.point && pars.precision <= 0) pars.precision = 6;
    long double buf_number = number;
    static int buff1[1024] = {0};
    static int buff[1024] = {0};
    if (number < const_zero) {
      power = 0;
      whole = 1;
      for (int i = 0; i < whole + pars.precision; i++) {
        buff[i] = 0;
      }
    } else {
      while (buf_number > 10) {
        buf_number = buf_number / 10;
        power++;
      }
      while (buf_number < 1) {
        buf_number = buf_number * 10;
        power--;
      }
      number = buf_number;
      whole = whole_part(number, buff);
      fraction_part(pars.precision, number, buff, whole);
      round_number(buff, whole + pars.precision, buff1, &whole);
      if (whole == 2) {
        number = number / 10;
        power++;
      }
      whole = whole_part(number, buff);
      fraction_part(pars.precision, number, buff, whole);
    }
    len = str_form(pars, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_grid);
    int len1 = form_power(power, e, str, len_buf);
    len += 4;
    format_f(pars, len1, len, sign, str, len_buf);
  }
  return power;
}

int form_power(int power, char e, char *str, int *len_buf) {
  char sign;
  if (power >= 0) {
    sign = '+';
  } else {
    power = power * (-1);
    sign = '-';
  }
  int pow[2];
  if (power >= 10) {
    int i = 0;
    while (i != 2) {
      pow[1 - i] = power % 10;
      power = power / 10;
      i++;
    }
  } else {
    pow[0] = 0;
    pow[1] = power;
  }
  str[*len_buf] = e;
  str[*len_buf + 1] = sign;
  str[*len_buf + 2] = pow[0] + 48;
  str[*len_buf + 3] = pow[1] + 48;
  str[*len_buf + 4] = '\0';
  *len_buf = *len_buf + 4;
  return *len_buf;
}

int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str) {
  long unsigned number = va_arg(args, long unsigned);
  if (pars.length_mod == 0) {
    number = (unsigned int)number;
  } else if (pars.length_mod == 'h') {
    number = (short unsigned int)number;
  }
  static char data[1024] = {0};
  int index = convert(pars, number, 16, data, pars.special_letter);
  for (int i = index; i >= 0; i--) str[index - i] = data[i];
  str[index + 1] = '\0';
  int i = index + 1;
  if (pars.point != 0 && pars.precision >= 0) {
    pars.zero = 0;
  }
  if (number == 0) {
    if (pars.point == 0) {
      str[0] = '0';
      str[1] = '\0';
      i = 1;
    }
    pars.grid = 0;
  }
  int len = consider_precision_x(pars, i, &pars.precision, str);
  format_x(pars, len, str, len_buf);
  return *len_buf;
}

int convert(parsing pars, long unsigned num, long unsigned divider, char *data,
            char spec) {
  int index = 0;
  if (num) {
    while (num) {
      long unsigned rem;
      char ch;
      rem = num % divider;
      num = num / divider;
      if ((spec == 'x') || (spec == 'o')) {
        ch = convert_small_letters(rem);
      }
      if (spec == 'X') {
        ch = convert_big_letters(rem);
      }
      data[index] = ch;
      index++;
    }
  } else {
    if (!pars.precision) {
      data[index] = '0';
      index++;
    }
    if (pars.point == 1 && pars.precision == 0 && pars.grid != 1)
      data[index - 1] = '\0';
    if (pars.precision == 0 && pars.grid != 1) data[index] = '\0';
    if (pars.point == 1 && pars.precision == 0 && pars.grid == 1)
      data[index] = '\0';
  }
  return index - 1;
}

char convert_big_letters(int value) {
  char ch;
  if (value >= 0 && value < 10) {
    ch = value + 48;
  } else {
    ch = value + 55;
  }
  return ch;
}

char convert_small_letters(int value) {
  char ch;
  if (value >= 0 && value < 10) {
    ch = value + 48;
  } else {
    ch = value + 87;
  }
  return ch;
}

int consider_precision_x(parsing pars, int i, int *precision, char *str) {
  if (pars.precision < 0) pars.precision = i;
  if (pars.precision > i) {
    s21_memmove(str + pars.precision - i, str, i);
    for (int j = 0; j < pars.precision - i; j++) {
      str[j] = '0';
    }
  } else if (pars.precision == 0) {
    pars.precision = i;
  } else {
    pars.precision = i;
  }
  int len;
  if (pars.grid) {
    len = pars.precision + 2;
  } else {
    len = pars.precision;
  }
  if (pars.grid) {
    s21_memmove(str + 2, str, pars.precision);
    str[0] = '0';
    str[1] = pars.special_letter;
    str[pars.precision + 2] = '\0';
  } else {
    str[pars.precision] = '\0';
  }
  *precision = pars.precision;
  return len;
}

void format_x(parsing pars, int len, char *str, int *len_buf) {
  if (pars.width > len) {
    if (!pars.minus) {
      s21_memmove(str + pars.width - len, str, len);
      if (pars.zero) {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = '0';
        if (pars.grid) {
          str[0] = '0';
          str[1] = pars.special_letter;
        }
      } else {
        for (int j = 0; j < pars.width - pars.precision; j++) str[j] = ' ';

        if (pars.grid) {
          str[pars.width - pars.precision - 1] = pars.special_letter;
          str[pars.width - pars.precision - 2] = '0';
        }
      }
    } else {
      for (int j = len; j < pars.width; j++) {
        str[j] = ' ';
      }
      str[pars.width] = '\0';
    }
    *len_buf = pars.width;
  } else {
    *len_buf = len;
  }
}

int o_func(parsing pars, va_list args, int *len_buf, char *str) {
  long unsigned number = va_arg(args, long unsigned);
  if (pars.length_mod == 0) {
    number = (unsigned int)number;
  } else if (pars.length_mod == 'h') {
    number = (short unsigned int)number;
  }
  char *data = (char *)malloc(1024 * sizeof(char));
  int index = convert(pars, number, 8, data, pars.special_letter);
  for (int i = index; i >= 0; i--) str[index - i] = data[i];
  str[index + 1] = '\0';
  int i = index + 1;
  if (pars.point) pars.zero = 0;
  if (pars.precision < 0) pars.precision = i;
  if (pars.grid && number != 0) {
    s21_memmove(str + 1, str, i);
    str[0] = '0';
    i++;
    str[i] = '\0';
  } else {
    str[i] = '\0';
  }
  if (pars.precision > i) {
    s21_memmove(str + pars.precision - i, str, i);
    for (int j = 0; j < pars.precision - i; j++) {
      str[j] = '0';
    }
  } else {
    pars.precision = i;
  }
  pars.plus = 0;
  pars.space = 0;
  format_d(pars, pars.precision, str, '+', len_buf);
  free(data);
  return *len_buf;
}

void n_func(va_list args, int length) {
  int *number = va_arg(args, int *);
  *number = length;
}

void p_func(parsing pars, va_list args, int *len_buf, char *str) {
  unsigned long num = va_arg(args, unsigned long);
  if ((void *)num != s21_NULL) {
    static char data[1024] = {0};
    static char reverse[1024] = {0};
    static char src[1024] = {0};
    static char tmp[1024] = {0};
    int index = convert(pars, num, 16, data, 'x');
    for (int i = index; i >= 0; i--) reverse[index - i] = data[i];
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    src[2] = '\0';
    if (pars.precision > (int)s21_strlen(reverse)) {
      int size_p = 0;
      size_p = pars.precision - (int)s21_strlen(reverse);
      for (int q = 0; q < size_p; q++) {
        src[q + 2] = '0';
      }
    }
    s21_strcat(src, reverse);
    if (pars.width) {
      int size = 0;
      if (pars.width > (int)s21_strlen(src)) {
        size = pars.width - (int)s21_strlen(src);
      }
      if (pars.minus) {
        for (int i = 0; i < (int)s21_strlen(src); i++) {
          str[i] = src[i];
        }
        for (int j = (int)s21_strlen(src); j < pars.width; j++) {
          str[j] = ' ';
        }
      } else {
        for (int i = 0; i < (int)s21_strlen(src); i++) {
          tmp[i] = src[i];
        }
        for (int i = 0; i < size; i++) {
          str[i] = ' ';
        }
        index = 0;
        for (int i = size; i < size + (int)s21_strlen(tmp); i++) {
          str[i] = tmp[index];
          index++;
        }
      }
    } else {
      for (int i = 0; i < (int)s21_strlen(src); i++) {
        str[i] = src[i];
      }
    }
  } else {
#ifdef __APPLE__
    str[0] = '0';
    str[1] = 'x';
#else
    str[0] = '(';
    str[1] = 'n';
    str[2] = 'i';
    str[3] = 'l';
    str[4] = ')';
    str[5] = '\0';
#endif
  }
  *len_buf = (int)s21_strlen(str);
}

// int main() {
// char ch[100] = {0};
// s21_sprintf(ch, "%d", "asd");
// printf("%s\n", ch);
// // printf("%d", "asd");

//   return 0;
// }
