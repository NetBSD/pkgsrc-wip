$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/ipcz/src/standalone/base/logging.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/ipcz/src/standalone/base/logging.cc
@@ -50,6 +50,9 @@ LogMessage::LogMessage(const char* file,
 #elif BUILDFLAG(IS_ANDROID)
   stream_ << getpid() << ":" << gettid() << ":";
   const char* trimmed_file = strrchr(file, '/') + 1;
+#elif BUILDFLAG(IS_BSD)
+  stream_ << getpid() << ":" << pthread_self() << ":";
+  const char* trimmed_file = strrchr(file, '/') + 1;
 #elif BUILDFLAG(IS_WIN)
   const char* trimmed_file = file;
   stream_ << (::GetCurrentProcessId()) << ":" << ::GetCurrentThreadId() << ":";
