$NetBSD$

From freebsd-base-ports
https://github.com/FreeBSDDesktop/freebsd-ports-graphics/tree/xserver-mesa-next-udev

--- src/gallium/state_trackers/clover/llvm/invocation.cpp.orig	2016-11-10 22:06:40.000000000 +0000
+++ src/gallium/state_trackers/clover/llvm/invocation.cpp
@@ -85,6 +85,14 @@ namespace {
       }
    }
 
+#if defined(__FreeBSD__)
+   char* convert(const std::string&s){
+      char *pc = new char[s.size()+1];
+      std::strcpy(pc, s.c_str());
+      return pc;
+   }
+#endif
+
    std::unique_ptr<LLVMContext>
    create_context(std::string &r_log) {
       init_targets();
@@ -104,8 +112,14 @@ namespace {
       // Parse the compiler options.  A file name should be present at the end
       // and must have the .cl extension in order for the CompilerInvocation
       // class to recognize it as an OpenCL source file.
+
+#if defined(__FreeBSD__)
+      std::vector<const char *> copts;
+      std::transform(opts.begin(), opts.end(), std::back_inserter(copts), convert);
+#else
       const std::vector<const char *> copts =
          map(std::mem_fn(&std::string::c_str), opts);
+#endif
 
       if (!clang::CompilerInvocation::CreateFromArgs(
              c->getInvocation(), copts.data(), copts.data() + copts.size(), diag))
