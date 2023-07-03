#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  for (int i = 0; str[i] != '\0'; i++) count++;
  return count;
}

void *s21_memset(void *str, int c, size_t n) {
  char *dest = str;

  for (s21_size_t i = 0; i < n; i++) dest[i] = c;

  return dest;
}

void *s21_memchr(const void *str, int c, size_t n) {
  const unsigned char *s = str;
  char *result = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == (unsigned char)c) {
      result = (char *)(s + i);
      break;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *memcmpStr1 = (const unsigned char *)str1;
  const unsigned char *memcmpStr2 = (const unsigned char *)str2;
  int flag = 0;
  s21_size_t i = 0;
  while (i < n && flag == 0) {
    if (memcmpStr1[i] != memcmpStr2[i]) {
      flag = memcmpStr1[i] - memcmpStr2[i];
    }
    i++;
  }
  return flag;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *ptr = dest;
  const char *s = src;

  while (n-- > 0) *ptr++ = *s++;

  return dest;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
  if (dest < src) {
    char *ptr = (char *)dest;
    const char *s = (char *)src;

    while (n-- > 0) *ptr++ = *s++;
  } else {
    char *ptr = (char *)dest + n;
    const char *s = (char *)src;

    while (n-- > 0) *ptr++ = *s++;
  }

  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t dest_size = s21_strlen(dest);

  for (s21_size_t src_pos = 0; src[src_pos] != '\0'; ++dest_size, ++src_pos) {
    dest[dest_size] = src[src_pos];
  }

  dest[dest_size] = '\0';

  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_size = s21_strlen(dest);

  for (s21_size_t src_pos = 0; src[src_pos] != '\0' && (src_pos + 1 <= n);
       ++dest_size, ++src_pos) {
    dest[dest_size] = src[src_pos];
  }

  dest[dest_size] = '\0';

  return dest;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  char *res = s21_NULL;
  for (; str[i] && str[i] != c; i++) {
  }
  if (c != str[i]) {
    res = s21_NULL;
  } else {
    res = (char *)str + i;
  }
  return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int res = 1;
  while (*s1 == *s2) {
    if (*s1 == '\0') {
      res = 0;
      break;
    }
    ++s1;
    ++s2;
  }
  if (res != 0) {
    res = *s1 - *s2;
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int size = 0;
  unsigned int i = 0;
  int flag = 0;
  while (flag == 0 && i < n) {
    if (str1[i] != str2[i]) {
      size = str1[i] - str2[i];
      flag = 1;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
      flag = 1;
    }
    i++;
  }
  return size;
  return 0;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t pos_src = 0;

  for (; src[pos_src] != '\0'; ++pos_src) {
    dest[pos_src] = src[pos_src];
  }

  dest[pos_src] = '\0';

  return dest;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  s21_size_t pos_src = 0;

  for (; src[pos_src] != '\0' && (pos_src < n); ++pos_src) {
    dest[pos_src] = src[pos_src];
  }

  dest[pos_src] = '\0';

  return dest;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == c) {
      res = (char *)str;
    }
  }
  if (res == s21_NULL) {
    res = (char *)str;
  }
  return *res == c ? (char *)res : s21_NULL;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;

  for (s21_size_t i = 0; str1[i] != '\0' && s21_strchr(str2, str1[i]); i++)
    count++;

  return count;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  size_t lenghtNeedle = s21_strlen(needle);
  if (lenghtNeedle == 0) {
    result = (char *)haystack;
  }
  while (*haystack) {
    if (*haystack == *needle &&
        s21_strncmp(haystack, needle, lenghtNeedle) == 0) {
      result = (char *)haystack;
    }
    haystack++;
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = s21_strlen(str1);

  for (s21_size_t j = 0; j < s21_strlen(str1); ++j) {
    for (s21_size_t i = 0; i < s21_strlen(str2); ++i) {
      if (str1[j] == str2[i] && (j < result)) result = j;
    }
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;
  if (str == s21_NULL) {
    str = last_token;
  }

  if (*str == '\0') {
    last_token = s21_NULL;
    return s21_NULL;
  }
  while (*str && s21_strchr(delim, *str)) {
    str++;
    if (*str == '\0') {
      last_token = str;
      return s21_NULL;
    }
  }
  char *token = str;
  while (*str && s21_strchr(delim, *str) == s21_NULL) {
    str++;
    if (*str == '\0') {
      last_token = s21_NULL;
      if (!token[0]) {
        return s21_NULL;
      }
    }
  }
  *str = '\0';
  last_token = str + 1;

  return token;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  static char *result = s21_NULL;

  if (str1) result = (char *)str1;

  if (result) result = result + s21_strcspn(str1, str2);

  return *result != '\0' ? result : s21_NULL;
}

char *s21_strerror(int errnum) {
  char *ERRORS[] = ERR_LIST;
  char *error = s21_NULL;
  static char buf[100];
  if (errnum >= 0 && errnum < N) {
    error = ERRORS[errnum];
  } else {
    if (std == 0) {
      char *undef = "Unknown error ";
      s21_sprintf(buf, "%s%d", undef, errnum);
    } else if (std == 1) {
      char *undef = "Unknown error: ";
      s21_sprintf(buf, "%s%d", undef, errnum);
    }
  }
  return error == s21_NULL ? buf : error;
}
