$NetBSD$

--- coregrind/m_replacemalloc/vg_replace_malloc.c.orig	2018-05-31 14:59:48.000000000 +0000
+++ coregrind/m_replacemalloc/vg_replace_malloc.c
@@ -298,6 +298,10 @@ static void init(void);
  ALLOC_or_NULL(VG_Z_LIBC_SONAME,      malloc,      malloc);
  ALLOC_or_NULL(SO_SYN_MALLOC,         malloc,      malloc);
 
+#elif defined(VGO_netbsd)
+ ALLOC_or_NULL(VG_Z_LIBC_SONAME,      malloc,      malloc);
+ ALLOC_or_NULL(SO_SYN_MALLOC,         malloc,      malloc);
+
 #elif defined(VGO_darwin)
  ALLOC_or_NULL(VG_Z_LIBC_SONAME,      malloc,      malloc);
  ALLOC_or_NULL(SO_SYN_MALLOC,         malloc,      malloc);
@@ -334,6 +338,20 @@ static void init(void);
   ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znwm,          __builtin_new);
  #endif
 
+#elif defined(VGO_netbsd)
+ // operator new(unsigned int), GNU mangling
+ #if VG_WORDSIZE == 4
+  ALLOC_or_BOMB(VG_Z_LIBSTDCXX_SONAME, _Znwj,          __builtin_new);
+  ALLOC_or_BOMB(VG_Z_LIBSUPCXX_SONAME, _Znwj,          __builtin_new);
+  ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znwm,          __builtin_new);
+ #endif
+ // operator new(unsigned long), GNU mangling
+ #if VG_WORDSIZE == 8
+  ALLOC_or_BOMB(VG_Z_LIBSTDCXX_SONAME, _Znwm,          __builtin_new);
+  ALLOC_or_BOMB(VG_Z_LIBSUPCXX_SONAME, _Znwm,          __builtin_new);
+  ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znwm,          __builtin_new);
+ #endif
+
 #elif defined(VGO_darwin)
  // operator new(unsigned int), GNU mangling
  #if VG_WORDSIZE == 4
@@ -377,6 +395,20 @@ static void init(void);
   ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnwmRKSt9nothrow_t,  __builtin_new);
  #endif
 
+#elif defined(VGO_netbsd)
+ // operator new(unsigned, std::nothrow_t const&), GNU mangling
+ #if VG_WORDSIZE == 4
+  ALLOC_or_NULL(VG_Z_LIBSTDCXX_SONAME, _ZnwjRKSt9nothrow_t,  __builtin_new);
+  ALLOC_or_NULL(VG_Z_LIBSUPCXX_SONAME, _ZnwjRKSt9nothrow_t,  __builtin_new);
+  ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnwjRKSt9nothrow_t,  __builtin_new);
+ #endif
+ // operator new(unsigned long, std::nothrow_t const&), GNU mangling
+ #if VG_WORDSIZE == 8
+  ALLOC_or_NULL(VG_Z_LIBSTDCXX_SONAME, _ZnwmRKSt9nothrow_t,  __builtin_new);
+  ALLOC_or_NULL(VG_Z_LIBSUPCXX_SONAME, _ZnwmRKSt9nothrow_t,  __builtin_new);
+  ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnwjRKSt9nothrow_t,  __builtin_new);
+ #endif
+
 #elif defined(VGO_darwin)
  // operator new(unsigned, std::nothrow_t const&), GNU mangling
  #if VG_WORDSIZE == 4
@@ -423,6 +455,20 @@ static void init(void);
   ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znam,             __builtin_vec_new );
  #endif
 
+#elif defined(VGO_netbsd)
+ // operator new[](unsigned int), GNU mangling
+ #if VG_WORDSIZE == 4
+  ALLOC_or_BOMB(VG_Z_LIBSTDCXX_SONAME, _Znaj,             __builtin_vec_new );
+  ALLOC_or_BOMB(VG_Z_LIBSUPCXX_SONAME, _Znaj,             __builtin_vec_new );
+  ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znaj,             __builtin_vec_new );
+ #endif
+ // operator new[](unsigned long), GNU mangling
+ #if VG_WORDSIZE == 8
+  ALLOC_or_BOMB(VG_Z_LIBSTDCXX_SONAME, _Znam,             __builtin_vec_new );
+  ALLOC_or_BOMB(VG_Z_LIBSUPCXX_SONAME, _Znam,             __builtin_vec_new );
+  ALLOC_or_BOMB(SO_SYN_MALLOC,         _Znaj,             __builtin_vec_new );
+ #endif
+
 #elif defined(VGO_darwin)
  // operator new[](unsigned int), GNU mangling
  #if VG_WORDSIZE == 4
@@ -466,6 +512,20 @@ static void init(void);
   ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnamRKSt9nothrow_t, __builtin_vec_new );
  #endif
 
+#elif defined(VGO_netbsd)
+ // operator new[](unsigned, std::nothrow_t const&), GNU mangling
+ #if VG_WORDSIZE == 4
+  ALLOC_or_NULL(VG_Z_LIBSTDCXX_SONAME, _ZnajRKSt9nothrow_t, __builtin_vec_new );
+  ALLOC_or_NULL(VG_Z_LIBSUPCXX_SONAME, _ZnajRKSt9nothrow_t, __builtin_vec_new );
+  ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnajRKSt9nothrow_t, __builtin_vec_new );
+ #endif
+ // operator new[](unsigned long, std::nothrow_t const&), GNU mangling
+ #if VG_WORDSIZE == 8
+  ALLOC_or_NULL(VG_Z_LIBSTDCXX_SONAME, _ZnamRKSt9nothrow_t, __builtin_vec_new );
+  ALLOC_or_NULL(VG_Z_LIBSUPCXX_SONAME, _ZnamRKSt9nothrow_t, __builtin_vec_new );
+  ALLOC_or_NULL(SO_SYN_MALLOC,         _ZnajRKSt9nothrow_t, __builtin_vec_new );
+ #endif
+
 #elif defined(VGO_darwin)
  // operator new[](unsigned, std::nothrow_t const&), GNU mangling
  #if VG_WORDSIZE == 4
@@ -529,6 +589,10 @@ static void init(void);
  FREE(VG_Z_LIBC_SONAME,       free,                 free );
  FREE(SO_SYN_MALLOC,          free,                 free );
 
+#elif defined(VGO_freebsd)
+ FREE(VG_Z_LIBC_SONAME,       free,                 free );
+ FREE(SO_SYN_MALLOC,          free,                 free );
+
 #elif defined(VGO_darwin)
  FREE(VG_Z_LIBC_SONAME,       free,                 free );
  FREE(SO_SYN_MALLOC,          free,                 free );
@@ -585,6 +649,10 @@ static void init(void);
  FREE(SO_SYN_MALLOC,          _ZdlPvm,               __builtin_delete );
 #endif
 
+#elif defined(VGO_netbsd)
+ FREE(VG_Z_LIBSTDCXX_SONAME,  _ZdlPv,               __builtin_delete );
+ FREE(VG_Z_LIBSUPCXX_SONAME,  _ZdlPv,               __builtin_delete );
+ FREE(SO_SYN_MALLOC,          _ZdlPv,               __builtin_delete );
 
 #elif defined(VGO_darwin)
  // operator delete(void*), GNU mangling
@@ -616,6 +684,12 @@ static void init(void);
  FREE(VG_Z_LIBC_SONAME,      _ZdlPvRKSt9nothrow_t,  __builtin_delete );
  FREE(SO_SYN_MALLOC,         _ZdlPvRKSt9nothrow_t,  __builtin_delete );
 
+#elif defined(VGO_netbsd)
+ // operator delete(void*, std::nothrow_t const&), GNU mangling
+ FREE(VG_Z_LIBSTDCXX_SONAME, _ZdlPvRKSt9nothrow_t,  __builtin_delete );
+ FREE(VG_Z_LIBSUPCXX_SONAME, _ZdlPvRKSt9nothrow_t,  __builtin_delete );
+ FREE(SO_SYN_MALLOC,         _ZdlPvRKSt9nothrow_t,  __builtin_delete );
+
 #elif defined(VGO_darwin)
  // operator delete(void*, std::nothrow_t const&), GNU mangling
  //FREE(VG_Z_LIBSTDCXX_SONAME, _ZdlPvRKSt9nothrow_t,  __builtin_delete );
@@ -652,6 +726,12 @@ static void init(void);
  FREE(SO_SYN_MALLOC,          _ZdaPvm,              __builtin_vec_delete );
 #endif
 
+#elif defined(VGO_netbsd)
+ // operator delete[](void*), GNU mangling
+ FREE(VG_Z_LIBSTDCXX_SONAME,  _ZdaPv,               __builtin_vec_delete );
+ FREE(VG_Z_LIBSUPCXX_SONAME,  _ZdaPv,               __builtin_vec_delete );
+ FREE(SO_SYN_MALLOC,          _ZdaPv,               __builtin_vec_delete );
+
 #elif defined(VGO_darwin)
  // operator delete[](void*), not mangled (for gcc 2.96)
  //FREE(VG_Z_LIBSTDCXX_SONAME,   __builtin_vec_delete, __builtin_vec_delete );
@@ -685,6 +765,12 @@ static void init(void);
  FREE(VG_Z_LIBC_SONAME,       _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
  FREE(SO_SYN_MALLOC,          _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
 
+#elif defined(VGO_netbsd)
+ // operator delete[](void*, std::nothrow_t const&), GNU mangling
+ FREE(VG_Z_LIBSTDCXX_SONAME,  _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
+ FREE(VG_Z_LIBSUPCXX_SONAME,  _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
+ FREE(SO_SYN_MALLOC,          _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
+
 #elif defined(VGO_darwin)
  // operator delete[](void*, std::nothrow_t const&), GNU mangling
  //FREE(VG_Z_LIBSTDCXX_SONAME,  _ZdaPvRKSt9nothrow_t, __builtin_vec_delete );
@@ -751,6 +837,10 @@ static void init(void);
  CALLOC(VG_Z_LIBC_SONAME, calloc);
  CALLOC(SO_SYN_MALLOC,    calloc);
 
+#elif defined(VGO_netbsd)
+ CALLOC(VG_Z_LIBC_SONAME, calloc);
+ CALLOC(SO_SYN_MALLOC,    calloc);
+
 #elif defined(VGO_darwin)
  CALLOC(VG_Z_LIBC_SONAME, calloc);
  CALLOC(SO_SYN_MALLOC,    calloc);
@@ -825,6 +915,11 @@ static void init(void);
  REALLOC(VG_Z_LIBC_SONAME, realloc);
  REALLOC(SO_SYN_MALLOC,    realloc);
 
+#elif defined(VGO_freebsd)
+ REALLOC(VG_Z_LIBC_SONAME, realloc);
+ REALLOC(SO_SYN_MALLOC,    realloc);
+ REALLOCF(VG_Z_LIBC_SONAME, reallocf);
+
 #elif defined(VGO_darwin)
  REALLOC(VG_Z_LIBC_SONAME, realloc);
  REALLOC(SO_SYN_MALLOC,    realloc);
@@ -898,6 +993,10 @@ static void init(void);
  MEMALIGN(VG_Z_LIBC_SONAME, memalign);
  MEMALIGN(SO_SYN_MALLOC,    memalign);
 
+#elif defined(VGO_netbsd)
+ MEMALIGN(VG_Z_LIBC_SONAME, memalign);
+ MEMALIGN(SO_SYN_MALLOC,    memalign);
+
 #elif defined(VGO_darwin)
  MEMALIGN(VG_Z_LIBC_SONAME, memalign);
  MEMALIGN(SO_SYN_MALLOC,    memalign);
@@ -945,6 +1044,10 @@ static void init(void);
  VALLOC(VG_Z_LIBC_SONAME, valloc);
  VALLOC(SO_SYN_MALLOC, valloc);
 
+#elif defined(VGO_netbsd)
+ VALLOC(VG_Z_LIBC_SONAME, valloc);
+ VALLOC(SO_SYN_MALLOC, valloc);
+
 #elif defined(VGO_darwin)
  VALLOC(VG_Z_LIBC_SONAME, valloc);
  VALLOC(SO_SYN_MALLOC, valloc);
@@ -1062,6 +1165,10 @@ static void init(void);
  POSIX_MEMALIGN(VG_Z_LIBC_SONAME, posix_memalign);
  POSIX_MEMALIGN(SO_SYN_MALLOC,    posix_memalign);
 
+#elif defined(VGO_netbsd)
+ POSIX_MEMALIGN(VG_Z_LIBC_SONAME, posix_memalign);
+ POSIX_MEMALIGN(SO_SYN_MALLOC,    posix_memalign);
+
 #elif defined(VGO_darwin)
  //POSIX_MEMALIGN(VG_Z_LIBC_SONAME, posix_memalign);
 
