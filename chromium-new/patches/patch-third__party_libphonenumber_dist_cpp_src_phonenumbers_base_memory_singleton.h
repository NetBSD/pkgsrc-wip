$NetBSD$

--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h.orig	2016-11-10 20:03:01.000000000 +0000
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h
@@ -56,7 +56,7 @@ template <class T> boost::once_flag Sing
 #include "phonenumbers/base/logging.h"
 #include "phonenumbers/base/thread_checker.h"
 
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 
 namespace i18n {
 namespace phonenumbers {
