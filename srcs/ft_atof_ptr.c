#include "libft.h"

double ft_atof_ptr(char **s)
{
        double a = 0.0;
        int e = 0;
        int c;
		int	minus;

		minus = 1;
		if (**s == ',')
			(*s)++;
		if ((c = **s) != '\0' && (c == '-'))
		{
			minus = -1;
			(*s)++;
		}	
        while ((c = **s) != '\0' && ft_isdigit(**s)) {
                a = a*10.0 + (c - '0');
				(*s)++;
        }
        if (c == '.') {
                while ((c = *(*s)++) != '\0' && ft_isdigit(c)) {
                        a = a*10.0 + (c - '0');
                        e = e-1;
                }
        }
        if (c == 'e' || c == 'E') {
                int sign = 1;
                int i = 0;
                c = *(*s)++;
                if (c == '+')
                        c = *(*s)++;
                else if (c == '-') {
                        c = *(*s)++;
                        sign = -1;
                }
                while (ft_isdigit(c)) {
                        i = i*10 + (c - '0');
                        c = *(*s)++;
                }
                e += i*sign;
        }
        while (e > 0) {
                a *= 10.0;
                e--;
        }
        while (e < 0) {
                a *= 0.1;
                e++;
        }
        return a * minus;
}