$NetBSD$

--- lib/sanitizer_common/sanitizer_procmaps.h.orig	2017-06-03 23:53:58.000000000 +0000
+++ lib/sanitizer_common/sanitizer_procmaps.h
@@ -20,7 +20,7 @@
 
 namespace __sanitizer {
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 struct ProcSelfMapsBuff {
   char *data;
   uptr mmaped_size;
@@ -29,7 +29,7 @@ struct ProcSelfMapsBuff {
 
 // Reads process memory map in an OS-specific way.
 void ReadProcMaps(ProcSelfMapsBuff *proc_maps);
-#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 class MemoryMappingLayout {
  public:
@@ -58,7 +58,7 @@ class MemoryMappingLayout {
 
   // FIXME: Hide implementation details for different platforms in
   // platform-specific files.
-# if SANITIZER_FREEBSD || SANITIZER_LINUX
+# if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
   ProcSelfMapsBuff proc_self_maps_;
   const char *current_;
 
