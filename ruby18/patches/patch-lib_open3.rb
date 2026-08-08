$NetBSD$

--- lib/open3.rb.orig	2009-12-14 04:28:06.000000000 +0000
+++ lib/open3.rb
@@ -56,39 +56,40 @@ module Open3
 
     pid = fork{
       # child
-      fork{
-	# grandchild
-	pw[1].close
-	STDIN.reopen(pw[0])
-	pw[0].close
+      pw[1].close
+      STDIN.reopen(pw[0])
+      pw[0].close
 
-	pr[0].close
-	STDOUT.reopen(pr[1])
-	pr[1].close
+      pr[0].close
+      STDOUT.reopen(pr[1])
+      pr[1].close
 
-	pe[0].close
-	STDERR.reopen(pe[1])
-	pe[1].close
+      pe[0].close
+      STDERR.reopen(pe[1])
+      pe[1].close
 
-	exec(*cmd)
-      }
-      exit!(0)
+      trap("EXIT", "DEFAULT")
+      at_exit {exit!(false)}
+      at_exit {raise($!)}
+      exec(*cmd)
     }
 
     pw[0].close
     pr[1].close
     pe[1].close
-    Process.waitpid(pid)
+    waiter = Process.detach(pid)
     pi = [pw[1], pr[0], pe[0]]
+    result = pi + [waiter]
     pw[1].sync = true
     if defined? yield
       begin
-	return yield(*pi)
+	return yield(*result)
       ensure
 	pi.each{|p| p.close unless p.closed?}
+        waiter.join
       end
     end
-    pi
+    result
   end
   module_function :popen3
 end
