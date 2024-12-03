$NetBSD$

Portability fix

--- utility/util_builders.c.orig	2024-12-03 23:51:29.672563271 +0000
+++ utility/util_builders.c
@@ -82,7 +82,7 @@ int gauge_builder(BUILDER_ARGS)
 
 	perc = 0;
 	if (argc == 1) {
-		perc = (u_int)strtoul(argv[0], NULL, 10);
+		perc = (unsigned int)strtoul(argv[0], NULL, 10);
 		perc = perc > 100 ? 100 : perc;
 	} else if (argc > 1) {
 		error_args(opt->name, argc - 1, argv + 1);
@@ -106,7 +106,7 @@ int mixedgauge_builder(BUILDER_ARGS)
 		exit_error(true,
 		    "bad %s pair number [<minilabel> <miniperc>]", opt->name);
 
-	mainperc = (u_int)strtoul(argv[0], NULL, 10);
+	mainperc = (unsigned int)strtoul(argv[0], NULL, 10);
 	mainperc = mainperc > 100 ? 100 : mainperc;
 	argc--;
 	argv++;
@@ -138,7 +138,7 @@ int pause_builder(BUILDER_ARGS)
 	if (argc > 1)
 		error_args(opt->name, argc - 1, argv + 1);
 
-	secs = (u_int)strtoul(argv[0], NULL, 10);
+	secs = (unsigned int)strtoul(argv[0], NULL, 10);
 	output = bsddialog_pause(conf, text, rows, cols, &secs);
 
 	return (output);
@@ -189,9 +189,9 @@ static int date(BUILDER_ARGS)
 		error_args(opt->name, argc - 3, argv + 3);
 	} else if (argc == 3) {
 		/* lib checks/sets max and min */
-		dd = (u_int)strtoul(argv[0], NULL, 10);
-		mm = (u_int)strtoul(argv[1], NULL, 10);
-		yy = (u_int)strtoul(argv[2], NULL, 10);
+		dd = (unsigned int)strtoul(argv[0], NULL, 10);
+		mm = (unsigned int)strtoul(argv[1], NULL, 10);
+		yy = (unsigned int)strtoul(argv[2], NULL, 10);
 	}
 
 	if (strcmp(opt->name, "--datebox") == 0)
@@ -259,9 +259,9 @@ int timebox_builder(BUILDER_ARGS)
 	if (argc > 3) {
 		error_args("--timebox", argc - 3, argv + 3);
 	} else if (argc == 3) {
-		hh = (u_int)strtoul(argv[0], NULL, 10);
-		mm = (u_int)strtoul(argv[1], NULL, 10);
-		ss = (u_int)strtoul(argv[2], NULL, 10);
+		hh = (unsigned int)strtoul(argv[0], NULL, 10);
+		mm = (unsigned int)strtoul(argv[1], NULL, 10);
+		ss = (unsigned int)strtoul(argv[2], NULL, 10);
 	}
 
 	output = bsddialog_timebox(conf, text, rows, cols, &hh, &mm, &ss);
@@ -315,7 +315,7 @@ get_menu_items(int argc, char **argv, bo
 	for (i = 0; i < *nitems; i++) {
 		(*items)[i].prefix = setprefix ? argv[j++] : "";
 		(*items)[i].depth = setdepth ?
-		    (u_int)strtoul(argv[j++], NULL, 0) : 0;
+		    (unsigned int)strtoul(argv[j++], NULL, 0) : 0;
 		(*items)[i].name = setname ? argv[j++] : "";
 		(*items)[i].desc = setdesc ? argv[j++] : "";
 		if (setstatus) {
@@ -436,7 +436,7 @@ int checklist_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--checklist missing <menurows>");
-	menurows = (u_int)strtoul(argv[0], NULL, 10);
+	menurows = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	get_menu_items(argc-1, argv+1, opt->item_prefix, opt->item_depth, true,
 	    true, true, opt->item_bottomdesc, &nitems, &items, &focusitem, opt);
@@ -461,7 +461,7 @@ int menu_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--menu missing <menurows>");
-	menurows = (u_int)strtoul(argv[0], NULL, 10);
+	menurows = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	get_menu_items(argc-1, argv+1, opt->item_prefix, opt->item_depth, true,
 	    true, false, opt->item_bottomdesc, &nitems, &items, &focusitem,
@@ -487,7 +487,7 @@ int radiolist_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--radiolist missing <menurows>");
-	menurows = (u_int)strtoul(argv[0], NULL, 10);
+	menurows = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	get_menu_items(argc-1, argv+1, opt->item_prefix, opt->item_depth, true,
 	    true, true, opt->item_bottomdesc, &nitems, &items, &focusitem, opt);
@@ -512,7 +512,7 @@ int treeview_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--treeview missing <menurows>");
-	menurows = (u_int)strtoul(argv[0], NULL, 10);
+	menurows = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	get_menu_items(argc-1, argv+1, opt->item_prefix, true, true, true, true,
 	    opt->item_bottomdesc, &nitems, &items, &focusitem, opt);
@@ -595,7 +595,7 @@ int form_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--form missing <formheight>");
-	formheight = (u_int)strtoul(argv[0], NULL, 10);
+	formheight = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	argc--;
 	argv++;
@@ -609,11 +609,11 @@ int form_builder(BUILDER_ARGS)
 	j = 0;
 	for (i = 0; i < nitems; i++) {
 		items[i].label	= argv[j++];
-		items[i].ylabel = (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xlabel = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].ylabel = (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xlabel = (unsigned int)strtoul(argv[j++], NULL, 10);
 		items[i].init	= argv[j++];
-		items[i].yfield	= (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xfield	= (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].yfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
 
 		fieldlen = (int)strtol(argv[j++], NULL, 10);
 		if (fieldlen == 0)
@@ -621,7 +621,7 @@ int form_builder(BUILDER_ARGS)
 		else
 			items[i].fieldlen = abs(fieldlen);
 
-		items[i].maxvaluelen = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].maxvaluelen = (unsigned int)strtoul(argv[j++], NULL, 10);
 		if (items[i].maxvaluelen == 0)
 			items[i].maxvaluelen = items[i].fieldlen;
 
@@ -678,7 +678,7 @@ int mixedform_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--mixedform missing <formheight>");
-	formheight = (u_int)strtoul(argv[0], NULL, 10);
+	formheight = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	argc--;
 	argv++;
@@ -692,21 +692,21 @@ int mixedform_builder(BUILDER_ARGS)
 	j = 0;
 	for (i = 0; i < nitems; i++) {
 		items[i].label	= argv[j++];
-		items[i].ylabel = (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xlabel = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].ylabel = (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xlabel = (unsigned int)strtoul(argv[j++], NULL, 10);
 		items[i].init	= argv[j++];
-		items[i].yfield	= (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xfield	= (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].yfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
 		fieldlen        = (int)strtol(argv[j++], NULL, 10);
 		if (fieldlen == 0)
 			items[i].fieldlen = strcols(items[i].init);
 		else
 			items[i].fieldlen = abs(fieldlen);
-		items[i].maxvaluelen = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].maxvaluelen = (unsigned int)strtoul(argv[j++], NULL, 10);
 		if (items[i].maxvaluelen == 0)
 			items[i].maxvaluelen = items[i].fieldlen;
 
-		items[i].flags = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].flags = (unsigned int)strtoul(argv[j++], NULL, 10);
 		if (fieldlen <= 0)
 			items[i].flags |= BSDDIALOG_FIELDREADONLY;
 
@@ -765,7 +765,7 @@ int passwordform_builder(BUILDER_ARGS)
 
 	if (argc < 1)
 		exit_error(true, "--passwordform missing <formheight>");
-	formheight = (u_int)strtoul(argv[0], NULL, 10);
+	formheight = (unsigned int)strtoul(argv[0], NULL, 10);
 
 	argc--;
 	argv++;
@@ -780,11 +780,11 @@ int passwordform_builder(BUILDER_ARGS)
 	j = 0;
 	for (i = 0; i < nitems; i++) {
 		items[i].label	= argv[j++];
-		items[i].ylabel = (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xlabel = (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].ylabel = (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xlabel = (unsigned int)strtoul(argv[j++], NULL, 10);
 		items[i].init	= argv[j++];
-		items[i].yfield	= (u_int)strtoul(argv[j++], NULL, 10);
-		items[i].xfield	= (u_int)strtoul(argv[j++], NULL, 10);
+		items[i].yfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
+		items[i].xfield	= (unsigned int)strtoul(argv[j++], NULL, 10);
 
 		fieldlen = (int)strtol(argv[j++], NULL, 10);
 		items[i].fieldlen = abs(fieldlen);
