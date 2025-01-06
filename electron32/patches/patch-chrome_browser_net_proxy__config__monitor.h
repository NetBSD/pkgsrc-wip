$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/net/proxy_config_monitor.h.orig	2024-10-18 12:34:01.745164400 +0000
+++ chrome/browser/net/proxy_config_monitor.h
@@ -40,11 +40,12 @@ class ProxyConfigMonitor : public net::P
 
 {
  public:
+#if 0
   // Creates a ProxyConfigMonitor that gets proxy settings from |profile| and
   // watches for changes. The created ProxyConfigMonitor must be destroyed
   // before |profile|.
   explicit ProxyConfigMonitor(Profile* profile);
-
+#endif
   // Creates a ProxyConfigMonitor that gets proxy settings from the
   // |local_state|, for use with NetworkContexts not
   // associated with a profile. Must be destroyed before |local_state|.
@@ -94,7 +95,7 @@ class ProxyConfigMonitor : public net::P
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
   mojo::ReceiverSet<network::mojom::ProxyErrorClient> error_receiver_set_;
-  raw_ptr<Profile> profile_ = nullptr;
+  // raw_ptr<Profile> profile_ = nullptr;
 #endif
 };
 
