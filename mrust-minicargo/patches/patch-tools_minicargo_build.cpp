$NetBSD$

--- tools/minicargo/build.cpp.orig	2021-09-12 00:15:52.000000000 +0000
+++ tools/minicargo/build.cpp
@@ -48,7 +48,7 @@ extern int _putenv_s(const char*, const 
 #ifdef __APPLE__
 # include <mach-o/dyld.h>
 #endif
-#if defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME)) // NetBSD 8.0+
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 # include <sys/sysctl.h>
 #endif
 
@@ -906,9 +906,11 @@ bool Builder::build_target(const Package
         }
     }
     if( true /*this->enable_debug*/ ) {
-        args.push_back("-g");
         args.push_back("--cfg"); args.push_back("debug_assertions");
     }
+    if( m_opts.mrustc_g ) {
+        args.push_back("-g");
+    }
     if( true /*this->enable_optimise*/ ) {
         args.push_back("-O");
     }
@@ -1044,7 +1046,7 @@ bool Builder::build_target(const Package
     args.push_back("--crate-type"); args.push_back("bin");
     args.push_back("-o"); args.push_back(outfile);
     args.push_back("-L"); args.push_back(this->get_output_dir(true).str()); // NOTE: Forces `is_for_host` to true here.
-    if( true )
+    if( m_opts.mrustc_g )
     {
         args.push_back("-g");
     }
@@ -1266,7 +1268,11 @@ const helpers::path& get_mrustc_path()
         else
             // TODO: Buffer too small
 # elif defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME)) // NetBSD 8.0+
+#  if defined(__NetBSD__)
+        int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+#  else
         int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+#  endif
         size_t s = sizeof(buf);
         if ( sysctl(mib, 4, buf, &s, NULL, 0) == 0 )
         {
