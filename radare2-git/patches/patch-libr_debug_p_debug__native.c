$NetBSD$

--- libr/debug/p/debug_native.c.orig	2016-07-18 23:01:08.145880903 +0000
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
