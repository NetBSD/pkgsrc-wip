/* librist. Copyright © 2026 SipRadius LLC. All right reserved.
 * Author: Sergio Ammirata, Ph.D. <sergio@ammirata.net>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * NetBSD TUN implementation 
 */

#ifdef __NetBSD__

#include "librist/tun.h"
#include <stdio.h>

int rist_tun_open(const char *requested_name, char *actual_name, size_t name_len)
{
	(void)requested_name;
	(void)actual_name;
	(void)name_len;
	fprintf(stderr, "librist: NetBSD TUN support not yet implemented\n");
	return -1;
}

void rist_tun_close(int fd)
{
	(void)fd;
}

int rist_tun_read(int fd, uint8_t *buf, size_t len)
{
	(void)fd;
	(void)buf;
	(void)len;
	return -1;
}

int rist_tun_write(int fd, const uint8_t *buf, size_t len)
{
	(void)fd;
	(void)buf;
	(void)len;
	return -1;
}

int rist_tun_set_ip(const char *dev, const char *ip, int prefix_len)
{
	(void)dev;
	(void)ip;
	(void)prefix_len;
	fprintf(stderr, "librist: NetBSD IP config not yet implemented\n");
	return -1;
}

int rist_tun_set_mtu(const char *dev, int mtu)
{
	(void)dev;
	(void)mtu;
	return -1;
}

int rist_tun_bring_up(const char *dev)
{
	(void)dev;
	return -1;
}

#endif /* __NetBSD__ */
