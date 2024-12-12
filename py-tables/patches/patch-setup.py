$NetBSD$

--- setup.py.orig	2024-08-17 08:56:33.000000000 +0000
+++ setup.py
@@ -359,17 +359,38 @@ class BasePackage:
         # (The argument is accepted for compatibility with previous
         # methods.)
 
+        # Try just library name, relying on the OS search path.
+        # This fails on macOS.
         # dlopen() won't tell us where the file is, just whether
         # success occurred, so this returns True instead of a filename
+        # Try this before the absolute path search below: A Valentino
         for prefix in self._runtime_prefixes:
             for suffix in self._runtime_suffixes:
+                path = f"{prefix}{self.runtime_name}{suffix}"
+                print("find_runtime_path() trying ", path)
+                      
                 try:
-                    ctypes.CDLL(f"{prefix}{self.runtime_name}{suffix}")
+                    ctypes.CDLL(path)
                 except OSError:
                     pass
                 else:
                     return True
 
+        # If the library was not found by name alone, try absolute pathnames.
+        # In this case, we can return the path, rather than just True.
+        for location in locations:
+            for prefix in self._runtime_prefixes:
+                for suffix in self._runtime_suffixes:
+                    abs_path = f"{location}/{prefix}{self.runtime_name}{suffix}"
+                    print("find_runtime_path() trying ", abs_path)
+                          
+                    try:
+                        ctypes.CDLL(abs_path)
+                    except OSError:
+                        pass
+                    else:
+                        return abs_path
+
     def _pkg_config(self, flags):
         try:
             cmd = [PKG_CONFIG] + flags.split() + [self.library_name]
@@ -496,7 +517,8 @@ class BasePackage:
                     directories[idx] = Path(path[: path.rfind(name)])
                 else:
                     directories[idx] = Path(path).parent
-
+            else:
+                print("Error: path is not set.")
         return tuple(directories)
 
 
