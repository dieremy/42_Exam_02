#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putstr(char *s)
{
    int i;

    i = 0;
    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (s[i])
        write(1, &s[i++], 1);
    return (i);
}

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putnbr(int n)
{
    int     len;

    len = 0;
    if (n == -2147483648)
    {
        len += write(1, "-2", 2);
        n = 147483648;
    }
    if (n < 0)
    {
        n = -n;
        len += ft_putchar('-');
    }
    if (n > 9)
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    else
        len += ft_putchar(n + 48);
    return (len);
}

int ft_hex(unsigned int n)
{
    int len;

    len = 0;
    if (n > 15)
    {
        len += ft_hex(n / 16);
        len += ft_hex(n % 16);
    }
    else
    {
        if (n < 10)
            len += ft_putchar(n + 48);
        else
            len += ft_putchar((n - 10) + 'a');
    }
    return (len);
}

int ft_printf(char const *ptr, ...)
{
    int i;
    int out;
    va_list p;

    i = 0;
    out = 0;
    va_start(p, ptr);
    while (ptr[i])
    {
        if ((ptr[i] == '%') && (ptr[i + 1]))
        {
            i++;
            if (ptr[i] == 's')
                out += ft_putstr(va_arg(p, char *));
            else if (ptr[i] == 'd')
                out += ft_putnbr(va_arg(p, int));
            else if (ptr[i] == 'x')
                out += ft_hex(va_arg(p, unsigned int)); 
        }
        else
            out += write(1, &ptr[i], 1);
        i++;
    }
    va_end(p);
    return (out);
}

int main()
{
    int n = -2147483648;
    ft_printf("%s\n", "how you doing");
    ft_printf("%d\n", n);
    ft_printf("%x\n", 54325234);
    printf("%x\n", 54325234);
}
