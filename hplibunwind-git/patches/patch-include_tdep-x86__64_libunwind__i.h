$NetBSD$

--- include/tdep-x86_64/libunwind_i.h.orig	2018-09-04 09:38:02.000000000 +0000
+++ include/tdep-x86_64/libunwind_i.h
@@ -200,7 +200,7 @@ dwarf_put (struct dwarf_cursor *c, dwarf
 #define tdep_get_exe_image_path         UNW_ARCH_OBJ(get_exe_image_path)
 #define tdep_access_reg                 UNW_OBJ(access_reg)
 #define tdep_access_fpreg               UNW_OBJ(access_fpreg)
-#if __linux__
+#if __linux__ || __NetBSD__
 # define tdep_fetch_frame               UNW_OBJ(fetch_frame)
 # define tdep_cache_frame               UNW_OBJ(cache_frame)
 # define tdep_reuse_frame               UNW_OBJ(reuse_frame)
@@ -248,7 +248,7 @@ extern int tdep_access_reg (struct curso
                             unw_word_t *valp, int write);
 extern int tdep_access_fpreg (struct cursor *c, unw_regnum_t reg,
                               unw_fpreg_t *valp, int write);
-#if __linux__
+#if __linux__ || __NetBSD__
 extern void tdep_fetch_frame (struct dwarf_cursor *c, unw_word_t ip,
                               int need_unwind_info);
 extern int tdep_cache_frame (struct dwarf_cursor *c);
