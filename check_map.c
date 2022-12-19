/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:37 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/19 15:38:45 by amontalb         ###   ########.fr       */
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

int check_char(char **map, int C, int P, int E)
{
	int i;
	int j;
		
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			if (map[i][j] == 'E')
				E++;
			if (map[i][j] == 'P')
				P++;
			if (map[i][j] == 'C')
				C++;
			j++;
		}	
		i++;
	}
	if (E != 1 || P != 1 || C < 1)
		return (1);
	return (0);
}

int check_close(char **map, char **argv)
{
	int i;
	int j;
		
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == get_height(argv) - 1) && map[i][j] != '1')
				return (1);
			if ((j == 0 || j == get_width(argv) - 1) && map[i][j] != '1')
				return (1);
			j++;
		}	
		i++;
	}
	return (0);
}

int check_map(char **map)
{




	
}