$NetBSD$

Python 3 compatability.

--- pystatsd/server.py.orig	2013-07-15 13:42:39.000000000 +0000
+++ pystatsd/server.py
@@ -4,7 +4,7 @@ import threading
 import time
 import types
 import logging
-import gmetric
+from pystatsd import gmetric
 from subprocess import call
 from warnings import warn
 # from xdrlib import Packer, Unpacker
@@ -16,7 +16,7 @@ try:
 except ImportError:
     setproctitle = None
 
-from daemon import Daemon
+from pystatsd.daemon import Daemon
 
 
 __all__ = ['Server']
@@ -141,7 +141,7 @@ class Server(object):
         """
         try:
             self.flush()
-        except Exception, e:
+        except Exception as e:
             log.exception('Error while flushing: %s', e)
         self._set_timer()
 
@@ -157,14 +157,14 @@ class Server(object):
         for k, (v, t) in self.counters.items():
             if self.expire > 0 and t + self.expire < ts:
                 if self.debug:
-                    print "Expiring counter %s (age: %s)" % (k, ts -t)
+                    print("Expiring counter %s (age: %s)" % (k, ts -t))
                 del(self.counters[k])
                 continue
             v = float(v)
             v = v if self.no_aggregate_counters else v / (self.flush_interval / 1000)
 
             if self.debug:
-                print "Sending %s => count=%s" % (k, v)
+                print("Sending %s => count=%s" % (k, v))
 
             if self.transport == 'graphite':
                 msg = '%s.%s %s %s\n' % (self.counters_prefix, k, v, ts)
@@ -183,13 +183,13 @@ class Server(object):
         for k, (v, t) in self.gauges.items():
             if self.expire > 0 and t + self.expire < ts:
                 if self.debug:
-                    print "Expiring gauge %s (age: %s)" % (k, ts - t)
+                    print("Expiring gauge %s (age: %s)" % (k, ts - t))
                 del(self.gauges[k])
                 continue
             v = float(v)
 
             if self.debug:
-                print "Sending %s => value=%s" % (k, v)
+                print("Sending %s => value=%s" % (k, v))
 
             if self.transport == 'graphite':
                 # note: counters and gauges implicitly end up in the same namespace
@@ -206,7 +206,7 @@ class Server(object):
         for k, (v, t) in self.timers.items():
             if self.expire > 0 and t + self.expire < ts:
                 if self.debug:
-                    print "Expiring timer %s (age: %s)" % (k, ts - t)
+                    print("Expiring timer %s (age: %s)" % (k, ts - t))
                 del(self.timers[k])
                 continue
             if len(v) > 0:
@@ -228,8 +228,8 @@ class Server(object):
                 del(self.timers[k])
 
                 if self.debug:
-                    print "Sending %s ====> lower=%s, mean=%s, upper=%s, %dpct=%s, count=%s" \
-                        % (k, min, mean, max, self.pct_threshold, max_threshold, count)
+                    print("Sending %s ====> lower=%s, mean=%s, upper=%s, %dpct=%s, count=%s"
+                        % (k, min, mean, max, self.pct_threshold, max_threshold, count))
 
                 if self.transport == 'graphite':
 
@@ -275,14 +275,14 @@ class Server(object):
                 graphite.connect((self.graphite_host, self.graphite_port))
                 graphite.sendall(stat_string)
                 graphite.close()
-            except socket.error, e:
+            except socket.error as e:
                 log.error("Error communicating with Graphite: %s" % e)
                 if self.debug:
-                    print "Error communicating with Graphite: %s" % e
+                    print("Error communicating with Graphite: %s" % e)
 
         if self.debug:
-            print "\n================== Flush completed. Waiting until next flush. Sent out %d metrics =======" \
-                % (stats)
+            print("\n================== Flush completed. Waiting until next flush. Sent out %d metrics ======="
+                % (stats))
 
     def _set_timer(self):
         self._timer = threading.Timer(self.flush_interval / 1000, self.on_timer)
