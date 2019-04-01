$NetBSD$

--- coregrind/m_stacktrace.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_stacktrace.c
@@ -500,7 +500,7 @@ UInt VG_(get_StackTrace_wrk) ( ThreadId 
 /* ----------------------- amd64 ------------------------ */
 
 #if defined(VGP_amd64_linux) || defined(VGP_amd64_darwin) \
-    || defined(VGP_amd64_solaris)
+    || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 
 UInt VG_(get_StackTrace_wrk) ( ThreadId tid_if_known,
                                /*OUT*/Addr* ips, UInt max_n_ips,
@@ -638,6 +638,34 @@ UInt VG_(get_StackTrace_wrk) ( ThreadId 
          continue;
       }
 
+#if defined(VGO_netbsd)
+      const NSegment *seg;
+      const HChar *filename = NULL;
+      int match = 0;
+
+      seg = VG_(am_find_nsegment)(uregs.xip);
+      if (seg != NULL) {
+         filename = VG_(am_get_filename)(seg);
+      }
+      if (filename != NULL && VG_(strstr)(filename, "/libc.so")) {
+         match = 1;
+      }
+      if (match == 1 && fp_min <= uregs.xsp &&
+          uregs.xsp <= fp_max - 1 * sizeof(UWord)) {
+         /* fp looks sane, so use it. */
+         uregs.xip = (((UWord*)uregs.xsp)[0]);
+         if (0 == uregs.xip || 1 == uregs.xip) break;
+         if (fps) fps[i] = uregs.xsp;
+         uregs.xsp = uregs.xsp + sizeof(Addr) /*ra*/;                                                                                                        
+         if (sps) sps[i] = uregs.xsp;
+         ips[i++] = uregs.xip - 1; /* -1: refer to calling insn, not the RA */
+         if (debug)
+            VG_(printf)("     ipsFF[%d]=%#08lx\n", i-1, ips[i-1]);
+         uregs.xip = uregs.xip - 1; /* as per comment at the head of this loop */
+         continue;
+      }
+#endif
+
       /* If VG_(use_CF_info) fails, it won't modify ip/sp/fp, so
          we can safely try the old-fashioned method. */
       /* This bit is supposed to deal with frames resulting from
