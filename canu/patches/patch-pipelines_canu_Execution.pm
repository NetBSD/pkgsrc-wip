--- pipelines/canu/Execution.pm.orig	2018-02-27 13:46:07 UTC
+++ pipelines/canu/Execution.pm
@@ -303,10 +303,6 @@ sub skipStage ($$@) {
 sub getInstallDirectory () {
     my $installDir = $FindBin::RealBin;
 
-    if ($installDir =~ m!^(.*)/\w+-\w+/bin$!) {
-        $installDir = $1;
-    }
-
     return($installDir);
 }
 
@@ -727,6 +723,9 @@ sub buildGridArray ($$$$) {
 
     $opt =~ s/ARRAY_NAME/$name/g;        #  Replace ARRAY_NAME with 'job name'
     $opt =~ s/ARRAY_JOBS/$bgn-$end/g;    #  Replace ARRAY_JOBS with 'bgn-end'
+    if ( defined(getGlobal("slurmArrayConcurrentTasks")) ) {
+        $opt = $opt . '%' . getGlobal("slurmArrayConcurrentTasks");
+    }
 
     return($opt, $off);
 }
