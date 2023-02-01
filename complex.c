#include <math.h>
#include <stdbool.h>

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
    return (sqrt(pow(c.real) + pow(c.imag)));
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

size_t  iterations;
size_t  max_iterations;

x = 0;
while (x < "width of window")
{
    y = 0;
    while (y < "height of window")
    {
        zk = 0;
        c = create_complex_from_int(x, y);
        while (iterations < max_iterations)
        {
            zk = calculate_zk_plus_one(zk, c);
            if (is_diverged(zk_plus_one))
            {
                draw_pixel(x, y, iterations, max_iterations);
                break ;
            }
            iterations++;
        }
        y++;
    }
    x++;
}