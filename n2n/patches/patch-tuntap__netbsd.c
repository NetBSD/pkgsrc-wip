$NetBSD: patch-tuntap__netbsd.c,v 1.1 2014/03/28 03:48:22 phonohawk Exp $

Hunk #1: struct ifreq is defined in <net/if.h> and it's not #included
         by <net/if_tap.h>.

Hunk #1: The maximum length of interface name is declared as a
         constant IF_NAMESIZE by <net/if.h>.

Hunk #2: dev will be an empty string if -d is not given.

TODO: This patch should be sent to the upstream.

--- tuntap_netbsd.c.orig	2014-03-27 03:34:47.000000000 +0000
+++ tuntap_netbsd.c
@@ -22,13 +22,13 @@
 
 #include <errno.h>
 #include <string.h>
+#include <net/if.h>
 #include <net/if_tap.h>
 
 void tun_close(tuntap_dev *device);
 
 /* ********************************** */
 
-#define N2N_NETBSD_TAPDEVICE_SIZE 32
 int tuntap_open(tuntap_dev *device /* ignored */,
                 char *dev,
                 const char *address_mode, /* static or dhcp */
@@ -36,10 +36,10 @@ int tuntap_open(tuntap_dev *device /* ig
                 char *device_mask,
                 const char * device_mac,
 		int mtu) {
-  char tap_device[N2N_NETBSD_TAPDEVICE_SIZE];
+  char tap_device[IF_NAMESIZE];
   struct ifreq req;
 
-  if (dev) {
+  if (dev && dev[0] != '\0') {
      snprintf(tap_device, sizeof(tap_device), "/dev/%s", dev);
      device->fd = open(tap_device, O_RDWR);
      snprintf(tap_device, sizeof(tap_device), "%s", dev);
