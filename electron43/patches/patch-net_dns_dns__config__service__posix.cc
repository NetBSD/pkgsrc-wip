$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/dns_config_service_posix.cc.orig	2026-08-17 18:32:36.000000000 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -145,6 +145,7 @@ class DnsConfigServicePosix::Watcher : p
 #endif
 
     bool success = true;
+#if !IS_MAS_BUILD()
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
       LOG(ERROR) << "DNS config watch failed to start.";
