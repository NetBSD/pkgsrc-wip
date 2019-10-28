$NetBSD$

* Add <stdlib.h> for pseudo-random number generator functions.
* Replace lrand48_r(3) by rand_r(3).

--- jsm/sessions.cc.orig	2019-09-29 18:37:09.000000000 +0000
+++ jsm/sessions.cc
@@ -37,6 +37,7 @@
 
 #include <messages.hh>
 #include <namespaces.hh>
+#include <stdlib.h>
 
 /* forward declarations */
 void _js_session_start(void *arg);
@@ -103,26 +104,41 @@ void js_session_route(session s, xmlnode
  */
 static void _js_create_session_id(char resultbuffer[9], xht existing_sessions) {
     static int seeded = 0;
+#if defined(__NetBSD__) || defined(__OpenBSD) || defined(__FreeBSD__) || defined(__DragonFly__)
+    static unsigned int seed;
+#else
     static struct drand48_data rand_state;
+#endif
     long int rand_value;
     int tries = 256;
 
     /* seed the random number generator on the first call */
     if (!seeded) {
         struct timeval now;
+#if !(defined(__NetBSD__) || defined(__OpenBSD) || defined(__FreeBSD__) || defined(__DragonFly__))
         unsigned short int seed_data[3];
+#endif
 
         gettimeofday(&now, NULL);
+#if defined(__NetBSD__) || defined(__OpenBSD) || defined(__FreeBSD__) || defined(__DragonFly__)
+        seed = now.tv_usec;
+        srand(seed);
+#else
         seed_data[0] = now.tv_sec % 0x10000;
         seed_data[1] = now.tv_sec / 0x10000;
         seed_data[2] = now.tv_usec % 0x10000;
         seed48_r(seed_data, &rand_state);
+#endif
         seeded = 1;
     }
 
     /* create an ID, that is not already used */
     while (tries--) {
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+        rand_value = rand_r(&seed);
+#else
         lrand48_r(&rand_state, &rand_value);
+#endif
         snprintf(resultbuffer, 9, "%lx", rand_value);
 
         if (existing_sessions == NULL ||
