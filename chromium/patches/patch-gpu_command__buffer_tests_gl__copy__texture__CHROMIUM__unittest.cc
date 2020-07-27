$NetBSD$

--- gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc
@@ -643,7 +643,7 @@ class GLCopyTextureCHROMIUMES3Test : pub
 
   bool ShouldSkipNorm16() const {
     DCHECK(!ShouldSkipTest());
-#if (defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)) && \
+#if (defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)) && \
     (defined(ARCH_CPU_X86) || defined(ARCH_CPU_X86_64))
     // Make sure it's tested; it is safe to assume that the flag is always true
     // on desktop.
