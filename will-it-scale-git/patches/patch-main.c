$NetBSD$

--- main.c.orig	2018-03-17 15:30:11.000000000 +0000
+++ main.c
@@ -15,7 +15,6 @@
 #include <string.h>
 #include <sys/mman.h>
 #include <hwloc.h>
-#include <hwloc/glibc-sched.h>
 #include <sys/types.h>
 #include <signal.h>
 #include <poll.h>
@@ -80,6 +79,8 @@ struct args
 	unsigned long long *arg1;
 	unsigned long arg2;
 	int poll_fd;
+	hwloc_topology_t topology;
+	hwloc_cpuset_t cpuset;
 };
 
 static void *testcase_trampoline(void *p)
@@ -103,17 +104,29 @@ void new_task(void *(func)(void *), void
 	pthread_create(&tid, NULL, func, arg);
 }
 
-void new_task_affinity(struct args *args,
-		       size_t cpuset_size, cpu_set_t *mask)
+static void *thread_pre_trampoline(void *p)
+{
+	struct args *args;
+
+	args = (struct args *)p;
+	if (hwloc_set_thread_cpubind(args->topology, pthread_self(),
+	    args->cpuset, 0)) {
+		perror("hwloc_set_thread_cpubind");
+		exit(1);
+	}
+	hwloc_topology_destroy(args->topology);
+	hwloc_bitmap_free(args->cpuset);
+	return testcase_trampoline(args);
+}
+
+void new_task_affinity(struct args *args)
 {
 	pthread_attr_t attr;
 	pthread_t tid;
 
 	pthread_attr_init(&attr);
 
-	pthread_attr_setaffinity_np(&attr, cpuset_size, mask);
-
-	pthread_create(&tid, &attr, testcase_trampoline, args);
+	pthread_create(&tid, &attr, thread_pre_trampoline, args);
 
 	pthread_attr_destroy(&attr);
 }
@@ -166,14 +179,27 @@ void new_task(void *(func)(void *), void
 	pids[nr_pids++] = pid;
 }
 
-void new_task_affinity(struct args *args,
-		       size_t cpuset_size, cpu_set_t *mask)
+void new_task_affinity(struct args *args)
 {
-	cpu_set_t old_mask;
+	hwloc_cpuset_t old_set;
 	int pid;
 
-	sched_getaffinity(0, sizeof(old_mask), &old_mask);
-	sched_setaffinity(0, cpuset_size, mask);
+
+	old_set = hwloc_bitmap_alloc();
+	if (old_set == NULL) {
+		perror("hwloc_bitmap_alloc");
+		exit(1);
+	}
+	if (hwloc_get_cpubind(args->topology, old_set,
+	    HWLOC_CPUBIND_PROCESS) < 0) {
+		perror("hwloc_get_cpubind");
+		exit(1);
+	}
+	if (hwloc_set_cpubind(args->topology, args->cpuset,
+	    HWLOC_CPUBIND_PROCESS) < 0) {
+		perror("hwloc_set_cpubind");
+		exit(1);
+	}
 
 	parent_pid = getpid();
 
@@ -195,9 +221,17 @@ void new_task_affinity(struct args *args
 		testcase_trampoline(args);
 	}
 
-	sched_setaffinity(0, sizeof(old_mask), &old_mask);
+	if (hwloc_set_cpubind(args->topology, old_set,
+	    HWLOC_CPUBIND_PROCESS) < 0) {
+		perror("hwloc_set_cpubind");
+		exit(1);
+	}
 
 	pids[nr_pids++] = pid;
+	hwloc_topology_destroy(args->topology);
+	hwloc_bitmap_free(args->cpuset);
+	hwloc_bitmap_free(old_set);
+
 }
 
 
@@ -273,7 +307,6 @@ int main(int argc, char *argv[])
 			smt_affinity ? HWLOC_OBJ_PU : HWLOC_OBJ_CORE);
 	for (i = 0; i < opt_tasks; i++) {
 		hwloc_obj_t obj;
-		cpu_set_t mask;
 		struct args *args;
 
 		args = malloc(sizeof(struct args));
@@ -285,13 +318,18 @@ int main(int argc, char *argv[])
 		args->arg1 = results[i];
 		args->arg2 = i;
 		args->poll_fd = fd[0];
-
 		obj = hwloc_get_obj_by_type(topology,
 				smt_affinity ? HWLOC_OBJ_PU : HWLOC_OBJ_CORE,
 				i % n);
-		hwloc_cpuset_to_glibc_sched_affinity(topology,
-				obj->cpuset, &mask, sizeof(mask));
-		new_task_affinity(args, sizeof(mask), &mask);
+		if ((args->cpuset = hwloc_bitmap_dup(obj->cpuset)) == NULL) {
+			perror("hwloc_bitmap_dup");
+			exit(1);
+		}
+		if (hwloc_topology_dup(&args->topology, topology)) {
+			perror("hwloc_topology_dup");
+			exit(1);
+		}
+		new_task_affinity(args);
 	}
 
 	if (write(fd[1], &i, 1) != 1) {
