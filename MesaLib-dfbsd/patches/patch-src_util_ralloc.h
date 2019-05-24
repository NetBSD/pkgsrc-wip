$NetBSD$

--- src/util/ralloc.h.orig	2019-03-23 16:29:21.000000000 +0000
+++ src/util/ralloc.h
@@ -426,7 +426,7 @@ bool ralloc_vasprintf_append(char **str,
  *
  * which is more idiomatic in C++ than calling ralloc.
  */
-#define DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(TYPE, ALLOC_FUNC)           \
+#define DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(TYPE, ALLOC_FUNC, USE_DESTRUCTOR) \
 private:                                                                 \
    static void _ralloc_destructor(void *p)                               \
    {                                                                     \
@@ -437,7 +437,7 @@ public:                                 
    {                                                                     \
       void *p = ALLOC_FUNC(mem_ctx, size);                               \
       assert(p != NULL);                                                 \
-      if (!HAS_TRIVIAL_DESTRUCTOR(TYPE))                                 \
+      if (USE_DESTRUCTOR && !HAS_TRIVIAL_DESTRUCTOR(TYPE))               \
          ralloc_set_destructor(p, _ralloc_destructor);                   \
       return p;                                                          \
    }                                                                     \
@@ -454,16 +454,24 @@ public:                                 
    }
 
 #define DECLARE_RALLOC_CXX_OPERATORS(type) \
-   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, ralloc_size)
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, ralloc_size, true)
 
 #define DECLARE_RZALLOC_CXX_OPERATORS(type) \
-   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, rzalloc_size)
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, rzalloc_size, true)
 
+#if defined(NO_LINEAR_ALLOC_DESTRUCTOR)
 #define DECLARE_LINEAR_ALLOC_CXX_OPERATORS(type) \
-   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_alloc_child)
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_alloc_child, false)
 
 #define DECLARE_LINEAR_ZALLOC_CXX_OPERATORS(type) \
-   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_zalloc_child)
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_zalloc_child, false)
+#else
+#define DECLARE_LINEAR_ALLOC_CXX_OPERATORS(type) \
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_alloc_child, true)
+
+#define DECLARE_LINEAR_ZALLOC_CXX_OPERATORS(type) \
+   DECLARE_ALLOC_CXX_OPERATORS_TEMPLATE(type, linear_zalloc_child, true)
+#endif
 
 
 /**
