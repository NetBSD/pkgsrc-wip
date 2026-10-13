$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/dns_config_service_posix.cc.orig	2026-10-13 15:23:12.816437074 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -146,6 +146,7 @@ class DnsConfigServicePosix::Watcher : p
 #endif
 
     bool success = true;
+#if !IS_MAS_BUILD()
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
       LOG(ERROR) << "DNS config watch failed to start.";
