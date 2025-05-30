$NetBSD$

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/opts.cc
+++ gcc/opts.cc
@@ -3289,6 +3289,7 @@ common_handle_option (struct gcc_options *opts,
       break;

     case OPT_fuse_ld_bfd:
+    case OPT_fuse_ld_classic:
     case OPT_fuse_ld_gold:
     case OPT_fuse_ld_lld:
     case OPT_fuse_ld_mold:
