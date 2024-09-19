$NetBSD$

Support whitespaces in filename
https://github.com/free-electrons/elixir/commit/4845e251862de3e915a1668e7c810072d7adb373#diff-8e6afdf322bc86524af61ffc82e64ca3

--- script.sh.orig	2017-05-25 08:56:01.000000000 +0000
+++ script.sh
@@ -86,6 +86,15 @@ case $cmd in
                 tac |
                 sed -r 's/^([0-9])\.([0-9]*)(.*)$/v\1 \1.\2 \1.\2\3/'
               ;;
+              NetBSD)
+                echo "trunk"
+              ;;
+              Linux)
+                echo "master"
+              ;;
+              RIOT)
+                echo "master"
+              ;;
               *)
                 echo "$tags" |
                 tac |
@@ -93,7 +102,20 @@ case $cmd in
               ;;
             esac
         else
-            echo "$tags"
+            case $project in
+              NetBSD)
+                echo "trunk"
+              ;;
+              Linux)
+                echo "master"
+              ;;
+              RIOT)
+                echo "master"
+              ;;
+              *)
+                echo "$tags"
+              ;;
+            esac
         fi
         ;;
 
@@ -162,9 +184,12 @@ case $cmd in
 
     parse-defs)
         tmp=`mktemp -d`
-        git cat-file blob "$1" > $tmp/$2
-        ctags -x --c-kinds=+p-m $tmp/$2 | awk '{print $1" "$2" "$3}'
-        rm $tmp/$2
+        full_path=$tmp/$2
+        git cat-file blob "$1" > "$full_path"
+        ctags -x --c-kinds=+p-m "$full_path" |
+        grep -av "^operator " |
+        awk '{print $1" "$2" "$3}'
+        rm "$full_path"
         rmdir $tmp
         ;;
 
