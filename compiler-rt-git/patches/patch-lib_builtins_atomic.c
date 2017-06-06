$NetBSD$

--- lib/builtins/atomic.c.orig	2017-06-04 14:47:39.000000000 +0000
+++ lib/builtins/atomic.c
@@ -45,6 +45,65 @@
 #endif
 static const long SPINLOCK_MASK = SPINLOCK_COUNT - 1;
 
+#if defined(__clang__)
+#define atomic_store_explicit(object, desired, order)                          \
+  __c11_atomic_store(object, desired, order)
+#define atomic_compare_exchange_weak_explicit(object, expected, desired,       \
+                                              success, failure)                \
+  __c11_atomic_compare_exchange_weak(object, expected, desired, success,       \
+                                     failure)
+#define atomic_is_lock_free(object) __c11_atomic_is_lock_free(object)
+#define atomic_load_explicit(object, order) __c11_atomic_load(object, order)
+#define atomic_compare_exchange_strong_explicit(object, expected, desired,     \
+                                                success, failure)              \
+  __c11_atomic_compare_exchange_strong(object, expected, desired, success,     \
+                                       failure)
+#define atomic_exchange_explicit(object, desired, order)                       \
+  __c11_atomic_exchange(object, desired, order)
+#define atomic_thread_fence(object)                       \
+  __c11_atomic_thread_fence(object)
+#define atomic_fetch_add_explicit(object, operand, order)                      \
+  __c11_atomic_fetch_add(object, operand, order)
+#define atomic_fetch_and_explicit(object, operand, order)                      \
+  __c11_atomic_fetch_and(object, operand, order)
+#define atomic_fetch_or_explicit(object, operand, order)                       \
+  __c11_atomic_fetch_or(object, operand, order)
+#define atomic_fetch_sub_explicit(object, operand, order)                      \
+  __c11_atomic_fetch_sub(object, operand, order)
+#define atomic_fetch_xor_explicit(object, operand, order)                      \
+  __c11_atomic_fetch_xor(object, operand, order)
+#elif defined(__GNUC__)
+#define atomic_store_explicit(object, desired, order)                          \
+  __atomic_store_n(&(object)->__val, desired, order)
+#define atomic_compare_exchange_weak_explicit(object, expected, desired,       \
+                                              success, failure)                \
+  __atomic_compare_exchange_n(&(object)->__val, expected, desired, 1, success, \
+                              failure)
+#define atomic_is_lock_free(object) __atomic_is_lock_free(object)
+#define atomic_load_explicit(object, order)                                    \
+  __atomic_load_n(&(object)->__val, order)
+#define atomic_compare_exchange_strong_explicit(object, expected, desired,     \
+                                                success, failure)              \
+  __atomic_compare_exchange_n(&(object)->__val, expected, desired, 0, success, \
+                              failure)
+#define atomic_exchange_explicit(object, desired, order)                       \
+  __atomic_exchange_n(&(object)->__val, desired, order)
+#define atomic_thread_fence(object)                       \
+  __atomic_thread_fence(object)
+#define atomic_fetch_add_explicit(object, operand, order)                      \
+  __atomic_fetch_add(&(object)->__val, operand, order)
+#define atomic_fetch_and_explicit(object, operand, order)                      \
+  __atomic_fetch_and(&(object)->__val, operand, order)
+#define atomic_fetch_or_explicit(object, operand, order)                       \
+  __atomic_fetch_or(&(object)->__val, operand, order)
+#define atomic_fetch_sub_explicit(object, operand, order)                      \
+  __atomic_fetch_sub(&(object)->__val, operand, order)
+#define atomic_fetch_xor_explicit(object, operand, order)                      \
+  __atomic_fetch_xor(&(object)->__val, operand, order)
+#else
+#error "atomic.c does not support your compiler"
+#endif
+
 ////////////////////////////////////////////////////////////////////////////////
 // Platform-specific lock implementation.  Falls back to spinlocks if none is
 // defined.  Each platform should define the Lock type, and corresponding
@@ -57,14 +116,14 @@ static const long SPINLOCK_MASK = SPINLO
 #include <sys/umtx.h>
 typedef struct _usem Lock;
 __inline static void unlock(Lock *l) {
-  __c11_atomic_store((_Atomic(uint32_t)*)&l->_count, 1, __ATOMIC_RELEASE);
+  atomic_store_explicit((_Atomic(uint32_t)*)&l->_count, 1, __ATOMIC_RELEASE);
   __c11_atomic_thread_fence(__ATOMIC_SEQ_CST);
   if (l->_has_waiters)
       _umtx_op(l, UMTX_OP_SEM_WAKE, 1, 0, 0);
 }
 __inline static void lock(Lock *l) {
   uint32_t old = 1;
-  while (!__c11_atomic_compare_exchange_weak((_Atomic(uint32_t)*)&l->_count, &old,
+  while (!atomic_compare_exchange_weak_explicit((_Atomic(uint32_t)*)&l->_count, &old,
         0, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)) {
     _umtx_op(l, UMTX_OP_SEM_WAIT, 0, 0, 0);
     old = 1;
@@ -90,13 +149,13 @@ static Lock locks[SPINLOCK_COUNT]; // in
 typedef _Atomic(uintptr_t) Lock;
 /// Unlock a lock.  This is a release operation.
 __inline static void unlock(Lock *l) {
-  __c11_atomic_store(l, 0, __ATOMIC_RELEASE);
+  atomic_store_explicit(l, 0, __ATOMIC_RELEASE);
 }
 /// Locks a lock.  In the current implementation, this is potentially
 /// unbounded in the contended case.
 __inline static void lock(Lock *l) {
   uintptr_t old = 0;
-  while (!__c11_atomic_compare_exchange_weak(l, &old, 1, __ATOMIC_ACQUIRE,
+  while (!atomic_compare_exchange_weak_explicit(l, &old, 1, __ATOMIC_ACQUIRE,
         __ATOMIC_RELAXED))
     old = 0;
 }
@@ -125,10 +184,10 @@ static __inline Lock *lock_for_pointer(v
 /// Macros for determining whether a size is lock free.  Clang can not yet
 /// codegen __atomic_is_lock_free(16), so for now we assume 16-byte values are
 /// not lock free.
-#define IS_LOCK_FREE_1 __c11_atomic_is_lock_free(1)
-#define IS_LOCK_FREE_2 __c11_atomic_is_lock_free(2)
-#define IS_LOCK_FREE_4 __c11_atomic_is_lock_free(4)
-#define IS_LOCK_FREE_8 __c11_atomic_is_lock_free(8)
+#define IS_LOCK_FREE_1 atomic_is_lock_free(1)
+#define IS_LOCK_FREE_2 atomic_is_lock_free(2)
+#define IS_LOCK_FREE_4 atomic_is_lock_free(4)
+#define IS_LOCK_FREE_8 atomic_is_lock_free(8)
 #define IS_LOCK_FREE_16 0
 
 /// Macro that calls the compiler-generated lock-free versions of functions
@@ -161,7 +220,7 @@ static __inline Lock *lock_for_pointer(v
 /// pointer only.
 void __atomic_load_c(int size, void *src, void *dest, int model) {
 #define LOCK_FREE_ACTION(type) \
-    *((type*)dest) = __c11_atomic_load((_Atomic(type)*)src, model);\
+    *((type*)dest) = atomic_load_explicit((_Atomic(type)*)src, model);\
     return;
   LOCK_FREE_CASES();
 #undef LOCK_FREE_ACTION
@@ -175,7 +234,7 @@ void __atomic_load_c(int size, void *src
 /// pointer only.
 void __atomic_store_c(int size, void *dest, void *src, int model) {
 #define LOCK_FREE_ACTION(type) \
-    __c11_atomic_store((_Atomic(type)*)dest, *(type*)dest, model);\
+    atomic_store_explicit((_Atomic(type)*)dest, *(type*)dest, model);\
     return;
   LOCK_FREE_CASES();
 #undef LOCK_FREE_ACTION
@@ -193,7 +252,7 @@ void __atomic_store_c(int size, void *de
 int __atomic_compare_exchange_c(int size, void *ptr, void *expected,
     void *desired, int success, int failure) {
 #define LOCK_FREE_ACTION(type) \
-  return __c11_atomic_compare_exchange_strong((_Atomic(type)*)ptr, (type*)expected,\
+  return atomic_compare_exchange_strong_explicit((_Atomic(type)*)ptr, (type*)expected,\
       *(type*)desired, success, failure)
   LOCK_FREE_CASES();
 #undef LOCK_FREE_ACTION
@@ -213,7 +272,7 @@ int __atomic_compare_exchange_c(int size
 /// with respect to the target address.
 void __atomic_exchange_c(int size, void *ptr, void *val, void *old, int model) {
 #define LOCK_FREE_ACTION(type) \
-    *(type*)old = __c11_atomic_exchange((_Atomic(type)*)ptr, *(type*)val,\
+    *(type*)old = atomic_exchange_explicit((_Atomic(type)*)ptr, *(type*)val,\
         model);\
     return;
   LOCK_FREE_CASES();
@@ -247,7 +306,7 @@ void __atomic_exchange_c(int size, void 
 #define OPTIMISED_CASE(n, lockfree, type)\
 type __atomic_load_##n(type *src, int model) {\
   if (lockfree)\
-    return __c11_atomic_load((_Atomic(type)*)src, model);\
+    return atomic_load_explicit((_Atomic(type)*)src, model);\
   Lock *l = lock_for_pointer(src);\
   lock(l);\
   type val = *src;\
@@ -260,7 +319,7 @@ OPTIMISED_CASES
 #define OPTIMISED_CASE(n, lockfree, type)\
 void  __atomic_store_##n(type *dest, type val, int model) {\
   if (lockfree) {\
-    __c11_atomic_store((_Atomic(type)*)dest, val, model);\
+    atomic_store_explicit((_Atomic(type)*)dest, val, model);\
     return;\
   }\
   Lock *l = lock_for_pointer(dest);\
@@ -275,7 +334,7 @@ OPTIMISED_CASES
 #define OPTIMISED_CASE(n, lockfree, type)\
 type __atomic_exchange_##n(type *dest, type val, int model) {\
   if (lockfree)\
-    return __c11_atomic_exchange((_Atomic(type)*)dest, val, model);\
+    return atomic_exchange_explicit((_Atomic(type)*)dest, val, model);\
   Lock *l = lock_for_pointer(dest);\
   lock(l);\
   type tmp = *dest;\
@@ -290,7 +349,7 @@ OPTIMISED_CASES
 int __atomic_compare_exchange_##n(type *ptr, type *expected, type desired,\
     int success, int failure) {\
   if (lockfree)\
-    return __c11_atomic_compare_exchange_strong((_Atomic(type)*)ptr, expected, desired,\
+    return atomic_compare_exchange_strong_explicit((_Atomic(type)*)ptr, expected, desired,\
         success, failure);\
   Lock *l = lock_for_pointer(ptr);\
   lock(l);\
@@ -312,7 +371,7 @@ OPTIMISED_CASES
 #define ATOMIC_RMW(n, lockfree, type, opname, op) \
 type __atomic_fetch_##opname##_##n(type *ptr, type val, int model) {\
   if (lockfree) \
-    return __c11_atomic_fetch_##opname((_Atomic(type)*)ptr, val, model);\
+    return atomic_fetch_##opname##_explicit((_Atomic(type)*)ptr, val, model);\
   Lock *l = lock_for_pointer(ptr);\
   lock(l);\
   type tmp = *ptr;\
