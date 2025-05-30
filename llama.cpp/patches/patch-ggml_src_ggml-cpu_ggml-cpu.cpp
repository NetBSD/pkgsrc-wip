$NetBSD$

--- ggml/src/ggml-cpu/ggml-cpu.cpp.orig	2025-05-16 09:51:15.207576848 +0000
+++ ggml/src/ggml-cpu/ggml-cpu.cpp
@@ -276,10 +276,10 @@ struct ggml_backend_cpu_device_context {
                     char * p = strchr(buf, ':');
                     if (p) {
                         p++;
-                        while (std::isspace(*p)) {
+                        while (std::isspace((unsigned char)(*p))) {
                             p++;
                         }
-                        while (std::isspace(p[strlen(p) - 1])) {
+                        while (std::isspace((unsigned char)(p[strlen(p) - 1]))) {
                             p[strlen(p) - 1] = '\0';
                         }
                         description = p;
