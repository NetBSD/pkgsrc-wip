$NetBSD$

--- setup.py.orig	2024-08-17 08:56:33.000000000 +0000
+++ setup.py
@@ -363,6 +363,8 @@ class BasePackage:
         # success occurred, so this returns True instead of a filename
         for prefix in self._runtime_prefixes:
             for suffix in self._runtime_suffixes:
+                print("find_runtime_path() trying ",
+                      f"{prefix}{self.runtime_name}{suffix}")
                 try:
                     ctypes.CDLL(f"{prefix}{self.runtime_name}{suffix}")
                 except OSError:
@@ -455,6 +457,10 @@ class BasePackage:
 
         hook_dirs = hook() if hook is not None else [None, None, None]
 
+        print("locations = ", locations)
+        print("hook_dirs = ", hook_dirs)
+        print("pkgconfig_dirs = ", pkgconfig_dirs)
+
         directories = [None, None, None]  # headers, libraries, runtime
         for idx, (name, find_path, default_dirs) in enumerate(dirdata):
             use_locations = (
@@ -463,6 +469,7 @@ class BasePackage:
                 or hook_dirs[idx]
                 or default_dirs
             )
+            print("use_locations = ", use_locations)
             # pkgconfig does not list bin/ as the runtime dir
             if (
                 name == "blosc"  # blosc
@@ -475,8 +482,12 @@ class BasePackage:
                 use_locations = list(use_locations)
                 use_locations[0] = use_locations[0].parent / "bin"
                 print(f"Patching runtime dir: {str(use_locations[0])}")
+
+            # FIXME: path is coming up empty for blosc rundir on macOS,
+            # while returning True on other platforms.
             path = find_path(use_locations)
             if path:
+                print("path = ", path)
                 if path is True:
                     directories[idx] = True
                     continue
@@ -496,7 +507,19 @@ class BasePackage:
                     directories[idx] = Path(path[: path.rfind(name)])
                 else:
                     directories[idx] = Path(path).parent
-
+            else:
+                print("path is not set!!  This is a problem.")
+                if name == "blosc" or name == "blosc2":
+                    print("directories = ", directories)
+                    print("rundir (should be 'True') = ", directories[2])
+                    # FIXME: tables-3.10.1 hack
+                    # Forcing rundir to True for macOS.  This is a
+                    # hack, but it's the value it should have, since the
+                    # headers and libs are found.  When rundir is None,
+                    # setup.py copyies libblosc into the py-tables
+                    # installation, breaking PLIST.
+                    # if directories[0] and directories[1]:
+                    #     directories[2] = True
         return tuple(directories)
 
 
