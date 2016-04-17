$NetBSD$

--- mono/utils/mono-threads-posix.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/utils/mono-threads-posix.c
@@ -296,6 +296,16 @@ mono_threads_core_set_name (MonoNativeTh
 		n [62] = '\0';
 		pthread_setname_np (n);
 	}
+#elif defined (__NetBSD__)
+	if (!name) {
+		pthread_setname_np (tid, "%s", (void*)"");
+	} else {
+		char n [PTHREAD_MAX_NAMELEN_NP];
+
+		strncpy (n, name, PTHREAD_MAX_NAMELEN_NP);
+		n [PTHREAD_MAX_NAMELEN_NP - 1] = '\0';
+		pthread_setname_np (tid, "%s", (void*)n);
+	}
 #elif defined (HAVE_PTHREAD_SETNAME_NP)
 	if (!name) {
 		pthread_setname_np (tid, "");
