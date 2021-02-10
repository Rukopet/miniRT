#include "minirt.h"

void 			matrix_use_vec(t_matrix *mat, t_vec **vec)
{
	t_vec 		*tmp;
	t_vec		*new;

	new = *vec;
	tmp = alloc_vector(
			mat->first->x * new->x + mat->first->y * new->x + mat->first->z *
			new->x,
			mat->second->x * new->y + mat->second->y * new->y +
			mat->second->z * new->y,
			mat->third->x * new->z + mat->third->y * new->z + mat->third->z *
					new->z
			);
	free(*vec);
	*vec = tmp;
}