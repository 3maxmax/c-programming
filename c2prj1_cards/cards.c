#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value);
  assert(c.value <= VALUE_ACE);
  assert(SPADES <= c.suit);
  assert(c.suit <= CLUBS); 
}

const char * ranking_to_string(hand_ranking_t r) {
  if (r == 0) {
    return "STRAIGHT_FLUSH";
  }
  else if (r == 1) {
    return "FOUR_OF_A_KIND";
  }
  else if (r == 2) {
    return "FULL_HOUSE";
  }
  else if (r == 3) {
    return "FLUSH";
  }
  else if (r == 4) {
    return "STRAIGHT";
  }
  else if (r == 5) {
    return "THREE_OF_A_KIND";
  }
  else if (r == 6) {
    return "TWO_PAIR";
  }
  else if (r == 7) {
    return "PAIR";
  }
  else if (r == 8) {
    return "NOTHING";
  }
  else {
    printf("That is not a hand \n");
    exit(EXIT_FAILURE);
  }
}

char value_letter(card_t c) {
  char x;
  assert_card_valid(c);
  if (c.value < 10) {
    x = c.value + '0';
      }
  else if (c.value == 10) {
    x = '0';
      }
  else if (c.value == VALUE_JACK) {
    x = 'J';
      }
  else if (c.value == VALUE_QUEEN) {
    x = 'Q';
      }
  else if (c.value == VALUE_KING) {
    x = 'K';
      }
  else if (c.value == VALUE_ACE) {
    x = 'A';
      }
  else {
    x = '0';
  }
  return x;
}

char suit_letter(card_t c) {
  char x;
  assert_card_valid(c);
  if (c.suit == SPADES) {
    x = 's';
  }
  if (c.suit == HEARTS) {
    x = 'h';
  }
  if (c.suit == DIAMONDS) {
    x = 'd';
  }
  if (c.suit == CLUBS) {
    x = 'c';
  }
  return x;
}

void print_card(card_t c){
  assert_card_valid(c);
  char val = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c", val, suit);
  return;
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let <= '9' && value_let > '1') {
    temp.value = (unsigned)value_let - (unsigned)'0';
  }
  else if ( value_let == '0') {
    temp.value = 10;
  }
  else if (value_let == 'J') {
    temp.value = 11;
  }
  else if (value_let == 'Q') {
    temp.value = 12;
  }
  else if (value_let == 'K') {
    temp.value = 13;
  }
  else if (value_let == 'A') {
    temp.value = 14;
  }
  else {
    printf("That's not a valid card value! (first character error) \n");
    exit(EXIT_FAILURE);
  }
  if (suit_let == 's') {
    temp.suit = SPADES;
  }
  else if (suit_let == 'd') {
    temp.suit = DIAMONDS;
  }
  else if (suit_let == 'c') {
    temp.suit = CLUBS;
  }
  else if (suit_let == 'h') {
    temp.suit = HEARTS;
  }
  else {
    printf("That's not a valid suit! (second character error) \n");
    exit(EXIT_FAILURE);
  } 
  return temp;
}

unsigned check_mod_val(unsigned c) {
  if (c % 13 == 0) {
    return 10;
  }
  if (c % 13 == 1) {
    return VALUE_ACE;
  }
  if (c % 13 <= 9 && c % 13 > 1) {
    return c % 13;
  }
  if (c % 13 == 10) {
    return VALUE_JACK;
  }
  if (c % 13 == 11) {
    return VALUE_QUEEN;
  }
  if (c % 13 == 12) {
    return VALUE_KING;
  }
  else {
    printf("This print isn't possible");
    exit(EXIT_SUCCESS);
  }
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = check_mod_val(c);
  if (c / 13 == 1) {
    temp.suit = CLUBS;
  }
  else if (c / 13 == 2) {
    temp.suit = SPADES;
  }
  else if (c / 13 == 3) {
    temp.suit = DIAMONDS;
  }
  else if (c / 13 == 0) {
    temp.suit = HEARTS;
  }
  else {
    printf("That's not a valid number! (Try [0,52))");
    exit(EXIT_FAILURE);
  }
  return temp;
}
