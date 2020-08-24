$NetBSD$

Adjust for (more) modern perl.

Not submitted upstream because pkgsrc is woefully out of date.

--- scripts/ZoneMinder/lib/ZoneMinder/Memory/Shared.pm.orig	2016-02-03 18:40:30.000000000 +0000
+++ scripts/ZoneMinder/lib/ZoneMinder/Memory/Shared.pm
@@ -158,7 +158,7 @@ sub zmMemClean
                   ."'"
     ;
     Debug( "Checking for shared memory with '$command'\n" );
-    open( my $CMD, '<', "$command |" )
+    open( my $CMD, '-|', "$command" )
         or Fatal( "Can't execute '$command': $!" );
     while( <$CMD> )
     {
