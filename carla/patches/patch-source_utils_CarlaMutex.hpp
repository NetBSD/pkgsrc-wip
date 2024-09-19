$NetBSD$

NetBSD does not have pthread_condattr_setpshared.

--- source/utils/CarlaMutex.hpp.orig	2020-09-26 14:38:36.000000000 +0000
+++ source/utils/CarlaMutex.hpp
@@ -204,7 +204,9 @@ public:
     {
         pthread_condattr_t cattr;
         pthread_condattr_init(&cattr);
+#if defined(PTHREAD_PROCESS_PRIVATE) && !defined(__NetBSD__)
         pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_PRIVATE);
+#endif
         pthread_cond_init(&fCondition, &cattr);
         pthread_condattr_destroy(&cattr);
 
