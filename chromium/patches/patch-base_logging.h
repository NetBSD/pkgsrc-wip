$NetBSD: patch-base_logging.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/logging.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/logging.h
@@ -141,6 +141,18 @@
 // There is also the special severity of DFATAL, which logs FATAL in
 // debug mode, ERROR in normal mode.
 
+// XXX better comment -- must be before we use << and in global namespace
+// These functions are provided as a convenience for logging, which is where we
+// use streams (it is against Google style to use streams in other places). It
+// is designed to allow you to emit non-ASCII Unicode strings to the log file,
+// which is normally ASCII. It is relatively slow, so try not to use it for
+// common cases. Non-ASCII characters will be converted to UTF-8 by these
+// operators.
+std::ostream& operator<<(std::ostream& out, const wchar_t* wstr);
+inline std::ostream& operator<<(std::ostream& out, const std::wstring& wstr) {
+  return out << wstr.c_str();
+}
+
 namespace logging {
 
 // Where to record logging output? A flat file and/or system debug log via
@@ -866,17 +878,6 @@ void RawLog(int level, const char* messa
 
 }  // namespace logging
 
-// These functions are provided as a convenience for logging, which is where we
-// use streams (it is against Google style to use streams in other places). It
-// is designed to allow you to emit non-ASCII Unicode strings to the log file,
-// which is normally ASCII. It is relatively slow, so try not to use it for
-// common cases. Non-ASCII characters will be converted to UTF-8 by these
-// operators.
-std::ostream& operator<<(std::ostream& out, const wchar_t* wstr);
-inline std::ostream& operator<<(std::ostream& out, const std::wstring& wstr) {
-  return out << wstr.c_str();
-}
-
 // The NOTIMPLEMENTED() macro annotates codepaths which have
 // not been implemented yet.
 //
