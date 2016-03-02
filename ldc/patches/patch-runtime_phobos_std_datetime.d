$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/datetime.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/datetime.d
@@ -26531,6 +26531,7 @@ auto tz = TimeZone.getTimeZone("America/
         version(Posix)
         {
             version(FreeBSD)      enum utcZone = "Etc/UTC";
+            else version(NetBSD)  enum utcZone = "UTC";
             else version(linux)   enum utcZone = "UTC";
             else version(OSX)     enum utcZone = "UTC";
             else static assert(0, "The location of the UTC timezone file on this Posix platform must be set.");
@@ -26965,19 +26966,31 @@ public:
         {
             scope(exit) clearTZEnvVar();
 
-            version(FreeBSD)
+            version(NetBSD)
             {
-                // A bug on FreeBSD 9+ makes it so that this test fails.
-                // https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=168862
+                //According http://mainfacts.com/world-timezones-time-zones/PPT :
+                //Actual zone of this location is PST now. It can be assigned to PPT too.
+                setTZEnvVar("America/Los_Angeles");
+                assert(LocalTime().dstName == "PPT");
+                setTZEnvVar("America/New_York");
+                assert(LocalTime().dstName == "EPT");
             }
             else
             {
-                setTZEnvVar("America/Los_Angeles");
-                assert(LocalTime().dstName == "PDT");
-            }
+                version(FreeBSD)
+                {
+                    // A bug on FreeBSD 9+ makes it so that this test fails.
+                    // https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=168862
+                }
+                else
+                {
+                    setTZEnvVar("America/Los_Angeles");
+                    assert(LocalTime().dstName == "PDT");
+                }
 
-            setTZEnvVar("America/New_York");
-            assert(LocalTime().dstName == "EDT");
+                setTZEnvVar("America/New_York");
+                assert(LocalTime().dstName == "EDT");
+           }
         }
     }
 
@@ -28416,7 +28429,8 @@ assert(tz.dstName == "PDT");
 
                 if(!tzName.extension().empty ||
                    !tzName.startsWith(subName) ||
-                   tzName == "+VERSION")
+                   tzName == "+VERSION" ||
+                   tzName == "leapseconds" )
                 {
                     continue;
                 }
