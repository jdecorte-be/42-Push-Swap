/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:17:38 by jdecorte          #+#    #+#             */
/*   Updated: 2022/03/09 15:15:13 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int character)
{
	if (!character)
		return (0);
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
