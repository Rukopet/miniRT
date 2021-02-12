#include "minirt.h"
#include <stdio.h>

//t_vp				*alloc_viewport(t_rt *scene)
//{
//	t_vp			*ret;
//	double			ratio;
//
//	if(!(ret = malloc(sizeof(t_vp))))
//		errors_and_exit(-1, scene);
//	ret->x = 1;
//	ratio = RES_X / RES_Y;
//	ret->y = 1 / ratio;
//	ret->x_iter = ret->x / RES_X;
//	ret->y_iter = ret->y / RES_Y;
//	return (ret);
//}

void 				do_rtx_calculations(void *limits)
{
	t_limits 		*tmp;
	int				i;
	int 			j;

	tmp = (t_limits*)limits;
	i = tmp->prev_y;
	printf("p_x  - %d\nx   -  %d\np_y  - %d\ny   -   %d\n", tmp->prev_x, tmp->x,
		tmp->prev_y, tmp->y);
	while (++i != tmp->y)
	{
		j = tmp->prev_x;
		while (++j != tmp->x)
		{
			painting_scene(tmp->scene, j, i);
		}
	}
	free(limits);
	limits = NULL;
}

t_matrix 			*matrix_alloc()
{
	t_matrix 		*ret;
	t_rt 			kek;

	if (!(ret = malloc(sizeof(t_matrix))))
		errors_and_exit(-1, &kek);
	return (ret);
}

void				rtx_with_angles(t_rt *scene, t_cam *cam)
{
//	t_vec			*first_dot;
	t_limits 		**limits;
	pthread_t		thread[4];
	int 			i;

	i = -1;
//	first_dot = firs_dot_angles_to_coordinate(scene, cam);
	limits = alloc_limits(scene);
	while (++i != 4)
		pthread_create(&thread[i], NULL, (void*)do_rtx_calculations, (void*)
		limits[i]);
	i = -1;
	while (++i != 4)
		pthread_join(thread[i], NULL);
	free(limits);
	limits = NULL;
//	mlx_loop(scene->d->mlx);
//	init_dots(scene);
//	ns = cp_scene(scene);
}

void 				rtx(t_rt *scene)
{
	static int 		cam;
	static int 		max;

	max = check_max_cams(scene);
	cam = 0;
	matrix_rellocation(scene, cam);
	get_angles_to_data(scene, scene->cam[cam]);
	rtx_with_angles(scene, scene->cam[cam]);

//	rtx_cam_zy(scene, &location, , 3);
//	vp = alloc_viewport(scene);
}
