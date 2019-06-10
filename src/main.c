#include "blake2.h"

#include "challenge.h"
#include "key.h"

#include <assert.h>
#include <stdio.h>

void print_buffer(const char* name, uint8_t *buf, size_t len) {
  assert(len > 0);
  printf("%s\t[", name);
  for (size_t i = 0; i < len - 1; ++i) {
    printf("%02X ", buf[i]);
  }
  printf("%02X]\n", buf[len - 1]);
}

int main(void) {
  uint8_t hash[BLAKE2S_OUTBYTES];

  assert(key_len == BLAKE2S_KEYBYTES);
  assert(challenge_len == BLAKE2S_BLOCKBYTES);

  blake2s(hash, BLAKE2S_OUTBYTES, challenge, BLAKE2S_BLOCKBYTES, key,
          BLAKE2S_KEYBYTES);

  print_buffer("CHALLENGE\t", challenge, BLAKE2S_BLOCKBYTES);
  print_buffer("KEY\t\t", key, BLAKE2S_KEYBYTES);
  print_buffer("RESPONSE\t", hash, BLAKE2S_OUTBYTES);
}
