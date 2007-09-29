/*
  Code to generate data to be pushed into memcached
*/

typedef struct pairs_st pairs_st;

struct pairs_st {
  char *key;
  size_t key_length;
  char *value;
  size_t value_length;
};

pairs_st *pairs_generate(unsigned long long number_of);
void pairs_free(pairs_st *pairs);
static void get_random_string(char *buffer, size_t size);