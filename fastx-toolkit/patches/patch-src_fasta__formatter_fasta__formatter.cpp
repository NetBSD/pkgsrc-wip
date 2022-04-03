$NetBSD$

# Silence compile error

--- src/fasta_formatter/fasta_formatter.cpp.orig	2022-04-03 12:45:51.295476843 +0000
+++ src/fasta_formatter/fasta_formatter.cpp
@@ -103,6 +103,7 @@ void parse_command_line(int argc, char* 
 		switch(opt) {
 		case 'h':
 			usage();
+			break;
 		
 		case 'i':
 			input_filename = optarg;
