$NetBSD$

--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h.orig	2016-06-24 01:03:50.000000000 +0000
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h
@@ -37,7 +37,7 @@ typedef boost::mutex::scoped_lock AutoLo
 // Dummy lock implementation on non-POSIX platforms. If you are running on a
 // different platform and care about thread-safety, please compile with
 // -DI18N_PHONENUMBERS_USE_BOOST.
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 
 namespace i18n {
 namespace phonenumbers {
