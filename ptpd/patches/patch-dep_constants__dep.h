$NetBSD: patch-dep_constants__dep.h,v 1.1 2013/06/18 10:29:14 fhajny Exp $

Add support for SunOS.
--- dep/constants_dep.h.orig	2012-06-20 20:02:51.000000000 +0000
+++ dep/constants_dep.h
@@ -16,7 +16,7 @@
 /* platform dependent */
 
 #if !defined(linux) && !defined(__NetBSD__) && !defined(__FreeBSD__) && \
-  !defined(__APPLE__)
+  !defined(__APPLE__) && !defined(__sun)
 #error Not ported to this architecture, please update.
 #endif
 
@@ -66,6 +66,31 @@
 #   define PTPD_MSBF
 # endif
 #endif
+
+#if defined(__sun)
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <netinet/in.h>
+# include <net/if.h>
+# include <net/if_dl.h>
+# include <net/if_types.h>
+# include <sys/ethernet.h>
+# include <sys/uio.h>
+# include <ifaddrs.h>
+# define IFACE_NAME_LENGTH         IF_NAMESIZE
+# define NET_ADDRESS_LENGTH        INET_ADDRSTRLEN
+
+# define IFCONF_LENGTH 10
+
+# define adjtimex ntp_adjtime
+
+# include <sys/isa_defs.h>
+# if defined(_LITTLE_ENDIAN)
+#   define PTPD_LSBF
+# elif defined(_BIG_ENDIAN)
+#   define PTPD_MSBF
+# endif
+#endif
 
 #define CLOCK_IDENTITY_LENGTH 8
 #define ADJ_FREQ_MAX  512000
