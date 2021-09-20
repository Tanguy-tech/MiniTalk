/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:54:36 by Tanguy            #+#    #+#             */
/*   Updated: 2021/09/20 10:09:55 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
# include "./libft/libft.h"

typedef struct	s_content
{
	char		c;
	size_t		size;
}				t_content;

#endif