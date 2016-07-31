$NetBSD$

--- libr/debug/p/debug_native.c.orig	2016-07-22 19:52:09.000000000 +0000
+++ libr/debug/p/debug_native.c
@@ -829,6 +829,50 @@ static RList *r_debug_native_sysctl_map 
 	free (buf);
 	return list;
 }
+#elif __NetBSD__
+static RList *r_debug_native_sysctl_map (RDebug *dbg) {
+	int mib[5];
+	size_t len;
+	struct kinfo_vmentry entry;
+	u_long old_end = 0;
+	RList *list = NULL;
+	RDebugMap *map;
+
+	len = sizeof(entry);
+	mib[0] = CTL_VM;
+	mib[1] = VM_PROC;
+	mib[2] = VM_PROC_MAP;
+	mib[3] = dbg->pid;
+	mib[4] = sizeof(struct kinfo_vmentry);
+	entry.kve_start = 0;
+
+	if (sysctl (mib, 5, &entry, &len, NULL, 0) == -1) {
+		eprintf ("Could not get memory map: %s\n", strerror(errno));
+		return NULL;
+	}
+
+	list = r_debug_map_list_new();
+	if (!list) return NULL;
+
+	while (sysctl (mib, 5, &entry, &len, NULL, 0) != -1) {
+		if (old_end == entry.kve_end) {
+			/* No more entries */
+			break;
+		}
+		/* path to vm obj is not included in kinfo_vmentry.
+		 * see usr.sbin/procmap for namei-cache lookup.
+		 */
+		map = r_debug_map_new ("", entry.kve_start, entry.kve_end,
+				entry.kve_protection, 0);
+		if (!map) break;
+		r_list_append (list, map);
+
+		entry.kve_start = entry.kve_start + 1;
+		old_end = entry.kve_end;
+	}
+
+	return list;
+}
 #elif __OpenBSD__
 static RList *r_debug_native_sysctl_map (RDebug *dbg) {
 	int mib[3];
@@ -966,7 +1010,8 @@ static RList *r_debug_native_map_get (RD
 	region[0] = region2[0] = '0';
 	region[1] = region2[1] = 'x';
 
-#if __OpenBSD__
+#if __NetBSD__ || __OpenBSD__
+	/* Prefer sysctl(7) over procfs on NetBSD */
 	/* OpenBSD has no procfs, so no idea trying. */
 	return r_debug_native_sysctl_map (dbg);
 #endif
