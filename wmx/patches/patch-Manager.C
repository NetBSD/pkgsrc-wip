$NetBSD: patch-Manager.C,v 1.1.1.1 2011/05/05 13:07:00 ishit Exp $

--- Manager.C.orig	2009-01-09 11:18:03.000000000 +0000
+++ Manager.C
@@ -61,6 +61,12 @@ Boolean ignoreBadWindowErrors;
 
 implementPList(ClientList, Client);
 
+#ifdef __OpenBSD__
+extern "C" {
+	int      snprintf(char *, size_t, const char *, ...);
+}
+#endif
+
 #if CONFIG_GROUPS != False
 implementPList(ListList, ClientList);
 #endif
