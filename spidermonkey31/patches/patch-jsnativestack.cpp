$NetBSD$

--- jsnativestack.cpp.orig	2014-10-10 18:31:12.000000000 +0000
+++ jsnativestack.cpp
@@ -98,7 +98,7 @@ js::GetNativeStackBaseImpl()
     pthread_attr_init(&sattr);
 #  if defined(__OpenBSD__)
     stack_t ss;
-#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
+#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD) || defined(__NetBSD__) /* NETBSD seems undefined */
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
 #  else
