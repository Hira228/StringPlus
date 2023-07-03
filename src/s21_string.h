#ifndef S21_STRING_H
#define S21_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef unsigned long s21_size_t;

#define s21_NULL (void *)0
#define SIZE 16
#define MAX_LENTH 256
//#define BUFF_SIZE 1000

#if defined(__linux__)
#define std 0
#define N 133
#define ERR_LIST                                        \
  {"Success",                                           \
   "Operation not permitted",                           \
   "No such file or directory",                         \
   "No such process",                                   \
   "Interrupted system call",                           \
   "Input/output error",                                \
   "No such device or address",                         \
   "Argument list too long",                            \
   "Exec format error",                                 \
   "Bad file descriptor",                               \
   "No child processes",                                \
   "Resource temporarily unavailable",                  \
   "Cannot allocate memory",                            \
   "Permission denied",                                 \
   "Bad address",                                       \
   "Block device required",                             \
   "Device or resource busy",                           \
   "File exists",                                       \
   "Invalid cross-device link",                         \
   "No such device",                                    \
   "Not a directory",                                   \
   "Is a directory",                                    \
   "Invalid argument",                                  \
   "Too many open files in system",                     \
   "Too many open files",                               \
   "Inappropriate ioctl for device",                    \
   "Text file busy",                                    \
   "File too large",                                    \
   "No space left on device",                           \
   "Illegal seek",                                      \
   "Read-only file system",                             \
   "Too many links",                                    \
   "Broken pipe",                                       \
   "Numerical argument out of domain",                  \
   "Numerical result out of range",                     \
   "Resource deadlock avoided",                         \
   "File name too long",                                \
   "No locks available",                                \
   "Function not implemented",                          \
   "Directory not empty",                               \
   "Too many levels of symbolic links",                 \
   "Unknown error 41",                                  \
   "No message of desired type",                        \
   "Identifier removed",                                \
   "Channel number out of range",                       \
   "Level 2 not synchronized",                          \
   "Level 3 halted",                                    \
   "Level 3 reset",                                     \
   "Link number out of range",                          \
   "Protocol driver not attached",                      \
   "No CSI structure available",                        \
   "Level 2 halted",                                    \
   "Invalid exchange",                                  \
   "Invalid request descriptor",                        \
   "Exchange full",                                     \
   "No anode",                                          \
   "Invalid request code",                              \
   "Invalid slot",                                      \
   "Unknown error 58",                                  \
   "Bad font file format",                              \
   "Device not a stream",                               \
   "No data available",                                 \
   "Timer expired",                                     \
   "Out of streams resources",                          \
   "Machine is not on the network",                     \
   "Package not installed",                             \
   "Object is remote",                                  \
   "Link has been severed",                             \
   "Advertise error",                                   \
   "Srmount error",                                     \
   "Communication error on send",                       \
   "Protocol error",                                    \
   "Multihop attempted",                                \
   "RFS specific error",                                \
   "Bad message",                                       \
   "Value too large for defined data type",             \
   "Name not unique on network",                        \
   "File descriptor in bad state",                      \
   "Remote address changed",                            \
   "Can not access a needed shared library",            \
   "Accessing a corrupted shared library",              \
   ".lib section in a.out corrupted",                   \
   "Attempting to link in too many shared libraries",   \
   "Cannot exec a shared library directly",             \
   "Invalid or incomplete multibyte or wide character", \
   "Interrupted system call should be restarted",       \
   "Streams pipe error",                                \
   "Too many users",                                    \
   "Socket operation on non-socket",                    \
   "Destination address required",                      \
   "Message too long",                                  \
   "Protocol wrong type for socket",                    \
   "Protocol not available",                            \
   "Protocol not supported",                            \
   "Socket type not supported",                         \
   "Operation not supported",                           \
   "Protocol family not supported",                     \
   "Address family not supported by protocol",          \
   "Address already in use",                            \
   "Cannot assign requested address",                   \
   "Network is down",                                   \
   "Network is unreachable",                            \
   "Network dropped connection on reset",               \
   "Software caused connection abort",                  \
   "Connection reset by peer",                          \
   "No buffer space available",                         \
   "Transport endpoint is already connected",           \
   "Transport endpoint is not connected",               \
   "Cannot send after transport endpoint shutdown",     \
   "Too many references: cannot splice",                \
   "Connection timed out",                              \
   "Connection refused",                                \
   "Host is down",                                      \
   "No route to host",                                  \
   "Operation already in progress",                     \
   "Operation now in progress",                         \
   "Stale file handle",                                 \
   "Structure needs cleaning",                          \
   "Not a XENIX named type file",                       \
   "No XENIX semaphores available",                     \
   "Is a named type file",                              \
   "Remote I/O error",                                  \
   "Disk quota exceeded",                               \
   "No medium found",                                   \
   "Wrong medium type",                                 \
   "Operation canceled",                                \
   "Required key not available",                        \
   "Key has expired",                                   \
   "Key has been revoked",                              \
   "Key was rejected by service",                       \
   "Owner died",                                        \
   "State not recoverable",                             \
   "Operation not possible due to RF-kill",             \
   "Memory page has hardware error"};

#endif

#if defined(__APPLE__)
#define std 1
#define N 107
#define ERR_LIST                                      \
  {"Undefined error: 0",                              \
   "Operation not permitted",                         \
   "No such file or directory",                       \
   "No such process",                                 \
   "Interrupted system call",                         \
   "Input/output error",                              \
   "Device not configured",                           \
   "Argument list too long",                          \
   "Exec format error",                               \
   "Bad file descriptor",                             \
   "No child processes",                              \
   "Resource deadlock avoided",                       \
   "Cannot allocate memory",                          \
   "Permission denied",                               \
   "Bad address",                                     \
   "Block device required",                           \
   "Resource busy",                                   \
   "File exists",                                     \
   "Cross-device link",                               \
   "Operation not supported by device",               \
   "Not a directory",                                 \
   "Is a directory",                                  \
   "Invalid argument",                                \
   "Too many open files in system",                   \
   "Too many open files",                             \
   "Inappropriate ioctl for device",                  \
   "Text file busy",                                  \
   "File too large",                                  \
   "No space left on device",                         \
   "Illegal seek",                                    \
   "Read-only file system",                           \
   "Too many links",                                  \
   "Broken pipe",                                     \
   "Numerical argument out of domain",                \
   "Result too large",                                \
   "Resource temporarily unavailable",                \
   "Operation now in progress",                       \
   "Operation already in progress",                   \
   "Socket operation on non-socket",                  \
   "Destination address required",                    \
   "Message too long",                                \
   "Protocol wrong type for socket",                  \
   "Protocol not available",                          \
   "Protocol not supported",                          \
   "Socket type not supported",                       \
   "Operation not supported",                         \
   "Protocol family not supported",                   \
   "Address family not supported by protocol family", \
   "Address already in use",                          \
   "Can't assign requested address",                  \
   "Network is down",                                 \
   "Network is unreachable",                          \
   "Network dropped connection on reset",             \
   "Software caused connection abort",                \
   "Connection reset by peer",                        \
   "No buffer space available",                       \
   "Socket is already connected",                     \
   "Socket is not connected",                         \
   "Can\'t send after socket shutdown",               \
   "Too many references: can\'t splice",              \
   "Operation timed out",                             \
   "Connection refused",                              \
   "Too many levels of symbolic links",               \
   "File name too long",                              \
   "Host is down",                                    \
   "No route to host",                                \
   "Directory not empty",                             \
   "Too many processes",                              \
   "Too many users",                                  \
   "Disc quota exceeded",                             \
   "Stale NFS file handle",                           \
   "Too many levels of remote in path",               \
   "RPC struct is bad",                               \
   "RPC version wrong",                               \
   "RPC prog. not avail",                             \
   "Program version wrong",                           \
   "Bad procedure for program",                       \
   "No locks available",                              \
   "Function not implemented",                        \
   "Inappropriate file type or format",               \
   "Authentication error",                            \
   "Need authenticator",                              \
   "Device power is off",                             \
   "Device error",                                    \
   "Value too large to be stored in data type",       \
   "Bad executable (or shared library)",              \
   "Bad CPU type in executable",                      \
   "Shared library version mismatch",                 \
   "Malformed Mach-o file",                           \
   "Operation canceled",                              \
   "Identifier removed",                              \
   "No message of desired type",                      \
   "Illegal byte sequence",                           \
   "Attribute not found",                             \
   "Bad message",                                     \
   "EMULTIHOP (Reserved)",                            \
   "No message available on STREAM",                  \
   "ENOLINK (Reserved)",                              \
   "No STREAM resources",                             \
   "Not a STREAM",                                    \
   "Protocol error",                                  \
   "STREAM ioctl timeout",                            \
   "Operation not supported on socket",               \
   "Policy not found",                                \
   "State not recoverable",                           \
   "Previous owner died",                             \
   "Interface output queue is full"};

#endif

s21_size_t s21_strlen(const char *str);
void *s21_memset(void *str, int c, size_t n);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);
//  sscanf
typedef struct format {
  char with[MAX_LENTH];
  char length;
  char specifer;
  int system;
  int point;
} format;

s21_size_t parcer(format *format, const char *str, s21_size_t *left_variable);

void percent(const char **buffer);
unsigned int char2int(char chr);
int is_valid_octal(const char hex);
int is_valid_hex(const char hex);
int s21_sscanf(const char *buffer, const char *frmt, ...);
void s21_sscanf_signed_integers(const char **buffer, va_list argc,
                                format format);
unsigned long string_to_dec_int(const char *str);
unsigned is_valid_hex_string(const char *hex);
long int signed_int2dec(const char *hex);
unsigned long unsigned_with_system_int2dec(const char *str, format format);
void s21_sscanf_unsigned_integers(const char **buffer, va_list argc,
                                  format format);
void s21_sscanf_symbols_before_n(const char *buffer, const char *copy_buffer,
                                 va_list argc, const char *frmt);

void s21_sscanf_address(const char **buffer, va_list argc, format format);
void s21_sscanf_string(const char **buffer, va_list argc, format format,
                       s21_size_t *separator);
unsigned is_valid_dec_string(const char *hex);
void check_length_signed(long result, format format, va_list argc);
void check_length_unsigned(long result, format format, va_list argc);

void s21_sscanf_char(const char **buffer, va_list argc, format format,
                     s21_size_t *separator);
void s21_sscanf_double(const char **buffer, va_list argc, format format);
long double string_to_double(const char *str);
void check_length_double(long double result, format format, va_list argc);
long double scientific_to_double(char *str);
void check_length_char(wchar_t c, format format, va_list argc);
void read_string_number(const char **buffer, format format, char *px,
                        int *sign);
void check_length_string(wchar_t *c, format format, va_list argc);
void copy_wchar(wchar_t *src, wchar_t *str);
void copy_wchar_char(char *src, const wchar_t *str);
unsigned is_valid_oct_string(const char *oct);

// to_lowerr
void *s21_to_lower(const char *str);
// to upper
void *s21_to_upper(const char *str);
// insert
void *s21_insert(const char *src, const char *str, size_t start_index);

// trim
void *s21_trim(const char *src, const char *trim_chars);

// sprintf

struct buffer {
  char *data;
  size_t size_buff;
  size_t pos_buff;
  size_t pos_buff_digit;
};

struct Flags_format {
  int FLAGS_ZEROPAD;
  int FLAGS_LEFT;
  int FLAGS_PLUS;
  int FLAGS_SPACE;
  int FLAGS_HASH;
  int FLAGS_SIGNED;
  int FLAGS_DOUBLE;
  int FLAGS_UPPER_X;
  int PRECISION;
  int EXPONENTA;
  int FLAGS_UPPER_E;
  int FLAGS_G;
  int FLAG_G_E;
  int FLAG_UPPER_G;
  int FLAG_POINTER;
};

enum type {
  S21_CHAR,
  S21_SHORT,
  S21_INT,
  S21_LONG,
  S21_DLONG,
  S21_FLOAT,
  S21_DOUBLE,
  S21_LDOUBLE,
  S21_UNSIG
};

void ftoa(long double n, int afterpoint, struct buffer *buf, int base,
          struct Flags_format *flags, size_t width);
uintmax_t type_definition_for_int(int s21_len, va_list args,
                                  struct Flags_format *flags);
void itoa(struct buffer *buf, uintmax_t arg, int base,
          struct Flags_format *flags, size_t width, size_t precision);
int s21_sprintf(char *buffer, const char *format, ...);
void buffer_write(struct buffer *buf, char c);
void buffer_write_str(struct buffer *buf, const char *arg, size_t width,
                      struct Flags_format *flags, size_t precision);
void buffer_write_str_wchar(struct buffer *buf, const wchar_t *arg,
                            size_t width, struct Flags_format *flags,
                            size_t precision);
int s21_parsing_format(char *buffer, size_t size, const char *format,
                       va_list args);
void flags_null(struct Flags_format *flags);
int is_digit(int c);
int is_flag(int c);
size_t format_atoz(const char **format);

#endif
