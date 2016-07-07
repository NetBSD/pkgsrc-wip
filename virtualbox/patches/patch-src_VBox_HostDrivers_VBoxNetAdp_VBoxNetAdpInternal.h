$NetBSD$

--- src/VBox/HostDrivers/VBoxNetAdp/VBoxNetAdpInternal.h.orig	2016-03-04 19:29:26.000000000 +0000
+++ src/VBox/HostDrivers/VBoxNetAdp/VBoxNetAdpInternal.h
@@ -113,6 +113,11 @@ struct VBoxNetAdapter
              * @{ */
             struct ifnet *ifp;
             /** @} */
+# elif defined(RT_OS_NETBSD)
+            /** @name NetBSD instance data.
+             * @{ */
+            struct ifnet *ifp;
+            /** @} */
 # else
 # error PORTME
 # endif
@@ -178,4 +183,3 @@ DECLHIDDEN(int) vboxNetAdpOsCreate(PVBOX
 RT_C_DECLS_END
 
 #endif
-
