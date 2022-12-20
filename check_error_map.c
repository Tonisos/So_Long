/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data->map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:37 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:40 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// verifier que cest un rectangle
// verifier que cest des murs autour
// verifier chemin valide
// • La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.

// si erreur "Error\n" +message d'erreur expicite"

// Votre carte peut être composée de ces 5 caractères :
// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à collecter (C pour collectible),
// E pour une sortie (E pour exit),
// P pour la position de départ du personnage.

#include "so_long.h"

int check_char(t_data *data, int C, int P, int E)
{
	int i;
	int j;
		
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P')
				return (1);
			if (data->map[i][j] == 'E')
				E++;
			if (data->map[i][j] == 'P')
				P++;
			if (data->map[i][j] == 'C')
				C++;
			j++;
		}	
		i++;
	}
	data->plant = C;
	if (E != 1 || P != 1 || C < 1)
		return (1);
	return (0);
}

int check_close(t_data *data)
{
	int i;
	int j;
		
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((i == 0 || i == data->height - 1) && data->map[i][j] != '1')
				return (1);
			if ((j == 0 || j == data->width - 1) && data->map[i][j] != '1')
				return (1);
			j++;
		}	
		i++;
	}
	return (0);
}

int	check_error_map(t_data *data)
{
	if (check_close(data) || check_char(data, 0, 0, 0))
		return (0);
	return (1);
}