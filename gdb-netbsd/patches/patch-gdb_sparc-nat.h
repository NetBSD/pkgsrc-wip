$NetBSD$

--- gdb/sparc-nat.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc-nat.h
@@ -75,7 +75,7 @@ struct sparc_target : public BaseTarget
       return sparc_xfer_wcookie (object, annex, readbuf, writebuf,
 				 offset, len, xfered_len);
 
-    return BaseTarget (object, annex, readbuf, writebuf,
+    return BaseTarget::xfer_partial (object, annex, readbuf, writebuf,
 		       offset, len, xfered_len);
   }
 };
