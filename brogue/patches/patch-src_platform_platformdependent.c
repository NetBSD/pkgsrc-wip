$NetBSD: patch-src_platform_platformdependent.c,v 1.1 2015/08/18 20:24:52 yhardy Exp $

The high scores file is kept in the BROGUE_SHARE directory

--- ./src/platform/platformdependent.c.orig	2014-07-03 19:19:10.000000000 +0000
+++ ./src/platform/platformdependent.c
@@ -75,7 +75,7 @@ void initScores() {
 	short i;
 	FILE *scoresFile;
 	
-	scoresFile = fopen("BrogueHighScores.txt", "w");
+	scoresFile = fopen(BROGUE_SHARE "/BrogueHighScores.txt", "w");
 	for (i=0; i<HIGH_SCORES_COUNT; i++) {
 		fprintf(scoresFile, "%li\t%li\t%s", (long) 0, (long) 0, "(empty entry)\n");
 	}
@@ -128,11 +128,11 @@ short loadScoreBuffer() {
 	time_t rawtime;
 	struct tm * timeinfo;
 	
-	scoresFile = fopen("BrogueHighScores.txt", "r");
+	scoresFile = fopen(BROGUE_SHARE "/BrogueHighScores.txt", "r");
 	
 	if (scoresFile == NULL) {
 		initScores();
-		scoresFile = fopen("BrogueHighScores.txt", "r");
+		scoresFile = fopen(BROGUE_SHARE "/BrogueHighScores.txt", "r");
 	}
 	
 	for (i=0; i<HIGH_SCORES_COUNT; i++) {
@@ -197,7 +197,7 @@ void saveScoreBuffer() {
 	short i;
 	FILE *scoresFile;
 	
-	scoresFile = fopen("BrogueHighScores.txt", "w");
+	scoresFile = fopen(BROGUE_SHARE "/BrogueHighScores.txt", "w");
 	
 	for (i=0; i<HIGH_SCORES_COUNT; i++) {
 		// save the entry
