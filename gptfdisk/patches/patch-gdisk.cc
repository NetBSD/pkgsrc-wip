$NetBSD$

Must have mutable device path to add 'r' if necessary

--- gdisk.cc.orig	2022-04-14 23:17:12.000000000 +0000
+++ gdisk.cc
@@ -39,7 +39,8 @@ int main(int argc, char* argv[]) {
          } // if/elseif
          break;
       case 2: // basic usage
-         if (theGPT.LoadPartitions(argv[1])) {
+         device = argv[1];
+         if (theGPT.LoadPartitions(device)) {
             if (theGPT.GetState() != use_gpt)
                WinWarning();
             theGPT.MainMenu(argv[1]);
