$NetBSD$

--- coregrind/m_debuginfo/d3basics.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/d3basics.c
@@ -405,7 +405,7 @@ static Bool get_Dwarf_Reg( /*OUT*/Addr* 
    if (regno == 5/*EBP*/) { *a = regs->fp; return True; }
    if (regno == 4/*ESP*/) { *a = regs->sp; return True; }
 #  elif defined(VGP_amd64_linux) || defined(VGP_amd64_darwin) \
-        || defined(VGP_amd64_solaris)
+        || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
    if (regno == 6/*RBP*/) { *a = regs->fp; return True; }
    if (regno == 7/*RSP*/) { *a = regs->sp; return True; }
 #  elif defined(VGP_ppc32_linux)
