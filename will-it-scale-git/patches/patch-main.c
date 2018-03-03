$NetBSD$

--- main.c.orig	2018-03-02 23:24:04.000000000 +0000
+++ main.c
@@ -15,11 +15,31 @@
 #include <string.h>
 #include <sys/mman.h>
 #include <hwloc.h>
+#if __linux__
 #include <hwloc/glibc-sched.h>
+#endif
 #include <sys/types.h>
 #include <signal.h>
 #include <poll.h>
 
+#ifdef __NetBSD__
+#define cpu_set_t cpuset_t
+#define sched_setaffinity sched_setaffinity_np
+#define sched_getaffinity sched_getaffinity_np
+static inline int
+hwloc_cpuset_to_glibc_sched_affinity(hwloc_topology_t topology __unused, hwloc_const_cpuset_t hwlocset,
+				    cpu_set_t *schedset, size_t schedsetsize)
+{
+  unsigned cpu;
+  cpuset_zero(schedset);
+  hwloc_bitmap_foreach_begin(cpu, hwlocset)
+    cpuset_set(cpu, schedset);
+  hwloc_bitmap_foreach_end();
+
+  return 0;
+}
+#endif
+
 #define MAX_TASKS 1024
 #define CACHELINE_SIZE 128
 #define WARMUP_ITERATIONS 5
@@ -103,11 +123,27 @@ void new_task(void *(func)(void *), void
 	pthread_create(&tid, NULL, func, arg);
 }
 
+#ifdef __NetBSD__
+struct nb_args {
+	struct args *args;
+	cpuset_t *mask;
+};
+
+void *
+testcase_trampoline_nb(void *a)
+{
+	struct nb_args *A = (struct nb_args *)a;
+	pthread_setaffinity_np(pthread_self(), cpuset_size(A->mask), A->mask);
+	return testcase_trampoline(A->args);
+}
+#endif
+
 void new_task_affinity(struct args *args,
 		       size_t cpuset_size, cpu_set_t *mask)
 {
-	pthread_attr_t attr;
 	pthread_t tid;
+#ifdef __linux__
+	pthread_attr_t attr;
 
 	pthread_attr_init(&attr);
 
@@ -116,6 +152,13 @@ void new_task_affinity(struct args *args
 	pthread_create(&tid, &attr, testcase_trampoline, args);
 
 	pthread_attr_destroy(&attr);
+#else
+	struct nb_args nba = {
+		.args = args,
+		.mask = mask
+	};
+	pthread_create(&tid, NULL, testcase_trampoline_nb, &nba);
+#endif
 }
 
 /* All threads will die when we exit */
@@ -169,10 +212,18 @@ void new_task(void *(func)(void *), void
 void new_task_affinity(struct args *args,
 		       size_t cpuset_size, cpu_set_t *mask)
 {
+#ifdef __linux__
 	cpu_set_t old_mask;
+#elif defined(__NetBSD__)
+	cpu_set_t *old_mask = cpuset_create();
+#endif
 	int pid;
 
-	sched_getaffinity(0, sizeof(old_mask), &old_mask);
+	sched_getaffinity(0, sizeof(old_mask),
+#ifdef __linux__
+	&
+#endif
+	old_mask);
 	sched_setaffinity(0, cpuset_size, mask);
 
 	parent_pid = getpid();
@@ -195,7 +246,15 @@ void new_task_affinity(struct args *args
 		testcase_trampoline(args);
 	}
 
-	sched_setaffinity(0, sizeof(old_mask), &old_mask);
+	sched_setaffinity(0, sizeof(old_mask),
+#ifdef __linux__
+	&
+#endif
+	old_mask);
+
+#ifdef __NetBSD__
+	cpuset_destroy(old_mask);
+#endif
 
 	pids[nr_pids++] = pid;
 }
@@ -273,7 +332,11 @@ int main(int argc, char *argv[])
 			smt_affinity ? HWLOC_OBJ_PU : HWLOC_OBJ_CORE);
 	for (i = 0; i < opt_tasks; i++) {
 		hwloc_obj_t obj;
+#if __linux__
 		cpu_set_t mask;
+#elif defined(__NetBSD__)
+		cpuset_t *mask = cpuset_create();
+#endif
 		struct args *args;
 
 		args = malloc(sizeof(struct args));
@@ -290,8 +353,19 @@ int main(int argc, char *argv[])
 				smt_affinity ? HWLOC_OBJ_PU : HWLOC_OBJ_CORE,
 				i % n);
 		hwloc_cpuset_to_glibc_sched_affinity(topology,
-				obj->cpuset, &mask, sizeof(mask));
-		new_task_affinity(args, sizeof(mask), &mask);
+				obj->cpuset,
+#ifdef	__linux__
+				&
+#endif
+				mask, sizeof(mask));
+		new_task_affinity(args, sizeof(mask),
+#ifdef __linux__
+				&
+#endif
+				mask);
+#ifdef __NetBSD__
+		cpuset_destroy(mask);
+#endif
 	}
 
 	if (write(fd[1], &i, 1) != 1) {
