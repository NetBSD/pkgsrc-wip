$NetBSD$

--- setup.py.orig	2020-10-26 15:54:27.000000000 +0000
+++ setup.py
@@ -322,6 +322,7 @@ def main():
     libdirs.extend(['/usr/local/lib', '/usr/lib', '/lib',
                     '/usr/lib/x86_64-linux-gnu',
                     '/usr/X11R6/lib', '/usr/lib/X11', '/usr/openwin/lib', ])
+    libdirs.extend([os.path.join(os.environ.get('BUILDLINK_DIR'), 'lib'), ])
 
     incdirs = [os.path.join(cfg['ASTER_ROOT'], 'public', 'include'),
                os.path.join(cfg['ASTER_ROOT'], 'public'), ]
@@ -376,6 +377,12 @@ def main():
                 cfg['ARCH'] = machine
             else:  # force to x86_64
                 cfg['ARCH'] = 'x86_64'
+    elif plt.startswith('netbsd'):
+        cfg['IFDEF'] = 'NETBSD'
+        if machine in ('x86_64', 'ia64', 'ppc64'):
+            cfg['ARCH'] = machine
+        else:  # force to x86_64
+            cfg['ARCH'] = 'x86_64'
     elif plt.startswith('osf1'):
         cfg['IFDEF'] = 'TRU64'
     elif plt == 'sunos5':
