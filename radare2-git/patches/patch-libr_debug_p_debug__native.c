$NetBSD$

--- libr/debug/p/debug_native.c.orig	2016-07-18 23:01:08.000000000 +0000
+++ libr/debug/p/debug_native.c
@@ -508,13 +508,22 @@ static RList *r_debug_native_pids (int p
 		}
 	}
 #else /* rest is BSD */
-#ifdef __OpenBSD__
+#ifdef __NetBSD__
+# define KVM_OPEN_FLAG KVM_NO_FILES
+# define KVM_GETPROCS(kd, opt, arg, cntptr) \
+	kvm_getproc2 (kd, opt, arg, sizeof(struct kinfo_proc2), cntptr)
+# define KP_COMM(x) (x)->p_comm
+# define KP_PID(x) (x)->p_pid
+# define KP_PPID(x) (x)->p_ppid
+# define KINFO_PROC kinfo_proc2
+#elif defined(__OpenBSD__)
 # define KVM_OPEN_FLAG KVM_NO_FILES
 # define KVM_GETPROCS(kd, opt, arg, cntptr) \
 	kvm_getprocs (kd, opt, arg, sizeof(struct kinfo_proc), cntptr)
 # define KP_COMM(x) (x)->p_comm
 # define KP_PID(x) (x)->p_pid
 # define KP_PPID(x) (x)->p_ppid
+# define KINFO_PROC kinfo_proc
 #else
 # define KVM_OPEN_FLAG O_RDONLY
 # define KVM_GETPROCS(kd, opt, arg, cntptr) \
@@ -522,11 +531,12 @@ static RList *r_debug_native_pids (int p
 # define KP_COMM(x) (x)->ki_comm
 # define KP_PID(x) (x)->ki_pid
 # define KP_PPID(x) (x)->ki_ppid
+# define KINFO_PROC kinfo_proc
 #endif
 	char errbuf[_POSIX2_LINE_MAX];
-	struct kinfo_proc* kp;
+	struct KINFO_PROC* kp;
 	int cnt = 0;
-	kvm_t* kd = kvm_openfiles (NULL, NULL, NULL, KVM_OPEN_FLAG, &errbuf);
+	kvm_t* kd = kvm_openfiles (NULL, NULL, NULL, KVM_OPEN_FLAG, errbuf);
 	if (!kd) {
 		eprintf ("kvm_openfiles says %s\n", errbuf);
 		return NULL;
@@ -819,6 +829,50 @@ static RList *r_debug_native_sysctl_map 
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
@@ -956,7 +1010,8 @@ static RList *r_debug_native_map_get (RD
 	region[0] = region2[0] = '0';
 	region[1] = region2[1] = 'x';
 
-#if __OpenBSD__
+#if __NetBSD__ || __OpenBSD__
+	/* Prefer sysctl(7) over procfs on NetBSD */
 	/* OpenBSD has no procfs, so no idea trying. */
 	return r_debug_native_sysctl_map (dbg);
 #endif
