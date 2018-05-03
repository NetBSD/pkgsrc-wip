$NetBSD$

--- fastmap.c.orig	2018-04-19 22:02:10.516983388 +0000
+++ fastmap.c
@@ -130,7 +130,9 @@ int main_mem(int argc, char *argv[])
 
 	aux.opt = opt = mem_opt_init();
 	memset(&opt0, 0, sizeof(mem_opt_t));
+	fprintf(stderr, "argc = %d argv[1] = %s\n", argc, argv[1]);
 	while ((c = getopt(argc, argv, "51qpaMCSPVYjk:c:v:s:r:t:R:A:B:O:E:U:w:L:d:T:Q:D:m:I:N:o:f:W:x:G:h:y:K:X:H:")) >= 0) {
+		fprintf(stderr, "c = %d %c\n", c, c);
 		if (c == 'k') opt->min_seed_len = atoi(optarg), opt0.min_seed_len = 1;
 		else if (c == '1') no_mt_io = 1;
 		else if (c == 'x') mode = optarg;
