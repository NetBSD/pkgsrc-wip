$NetBSD$

Use inttypes.h for printing 64 bit numbers compatibly

--- gptcurses.cc.orig	2022-04-14 19:17:12.000000000 -0400
+++ gptcurses.cc
@@ -30,6 +30,7 @@
 #endif
 #include "gptcurses.h"
 #include "support.h"
+#include <inttypes.h>
 
 using namespace std;
 
@@ -333,13 +334,13 @@
    printw("Partition GUID code: %s (%s)\n", partitions[partNum].GetType().AsString().c_str(),
           partitions[partNum].GetTypeName().c_str());
    printw("Partition unique GUID: %s\n", partitions[partNum].GetUniqueGUID().AsString().c_str());
-   printw("First sector: %lld (at %s)\n", partitions[partNum].GetFirstLBA(),
+   printw("First sector: %" PRId64 " (at %s)\n", partitions[partNum].GetFirstLBA(),
           BytesToIeee(partitions[partNum].GetFirstLBA(), blockSize).c_str());
-   printw("Last sector: %lld (at %s)\n", partitions[partNum].GetLastLBA(),
+   printw("Last sector: %" PRId64 " (at %s)\n", partitions[partNum].GetLastLBA(),
           BytesToIeee(partitions[partNum].GetLastLBA(), blockSize).c_str());
    size = partitions[partNum].GetLastLBA() - partitions[partNum].GetFirstLBA() + 1;
-   printw("Partition size: %lld sectors (%s)\n", size, BytesToIeee(size, blockSize).c_str());
-   printw("Attribute flags: %016llx\n", partitions[partNum].GetAttributes().GetAttributes());
+   printw("Partition size: %" PRId64 " sectors (%s)\n", size, BytesToIeee(size, blockSize).c_str());
+   printw("Attribute flags: %016" PRIX64 "\n", partitions[partNum].GetAttributes().GetAttributes());
    #ifdef USE_UTF16
    partitions[partNum].GetDescription().extract(0, NAME_SIZE , temp, NAME_SIZE );
    printw("Partition name: '%s'\n", temp);
@@ -447,7 +448,7 @@
       clrtoeol();
       newFirstLBA = currentSpace->firstLBA;
       Align(&newFirstLBA);
-      printw("First sector (%lld-%lld, default = %lld): ", newFirstLBA, currentSpace->lastLBA, newFirstLBA);
+      printw("First sector (%" PRId64 "-%" PRId64 ", default = %" PRId64 "): ", newFirstLBA, currentSpace->lastLBA, newFirstLBA);
       echo();
       getnstr(inLine, 79);
       noecho();
@@ -461,7 +462,7 @@
    while ((newLastLBA > currentSpace->lastLBA) || (newLastLBA < newFirstLBA)) {
       move(LINES - 3, 0);
       clrtoeol();
-      printw("Size in sectors or {KMGTP} (default = %lld): ", size);
+      printw("Size in sectors or {KMGTP} (default = %" PRId64 "): ", size);
       echo();
       getnstr(inLine, 79);
       noecho();
