$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- buildtools/reclient_cfgs/configure_reclient_cfgs.py.orig	2024-10-18 12:33:59.934179500 +0000
+++ buildtools/reclient_cfgs/configure_reclient_cfgs.py
@@ -322,4 +322,13 @@ def main():
 
 
 if __name__ == "__main__":
-    sys.exit(main())
+    r = main()
+    if r != 0:
+        sys.exit(r)
+
+    electron_script = os.path.join(CHROMIUM_SRC, 'third_party', 'engflow-reclient-configs', 'configure_reclient.py')
+    r = subprocess.call([sys.executable, electron_script, '--src_dir=src', '--force'])
+    if r != 0:
+        sys.exit(r)
+
+    print('done')
