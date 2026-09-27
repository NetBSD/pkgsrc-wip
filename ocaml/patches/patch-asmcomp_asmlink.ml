$NetBSD$

linker uses $PTHREAD_CFLAGS.

When building outside of pkgsrc, Autoconf's AX_PTHREAD returns
$PTHREAD_CFLAGS="-pthread" and and $PTHREAD_LIBS="-lpthread".
However, for some reason, inside pkgsrc returns
$PTHREAD_CFLAGS="-pthread" and and $PTHREAD_LIBS="".
Therefore, linker loses pthread library, resulting in an error.

By the way, AX_PTHREAD assumes to not only compiler with cflags,
but also link with them. So, as a test, I tried adding
'Config.native_cflags' to linker, it working.

https://www.gnu.org/software/autoconf-archive/ax_pthread.html

--- asmcomp/asmlink.ml.orig	2026-06-19 12:16:03.000000000 +0000
+++ asmcomp/asmlink.ml
@@ -323,7 +323,7 @@ let call_linker file_list startup_file output_name =
       files @ (List.rev !Clflags.ccobjs) @ runtime_lib (),
       native_ldflags ^ " " ^
       (if !Clflags.nopervasives || (main_obj_runtime && not main_dll)
-       then "" else Config.native_c_libraries)
+       then "" else Config.native_cflags ^ " " ^ Config.native_c_libraries)
     else
       files, ""
   in
