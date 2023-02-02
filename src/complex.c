# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef struct  s_complex
{
    double  real;
    double  imag;
}   t_complex;

t_complex   mul_complex(t_complex c1, t_complex c2)
{
    t_complex result;

    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return (result);
}

t_complex   add_complex(t_complex c1, t_complex c2)
{
    t_complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return (result);
}

double   abs_complex(t_complex c)
{
    return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex   create_complex_from_int(int x, int y)
{
    t_complex   complex;

    complex.real = x;
    complex.imag = y;
    return (complex);
}

t_complex   calculate_zk_plus_one(t_complex zk, t_complex c)
{
    return add_complex(mul_complex(zk, zk), c);
}

bool    is_diverged(t_complex zk_plus_one)
{
    return (abs_complex(zk_plus_one) > 2);
}

void    draw_pixel(int x, int y, size_t iterations, size_t max_iterations)
{
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("iterations: %ld\n", iterations);
}

int main(void)
{
    size_t  iterations = 0;
    size_t  max_iterations = 1000;
    int     x;
    int     y;
    t_complex zk;
    t_complex c;

    x = -1;
    while (x < 1000)
    {
        y = -1;
        while (y < 1000)
        {
            zk.imag = 0;
            zk.real = 0;
            c = create_complex_from_int(x, y);
            while (iterations < max_iterations)
            {
                zk = calculate_zk_plus_one(zk, c);
                if (is_diverged(zk))
                {
                    draw_pixel(x, y, iterations, max_iterations); // not defined yet
                    break ;
                }
                iterations++;
            }
            y++;
        }
        x++;
    }
}
