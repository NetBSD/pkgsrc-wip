/***************************************************************************
 *
 * devinfo.c : main file for drvctl-based device enumeration
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <string.h>

#include <sys/drvctlio.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "../hald_runner.h"
#include "osspec_netbsd.h"
#include "hotplug.h"
#include "devinfo.h"
#include "devinfo_audio.h"
#include "devinfo_video.h"
#include "devinfo_pci.h"
#include "devinfo_storage.h"
#include "devinfo_mass.h"
#include "devinfo_usb.h"
#include "devinfo_misc.h"
#include "devinfo_cpu.h"
#include "devinfo_optical.h"
/* #include "devinfo_scsipi.h" */
#include "drvctl.h"

void devinfo_add_subtree(HalDevice *parent, const char *devnode, gboolean is_root);

void
devinfo_add(HalDevice *parent, gchar *name)
{
	devinfo_add_subtree (parent, name, TRUE);
}

void
devinfo_add_subtree(HalDevice *parent, const char *devnode, gboolean is_root)
{
	HalDevice *d;
	struct devlistargs laa;
	int i;

	HAL_INFO (("add_subtree: %s", devnode));

	if (parent == NULL) {
		parent = devinfo_add_node (NULL, devnode);
	}

	if (drvctl_list (devnode, &laa) == -1) {
		HAL_INFO (("devinfo_add_subtree: drvctl_list failed"));
		return;
	}

	for (i = 0; i < laa.l_children; i++) {
		d = devinfo_add_node (parent, laa.l_childname[i]);
		if (d)
			devinfo_add_subtree (d, laa.l_childname[i], FALSE);
	}

	if (laa.l_childname)
		free(laa.l_childname);
}

void
devinfo_set_default_properties (HalDevice *d, HalDevice *parent, const char *devnode, char *devfs_path)
{
	char	*driver_name, *s;
	const char *s1;
	char	udi[HAL_PATH_MAX];

	if (parent != NULL) {
		char *pdevice = hal_device_property_get_string (parent, "netbsd.device");
		if (pdevice) {
			gchar *path;
			if (strcmp (pdevice, "mainbus0") == 0)
				pdevice = "computer";
			path = g_strdup_printf ("/org/freedesktop/Hal/devices/%s", pdevice);
			hal_device_property_set_string (d, "info.parent", path);
			g_free (path);
		}
	} else {
		gchar pdevnode[512];
		char *pdevice = pdevnode;
		if (drvctl_find_parent (devnode, pdevnode) == TRUE) {
			gchar *path;
			if (strcmp (pdevnode, "mainbus0") == 0)
				pdevice = "computer";
			path = g_strdup_printf ("/org/freedesktop/Hal/devices/%s", pdevice);
			hal_device_property_set_string (d, "info.parent", path);
			g_free (path);
		} else
			hal_device_property_set_string (d, "info.parent", "/org/freedesktop/Hal/devices/local");
	}

	hald_compute_udi (udi, sizeof (udi),
			  "/org/freedesktop/Hal/devices/%s", devnode);
	hal_device_set_udi (d, udi);

#if notyet
	if (di_prop_lookup_strings (DDI_DEV_T_ANY, node, "model", &s) > 0) {
		hal_device_property_set_string (d, "info.product", s);
	} else {
		hal_device_property_set_string (d, "info.product", di_node_name (node));
	}
#else
	hal_device_property_set_string (d, "info.product", devnode);
#endif

	hal_device_property_set_string (d, "netbsd.device", devnode);

#if notyet
	if ((driver_name = di_driver_name (node)) != NULL) {
		hal_device_property_set_string (d, "info.solaris.driver",
						driver_name);
	}

	/* inherit parent's claim attributes */
	if (hal_device_property_get_bool (parent, "info.claimed")) {
		s1 = hal_device_property_get_string (parent, "info.claimed.service");
		if (s1 != NULL) {
			hal_device_property_set_bool (d, "info.claimed", TRUE);
			hal_device_property_set_string (d, "info.claimed.service", s1);
		}
	}
#endif
}

/* device handlers, ordered specific to generic */
static DevinfoDevHandler *devinfo_handlers[] = {
	&devinfo_computer_handler,
	&devinfo_cpu_handler,
	&devinfo_optical_handler,
#if notyet
	&devinfo_scsipi_handler,
	&devinfo_ide_handler,
	&devinfo_scsi_handler,
	&devinfo_floppy_handler,
	&devinfo_usb_handler,
	&devinfo_pci_handler,
	&devinfo_lofi_handler,
#endif
	&devinfo_audio_handler,
	&devinfo_audio_mixer_handler,
	&devinfo_audio_dsp_handler,
	&devinfo_video_handler,
	&devinfo_mass_handler,
	&devinfo_default_handler,
	NULL
};

HalDevice *
devinfo_add_node(HalDevice *parent, const char *devnode)
{
	HalDevice *d = NULL;
	char	*devfs_path;
	char	*device_type = NULL;
	DevinfoDevHandler *handler;
	int	i;

	devfs_path = g_strdup_printf ("%s", devnode);

#if notyet
        (void) di_prop_lookup_strings (DDI_DEV_T_ANY, node, "device_type",
	    &device_type);
#else
	device_type = "unknown";
#endif

	for (i = 0; (d == NULL) && (devinfo_handlers[i] != NULL); i++) {
		handler = devinfo_handlers[i];
		d = handler->add (parent, devnode, devfs_path, device_type);
	}

	g_free(devfs_path);

	HAL_INFO (("add_node: %s", d ? hal_device_get_udi (d) : "none"));
	return (d);
}

void
devinfo_hotplug_enqueue(HalDevice *d, gchar *devfs_path, DevinfoDevHandler *handler, int action, int front)
{
	HotplugEvent *hotplug_event;

	hotplug_event = g_new0 (HotplugEvent, 1);
	hotplug_event->action = action;
	hotplug_event->type = HOTPLUG_EVENT_DEVFS;
	hotplug_event->d = d;
	strlcpy (hotplug_event->un.devfs.devfs_path, devfs_path,
		sizeof (hotplug_event->un.devfs.devfs_path));
	hotplug_event->un.devfs.handler = handler;

	hotplug_event_enqueue (hotplug_event, front);
}

void
devinfo_add_enqueue(HalDevice *d, gchar *devfs_path, DevinfoDevHandler *handler)
{
	devinfo_hotplug_enqueue (d, devfs_path, handler, HOTPLUG_ACTION_ADD, 0);
}

void
devinfo_add_enqueue_at_front(HalDevice *d, gchar *devfs_path, DevinfoDevHandler *handler)
{
	devinfo_hotplug_enqueue (d, devfs_path, handler, HOTPLUG_ACTION_ADD, 1);
}

void
devinfo_remove_enqueue(gchar *devfs_path, DevinfoDevHandler *handler)
{
	devinfo_hotplug_enqueue (NULL, devfs_path, handler, HOTPLUG_ACTION_REMOVE, 0);
}

void
devinfo_callouts_add_done (HalDevice *d, gpointer userdata1, gpointer userdata2)
{
        void *end_token = (void *) userdata1;

        /* Move from temporary to global device store */
        hal_device_store_remove (hald_get_tdl (), d);
        hal_device_store_add (hald_get_gdl (), d);

        hotplug_event_end (end_token);
}

void
devinfo_callouts_probing_done (HalDevice *d, guint32 exit_type, gint return_code, char **error, gpointer userdata1, gpointer userdata2)
{
        void *end_token = (void *) userdata1;

        /* Discard device if probing reports failure */
        if (exit_type != HALD_RUN_SUCCESS || (return_code != 0)) {
		HAL_INFO (("Probing for %s failed %d", hal_device_get_udi (d), return_code));
                hal_device_store_remove (hald_get_tdl (), d);
                g_object_unref (d);
                hotplug_event_end (end_token);
		return;
        }

        /* Merge properties from .fdi files */
        di_search_and_merge (d, DEVICE_INFO_TYPE_INFORMATION);
        di_search_and_merge (d, DEVICE_INFO_TYPE_POLICY);

	hal_util_callout_device_add (d, devinfo_callouts_add_done, end_token, NULL);
}

void
devinfo_callouts_preprobing_done (HalDevice *d, gpointer userdata1, gpointer userdata2)
{
        void *end_token = (void *) userdata1;
	DevinfoDevHandler *handler = (DevinfoDevHandler *) userdata2;
	void (*probing_done) (HalDevice *, guint32, gint, char **, gpointer, gpointer);
	const gchar *prober;
	int prober_timeout;

        if (hal_device_property_get_bool (d, "info.ignore")) {
		HAL_INFO (("Preprobing merged info.ignore==TRUE"));

                /* Leave device with info.ignore==TRUE so we won't pick up children */
		hal_device_property_remove (d, "info.category");
		hal_device_property_remove (d, "info.capabilities");

		hal_device_store_remove (hald_get_tdl (), d);
		hal_device_store_add (hald_get_gdl (), d);

		hotplug_event_end (end_token);
		return;
        }

        if (handler != NULL && handler->get_prober != NULL) {
                prober = handler->get_prober (d, &prober_timeout);
        } else {
                prober = NULL;
	}

	if (handler->probing_done != NULL) {
		probing_done = handler->probing_done;
	} else {
		probing_done = devinfo_callouts_probing_done;
	}

        if (prober != NULL) {
                /* probe the device */
		HAL_INFO(("Probing udi=%s", hal_device_get_udi (d)));
                hald_runner_run (d,
				prober, NULL,
				prober_timeout,
				probing_done,
				(gpointer) end_token, (gpointer) handler);
	} else {
		probing_done (d, 0, 0, NULL, userdata1, userdata2);
	}
}

/* This is the beginning of hotplug even handling */
void
hotplug_event_begin_add_devinfo (HalDevice *d, HalDevice *parent, DevinfoDevHandler *handler, void *end_token)
{
	HAL_INFO(("Preprobing udi=%s", hal_device_get_udi (d)));

	if (parent != NULL && hal_device_property_get_bool (parent, "info.ignore")) {
		HAL_INFO (("Ignoring device since parent has info.ignore==TRUE"));

		hotplug_event_end (end_token);
		return;
	}

        /* add to TDL so preprobing callouts and prober can access it */
        hal_device_store_add (hald_get_tdl (), d);

#if 0
        /* Process preprobe fdi files */
        di_search_and_merge (d, DEVICE_INFO_TYPE_PREPROBE);
#endif

        /* Run preprobe callouts */
        hal_util_callout_device_preprobe (d, devinfo_callouts_preprobing_done, end_token, handler);
}

void
devinfo_remove (gchar *devfs_path)
{
	devinfo_remove_enqueue ((gchar *)devfs_path, NULL);
}

/* generate hotplug event for each device in this branch */
void
devinfo_remove_branch (gchar *devnode, HalDevice *d)
{
	GSList *i;
	GSList *children;
	HalDevice *child;
	char *child_devfs_path;

	if (d == NULL) {
		d = hal_device_store_match_key_value_string (hald_get_gdl (),
			"netbsd.device", devnode);
		if (d == NULL)
			return;
	}

	HAL_INFO (("remove_branch: %s %s\n", devnode, hal_device_get_udi (d)));

	/* first remove children */
	children = hal_device_store_match_multiple_key_value_string (hald_get_gdl(),
		"info.parent", hal_device_get_udi (d));
        for (i = children; i != NULL; i = g_slist_next (i)) {
                child = HAL_DEVICE (i->data);
		HAL_INFO (("remove_branch: child %s\n", hal_device_get_udi (child)));
		devinfo_remove_branch ((gchar *)hal_device_property_get_string (child, "netbsd.device"), child);
	}
	g_slist_free (children);
	HAL_INFO (("remove_branch: done with children"));

	/* then remove self */
	HAL_INFO (("remove_branch: queueing %s", devnode));
	devinfo_remove_enqueue (devnode, NULL);
}

void
devinfo_callouts_remove_done (HalDevice *d, gpointer userdata1, gpointer userdata2)
{
        void *end_token = (void *) userdata1;

        HAL_INFO (("Remove callouts completed udi=%s", hal_device_get_udi (d)));

        if (!hal_device_store_remove (hald_get_gdl (), d)) {
                HAL_WARNING (("Error removing device"));
        }
        g_object_unref (d);

        hotplug_event_end (end_token);
}

void
hotplug_event_begin_remove_devinfo (HalDevice *d, gchar *devfs_path, void *end_token)
{
#if notyet
	if (hal_device_has_capability (d, "volume")) {
		devinfo_volume_hotplug_begin_remove (d, devfs_path, end_token);
	} else {
		hal_util_callout_device_remove (d, devinfo_callouts_remove_done, end_token, NULL);
	}
#else
#warning hotplug_event_begin_remove_devinfo TODO
	hal_util_callout_device_remove (d, devinfo_callouts_remove_done, end_token, NULL);
#endif
}

gboolean
devinfo_device_rescan (HalDevice *d)
{
#if notyet
	if (hal_device_has_capability (d, "block")) {
		return (devinfo_storage_device_rescan (d));
	} else {
		return (FALSE);
	}
#else
#warning devinfo_device_rescan TODO
	return FALSE;
#endif
}
