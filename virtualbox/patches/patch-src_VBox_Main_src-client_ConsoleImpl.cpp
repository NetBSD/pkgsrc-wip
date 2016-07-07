$NetBSD$

--- src/VBox/Main/src-client/ConsoleImpl.cpp.orig	2016-03-04 19:29:38.000000000 +0000
+++ src/VBox/Main/src-client/ConsoleImpl.cpp
@@ -29,7 +29,7 @@
 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <errno.h>
 # include <sys/ioctl.h>
 # include <sys/poll.h>
@@ -8771,7 +8771,7 @@ Console::i_usbDetachCallback(Console *th
 #endif /* VBOX_WITH_USB */
 
 /* Note: FreeBSD needs this whether netflt is used or not. */
-#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
 /**
  * Helper function to handle host interface device creation and attachment.
  *
@@ -8885,7 +8885,7 @@ HRESULT Console::i_attachToTapInterface(
         }
     }
 
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /*
      * Set/obtain the tap interface.
      */
@@ -9003,7 +9003,7 @@ HRESULT Console::i_detachFromTapInterfac
     LogFlowThisFunc(("returning %d\n", rc));
     return rc;
 }
-#endif /* (RT_OS_LINUX || RT_OS_FREEBSD) && !VBOX_WITH_NETFLT */
+#endif /* (RT_OS_LINUX || RT_OS_FREEBSD || RT_OS_NETBSD) && !VBOX_WITH_NETFLT */
 
 /**
  * Called at power down to terminate host interface networking.
@@ -9047,11 +9047,11 @@ HRESULT Console::i_powerDownHostInterfac
         pNetworkAdapter->COMGETTER(AttachmentType)(&attachment);
         if (attachment == NetworkAttachmentType_Bridged)
         {
-#if ((defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && !defined(VBOX_WITH_NETFLT))
+#if ((defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)) && !defined(VBOX_WITH_NETFLT))
             HRESULT rc2 = i_detachFromTapInterface(pNetworkAdapter);
             if (FAILED(rc2) && SUCCEEDED(rc))
                 rc = rc2;
-#endif /* (RT_OS_LINUX || RT_OS_FREEBSD) && !VBOX_WITH_NETFLT */
+#endif /* (RT_OS_LINUX || RT_OS_FREEBSD || RT_OS_NETBSD) && !VBOX_WITH_NETFLT */
         }
     }
 
