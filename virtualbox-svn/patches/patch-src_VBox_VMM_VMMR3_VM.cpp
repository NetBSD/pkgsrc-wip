$NetBSD$

--- src/VBox/VMM/VMMR3/VM.cpp.orig	2016-03-04 19:30:12.000000000 +0000
+++ src/VBox/VMM/VMMR3/VM.cpp
@@ -410,7 +410,7 @@ VMMR3DECL(int)   VMR3Create(uint32_t cCp
                                   "you the permission you need to access the device.");
 # elif defined(RT_OS_WINDOWS)
                     pszError = N_("VirtualBox kernel driver is not accessible, permission problem.");
-# else /* solaris, freebsd, ++. */
+# else /* solaris, freebsd, netbsd, ++. */
                     pszError = N_("VirtualBox kernel module is not accessible, permission problem. "
                                   "If you have built VirtualBox yourself, make sure that you do "
                                   "not have the vboxdrv kernel module from a different install loaded.");
@@ -4510,4 +4510,3 @@ VMMR3DECL(int) VMR3SetPowerOffInsteadOfR
     pVM->vm.s.fPowerOffInsteadOfReset = fPowerOffInsteadOfReset;
     return VINF_SUCCESS;
 }
-
