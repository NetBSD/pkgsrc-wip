$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ipcz/src/standalone/base/logging.cc.orig	2024-09-24 20:49:54.337130800 +0000
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
