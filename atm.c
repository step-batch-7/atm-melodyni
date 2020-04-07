#include "atm.h"

unsigned int get_money(unsigned short int amount){
  unsigned int denominations[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int note_count = 0x00000000;
  if(amount > 31999){
    return note_count;
  }
  for(int i = 0; i < 8; i++){
    note_count = note_count << 4;
    note_count += amount / denominations[i];
    amount = amount % denominations[i];
  }
  return note_count;
}
