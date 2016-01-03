$NetBSD: patch-jsnativestack.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- jsnativestack.cpp.orig	2013-10-29 20:40:20.000000000 +0000
+++ jsnativestack.cpp
@@ -114,7 +114,7 @@ js::GetNativeStackBaseImpl()
     pthread_attr_init(&sattr);
 #  if defined(__OpenBSD__)
     stack_t ss;
-#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
+#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(__DragonFly__) || defined(NETBSD) || defined(__NetBSD__) /* XXX tnn not sure why NETBSD isn't defined, it looks like it should be ... */
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
 #  else
