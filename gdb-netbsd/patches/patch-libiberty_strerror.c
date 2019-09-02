$NetBSD$

--- libiberty/strerror.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ libiberty/strerror.c
@@ -347,7 +347,7 @@ static const struct error_info error_tab
   ENTRY(EPROTOTYPE, "EPROTOTYPE", "Protocol wrong type for socket"),
 #endif
 #if defined (ENOPROTOOPT)
-  ENTRY(ENOPROTOOPT, "ENOPROTOOPT", "Protocol not available"),
+  ENTRY(ENOPROTOOPT, "ENOPROTOOPT", "Protocol option not available"),
 #endif
 #if defined (EPROTONOSUPPORT)
   ENTRY(EPROTONOSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"),
