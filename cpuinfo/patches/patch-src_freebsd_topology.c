$NetBSD$

NetBSD support.

--- src/freebsd/topology.c.orig	2025-07-24 17:36:24.000000000 +0000
+++ src/freebsd/topology.c
@@ -50,6 +50,7 @@ struct cpuinfo_freebsd_topology cpuinfo_
 		.threads_per_core = 0,
 		.threads = 0,
 	};
+#if defined(__FreeBSD)
 	char* topology_spec = sysctl_str("kern.sched.topology_spec");
 	if (!topology_spec) {
 		return topology;
@@ -94,6 +95,13 @@ struct cpuinfo_freebsd_topology cpuinfo_
 		topology.threads_per_core);
 	topology.threads = topology.threads_per_core * topology.cores;
 	return topology;
+#elif defined(__NetBSD__)
+	topology.cores = sysctl_int("hw.ncpu");
+	if (topology.cores == 0) {
+		goto fail;
+	}
+	return topology;
+#endif
 fail:
 	topology.packages = 0;
 	return topology;
