$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- buildtools/reclient_cfgs/configure_reclient_cfgs.py.orig	2025-02-24 19:59:26.000000000 +0000
+++ buildtools/reclient_cfgs/configure_reclient_cfgs.py
@@ -344,4 +344,13 @@ def main():
 
 
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
