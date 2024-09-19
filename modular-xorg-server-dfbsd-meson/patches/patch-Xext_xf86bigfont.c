$NetBSD$

--- Xext/xf86bigfont.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ Xext/xf86bigfont.c
@@ -377,7 +377,11 @@ ProcXF86BigfontQueryFont(ClientPtr clien
 #ifdef HAS_SHM
         if (!badSysCall)
             pDesc = (ShmDescPtr) FontGetPrivate(pFont, FontShmdescIndex);
+#if defined(STRICT_XSRC_NETBSD)
+        if (pDesc && pDesc->attach_addr) {
+#else
         if (pDesc) {
+#endif
             pCI = (xCharInfo *) pDesc->attach_addr;
             if (stuff_flags & XF86Bigfont_FLAGS_Shm)
                 shmid = pDesc->shmid;
