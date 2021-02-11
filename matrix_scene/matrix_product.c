#include "minirt.h"

//t_matrix *matrix_product(t_matrix *mat1, t_matrix *mat2)
//{
//
//}

void alloc_matrix_vecs(t_matrix *matrix, t_rt *scene)
{
	if (!(matrix->first = malloc(sizeof(t_vec))))
		errors_and_exit(-1, scene);
	if (!(matrix->second = malloc(sizeof(t_vec))))
		errors_and_exit(-1, scene);
	if (!(matrix->third = malloc(sizeof(t_vec))))
		errors_and_exit(-1, scene);
}

void init_matrix_z(t_rt *scene, t_matrix *mat, t_cos_sin *cs)
{
	mat->first->x = cs->cos_c;
	mat->first->y = cs->sin_c;
	mat->first->z = 0;
	mat->second->x = cs->sin_c;
	mat->second->y = cs->cos_c;
	mat->second->z = 0;
	mat->third->x = 0;
	mat->third->y = 0;
	mat->third->z = 1;
}

void init_matrix_y(t_rt *scene, t_matrix *mat, t_cos_sin *cs)
{
	mat->first->x = cs->cos_c;
	mat->first->y = 0;
	mat->first->z = -1 * cs->sin_c;
	mat->second->x = 0;
	mat->second->y = 1;
	mat->second->z = 0;
	mat->third->x = cs->sin_c;
	mat->third->y = 0;
	mat->third->z = cs->cos_c;
}