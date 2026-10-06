$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/chromoting_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/chromoting_host.h
@@ -36,7 +36,7 @@
 #include "remoting/protocol/session_manager.h"
 #include "remoting/protocol/transport_context.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/chromoting_host_services_server.h"
 #endif
 
@@ -112,7 +112,7 @@ class ChromotingHost : public ClientSess
   // This method can only be called once during the lifetime of this object.
   void Start(const std::string& host_owner);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts running the ChromotingHostServices server and listening for incoming
   // IPC binding requests.
   // Currently only Linux runs the ChromotingHostServices server on the host
@@ -220,7 +220,7 @@ class ChromotingHost : public ClientSess
   // List of host extensions.
   std::vector<std::unique_ptr<HostExtension>> extensions_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // IPC server that runs the CRD host service API. Non-null if the server name
   // is set and the host is started.
   // Currently only Linux runs the ChromotingHostServices server on the host
