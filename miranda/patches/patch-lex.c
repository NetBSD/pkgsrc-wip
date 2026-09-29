$NetBSD$

--- lex.c.orig	2026-09-29 19:08:36.978950725 +0000
+++ lex.c
@@ -97,7 +97,7 @@ char *token() /* lex analyser for comman
     { char *h;
       *dicq++ = ch;
       ch=cmdgetchar();
-      while(isalnum(ch)||ch=='-'||ch=='_'||ch=='.')
+      while(isalnum((unsigned char)ch)||ch=='-'||ch=='_'||ch=='.')
 	   *dicq++ = ch,ch=cmdgetchar();
 	   /* NB csh does not allow `.' in user ids when expanding `~'
 	      but this may be a mistake */
@@ -108,7 +108,7 @@ char *token() /* lex analyser for comman
 #ifdef SPACEINFILENAMES
   if(ch!='"'&&ch!='<')        /* test added 9.5.06 see else part */
 #endif
-  while(!isspace(ch)&&ch!=EOF)
+  while(!isspace((unsigned char)ch)&&ch!=EOF)
        { *dicq++ = ch;
 	 if(ch=='%')
            {
@@ -277,15 +277,15 @@ int getlitch()
     case 't': return('\t');
     case 'v': return('\v');
     case 'X': /* omit for Haskell escape rules, see also lines marked H */
-    case 'x': if(isxdigit(c))
+    case 'x': if(isxdigit((unsigned char)c))
               { int value, N=ch=='x'?4:6; /* N=7 for Haskell escape rules */
                 char hold[8];
                 int count=0;
                 ch = c;
 #ifdef HASKELL
-             while(ch=='0'&&isxdigit(peekch()))ch=getch(); /* lose leading 0s */
+             while(ch=='0'&&isxdigit((unsigned char)peekch()))ch=getch(); /* lose leading 0s */
 #endif
-                while(isxdigit(ch)&&count<N)
+                while(isxdigit((unsigned char)ch)&&count<N)
                      hold[count++]=ch,ch=getch();
                 /* read upto N hex digits */
                 hold[count] = '\0';
@@ -298,9 +298,9 @@ int getlitch()
              { word n=ch-'0',count=1,N=3; /* N=8 for Haskell escape rules */
                ch = c;
 #ifdef HASKELL
-               while(ch=='0'&&isdigit(peekch()))ch=getch(); /* lose leading 0s */
+               while(ch=='0'&&isdigit((unsigned char)peekch()))ch=getch(); /* lose leading 0s */
 #endif
-               while(isdigit(ch)&&count<N)
+               while(isdigit((unsigned char)ch)&&count<N)
                /* read upto N digits */
                { n = 10*n+ch-'0';
                  count++;
@@ -400,7 +400,7 @@ int yylex()         /* called by YACC to
         }
       else return(';');
     }
-  if(isalpha(c)){ kollect(okid);
+  if(isalpha((unsigned char)c)){ kollect(okid);
                    if(inlex==1){ layout();
                                  yylval=name();
                                  return(c=='='?LEXDEF:
@@ -486,7 +486,7 @@ int yylex()         /* called by YACC to
                 if(c=='<'){ c=getch(); return(LE); }
                 if(c=='>'){ c=getch(); return(GE); }
                 if(c=='%'&&!commandmode)return(directive());
-                if(isalpha(c)) /* underlined reserved word */
+                if(isalpha((unsigned char)c)) /* underlined reserved word */
 	          { kollect(okulid);
                     if(dicp[1]=='_'&&dicp[2]=='')
 	              return(identifier(1)); }
@@ -522,7 +522,7 @@ int yylex()         /* called by YACC to
 	      }
 	    return(lastc);
   case '$': if(
-              isalpha(c))
+              isalpha((unsigned char)c))
               { int t;
                 kollect(okid);
                 t=identifier(0);
@@ -530,7 +530,7 @@ int yylex()         /* called by YACC to
                 /* the last alternative is an error - caveat */
 	    if('1'<=c&&c<='9')
 	      { int n=0;
-		while(isdigit(c)&&n<1e6)n=10*n+c-'0',c=getch();
+		while(isdigit((unsigned char)c)&&n<1e6)n=10*n+c-'0',c=getch();
 		if(n>sreds)
 		  /* sreds==0 everywhere except in semantic redn clause */
 		  printf("%ssyntax error: illegal symbol $%d%s\n",
@@ -660,7 +660,7 @@ char *pathname() /* returns NULL if not 
       extern char linebuf[];
       *dicp++ = c;
       c=getch();
-      while(isalnum(c)||c=='-'||c=='_'||c=='.')
+      while(isalnum((unsigned char)c)||c=='-'||c=='_'||c=='.')
            *dicp++ = c, c=getch();
       *dicp='\0';
       if((h=gethome(hold+1)))
@@ -913,22 +913,22 @@ void dic_check()  /* called from REDUCE 
 void numeral()
 { word nflag=1;
   dicq= dicp;
-  while(isdigit(c))
+  while(isdigit((unsigned char)c))
        *dicq++ = c, c=getch();
   if(c=='.'&&peekdig())
     { *dicq++ = c, c=getch(); nflag=0;
-      while(isdigit(c))
+      while(isdigit((unsigned char)c))
            *dicq++ = c, c=getch(); }
   if(c=='e')
     { word np=0;
       *dicq++ = c, c=getch(); nflag=0;
       if(c=='+')c=getch(); else  /* ignore + before exponent */
       if(c=='-')*dicq++ = c, c=getch();
-      if(!isdigit(c))  /* e must be followed by some digits */
+      if(!isdigit((unsigned char)c))  /* e must be followed by some digits */
 	syntax("badly formed floating point number\n");
       while(c=='0')
            *dicq++ = c, c=getch();
-      while(isdigit(c))
+      while(isdigit((unsigned char)c))
            np++, *dicq++ = c, c=getch();
       if(!nflag&&np>3) /* scanf falls over with silly exponents */
 	{ syntax("floating point number out of range\n");
@@ -952,22 +952,22 @@ void hexnumeral()   /* added 21.11.2013 
 { dicq= dicp;
   *dicq++ = c, c=getch(); /* 0 */
   *dicq++ = c, c=getch(); /* x */
-  if(!isxdigit(c)&&c!='.')syntax("malformed hex number\n");
-  while(c=='0'&&isxdigit(peekch()))c=getch(); /* skip zeros before first nonzero digit */
-  while(isxdigit(c))
+  if(!isxdigit((unsigned char)c)&&c!='.')syntax("malformed hex number\n");
+  while(c=='0'&&isxdigit((unsigned char)peekch()))c=getch(); /* skip zeros before first nonzero digit */
+  while(isxdigit((unsigned char)c))
        *dicq++ = c, c=getch();
   ovflocheck;
   if(c=='.'||tolower(c)=='p') /* hex float, added 20.11.19 */
     { double d;
       if(c=='.')
         { *dicq++ = c, c=getch();
-          while(isxdigit(c))
+          while(isxdigit((unsigned char)c))
           *dicq++ = c, c=getch(); }
       if(c=='p')
         { *dicq++ = c, c=getch();
           if(c=='+'||c=='-')*dicq++ = c, c=getch();
-          if(!isdigit(c))syntax("malformed hex float\n");
-          while(isdigit(c))
+          if(!isdigit((unsigned char)c))syntax("malformed hex float\n");
+          while(isdigit((unsigned char)c))
           *dicq++ = c, c=getch(); }
       ovflocheck;
       *dicq='\0';
@@ -981,11 +981,11 @@ void hexnumeral()   /* added 21.11.2013 
 
 void octnumeral()   /* added 21.11.2013 */
 { dicq= dicp;
-  if(!isdigit(c))syntax("malformed octal number\n");
-  while(c=='0'&&isdigit(peekch()))c=getch(); /* skip zeros before first nonzero digit */
-  while(isdigit(c)&&c<='7')
+  if(!isdigit((unsigned char)c))syntax("malformed octal number\n");
+  while(c=='0'&&isdigit((unsigned char)peekch()))c=getch(); /* skip zeros before first nonzero digit */
+  while(isdigit((unsigned char)c)&&c<='7')
        *dicq++ = c, c=getch();
-  if(isdigit(c))syntax("illegal digit in octal number\n");
+  if(isdigit((unsigned char)c))syntax("illegal digit in octal number\n");
   ovflocheck;
   *dicq = '\0';
   yylval= bigoscan(dicp,dicq);
@@ -1001,7 +1001,7 @@ int hash(char *s) /* returns a value in 
 
 int isconstrname(char *s)
 { if(s[0]=='$')s++;
-  return isupper((int)*s); /* formerly !islower */
+  return isupper((unsigned char)*s); /* formerly !islower */
 }
 
 word getfname(word x)
