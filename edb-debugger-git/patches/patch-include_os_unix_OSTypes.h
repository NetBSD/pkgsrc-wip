$NetBSD$

--- include/os/unix/OSTypes.h.orig	2017-02-18 21:21:09.000000000 +0000
+++ include/os/unix/OSTypes.h
@@ -24,7 +24,12 @@ along with this program.  If not, see <h
 namespace edb {
 	using   ::pid_t;
 	using   ::uid_t;
+#if defined(__NetBSD__)
+	typedef ::pid_t pid_t;
+	typedef ::lwpid_t tid_t;
+#else
 	typedef ::pid_t tid_t;
+#endif
 }
 
 #endif
