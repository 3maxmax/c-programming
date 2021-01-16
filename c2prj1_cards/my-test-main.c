#include "cards.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  card_t c;
  c.value = 9;
  c.suit = 3;
  char val = value_letter(c);
  char suit = suit_letter(c);
  printf("The value of this card is: %c \n", val);
  printf("The suit of this card is: %c \n", suit);
  print_card(c);

  char val_tag = '0';
  char suit_tag = 'd';
  card_t card = card_from_letters(val_tag, suit_tag);
  printf("The card_t struct for this card is: %d, %d \n", card.value, card.suit);
  
  for (int i = 0; i < 52; i++) {
    card_t my_card = card_from_num(i);
    print_card(my_card);
  }
  return EXIT_SUCCESS;
}
