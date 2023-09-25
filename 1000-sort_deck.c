#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - 2 strings compared
 * @str1: string
 * @str2: string
 * Return: 1 if str1 and str2 are equal, 0 otherwise
 */

int _strcmp(const char *str1, const char *str2)

{
	size_t y = 0;

	if (str1 == NULL)
		return (0);

	while (str1[y] && str2[y] && str1[y] == str2[y])
		y++;

	return (str1[y] == '\0' && str2[y] == '\0');
}

/**
 * get_card_position - return the position based on card you put in
 * @node: card represented
 * Return: card position returned
 */

int get_card_position(const deck_node_t *node)

{
	int value;

	value = node->card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp(node->card->value, "Ace"))
			value = 1;
		else if (_strcmp(node->card->value, "10"))
			value = 10;
		else if (_strcmp(node->card->value, "Jack"))
			value = 11;
		else if (_strcmp(node->card->value, "Queen"))
			value = 12;
		else if (_strcmp(node->card->value, "King"))
			value = 13;
	}
	value += node->card->kind * 13;
	return (value);
}

/**
 * swap_card - swap a card for its previous one
 * @card: card
 * @deck: card deck
 * Return: return a pointer to a card which was used to enter it
 */

deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)

{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck of integers in ascending order
 * @deck: sort deck linked twice
 */

void insertion_sort_deck(deck_node_t **deck)

{
	deck_node_t *node;
	int value_prev, value_current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
		}
		while (node->prev && value_prev > value_current)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
			node = swap_card(node, deck);
		}
		node = node->next;
	}
}

/**
 * sort_deck - sort a deck you put in using insertion sort algorithm
 * @deck: deck
 */

void sort_deck(deck_node_t **deck)

{
	insertion_sort_deck(deck);
}
