$NetBSD$

--- src/pipewire/thread.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/pipewire/thread.c
@@ -20,6 +20,11 @@
 #include <pipewire/private.h>
 #include <pipewire/thread.h>
 
+#if defined(__NetBSD__)
+#include <sched.h>
+#define cpu_set_t cpuset_t*
+#endif
+
 #define CHECK(expression,label)						\
 do {									\
 	if ((errno = (expression)) != 0) {				\
@@ -34,13 +39,22 @@ static int parse_affinity(const char *af
 	struct spa_json it[1];
 	int v;
 
+#if defined(__NetBSD__)
+	cpuset_zero(*set);
+#else
 	CPU_ZERO(set);
+#endif
 	if (spa_json_begin_array_relax(&it[0], affinity, strlen(affinity)) <= 0)
 		return 0;
 
 	while (spa_json_get_int(&it[0], &v) > 0) {
+#if defined(__NetBSD__)
+		if (v >= 0 && v < cpuset_size(*set))
+			cpuset_set(v, *set);
+#else
 		if (v >= 0 && v < CPU_SETSIZE)
 			CPU_SET(v, set);
+#endif
         }
 	return 0;
 }
@@ -82,7 +96,11 @@ static int thread_setaffinity(pthread_t 
 {
 	cpu_set_t set;
 	parse_affinity(affinity, &set);
+#if defined(__NetBSD__)
+	return -pthread_setaffinity_np(thread, sizeof(set), set);
+#else
 	return -pthread_setaffinity_np(thread, sizeof(set), &set);
+#endif
 }
 
 static struct spa_thread *impl_create(void *object,
@@ -113,7 +131,11 @@ static struct spa_thread *impl_create(vo
 	}
 	if (props) {
 		if ((str = spa_dict_lookup(props, SPA_KEY_THREAD_NAME)) != NULL &&
+#if defined(__NetBSD__)
+		    (err = pthread_setname_np(pt, "%s", str)) != 0)
+#else
 		    (err = pthread_setname_np(pt, str)) != 0)
+#endif
 			pw_log_warn("pthread_setname error: %s", strerror(err));
 		if ((str = spa_dict_lookup(props, SPA_KEY_THREAD_AFFINITY)) != NULL &&
 		    (err = thread_setaffinity(pt, str)) != 0)
