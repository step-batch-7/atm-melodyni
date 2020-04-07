#include<stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int amount){
  unsigned int denominations[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int notes = 0x00000000;
  if(amount <= 31999){
    for(int i = 0; i < 8; i++){
      notes = notes << 4;
      notes += amount / denominations[i];
      amount = amount % denominations[i];
    }
  }
  return notes;
}

void print_denomination(unsigned int notes){
  unsigned int denominations[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int note_count = 0;
  for(int i = 7; i >= 0; i--){
    note_count = notes & 0xf;
    printf("%u notes of Rs %u\n", note_count, denominations[i]);
    notes = notes >> 4;
  }
}
