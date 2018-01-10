$NetBSD$

Fix portability issues for non-bash interpreters, this was
identified by the check_portability.awk script used when
PKG_DEVELOPER is set to ~yes~. Patches for source files were
submitted to upstream, their revision and integration is pending.

--- libs/spandsp/unpack_gsm0610_data.sh.orig	2017-04-19 13:14:01.304432000 +0000
+++ libs/spandsp/unpack_gsm0610_data.sh
@@ -53,7 +53,7 @@ else
     cd gsm0610
 fi
 
-if [ $1x == --no-exe-runx ]
+if [ $1x = --no-exe-runx ]
 then
     # Run the .exe files, which should be here
     ./FR_A.EXE
@@ -77,7 +77,7 @@ rm -rf READ_FRA.TXT
 rm -rf ACTION
 rm -rf unpacked
 
-if [ $1x == --no-exex ]
+if [ $1x = --no-exex ]
 then
     # We need to prepare the .exe files to be run separately
     rm -rf *.INP
