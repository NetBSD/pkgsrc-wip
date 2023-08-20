$NetBSD$

* don't require git

--- deps.sh.orig	2023-08-18 15:54:41.998155227 +0000
+++ deps.sh
@@ -59,17 +59,6 @@ download_github() {
 
 
 main() {
-  if git -C "${MYDIR}" rev-parse; then
-    cat >&2 <<EOF
-Current directory is a git repository, downloading dependencies via git:
-
-  git submodule update --init --recursive
-
-EOF
-    git -C "${MYDIR}" submodule update --init --recursive --depth 1 --recommend-shallow
-    return 0
-  fi
-
   # Sources downloaded from a tarball.
   download_github third_party/brotli google/brotli
   download_github third_party/highway google/highway
