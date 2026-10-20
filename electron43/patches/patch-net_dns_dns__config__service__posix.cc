$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- net/dns/dns_config_service_posix.cc.orig	2026-10-20 08:24:51.527578577 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -146,6 +146,7 @@ class DnsConfigServicePosix::Watcher : p
 #endif
 
     bool success = true;
+#if !IS_MAS_BUILD()
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
       LOG(ERROR) << "DNS config watch failed to start.";
