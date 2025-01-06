$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/services/storage/dom_storage/dom_storage_constants.cc.orig	2024-10-18 12:34:08.033731000 +0000
+++ components/services/storage/dom_storage/dom_storage_constants.cc
@@ -6,7 +6,9 @@
 
 namespace storage {
 
-const size_t kPerStorageAreaQuota = 10 * 1024 * 1024;
+// Electron's dom_storage_limits.patch increased this value from 10MiB to 100MiB
+const size_t kPerStorageAreaQuota = 100 * 1024 * 1024;
+
 const size_t kPerStorageAreaOverQuotaAllowance = 100 * 1024;
 
 }  // namespace storage
