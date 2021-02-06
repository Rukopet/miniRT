#ifndef VECTORS_H
#define VECTORS_H

t_vec				*vector_deduction(t_vec *first, t_vec *second, int flag);
t_vec				*alloc_vector(double x, double y, double z);
double 				length_vector(t_vec *vec);
int 				norm_vec(t_vec *vec);
double				scalar_product(t_vec *f, t_vec *s, int flag);

#endif
