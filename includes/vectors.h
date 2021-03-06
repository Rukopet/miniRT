#ifndef VECTORS_H
#define VECTORS_H

t_vec				*vector_deduction(t_vec *first, t_vec *second, int flag);
t_vec				vec_subt(t_vec vec1, t_vec vec2);
t_vec				*alloc_vector(double x, double y, double z);
double 				length_vector(t_vec *vec);
int 				norm_vec(t_vec *vec);
double				scalar_product(t_vec *f, t_vec *s, int flag);

double				scalar_product_cos(t_vec *vec1, t_vec *vec2, int flag);
double 				scalar_product_self(t_vec *vec);
double				vec_scal(t_vec vec1, t_vec vec2);


t_vec 				*product_vec_and_int(t_vec *vec, double distance, int flag);
t_vec				vec_multi(t_vec vec, double dist);

double				normal_vector(t_vec *vec1, t_vec *vec2);
t_vec				vector_cross(t_vec *vec1, t_vec *vec2);



double 				angle_to_x(double x);
double 				angle_to_y(double y);
double 				angle_to_z(double z);


#endif
