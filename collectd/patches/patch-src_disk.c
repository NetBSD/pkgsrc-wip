$NetBSD: patch-src_disk.c,v $

Provide a working port to NetBSD.

--- src/disk.c.orig	2018-08-30 15:04:48.000000000 +0200
+++ src/disk.c	2018-08-30 15:04:49.000000000 +0200
@@ -135,6 +135,16 @@ static int numdisk;
 static int pnumdisk;
 /* #endif HAVE_PERFSTAT */
 
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+
+#include <sys/sysctl.h>
+#include <sys/iostat.h>
+
+static struct io_sysctl *drives = NULL;
+static size_t ndrive = 0;
+
+/* #endif HAVE_SYSCTL && KERNEL_NETBSD */
+
 #else
 #error "No applicable input method."
 #endif
@@ -253,7 +263,31 @@ static int disk_init(void) {
       continue;
     ksp[numdisk++] = ksp_chain;
   }
-#endif /* HAVE_LIBKSTAT */
+/* #endif HAVE_LIBKSTAT */
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+  int mib[3];
+  size_t size;
+
+  /* figure out number of drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, NULL, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for ndrives failed");
+    return -1;
+  }
+  ndrive = size / sizeof(struct io_sysctl);
+
+  if (size == 0 ) {
+    ERROR ("disk plugin: no drives found");
+    return -1;
+  }
+  drives = (struct io_sysctl *)malloc(size);
+  if (drives == NULL) {
+    ERROR ("disk plugin: memory allocation failure");
+    return -1;
+  }
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
 
   return 0;
 } /* int disk_init */
@@ -284,7 +318,7 @@ static void disk_submit(const char *plug
   plugin_dispatch_values(&vl);
 } /* void disk_submit */
 
-#if KERNEL_FREEBSD || KERNEL_LINUX
+#if KERNEL_FREEBSD || (HAVE_SYSCTL && KERNEL_NETBSD) || KERNEL_LINUX
 static void submit_io_time(char const *plugin_instance, derive_t io_time,
                            derive_t weighted_time) {
   value_list_t vl = VALUE_LIST_INIT;
@@ -300,7 +334,7 @@ static void submit_io_time(char const *p
 
   plugin_dispatch_values(&vl);
 } /* void submit_io_time */
-#endif /* KERNEL_FREEBSD || KERNEL_LINUX */
+#endif /* KERNEL_FREEBSD || (HAVE_SYSCTL && KERNEL_NETBSD) || KERNEL_LINUX */
 
 #if KERNEL_LINUX
 static void submit_in_progress(char const *disk_name, gauge_t in_progress) {
@@ -1017,7 +1051,58 @@ static int disk_read(void) {
                   1000000.0;
     disk_submit(stat_disk[i].name, "disk_time", read_time, write_time);
   }
-#endif /* defined(HAVE_PERFSTAT) */
+/* #endif defined(HAVE_PERFSTAT) */
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+  int mib[3];
+  size_t size, i, nndrive;
+
+  /* figure out number of drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, NULL, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for ndrives failed");
+    return -1;
+  }
+  nndrive = size / sizeof(struct io_sysctl);
+
+  if (size == 0 ) {
+    ERROR ("disk plugin: no drives found");
+    return -1;
+  }
+  /* number of drives changed, reallocate buffer */
+  if (nndrive != ndrive) {
+    drives = (struct io_sysctl *)realloc(drives, size);
+    if (drives == NULL) {
+      ERROR ("disk plugin: memory allocation failure");
+      return -1;
+    }
+    ndrive = nndrive;
+  }
+
+  /* get stats for all drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, drives, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for drive stats failed");
+    return -1;
+  }
+
+  for (i = 0; i < ndrive; i++) {
+    if (drives[i].type != IOSTAT_DISK)
+      continue;
+    if (ignorelist_match(ignorelist, drives[i].name))
+      continue;
+
+    disk_submit(drives[i].name, "disk_octets",
+                drives[i].rbytes, drives[i].wbytes);
+    disk_submit(drives[i].name, "disk_ops",
+                drives[i].rxfer, drives[i].wxfer);
+    submit_io_time(drives[i].name,
+                   drives[i].time_sec * 1000 + drives[i].time_usec / 1000, 0);
+  }
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
 
   return 0;
 } /* int disk_read */
