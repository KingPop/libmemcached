/*
  Common include file for libmemached
*/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <memcached.h>
#include <memcached_io.h>

#include <libmemcached_config.h>

#ifdef HAVE_DTRACE
#define _DTRACE_VERSION 1
#else
#undef _DTRACE_VERSION
#endif

#include "libmemcached_probes.h"

typedef enum {
  MEM_NO_BLOCK= (1 << 0),
  MEM_TCP_NODELAY= (1 << 1),
  MEM_REUSE_MEMORY= (1 << 2),
  MEM_USE_MD5= (1 << 3),
  MEM_USE_KETAMA= (1 << 4),
} memcached_flags;

void md5_signature(unsigned char *key, unsigned int length, unsigned char *result);
memcached_return memcached_connect(memcached_st *ptr, unsigned int server_key);
memcached_return memcached_response(memcached_st *ptr, 
                                    char *buffer, size_t buffer_length,
                                    unsigned int server_key);
unsigned int memcached_generate_hash(memcached_st *ptr, char *key, size_t key_length);
void memcached_quit_server(memcached_st *ptr, unsigned int server_key);

#define memcached_server_response_increment(A,B) A->hosts[B].stack_responses++
#define memcached_server_response_decrement(A,B) A->hosts[B].stack_responses--

#endif /* __COMMON_H__ */
