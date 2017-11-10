//
// Created by Ziya Sarikaya on 10.11.17.
//

#ifndef LIBCONSISTENT_MURMURHASH3_H
#define LIBCONSISTENT_MURMURHASH3_H


#include <iostream>


void MurmurHash3_x86_32  (const void * key, int len, uint32_t seed, void * out );

void MurmurHash3_x86_128 ( const void * key, int len, uint32_t seed, void * out );

void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );


#endif //LIBCONSISTENT_MURMURHASH3_H
