$NetBSD: patch-src_nfs.c,v $

Provide a port to NetBSD.

--- src/nfs.c.orig	2017-11-18 10:03:27.000000000 +0100
+++ src/nfs.c	2019-10-31 15:48:19.000000000 +0100
@@ -27,6 +27,15 @@
 #include "common.h"
 #include "plugin.h"
 
+#if KERNEL_NETBSD
+#include <sys/param.h>
+#include <sys/mount.h>
+#include <sys/sysctl.h>
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
+#include <nfs/nfs.h>
+#endif
+
 #if HAVE_KSTAT_H
 #include <kstat.h>
 #endif
@@ -82,12 +91,14 @@ Number      Procedures  Procedures
 21                      commit
 */
 
+#if KERNEL_LINUX | HAVE_KSTAT
 static const char *nfs2_procedures_names[] = {
     "null", "getattr", "setattr", "root",   "lookup",  "readlink",
     "read", "wrcache", "write",   "create", "remove",  "rename",
     "link", "symlink", "mkdir",   "rmdir",  "readdir", "fsstat"};
 static size_t nfs2_procedures_names_num =
     STATIC_ARRAY_SIZE(nfs2_procedures_names);
+#endif
 
 static const char *nfs3_procedures_names[] = {
     "null",   "getattr", "setattr",  "lookup", "access",  "readlink",
@@ -320,7 +331,7 @@ static int nfs_config(const char *key, c
   return 0;
 }
 
-#if KERNEL_LINUX
+#if KERNEL_LINUX || KERNEL_NETBSD
 static int nfs_init(void) { return 0; }
 /* #endif KERNEL_LINUX */
 
@@ -596,6 +607,28 @@ static int nfs_read(void) {
 }
 /* #endif KERNEL_LINUX */
 
+#elif KERNEL_NETBSD
+static int nfs_read(void) {
+  struct nfsstats ns;
+  size_t size = sizeof(ns);
+  int mib[] = { CTL_VFS, 2, NFS_NFSSTATS };
+  value_t values[nfs3_procedures_names_num];
+  int i;
+
+  /* NetBSD reports v2 statistics mapped to v3 and doen't yet support v4 */
+  if (!report_v3) return 0;
+  if (sysctl(mib, 3, &ns, &size, NULL, 0) != 0) return 1;
+
+  for (i = 0; i < nfs3_procedures_names_num; i++) values[i].counter = (derive_t)ns.rpccnt[i];
+  nfs_procedures_submit("v3client", nfs3_procedures_names, values, nfs3_procedures_names_num);
+
+  for (i = 0; i < nfs3_procedures_names_num; i++) values[i].counter = (derive_t)ns.srvrpccnt[i];
+  nfs_procedures_submit("v3server", nfs3_procedures_names, values, nfs3_procedures_names_num);
+     
+  return 0;
+}
+/* #endif KERNEL_NETBSD */
+
 #elif HAVE_LIBKSTAT
 static int nfs_read(void) {
   if (report_v2) {
