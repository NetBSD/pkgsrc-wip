$NetBSD$

Make python command SUBST_VARSible.

--- bundles/pyml/pyml-current/py.ml.orig	2016-09-27 20:47:06.000000000 +0000
+++ bundles/pyml/pyml-current/py.ml
@@ -145,7 +145,7 @@ let find_library_path version_major vers
     None ->
       let library_paths =
         try
-          [Filename.concat (Filename.dirname (run_command "which python" false))
+          [Filename.concat (Filename.dirname (run_command "which python@PYVERSSUFFIX@" false))
              "../lib"]
         with Failure _ -> [] in
       let library_filenames =
@@ -178,7 +178,7 @@ let find_library_path version_major vers
       (library_paths, [library_filename])
 
 let initialize_version_value () =
-  let version_line = run_command "python --version" true in
+  let version_line = run_command "python@PYVERSSUFFIX@ --version" true in
   let version = extract_version version_line in
   let (version_major, version_minor) = extract_version_major_minor version in
   version_value := version;
