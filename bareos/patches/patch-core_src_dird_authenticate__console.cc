$NetBSD$

	Remove inadequate clutter in production messages

--- core/src/dird/authenticate_console.cc.orig	2019-02-01 07:13:31.178559767 +0000
+++ core/src/dird/authenticate_console.cc
@@ -204,10 +204,12 @@ bool ConsoleAuthenticatorFrom_18_2::Send
 bool ConsoleAuthenticatorFrom_18_2::SendInfoMessage()
 {
   std::string message;
+#ifndef NO_ADV
   message += BAREOS_BINARY_INFO;
   message += " binary\n";
   message += BAREOS_SERVICES_MESSAGE;
   message += "\n";
+#endif
   message += "You are ";
   if (ua_->cons) {
     message += "logged in as: ";
