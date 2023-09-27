#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

size_t    ft_strlen(const char *str)
{
    size_t    i;

    i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return (i);
}

static int    stringlen(unsigned long value, int base)
{
    int    len;

    len = 0;
    if (value == 0)
        return (1);
    while (value)
    {
        value = value / base;
        len++;
    }
    return (len);
}

char    *ft_itoa_base(unsigned long value, int base)
{
    static char        dict[] = "0123456789abcdef";
    char            *result;
    int                len;

    if (base < 2 || base > 16)
        return (NULL);
    len = stringlen(value, base);
    result = (char *)malloc(sizeof(char) * len + 1);
    if (!result)
        return (NULL);
    if (value == 0)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else
    {
        result[len] = '\0';
        while (len--)
        {
            result[len] = dict[value % base];
            value = value / base;
        }
    }
    return (result);
}

int    ft_putstr_fd(char *s, int fd)
{
    int    length;
    int    written;

    if (!s)
        s = "(null)";
    length = ft_strlen(s);
    written = write(fd, s, length);
    if (written != length)
        return (-1);
    return (written);
}

int    ft_putptr_fd(void *ptr, int fd)
{
    unsigned long    addr;
    char            *hex_str;
    int                len;

    addr = (unsigned long)ptr;
    hex_str = ft_itoa_base(addr, 16);
    if (!hex_str)
        return (-1);
    ft_putstr_fd("0x", fd);
    ft_putstr_fd(hex_str, fd);
    len = 2 + ft_strlen(hex_str);
    free(hex_str);
    return (len);
}

int main(void)
{
  int n;
  int len;
  
  n = 42;
  len = ft_putptr_fd(&n, 1);
  printf("\n%d\n", len);
  return (0);
}
