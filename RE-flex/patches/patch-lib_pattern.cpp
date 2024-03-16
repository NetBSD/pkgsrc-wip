$NetBSD$

- cast chars to unsigned for ctype functions
- fix debug log statement

--- lib/pattern.cpp.orig	2024-03-16 22:12:13.189685354 +0000
+++ lib/pattern.cpp
@@ -537,7 +537,7 @@ void Pattern::init_options(const char *o
         case 'z':
           for (const char *t = s += (s[1] == '='); *s != ';' && *s != '\0'; ++t)
           {
-            if (std::isspace(*t) || *t == ';' || *t == '\0')
+            if (std::isspace(static_cast<unsigned char>(*t)) || *t == ';' || *t == '\0')
             {
               if (t > s + 1)
                 opt_.z = std::string(s + 1, t - s - 1);
@@ -4414,7 +4414,7 @@ void Pattern::gen_match_hfa_start(DFA::S
       hfa_.states[start->index].insert(next_state->index);
       Char lo = edge->first;
       Char hi = edge->second.first;
-      DBGLOG("0 HFA %p: %u..%u -> %p", state, lo, hi, next_state);
+      DBGLOG("0 HFA %p: %u..%u -> %p", start, lo, hi, next_state);
       hashes[next_state][0].insert(lo, hi);
     }
   }
