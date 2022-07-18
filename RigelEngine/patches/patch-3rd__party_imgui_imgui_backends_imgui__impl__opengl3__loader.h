$NetBSD$

Load the unversioned libGL, since libGL.so.1 is not correct
for all platforms.

--- 3rd_party/imgui/imgui/backends/imgui_impl_opengl3_loader.h.orig	2021-12-31 07:11:21.779651179 +0000
+++ 3rd_party/imgui/imgui/backends/imgui_impl_opengl3_loader.h
@@ -625,7 +625,7 @@ static GL3WglProc (*glx_get_proc_address
 
 static int open_libgl(void)
 {
-    libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
+    libgl = dlopen("libGL.so", RTLD_LAZY | RTLD_LOCAL);
     if (!libgl)
         return GL3W_ERROR_LIBRARY_OPEN;
     *(void **)(&glx_get_proc_address) = dlsym(libgl, "glXGetProcAddressARB");
