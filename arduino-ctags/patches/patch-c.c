$NetBSD$

--- c.c.orig	2019-03-25 18:42:04.893874209 +0000
+++ c.c
@@ -624,7 +624,7 @@ static const char *keywordString (const 
 	return name;
 }
 
-static void __unused__ pt (tokenInfo *const token)
+static void CTAGS_UNUSED pt (tokenInfo *const token)
 {
 	if (isType (token, TOKEN_NAME))
 		printf ("type: %-12s: %-13s   line: %lu\n",
@@ -639,7 +639,7 @@ static void __unused__ pt (tokenInfo *co
 			tokenString (token->type), token->lineNumber);
 }
 
-static void __unused__ ps (statementInfo *const st)
+static void CTAGS_UNUSED ps (statementInfo *const st)
 {
 	unsigned int i;
 	printf ("scope: %s   decl: %s   gotName: %s   gotParenName: %s isPointer: %s\n",
