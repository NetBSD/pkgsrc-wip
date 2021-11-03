$NetBSD$

support NetBSD

--- kernel/yosys.cc.orig	2021-11-01 14:44:53.161071165 +0000
+++ kernel/yosys.cc
@@ -55,7 +55,7 @@
 #  include <glob.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/sysctl.h>
 #endif
 
@@ -790,6 +790,22 @@ std::string proc_self_dirname()
 	free(buffer);
 	return path;
 }
+#elif defined(__NetBSD__)
+std::string proc_self_dirname()
+{
+	const int mib[4] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+	char *buffer;
+	size_t buflen;
+	std::string path;
+	buffer = (char *)asysctl(mib, 4, &buflen);
+	if (buffer == NULL)
+		log_error("sysctl failed: %s\n", strerror(errno));
+	while (buflen > 0 && buffer[buflen-1] != '/')
+		buflen--;
+	path.assign(buffer, buflen);
+	free(buffer);
+	return path;
+}
 #elif defined(__APPLE__)
 std::string proc_self_dirname()
 {
