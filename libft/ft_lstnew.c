/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:22:20 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 12:29:02 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*sol;

	sol = malloc(sizeof(t_list));
	if (!sol)
		return (0);
	sol->content = content;
	sol->next = 0;
	return (sol);
}
