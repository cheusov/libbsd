/*
 * Copyright © 2024 Aleksey Cheusov <vle@gmx.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "../include/bsd/stdlib.h"
#include <stdio.h>
#include <assert.h>

#define COUNT 100

static uint32_t randoms[100];

static void check(void)
{
	unsigned i,j;
	for (i = 0; i < COUNT; ++i) {
		for (j = i + 1; j < COUNT; ++j) {
			assert(randoms[i] != randoms[j]);
		}
	}
}

int
main(int argc, char **argv)
{
	// check for linking :-)
	arc4random_stir();
	static const uint32_t init = 7;
	arc4random_addrandom(&init, sizeof(init));

	// arc4random(3)
	memset(randoms, 0, sizeof(randoms));
	for (unsigned i = 0; i < COUNT; ++i) {
		randoms[i] = arc4random();
	}
	check();

	// arc4random_uniform(3)
	memset(randoms, 0, sizeof(randoms));
	for (unsigned i = 0; i < COUNT; ++i) {
		randoms[i] = arc4random_uniform((uint32_t) -1);
	}
	check();

	// arc4random_buf(3)
	memset(randoms, 0, sizeof(randoms));
	arc4random_buf(randoms, sizeof(randoms));
	check();

	//
	return 0;
}
