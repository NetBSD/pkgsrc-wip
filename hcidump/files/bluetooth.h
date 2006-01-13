/* $NetBSD: bluetooth.h,v 1.3 2006/01/13 14:32:14 plunky Exp $ */
/*
 * Copyright (c) 2005 Iain D. Hibbert,
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NETBT_BLUETOOTH_H_
#define _NETBT_BLUETOOTH_H_

#include <sys/socket.h>			// sa_family_t

/*
 * Bluetooth Address Family Protocol Numbers
 */
#define BLUETOOTH_PROTO_HCI	1
#define BLUETOOTH_PROTO_L2CAP	2
#define BLUETOOTH_PROTO_RFCOMM	3

/* All sizes are in bytes */
#define BLUETOOTH_BDADDR_SIZE	6

/*
 * Bluetooth device address
 */
typedef struct {
	uint8_t	b[BLUETOOTH_BDADDR_SIZE];
} __attribute__ ((packed)) bdaddr_t;

typedef bdaddr_t *bdaddr_p;

/*
 * bdaddr utility functions
 */
static __inline int bdaddr_same(bdaddr_t *a, bdaddr_t *b)
{
	return (memcmp(a, b, sizeof(bdaddr_t)) == 0);
}

static __inline int bdaddr_any(bdaddr_t *a)
{
	return (a->b[0] == 0 && a->b[1] == 0 && a->b[2] == 0
		&& a->b[3] == 0 && a->b[4] == 0 && a->b[5] == 0);
}

static __inline void bdaddr_copy(bdaddr_t *d, bdaddr_t *s)
{
	memcpy(d, s, sizeof(bdaddr_t));
}

/*
 * Socket address used by Bluetooth protocols
 */
struct sockaddr_bt {
	uint8_t	len;
	sa_family_t	family;
	bdaddr_t	bdaddr;
};

/* Note: this is actually 7 bytes (count \0 terminator) */
#define BDADDR_ANY	((bdaddr_t *) "\000\000\000\000\000\000")

#endif	/* _NETBT_BLUETOOTH_H_ */
