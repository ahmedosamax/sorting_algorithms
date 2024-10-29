#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - for comparing of strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the value of a card
 * @card: ptr to card
 *
 * Return: the value of card
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - for sorting card.
 * @deck: ptr
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterr, *inserrtt, *tmmpp;

	for (iterr = (*deck)->next; iterr != NULL; iterr = tmmpp)
	{
		tmmpp = iterr->next;
		inserrtt = iterr->prev;
		while (inserrtt != NULL && inserrtt->card->kind > iterr->card->kind)
		{
			inserrtt->next = iterr->next;
			if (iterr->next != NULL)
				iterr->next->prev = inserrtt;
			iterr->prev = inserrtt->prev;
			iterr->next = inserrtt;
			if (inserrtt->prev != NULL)
				inserrtt->prev->next = iterr;
			else
				*deck = iterr;
			inserrtt->prev = iterr;
			inserrtt = iterr->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - for sorting
 * @deck: ptr
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itterr, *insertt, *tmmpp;

	for (itterr = (*deck)->next; itterr != NULL; itterr = tmmpp)
	{
		tmmpp = itterr->next;
		insertt = itterr->prev;
		while (insertt != NULL &&
		       insertt->card->kind == itterr->card->kind &&
		       get_value(insertt) > get_value(itterr))
		{
			insertt->next = itterr->next;
			if (itterr->next != NULL)
				itterr->next->prev = insertt;
			itterr->prev = insertt->prev;
			itterr->next = insertt;
			if (insertt->prev != NULL)
				insertt->prev->next = itterr;
			else
				*deck = itterr;
			insertt->prev = itterr;
			insertt = itterr->prev;
		}
	}
}

/**
 * sort_deck - for sorting
 * @deck: ptr
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
