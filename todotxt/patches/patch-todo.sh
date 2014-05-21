$NetBSD: patch-todo.sh,v 1.4 2014/05/21 14:06:31 ttys Exp $

Use temp file for "in-place" option not available in BSD/sed

--- todo.sh.orig	2014-05-21 12:49:20.000000000 +0000
+++ todo.sh
@@ -26,6 +26,9 @@ TODO_SH=$(basename "$0")
 TODO_FULL_SH="$0"
 export TODO_SH TODO_FULL_SH
 
+# Create temp file for "in-place" option not available in BSD/sed
+TODO_TMP="/tmp/.todo.tmp"
+
 oneline_usage="$TODO_SH [-fhpantvV] [-d todo_config] action [task_number] [task_description]"
 
 usage()
@@ -449,7 +452,8 @@ replaceOrPrepend()
   # change (replace/prepend) and re-insert the existing priority and prepended
   # date again.
   cleaninput "for sed"
-  sed -i.bak -e "$item s/^${priority}${prepdate}//" -e "$item s|^.*|${priority}${prepdate}${input}${backref}|" "$TODO_FILE"
+  sed -e "$item s/^${priority}${prepdate}//" -e "$item s|^.*|${priority}${prepdate}${input}${backref}|" "$TODO_FILE" \
+	> "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
   if [ $TODOTXT_VERBOSE -gt 0 ]; then
     getNewtodo "$item"
     case "$action" in
@@ -594,7 +598,7 @@ TODOTXT_DEFAULT_ACTION=${TODOTXT_DEFAULT
 TODOTXT_SORT_COMMAND=${TODOTXT_SORT_COMMAND:-env LC_COLLATE=C sort -f -k2}
 TODOTXT_DISABLE_FILTER=${TODOTXT_DISABLE_FILTER:-}
 TODOTXT_FINAL_FILTER=${TODOTXT_FINAL_FILTER:-cat}
-TODOTXT_GLOBAL_CFG_FILE=${TODOTXT_GLOBAL_CFG_FILE:-/etc/todo/config}
+TODOTXT_GLOBAL_CFG_FILE=${TODOTXT_GLOBAL_CFG_FILE:-@PKG_SYSCONFDIR@/todo/config}
 
 # Export all TODOTXT_* variables
 export ${!TODOTXT_@}
@@ -1052,7 +1056,7 @@ case $action in
     esac
     cleaninput "for sed"
 
-    if sed -i.bak $item" s|^.*|&${appendspace}${input}|" "$TODO_FILE"; then
+    if sed $item" s|^.*|&${appendspace}${input}|" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"; then
         if [ $TODOTXT_VERBOSE -gt 0 ]; then
             getNewtodo "$item"
             echo "$item $newtodo"
@@ -1064,10 +1068,10 @@ case $action in
 
 "archive" )
     # defragment blank lines
-    sed -i.bak -e '/./!d' "$TODO_FILE"
+    sed -e '/./!d' "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
     [ $TODOTXT_VERBOSE -gt 0 ] && grep "^x " "$TODO_FILE"
     grep "^x " "$TODO_FILE" >> "$DONE_FILE"
-    sed -i.bak '/^x /d' "$TODO_FILE"
+    sed '/^x /d' "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
     if [ $TODOTXT_VERBOSE -gt 0 ]; then
 	echo "TODO: $TODO_FILE archived."
     fi
@@ -1089,10 +1093,10 @@ case $action in
         if [ "$ANSWER" = "y" ]; then
             if [ $TODOTXT_PRESERVE_LINE_NUMBERS = 0 ]; then
                 # delete line (changes line numbers)
-                sed -i.bak -e $item"s/^.*//" -e '/./!d' "$TODO_FILE"
+                sed -e $item"s/^.*//" -e '/./!d' "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
             else
                 # leave blank line behind (preserves line numbers)
-                sed -i.bak -e $item"s/^.*//" "$TODO_FILE"
+                sed -e $item"s/^.*//" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
             fi
             if [ $TODOTXT_VERBOSE -gt 0 ]; then
                 echo "$item $todo"
@@ -1102,13 +1106,13 @@ case $action in
             echo "TODO: No tasks were deleted."
         fi
     else
-        sed -i.bak \
+        sed \
             -e $item"s/^\((.) \)\{0,1\} *$3 */\1/g" \
             -e $item"s/ *$3 *\$//g" \
             -e $item"s/  *$3 */ /g" \
             -e $item"s/ *$3  */ /g" \
             -e $item"s/$3//g" \
-            "$TODO_FILE"
+            "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
         getNewtodo "$item"
         if [ "$todo" = "$newtodo" ]; then
             [ $TODOTXT_VERBOSE -gt 0 ] && echo "$item $todo"
@@ -1133,7 +1137,7 @@ case $action in
         getTodo "$item"
 
 	if [[ "$todo" = \(?\)\ * ]]; then
-	    sed -i.bak -e $item"s/^(.) //" "$TODO_FILE"
+	    sed -e $item"s/^(.) //" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
 	    if [ $TODOTXT_VERBOSE -gt 0 ]; then
 		getNewtodo "$item"
 		echo "$item $newtodo"
@@ -1160,8 +1164,8 @@ case $action in
         if [ "${todo:0:2}" != "x " ]; then
             now=$(date '+%Y-%m-%d')
             # remove priority once item is done
-            sed -i.bak $item"s/^(.) //" "$TODO_FILE"
-            sed -i.bak $item"s|^|x $now |" "$TODO_FILE"
+            sed $item"s/^(.) //" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
+            sed $item"s|^|x $now |" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
             if [ $TODOTXT_VERBOSE -gt 0 ]; then
                 getNewtodo "$item"
                 echo "$item $newtodo"
@@ -1285,10 +1289,10 @@ case $action in
     if [ "$ANSWER" = "y" ]; then
         if [ $TODOTXT_PRESERVE_LINE_NUMBERS = 0 ]; then
             # delete line (changes line numbers)
-            sed -i.bak -e $item"s/^.*//" -e '/./!d' "$src"
+            sed -e $item"s/^.*//" -e '/./!d' "$src" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
         else
             # leave blank line behind (preserves line numbers)
-            sed -i.bak -e $item"s/^.*//" "$src"
+            sed -e $item"s/^.*//" "$src" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
         fi
         echo "$todo" >> "$dest"
 
@@ -1323,7 +1327,7 @@ note: PRIORITY must be anywhere from A t
     fi
 
     if [ "$oldpri" != "$newpri" ]; then
-        sed -i.bak -e $item"s/^(.) //" -e $item"s/^/($newpri) /" "$TODO_FILE"
+        sed -e $item"s/^(.) //" -e $item"s/^/($newpri) /" "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
     fi
     if [ $TODOTXT_VERBOSE -gt 0 ]; then
         getNewtodo "$item"
@@ -1396,12 +1400,12 @@ note: PRIORITY must be anywhere from A t
     #   h;        - replace the hold space with the expanded pattern space
     #   P;        - print up to the first newline (that is, the input line)
     #   b         - end processing of the current line
-    sed -i.bak -n \
+    sed -n \
         -e 'G; s/\n/&&/; /^\([^\n]*\n\).*\n\1/b dedup' \
         -e 's/\n//; h; P; b' \
         -e ':dedup' \
         -e "$deduplicateSedCommand" \
-        "$TODO_FILE"
+        "$TODO_FILE" > "$TODO_TMP" && cat "$TODO_TMP" > "$TODO_FILE"
 
     newTaskNum=$( sed -e '/./!d' "$TODO_FILE" | sed -n '$ =' )
     deduplicateNum=$(( originalTaskNum - newTaskNum ))
