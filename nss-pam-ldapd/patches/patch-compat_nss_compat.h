$NetBSD$

NetBSD doesn't have <nss.h>

--- compat/nss_compat.h.orig	2012-05-11 14:25:15.000000000 +0200
+++ compat/nss_compat.h	2013-11-28 18:11:22.000000000 +0100
@@ -25,6 +25,29 @@
 
 #ifdef HAVE_NSS_H
 #include <nss.h>
+#else
+#ifdef __NetBSD__
+#include <nsswitch.h>
+enum nss_status {
+	NSS_STATUS_TRYAGAIN = -2,
+	NSS_STATUS_UNAVAIL,
+	NSS_STATUS_NOTFOUND,
+	NSS_STATUS_SUCCESS,
+	NSS_STATUS_RETURN
+};
+#define HAVE_ENUM_NSS_STATUS 1
+#include <stdarg.h>
+#define NSS_METHOD_PROTOTYPE(method) \
+	int method(void *, void *, va_list)
+#define __nss_compat_result(rv, err) \
+	((rv == NSS_STATUS_TRYAGAIN) ? (err == ERANGE ? NS_UNAVAIL : NS_TRYAGAIN) : \
+	 (rv == NSS_STATUS_TRYAGAIN) ? NS_TRYAGAIN : \
+	 (rv == NSS_STATUS_UNAVAIL)  ? NS_UNAVAIL  : \
+	 (rv == NSS_STATUS_NOTFOUND) ? NS_NOTFOUND : \
+	 (rv == NSS_STATUS_SUCCESS)  ? NS_SUCCESS  : \
+	 (rv == NSS_STATUS_RETURN)   ? NS_UNAVAIL  : \
+	0)
+#endif /* __NetBSD__ */
 #endif /* HAVE_NSS_H */
 #ifdef HAVE_NSS_COMMON_H
 #include <nss_common.h>
