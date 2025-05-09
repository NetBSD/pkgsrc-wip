$NetBSD$

--- Libraries/LibJS/Runtime/ExecutionContext.h.orig	2025-05-09 07:27:30.947037549 +0000
+++ Libraries/LibJS/Runtime/ExecutionContext.h
@@ -121,7 +121,7 @@ private:
         + (((registers_and_constants_and_locals_count) + (arguments_count))                  \
             * sizeof(JS::Value));                                                            \
                                                                                              \
-    void* execution_context_memory = alloca(execution_context_size);                         \
+    void* execution_context_memory = __builtin_alloca(execution_context_size);                         \
                                                                                              \
     execution_context = new (execution_context_memory)                                       \
         JS::ExecutionContext((registers_and_constants_and_locals_count), (arguments_count)); \
