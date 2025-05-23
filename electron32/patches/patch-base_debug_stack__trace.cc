$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/debug/stack_trace.cc.orig	2024-10-18 12:33:59.758278800 +0000
+++ base/debug/stack_trace.cc
@@ -255,7 +255,7 @@ bool StackTrace::WillSymbolizeToStreamFo
   // Symbols are not expected to be reliable when gn args specifies
   // symbol_level=0.
   return false;
-#elif defined(__UCLIBC__) || defined(_AIX)
+#elif defined(__UCLIBC__) || defined(_AIX) || BUILDFLAG(IS_BSD)
   // StackTrace::OutputToStream() is not implemented under uclibc, nor AIX.
   // See https://crbug.com/706728
   return false;
@@ -317,7 +317,7 @@ std::string StackTrace::ToString() const
 
 std::string StackTrace::ToStringWithPrefix(cstring_view prefix_string) const {
   std::stringstream stream;
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(&stream, prefix_string);
 #endif
   return stream.str();
@@ -341,7 +341,7 @@ bool StackTrace::ShouldSuppressOutput() 
 }
 
 std::ostream& operator<<(std::ostream& os, const StackTrace& s) {
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   s.OutputToStream(&os);
 #else
   os << "StackTrace::OutputToStream not implemented.";
