$NetBSD: patch-tuntap__netbsd.c,v 1.2 2014/04/04 13:48:34 phonohawk Exp $

Hunk #1: struct ifreq is defined in <net/if.h> and it's not #included
         by <net/if_tap.h>.

Hunk #1: The maximum length of interface name is declared as a
         constant IF_NAMESIZE by <net/if.h>.

Hunk #2: dev will be an empty string if -d is not given.

Hunk #3: FILE* fd will never be < 0.

Hunk #1, #3: tuntap_open() is calling a wrong function, leading to a
         linkage failure. This bug goes unnoticed if you are using GCC
         because the call of tun_close() is optimized out as the
         condition "fd < 0" never holds.

TODO: This patch should be sent to the upstream.

--- tuntap_netbsd.c.orig	2014-04-04 13:13:24.000000000 +0000
+++ tuntap_netbsd.c
@@ -22,13 +22,11 @@
 
 #include <errno.h>
 #include <string.h>
+#include <net/if.h>
 #include <net/if_tap.h>
 
-void tun_close(tuntap_dev *device);
-
 /* ********************************** */
 
-#define N2N_NETBSD_TAPDEVICE_SIZE 32
 int tuntap_open(tuntap_dev *device /* ignored */,
                 char *dev,
                 const char *address_mode, /* static or dhcp */
@@ -36,10 +34,10 @@ int tuntap_open(tuntap_dev *device /* ig
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
@@ -90,8 +88,8 @@ int tuntap_open(tuntap_dev *device /* ig
     /* traceEvent(TRACE_INFO, "%s", buf); */
 
     fd = popen(buf, "r");
-    if(fd < 0) {
-      tun_close(device);
+    if(fd == NULL) {
+      tuntap_close(device);
       return(-1);
     } else {
       int a, b, c, d, e, f;
