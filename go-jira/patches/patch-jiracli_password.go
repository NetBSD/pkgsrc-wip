$NetBSD$

Remove `keyring' support to support more platforms.

The `keyring' support at the moment is only supported on Linux and needs to be
ported on other Unix-like platforms.

--- jiracli/password.go.orig	2020-09-11 18:12:24.000000000 +0000
+++ jiracli/password.go
@@ -57,14 +57,7 @@ func (o *GlobalOptions) GetPass() string
 	log.Debugf("Getting Password")
 	if o.PasswordSource.Value != "" {
 		log.Debugf("password-source: %s", o.PasswordSource)
-		if o.PasswordSource.Value == "keyring" {
-			log.Info("Querying keyring password source.")
-			var err error
-			o.cachedPassword, err = keyringGet(o.keyName())
-			if err != nil {
-				panic(err)
-			}
-		} else if o.PasswordSource.Value == "gopass" {
+		if o.PasswordSource.Value == "gopass" {
 			log.Debugf("Querying gopass password source.")
 			binary := o.GetPasswordPath()
 			if o.PasswordDirectory.Value != "" {
@@ -167,14 +160,7 @@ func (o *GlobalOptions) SetPass(passwd s
 		return nil
 	}
 
-	if o.PasswordSource.Value == "keyring" {
-		// save password in keychain so that it can be used for subsequent http requests
-		err := keyringSet(o.keyName(), passwd)
-		if err != nil {
-			log.Errorf("Failed to set password in keyring: %s", err)
-			return err
-		}
-	} else if o.PasswordSource.Value == "gopass" {
+	if o.PasswordSource.Value == "gopass" {
 		if o.PasswordDirectory.Value != "" {
 			orig := os.Getenv("PASSWORD_STORE_DIR")
 			os.Setenv("PASSWORD_STORE_DIR", o.PasswordDirectory.Value)
