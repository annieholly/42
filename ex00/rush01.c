/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_github2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 05:41:31 by aho               #+#    #+#             */
/*   Updated: 2017/07/12 06:20:08 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_safe(int array[9][9], int row, int col, int num)
{
	int		i;
	int		j;
	int		start_row;
	int		start_column;

	start_row = (row / 3) * 3;
	start_column = (col / 3) * 3;
	i = 0;
	j = start_column;
	while (i < 9)
	{
		if (array[row][i] == num)
			return (0);
		if (array[i][col] == num)
			return (0);
		if (array[start_row + (i % 3)][start_column + (i / 3)] == num)
			return (0);
		++i;
	}
	return (1);
}

int		fillarray(int array[9][9], int row, int col)
{
	int		i;

	i = 0;
	if (row < 9 && col < 9)
	{
		if (array[row][col] != 0)
		{
			if ((col + 1) < 9)
				return (fillarray(array, row, col + 1));
			else if ((row + 1) < 9)
				return (fillarray(array, row + 1, 0));
			else
				return (1);
		}
		else
		{
			while (i < 9)
			{
				if (is_safe(array, row, col, i + 1))
				{
					array[row][col] = i + 1;
					if ((col + 1) < 9)
					{
						if (fillarray(array, row, col + 1))
							return (1);
						else
							array[row][col] = 0;
					}
					else if ((row + 1) < 9)
					{
						if (fillarray(array, row + 1, 0))
							return (1);
						else
							array[row][col] = 0;
					}
					else
						return (1);
				}
				++i;
			}
		}
		return (0);
	}
	else
	{
		return (1);
	}
}

void	change_to_int_array(int dest[9][9], char **source)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			dest[i - 1][j] = (source[i][j] == '.') ? 0 : source[i][j] - '0';
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		array[9][9];
	int		i;
	int		j;

	i = 0;
	while (argc != 10)
		return (0);
	change_to_int_array(array, argv);
	if (fillarray(array, 0, 0))
	{
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				printf("%d ", array[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	else
		printf("Error\n");
	return (0);
}
