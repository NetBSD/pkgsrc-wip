$NetBSD$

--- src/VBox/HostDrivers/VBoxNetFlt/VBoxNetFltInternal.h.orig	2016-03-04 19:29:26.000000000 +0000
+++ src/VBox/HostDrivers/VBoxNetFlt/VBoxNetFltInternal.h
@@ -244,6 +244,30 @@ typedef struct VBOXNETFLTINS
             /** The MAC address of the interface. */
             RTMAC MacAddr;
             /** @} */
+# elif defined(RT_OS_NETBSD)
+            /** @name NetBSD instance data.
+             * @{ */
+            /** Interface handle */
+            struct ifnet *ifp;
+            /** Netgraph node handle */
+            node_p node;
+            /** Input hook */
+            hook_p input;
+            /** Output hook */
+            hook_p output;
+            /** Original interface flags */
+            unsigned int flags;
+            /** Input queue */
+            struct ifqueue inq;
+            /** Output queue */
+            struct ifqueue outq;
+            /** Input task */
+            struct task tskin;
+            /** Output task */
+            struct task tskout;
+            /** The MAC address of the interface. */
+            RTMAC MacAddr;
+            /** @} */
 # elif defined(RT_OS_WINDOWS)
             /** @name Windows instance data.
              * @{ */
@@ -475,4 +499,3 @@ DECLHIDDEN(int) vboxNetFltOsPreInitInsta
 RT_C_DECLS_END
 
 #endif
-
