/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:07:51 by marcela           #+#    #+#             */
/*   Updated: 2022/11/03 23:46:29 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_len(uintptr_t num) //tipo que faz com que eu possa trabalhar com o ponteiro como um inteiro
{
    size_t  num;

    num = 0;
    while (num != 0)
    {
        num++;
        num = num / 16; //divido por 16 para achar em hexa
    }
    return (num);
}

void    ft_put_ptr(uintptr_t ptr)
{
    if (ptr >= 16) //se o número for maior que 16 tenho que trabalhar com as casas decimais uma a uma pq hexa vai de 0 a 15
    {
        ft_put_ptr(ptr / 16);
        ft_put_ptr(ptr % 16);
    }
    else 
    {
        if (ptr <= 9) //se for menor que 9 só achar na tabela ascii
            ft_putchar_fd((ptr + 48), 1);
        else //entre 10 e 16 os numeros são representados cono letras 
            ft_putchar_fd((ptr - 10 + 'a'), 1);
    }
}

int ft_print_ptr(unsigned long long ptr)
{
    int lenght;

    lenght += write(1, "0x", 2); //????????
    if (ptr == 0)
        lenght += write(1, "0", 1);
    else
    {
        ft_put_ptr(ptr);
        lenght += ft_len_ptr(ptr);
    } 
    return (lenght);
}