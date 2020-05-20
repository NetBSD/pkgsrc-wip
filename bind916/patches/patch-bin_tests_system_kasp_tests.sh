$NetBSD$

Portability in shell script, don't use == with test.

--- bin/tests/system/kasp/tests.sh.orig	2020-05-06 09:59:35.000000000 +0000
+++ bin/tests/system/kasp/tests.sh
@@ -281,7 +281,7 @@ check_key() {
 	# Check file existence.
 	[ -s "$KEY_FILE" ] || ret=1
 	[ -s "$PRIVATE_FILE" ] || ret=1
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		[ -s "$STATE_FILE" ] || ret=1
 	fi
 	[ "$ret" -eq 0 ] || log_error "${BASE_FILE} files missing"
@@ -296,9 +296,9 @@ check_key() {
 	grep "Private-key-format: v1.3" "$PRIVATE_FILE" > /dev/null || log_error "mismatch private key format in $PRIVATE_FILE"
 	grep "Algorithm: ${_alg_num} (${_alg_string})" "$PRIVATE_FILE" > /dev/null || log_error "mismatch algorithm in $PRIVATE_FILE"
 	# Now check the key state file.
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "This is the state of key ${_key_id}, for ${_zone}." "$STATE_FILE" > /dev/null || log_error "mismatch top comment in $STATE_FILE"
-		if [ "$_lifetime" == "none" ]; then
+		if [ "$_lifetime" = "none" ]; then
 			grep "Lifetime: " "$STATE_FILE" > /dev/null && log_error "unexpected lifetime in $STATE_FILE"
 		else
 			grep "Lifetime: ${_lifetime}" "$STATE_FILE" > /dev/null || log_error "mismatch lifetime in $STATE_FILE"
@@ -352,13 +352,13 @@ check_key() {
 	if [ "$_published" = "none" ]; then
 		grep "; Publish:" "$KEY_FILE" > /dev/null && log_error "unexpected publish comment in $KEY_FILE"
 		grep "Publish:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected publish in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Published: " "$STATE_FILE" > /dev/null && log_error "unexpected publish in $STATE_FILE"
 		fi
 	else
 		grep "; Publish:" "$KEY_FILE" > /dev/null || log_error "mismatch publish comment in $KEY_FILE"
 		grep "Publish:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch publish in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Published:" "$STATE_FILE" > /dev/null || log_error "mismatch publish in $STATE_FILE"
 		fi
 	fi
@@ -366,13 +366,13 @@ check_key() {
 	if [ "$_active" = "none" ]; then
 		grep "; Activate:" "$KEY_FILE" > /dev/null && log_error "unexpected active comment in $KEY_FILE"
 		grep "Activate:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected active in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Active: " "$STATE_FILE" > /dev/null && log_error "unexpected active in $STATE_FILE"
 		fi
 	else
 		grep "; Activate:" "$KEY_FILE" > /dev/null || log_error "mismatch active comment in $KEY_FILE"
 		grep "Activate:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch active in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Active: " "$STATE_FILE" > /dev/null || log_error "mismatch active in $STATE_FILE"
 		fi
 	fi
@@ -380,13 +380,13 @@ check_key() {
 	if [ "$_retired" = "none" ]; then
 		grep "; Inactive:" "$KEY_FILE" > /dev/null && log_error "unexpected retired comment in $KEY_FILE"
 		grep "Inactive:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected retired in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Retired: " "$STATE_FILE" > /dev/null && log_error "unexpected retired in $STATE_FILE"
 		fi
 	else
 		grep "; Inactive:" "$KEY_FILE" > /dev/null || log_error "mismatch retired comment in $KEY_FILE"
 		grep "Inactive:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch retired in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Retired: " "$STATE_FILE" > /dev/null || log_error "mismatch retired in $STATE_FILE"
 		fi
 	fi
@@ -394,13 +394,13 @@ check_key() {
 	if [ "$_revoked" = "none" ]; then
 		grep "; Revoke:" "$KEY_FILE" > /dev/null && log_error "unexpected revoked comment in $KEY_FILE"
 		grep "Revoke:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected revoked in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Revoked: " "$STATE_FILE" > /dev/null && log_error "unexpected revoked in $STATE_FILE"
 		fi
 	else
 		grep "; Revoke:" "$KEY_FILE" > /dev/null || log_error "mismatch revoked comment in $KEY_FILE"
 		grep "Revoke:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch revoked in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Revoked: " "$STATE_FILE" > /dev/null || log_error "mismatch revoked in $STATE_FILE"
 		fi
 	fi
@@ -408,20 +408,20 @@ check_key() {
 	if [ "$_removed" = "none" ]; then
 		grep "; Delete:" "$KEY_FILE" > /dev/null && log_error "unexpected removed comment in $KEY_FILE"
 		grep "Delete:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected removed in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Removed: " "$STATE_FILE" > /dev/null && log_error "unexpected removed in $STATE_FILE"
 		fi
 	else
 		grep "; Delete:" "$KEY_FILE" > /dev/null || log_error "mismatch removed comment in $KEY_FILE"
 		grep "Delete:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch removed in $PRIVATE_FILE"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Removed: " "$STATE_FILE" > /dev/null || log_error "mismatch removed in $STATE_FILE"
 		fi
 	fi
 
 	grep "; Created:" "$KEY_FILE" > /dev/null || log_error "mismatch created comment in $KEY_FILE"
 	grep "Created:" "$PRIVATE_FILE" > /dev/null || log_error "mismatch created in $PRIVATE_FILE"
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "Generated: " "$STATE_FILE" > /dev/null || log_error "mismatch generated in $STATE_FILE"
 	fi
 }
@@ -470,7 +470,7 @@ key_unused() {
 	grep "Revoke:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected revoked in $PRIVATE_FILE"
 	grep "Delete:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected removed in $PRIVATE_FILE"
 
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "Published: " "$STATE_FILE" > /dev/null && log_error "unexpected publish in $STATE_FILE"
 		grep "Active: " "$STATE_FILE" > /dev/null && log_error "unexpected active in $STATE_FILE"
 		grep "Retired: " "$STATE_FILE" > /dev/null && log_error "unexpected retired in $STATE_FILE"
@@ -3134,8 +3134,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy uses the same keys ($n)"
 ret=0
-[ $_migrate_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migrate_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migrate_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migrate_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 # Test migration to dnssec-policy, existing keys do not match key algorithm.
@@ -3191,8 +3191,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy keeps existing keys ($n)"
 ret=0
-[ $_migratenomatch_algnum_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migratenomatch_algnum_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migratenomatch_algnum_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migratenomatch_algnum_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 # Test migration to dnssec-policy, existing keys do not match key length.
@@ -3249,8 +3249,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy keeps existing keys ($n)"
 ret=0
-[ $_migratenomatch_alglen_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migratenomatch_alglen_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migratenomatch_alglen_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migratenomatch_alglen_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 #
