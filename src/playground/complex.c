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

typedef struct  s_coordinate
{
    int			x;
    int			y;
	double		a;
	double		b;
	double		complex_unit;
}   t_coordinate;

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

t_complex   create_complex_from_int(double x, double y)
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
    return (abs_complex(zk_plus_one) > 2.00);
}

void    draw_pixel(t_coordinate coordinate, size_t iterations, size_t max_iterations)
{
    // printf("x: %d\n", coordinate.x);
    // printf("y: %d\n", coordinate.y);
    printf("%f + %fi\n", coordinate.a, coordinate.b);
    // printf("iterations: %ld\n", iterations);
}

void	set_horizontal(t_coordinate *coordinate)
{
	coordinate->x = 0;
	coordinate->a = (coordinate->x / 500) - 1.00;
}

void	set_vertical(t_coordinate *coordinate)
{
	coordinate->y = 0;
	coordinate->b = (coordinate->y / 100) - 1.00;
}

void	increment_vertical(t_coordinate *coordinate)
{
	coordinate->y++;
	coordinate->b += coordinate->complex_unit;
}

void	increment_horizontal(t_coordinate *coordinate)
{
	coordinate->x++;
	coordinate->a += coordinate->complex_unit;
}

int main(void)
{
    size_t  iterations;
    size_t  max_iterations = 1000;
	t_coordinate	coordinate;
    t_complex		zk;
    t_complex		c;

	set_horizontal(&coordinate);
	coordinate.complex_unit = 0.01;
    // x = -1.00;
    // while (x < 1)
    while (coordinate.x < 100)
    {
        // y = -1.00;
		set_vertical(&coordinate);
        // while (y < 1)
        while (coordinate.y < 100)
        {
            zk.imag = 0;
            zk.real = 0;
            c = create_complex_from_int(coordinate.a, coordinate.b);
			iterations = 0;
            while (iterations < max_iterations)
            {
                zk = calculate_zk_plus_one(zk, c);
                if (is_diverged(zk))
                {
                    draw_pixel(coordinate, iterations, max_iterations); // not defined yet
                    break ;
                }
                iterations++;
            }
            increment_vertical(&coordinate);
        }
		increment_horizontal(&coordinate);
    }
}
