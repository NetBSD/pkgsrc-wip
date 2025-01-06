$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/site_instance_impl.cc.orig	2024-10-18 12:34:13.882657500 +0000
+++ content/browser/site_instance_impl.cc
@@ -211,7 +211,7 @@ scoped_refptr<SiteInstanceImpl> SiteInst
     BrowserContext* browser_context,
     const StoragePartitionConfig& partition_config) {
   DCHECK(browser_context);
-  DCHECK(!partition_config.is_default());
+  // DCHECK(!partition_config.is_default());
 
   auto guest_site_info =
       SiteInfo::CreateForGuest(browser_context, partition_config);
