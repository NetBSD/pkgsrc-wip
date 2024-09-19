/***************************************************************************
 *
 * devinfo_acpi.h : definitions for acpi devices
 *
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef DEVINFO_ACPI_H
#define	DEVINFO_ACPI_H

#include "devinfo.h"

extern DevinfoDevHandler devinfo_acpi_handler;
extern DevinfoDevHandler devinfo_power_button_handler;

#define	MINOR_SHIFT			8
#define	MINOR2TYPE(minor)		((minor) >> MINOR_SHIFT)

/* Battery device types */
enum batt_type {
	BATT_TYPE_UNKNOWN = -1,
	BATT_TYPE_CBAT,
	BATT_TYPE_AC,
	BATT_TYPE_SBAT
};

HalDevice *devinfo_battery_add_major(HalDevice *parent, const char *devnode,
    char *devfs_path, char *device_type, gboolean rescan, HalDevice *battery_d);
void devinfo_acpi_add_minor(HalDevice *parent, const char *devnode,
    char *minor_path, dev_t dev);
void devinfo_battery_remove_minor(char *parent_devfs_path, gchar *udi);
void devinfo_battery_rescan(char *parent_devfs_path, gchar *udi);
const gchar *devinfo_acpi_get_prober(HalDevice *d, int *timeout);
void devinfo_power_button_event(void);
void devinfo_brightness_hotkeys_event(char *subclass);

void devinfo_lid_event(char *subclass, gchar *udi);
gboolean devinfo_lid_rescan(HalDevice *d);

#endif /* DEVINFO_ACPI_H */
