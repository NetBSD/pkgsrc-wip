$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/site_instance_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/site_instance_impl.cc
@@ -210,7 +210,7 @@ scoped_refptr<SiteInstanceImpl> SiteInst
     BrowserContext* browser_context,
     const StoragePartitionConfig& partition_config) {
   DCHECK(browser_context);
-  DCHECK(!partition_config.is_default());
+  // DCHECK(!partition_config.is_default());
 
   auto guest_site_info =
       SiteInfo::CreateForGuest(browser_context, partition_config);
