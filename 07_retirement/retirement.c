#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double monthly (int startAge, double initial, retire_info info) {
  int year = startAge / 12;
  int month = (startAge % 12);
  for (int i = 1; i <= info.months; i++) {
    year = startAge / 12;
    printf("Age %3d month %2d you have $%.2f\n", year, month, initial);
    if (month == 11) {
      month = 0;
    }
    else {
      month++;
    }
    startAge++;
    initial = initial * info.rate_of_return + info.contribution + initial;
  }
  return initial;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double balance = monthly (startAge, initial, working);
  startAge = startAge + working.months;
  monthly (startAge, balance, retired);
  return;
}

int main (void) {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12.000;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12.000;

  int startAge = 327;
  double initial = 21345;

  retirement(startAge, initial, working, retired);
  return EXIT_SUCCESS;
}
  
