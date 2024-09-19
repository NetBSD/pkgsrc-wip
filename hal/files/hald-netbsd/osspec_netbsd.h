/***************************************************************************
 *
 * osspec_netbsd.h : definitions for NetBSD HAL backend
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef OSSPEC_NETBSD_H
#define OSSPEC_NETBSD_H

#include <glib.h>

void hotplug_queue_now_empty (void);
HalDevice *hal_util_find_closest_ancestor (const gchar *devfs_path, gchar **ancestor_devfs_path, gchar **hotplug_devfs_path);
char *dsk_to_rdsk(char *);

#endif /* OSSPEC_NETBSD_H */
