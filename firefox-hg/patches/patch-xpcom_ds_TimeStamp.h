$NetBSD: patch-xpcom_ds_TimeStamp.h,v 1.1 2014/09/29 10:46:26 thomasklausner Exp $

http://gnats.netbsd.org/47233

--- xpcom/ds/TimeStamp.h.orig	2014-09-28 08:30:06.000000000 +0000
+++ xpcom/ds/TimeStamp.h
@@ -139,7 +139,7 @@ public:
 
   static BaseTimeDuration Forever()
   {
-    return FromTicks(INT64_MAX);
+    return FromTicks(int64_t(INT64_MAX));
   }
 
   BaseTimeDuration operator+(const BaseTimeDuration& aOther) const
@@ -289,12 +289,12 @@ private:
     // NOTE: this MUST be a >= test, because int64_t(double(INT64_MAX))
     // overflows and gives INT64_MIN.
     if (aTicks >= double(INT64_MAX)) {
-      return FromTicks(INT64_MAX);
+      return FromTicks(int64_t(INT64_MAX));
     }
 
     // This MUST be a <= test.
     if (aTicks <= double(INT64_MIN)) {
-      return FromTicks(INT64_MIN);
+      return FromTicks(int64_t(INT64_MIN));
     }
 
     return FromTicks(int64_t(aTicks));
