$NetBSD$

--- lib/sanitizer_common/sanitizer_fuchsia.cc.orig	2018-06-01 09:39:33.000000000 +0000
+++ lib/sanitizer_common/sanitizer_fuchsia.cc
@@ -87,6 +87,7 @@ void GetThreadStackTopAndBottom(bool, up
 }
 
 void MaybeReexec() {}
+void CheckASLR() {}
 void PlatformPrepareForSandboxing(__sanitizer_sandbox_arguments *args) {}
 void DisableCoreDumperIfNecessary() {}
 void InstallDeadlySignalHandlers(SignalHandlerType handler) {}
