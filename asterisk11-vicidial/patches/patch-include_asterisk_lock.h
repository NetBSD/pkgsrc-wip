$NetBSD: patch-include_asterisk_lock.h,v 1.3 2015/05/19 07:52:14 jnemeth Exp $

--- include/asterisk/lock.h.orig	2015-02-21 02:45:17.000000000 +0000
+++ include/asterisk/lock.h
@@ -516,6 +516,17 @@ static void  __attribute__((destructor))
 #define AST_RWLOCK_DEFINE_STATIC(rwlock) __AST_RWLOCK_DEFINE(static, rwlock, AST_RWLOCK_INIT_VALUE, 1)
 #define AST_RWLOCK_DEFINE_STATIC_NOTRACKING(rwlock) __AST_RWLOCK_DEFINE(static, rwlock, AST_RWLOCK_INIT_VALUE_NOTRACKING, 0)
 
+#undef pthread_mutex_lock
+#undef pthread_mutex_unlock
+#undef pthread_mutex_trylock
+#undef pthread_mutex_init
+#undef pthread_mutex_destroy
+#undef pthread_cond_init
+#undef pthread_cond_destroy
+#undef pthread_cond_signal
+#undef pthread_cond_broadcast
+#undef pthread_cond_wait
+#undef pthread_cond_timedwait
 #ifndef __CYGWIN__	/* temporary disabled for cygwin */
 #define pthread_mutex_t		use_ast_mutex_t_instead_of_pthread_mutex_t
 #define pthread_cond_t		use_ast_cond_t_instead_of_pthread_cond_t
@@ -536,7 +547,7 @@ static void  __attribute__((destructor))
 
 #define gethostbyname __gethostbyname__is__not__reentrant__use__ast_gethostbyname__instead__
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #define pthread_create __use_ast_pthread_create_instead__
 #endif
 
@@ -558,6 +569,10 @@ int ast_atomic_fetchadd_int_slow(volatil
 #include "libkern/OSAtomic.h"
 #endif
 
+#if defined(HAVE_SYS_ATOMIC_H)
+#include <sys/atomic.h>
+#endif
+
 /*! \brief Atomically add v to *p and return * the previous value of *p.
  * This can be used to handle reference counts, and the return value
  * can be used to generate unique identifiers.
@@ -578,6 +593,16 @@ AST_INLINE_API(int ast_atomic_fetchadd_i
 {
 	return OSAtomicAdd64(v, (int64_t *) p) - v;
 })
+#elif defined(HAVE_SYS_ATOMIC_H) && (SIZEOF_INT == 4)
+AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
+{
+	return atomic_add_32_nv((uint32_t *)p, v) - v;
+})
+#elif defined(HAVE_SYS_ATOMIC_H) && (SIZEOF_INT == 8)
+AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
+{
+	return atomic_add_64_nv((uint64_t *)p, v) - v;
+})
 #elif defined (__i386__) || defined(__x86_64__)
 #ifdef sun
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
@@ -625,6 +650,16 @@ AST_INLINE_API(int ast_atomic_dec_and_te
 {
 	return OSAtomicAdd64( -1, (int64_t *) p) == 0;
 })
+#elif defined(HAVE_SYS_ATOMIC_H) && (SIZEOF_INT == 4)
+AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
+{
+	return atomic_dec_32_nv((uint32_t *)p) == 0;
+})
+#elif defined(HAVE_SYS_ATOMIC_H) && (SIZEOF_INT == 8)
+AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
+{
+	return atomic_dec_64_nv((uint64_t *)p) == 0;
+})
 #else
 AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
 {
