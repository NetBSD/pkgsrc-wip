$NetBSD$

Avoid to use `git' and fail because it is not a Git repository

--- manifests/scripts/bundle.sh.orig	2021-04-23 10:51:40.000000000 +0000
+++ manifests/scripts/bundle.sh
@@ -16,8 +16,8 @@
 
 set -e
 
-IN_PATH=${1:-"$(git rev-parse --show-toplevel)/manifests"}
-OUT_PATH=${2:-"$(git rev-parse --show-toplevel)/cmd/flux/manifests"}
+IN_PATH=${1:-"./manifests"}
+OUT_PATH=${2:-"./cmd/flux/manifests"}
 TAR=${3}
 
 info() {
