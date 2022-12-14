/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:46:32 by cbridget          #+#    #+#             */
/*   Updated: 2022/10/15 23:30:28 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coords	vector_subtraction(t_coords *a, t_coords *b)
{
	t_coords	res;

	res.x = a->x - b->x;
	res.y = a->y - b->y;
	res.z = a->z - b->z;
	return (res);
}

t_coords	vector_addition(t_coords *a, t_coords *b)
{
	t_coords	res;

	res.x = a->x + b->x;
	res.y = a->y + b->y;
	res.z = a->z + b->z;
	return (res);
}

t_coords	multiplication_scalar(t_coords *x, float s)
{
	t_coords	res;

	res.x = x->x * s;
	res.y = x->y * s;
	res.z = x->z * s;
	return (res);
}

float	dot_vectors(t_coords *a, t_coords *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_coords	cross_vectors(t_coords *a, t_coords *b)
{
	t_coords	res;

	res.x = (a->y * b->z) - (a->z * b->y);
	res.y = (a->z * b->x) - (a->x * b->z);
	res.z = (a->x * b->y) - (a->y * b->x);
	return (res);
}
