/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_it_now.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:42:27 by nqasem            #+#    #+#             */
/*   Updated: 2024/12/11 09:43:58 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_it_now(char **s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		free(s[n]);
		n++;
	}
	free(s);
}
