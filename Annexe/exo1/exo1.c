//
// Created by edboutil on 4/13/23.
//

#include "exo1.h"
#include <stdlib.h>
#include <stdio.h>

void	afficherListe(llist liste)
{
	llist *tmp = liste;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int main(void)
{
	llist	*element;
	int i;


}