$NetBSD$

--- ELF/Writer.cpp.orig	2019-02-15 21:11:17.385984659 +0000
+++ ELF/Writer.cpp
@@ -2026,14 +2026,16 @@ template <class ELFT> std::vector<PhdrEn
   if (OutputSection *Cmd = findSection(".openbsd.randomdata"))
     AddHdr(PT_OPENBSD_RANDOMIZE, Cmd->getPhdrFlags())->add(Cmd);
 
-  // PT_GNU_STACK is a special section to tell the loader to make the
-  // pages for the stack non-executable. If you really want an executable
-  // stack, you can pass -z execstack, but that's not recommended for
-  // security reasons.
-  unsigned Perm = PF_R | PF_W;
-  if (Config->ZExecstack)
-    Perm |= PF_X;
-  AddHdr(PT_GNU_STACK, Perm)->p_memsz = Config->ZStackSize;
+  if (!Config->ZNognustack) {
+    // PT_GNU_STACK is a special section to tell the loader to make the
+    // pages for the stack non-executable. If you really want an executable
+    // stack, you can pass -z execstack, but that's not recommended for
+    // security reasons.
+    unsigned Perm = PF_R | PF_W;
+    if (Config->ZExecstack)
+      Perm |= PF_X;
+    AddHdr(PT_GNU_STACK, Perm)->p_memsz = Config->ZStackSize;
+  }
 
   // PT_OPENBSD_WXNEEDED is a OpenBSD-specific header to mark the executable
   // is expected to perform W^X violations, such as calling mprotect(2) or
