$NetBSD$

Remove unused member.
https://github.com/indygreg/PyOxidizer/pull/623

--- src/macho.rs.orig	2022-08-07 20:37:36.000000000 +0000
+++ src/macho.rs
@@ -630,8 +630,6 @@ pub fn semver_to_macho_target_version(ve
 
 /// Represents a semi-parsed Mach[-O] binary.
 pub struct MachFile<'a> {
-    data: &'a [u8],
-
     machos: Vec<MachOBinary<'a>>,
 }
 
@@ -663,7 +661,7 @@ impl<'a> MachFile<'a> {
             }
         };
 
-        Ok(Self { data, machos })
+        Ok(Self { machos })
     }
 
     /// Whether this Mach-O data has multiple architectures.
