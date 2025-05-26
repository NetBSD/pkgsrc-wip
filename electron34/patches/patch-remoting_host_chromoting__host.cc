$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/chromoting_host.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/chromoting_host.cc
@@ -135,7 +135,7 @@ void ChromotingHost::Start(const std::st
       &ChromotingHost::OnIncomingSession, base::Unretained(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
