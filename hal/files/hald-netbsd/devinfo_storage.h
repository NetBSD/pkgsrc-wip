/***************************************************************************
 *
 * devinfo_storage.h : definitions for storage devices
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef DEVINFO_STORAGE_H
#define DEVINFO_STORAGE_H

#include "devinfo.h"

extern DevinfoDevHandler devinfo_ide_handler;
extern DevinfoDevHandler devinfo_scsi_handler;
extern DevinfoDevHandler devinfo_pcata_handler;
extern DevinfoDevHandler devinfo_floppy_handler;
extern DevinfoDevHandler devinfo_lofi_handler;

gboolean devinfo_storage_device_rescan (HalDevice *d);
HalDevice *devinfo_lofi_add_major(HalDevice *parent, const char *devinfo, char *devfs_path,
    char *device_type, gboolean rescan, HalDevice *lofi_d);
void devinfo_lofi_remove_minor(char *parent_devfs_path, char *name);
void devinfo_storage_mnttab_event (HalDevice *hal_volume);
void devinfo_volume_hotplug_begin_remove (HalDevice *d, char *devfs_path, void *end_token);

#endif /* DEVINFO_STORAGE_H */
