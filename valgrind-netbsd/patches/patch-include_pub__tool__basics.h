$NetBSD$

--- include/pub_tool_basics.h.orig	2018-07-13 08:52:05.000000000 +0000
+++ include/pub_tool_basics.h
@@ -104,7 +104,7 @@ typedef  Word                 PtrdiffT; 
 // always a signed 64-bit int.  So we defined our own Off64T as well.
 #if defined(VGO_linux) || defined(VGO_solaris)
 typedef Word                   OffT;      // 32             64
-#elif defined(VGO_darwin)
+#elif defined(VGO_darwin) || defined(VGO_netbsd)
 typedef Long                   OffT;      // 64             64
 #else
 #  error Unknown OS
@@ -228,7 +228,7 @@ typedef
    }
    SysRes;
 
-#elif defined(VGO_solaris)
+#elif defined(VGO_solaris) || defined(VGO_netbsd)
 typedef
    struct {
       UWord _val;
@@ -364,7 +364,14 @@ static inline Bool sr_EQ ( UInt sysno, S
           && sr1._wLO == sr2._wLO && sr1._wHI == sr2._wHI;
 }
 
-#elif defined(VGO_solaris)
+#elif defined(VGO_solaris) || defined(VGO_netbsd)
+
+/*
+   NetBSD/amd64
+   X86_TF_RAX(frame) = rval[0];
+   X86_TF_RDX(frame) = rval[1];
+//   X86_TF_RFLAGS(frame) &= ~PSL_C; // carry bit <- enabled ZC signs error
+*/
 
 static inline Bool sr_isError ( SysRes sr ) {
    return sr._isError;
