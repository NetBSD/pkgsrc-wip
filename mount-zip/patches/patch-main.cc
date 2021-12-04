$NetBSD$

Hunk #0:
    O_PATH does not exist on NetBSD.
https://github.com/google/mount-zip/pull/1

Hunk #1, #2:
    Work around an issue in librefuse <fuse_opt.h>. It has been
    incompatible with C++11 compilers. Fixed in HEAD:
    * http://mail-index.netbsd.org/source-changes/2021/12/01/msg134169.html
    * http://mail-index.netbsd.org/source-changes/2021/12/01/msg134170.html
    ([pho@] It's me who broke it.)

Hunk #3:
    fuse_setup() and fuse_teardown() are obsolete functions and has been
    (wrongly) removed from librefuse. Use fuse_main() instead, especially when
    nothing special needs to be done while mounting a filesystem and entering a
    main loop.
https://github.com/google/mount-zip/pull/1

    TODO: These two functions should be added back to librefuse, along with
    proper FUSE_USE_VERSION checks. Old applications are everywhere and it's
    clear we still need to support the decades old API given the amount of
    patches we ended up with for filesystems/fuse-*.
    ([pho@] I must admit it's me who removed them.)

--- main.cc.orig	2021-11-28 04:14:07.000000000 +0000
+++ main.cc
@@ -46,6 +46,10 @@
 #error "libzip >= 1.0 is required!"
 #endif
 
+#ifndef O_PATH
+#define O_PATH 0
+#endif
+
 // Prints usage information.
 void print_usage() {
   fprintf(
@@ -364,6 +368,8 @@ int main(int argc, char* argv[]) try {
   Cleanup cleanup{.args = &args};
   Param param;
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wnarrowing"
   const fuse_opt opts[] = {FUSE_OPT_KEY("--help", KEY_HELP),
                            FUSE_OPT_KEY("-h", KEY_HELP),
                            FUSE_OPT_KEY("--version", KEY_VERSION),
@@ -378,6 +384,7 @@ int main(int argc, char* argv[]) try {
                            FUSE_OPT_KEY("nohardlinks", KEY_NO_HARDLINKS),
                            {"encoding=%s", offsetof(Param, opts.encoding), 0},
                            {nullptr, 0, 0}};
+#pragma GCC diagnostic pop
 
   if (fuse_opt_parse(&args, &param, opts, ProcessArg))
     return EXIT_FAILURE;
@@ -440,32 +447,7 @@ int main(int argc, char* argv[]) try {
   // Single-threaded operation.
   fuse_opt_add_arg(&args, "-s");
 
-  char* absolute_mount_point;
-  int multithreaded;
-  timer.Reset();
-  struct fuse* const fuse =
-      fuse_setup(args.argc, args.argv, &operations, sizeof(operations),
-                 &absolute_mount_point, &multithreaded, tree.get());
-
-  if (!fuse)
-    throw std::runtime_error(StrCat("Cannot mount ", Path(param.filename),
-                                    " on ", Path(param.mount_point)));
-
-  Log(LOG_DEBUG, "Mounted ", Path(param.filename), " on ",
-      Path(param.mount_point), " in ", timer);
-  Log(LOG_DEBUG, "When finished, run: fusermount -u ",
-      Path(absolute_mount_point));
-
-  assert(!multithreaded);
-  const int res = fuse_loop(fuse);
-
-  Log(LOG_DEBUG, "Unmounting ", Path(param.filename), " from ",
-      Path(param.mount_point), "...");
-  timer.Reset();
-  fuse_teardown(fuse, absolute_mount_point);
-  Log(LOG_DEBUG, "Unmounted ", Path(param.filename), " in ", timer);
-
-  return res;
+  return fuse_main(args.argc, args.argv, &operations, tree.get());
 } catch (const ZipError& e) {
   Log(LOG_ERR, e.what());
   // Shift libzip error codes in order to avoid collision with FUSE errors.
