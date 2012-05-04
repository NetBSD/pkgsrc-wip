$NetBSD: patch-src_netbsd.c,v 1.1 2012/05/04 10:57:24 imilh Exp $

--- src/netbsd.c.orig	2010-10-05 21:29:36.000000000 +0000
+++ src/netbsd.c
@@ -91,12 +91,12 @@ void prepare_update()
 {
 }
 
-void update_uptime()
+int update_uptime(void)
 {
 	int mib[2] = { CTL_KERN, KERN_BOOTTIME };
 	struct timeval boottime;
 	time_t now;
-	int size = sizeof(boottime);
+	size_t size = sizeof(boottime);
 
 	if ((sysctl(mib, 2, &boottime, &size, NULL, 0) != -1)
 			&& (boottime.tv_sec != 0)) {
@@ -114,7 +114,7 @@ int check_mount(char *s)
 	return 0;
 }
 
-void update_meminfo()
+int update_meminfo(void)
 {
 	int mib[] = { CTL_VM, VM_UVMEXP2 };
 	int total_pages, inactive_pages, free_pages;
@@ -125,7 +125,7 @@ void update_meminfo()
 
 	if (sysctl(mib, 2, &uvmexp, &size, NULL, 0) < 0) {
 		warn("could not get memory info");
-		return;
+		return 0;
 	}
 
 	total_pages = uvmexp.npages;
@@ -143,7 +143,7 @@ void update_meminfo()
 	}
 }
 
-void update_net_stats()
+int update_net_stats(void)
 {
 	int i;
 	double delta;
@@ -161,10 +161,10 @@ void update_net_stats()
 		if (nkd == NULL) {
 			warnx("cannot kvm_openfiles: %s", errbuf);
 			warnx("maybe you need to setgid kmem this program?");
-			return;
+			return 0;
 		} else if (kvm_nlist(nkd, namelist) != 0) {
 			warn("cannot kvm_nlist");
-			return;
+			return 0;
 		} else {
 			nkd_init = 1;
 		}
@@ -173,13 +173,13 @@ void update_net_stats()
 	if (kvm_read(nkd, (u_long) namelist[0].n_value, (void *) &ifhead,
 			sizeof(ifhead)) < 0) {
 		warn("cannot kvm_read");
-		return;
+		return 0;
 	}
 
 	/* get delta */
 	delta = current_update_time - last_update_time;
 	if (delta <= 0.0001) {
-		return;
+		return 0;
 	}
 
 	for (i = 0, ifnetaddr = (u_long) ifhead.tqh_first;
@@ -223,7 +223,7 @@ void update_net_stats()
 	}
 }
 
-void update_total_processes()
+int update_total_processes(void)
 {
 	/* It's easier to use kvm here than sysctl */
 
@@ -232,7 +232,7 @@ void update_total_processes()
 	info.procs = 0;
 
 	if (init_kvm() < 0) {
-		return;
+		return 0;
 	} else {
 		kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
 			&n_processes);
@@ -241,7 +241,7 @@ void update_total_processes()
 	info.procs = n_processes;
 }
 
-void update_running_processes()
+int update_running_processes(void)
 {
 	struct kinfo_proc2 *p;
 	int n_processes;
@@ -250,7 +250,7 @@ void update_running_processes()
 	info.run_procs = 0;
 
 	if (init_kvm() < 0) {
-		return;
+		return 0;
 	} else {
 		p = kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
 			&n_processes);
@@ -275,7 +275,7 @@ struct cpu_load_struct fresh = {
 
 long cpu_used, oldtotal, oldused;
 
-void update_cpu_usage()
+int update_cpu_usage(void)
 {
 	long used, total;
 	static u_int64_t cp_time[CPUSTATES];
@@ -297,17 +297,17 @@ void update_cpu_usage()
 	total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
 
 	if ((total - oldtotal) != 0) {
-		info.cpu_usage = ((double) (used - oldused)) /
-			(double) (total - oldtotal);
+		info.cpu_usage[0] = ((double) (used - oldused)) /
+				(double) (total - oldtotal);
 	} else {
-		info.cpu_usage = 0;
+		info.cpu_usage[0] = 0;
 	}
 
 	oldused = used;
 	oldtotal = total;
 }
 
-void update_load_average()
+int update_load_average(void)
 {
 	double v[3];
 
@@ -364,3 +364,50 @@ int get_entropy_poolsize(unsigned int *v
 {
 	return 1;
 }
+
+/* void */
+char get_freq(char *p_client_buffer, size_t client_buffer_size,
+                const char *p_format, int divisor, unsigned int cpu)
+{
+        int freq = cpu;
+
+        if (!p_client_buffer || client_buffer_size <= 0 || !p_format
+                        || divisor <= 0) {
+                return 0;
+        }
+
+        size_t size = sizeof(freq);
+
+	if (sysctlbyname("machdep.est.frequency.current",
+			NULL, &size, NULL, 0) == 0) {
+		sysctlbyname("machdep.est.frequency.current", &freq, &size, NULL, 0);
+                snprintf(p_client_buffer, client_buffer_size, p_format,
+                        (float) freq / divisor);
+        } else {
+                snprintf(p_client_buffer, client_buffer_size, p_format, 0.0f);
+        }
+
+        return 1;
+}
+
+void get_cpu_count()
+{
+        int cpu_count = 1;      /* default to 1 cpu */
+
+        info.cpu_count = cpu_count;
+
+        info.cpu_usage = malloc(info.cpu_count * sizeof(float));
+        if (info.cpu_usage == NULL) {
+                warn("malloc");
+        }
+}
+
+void update_diskio()
+{
+        return; /* XXX: implement? hifi: not sure how */
+}
+
+int update_top()
+{
+	return 0;
+}
