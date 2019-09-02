$NetBSD$

--- sim/common/cgen.sh.orig	2019-07-16 00:00:27.000000000 +0000
+++ sim/common/cgen.sh
@@ -29,6 +29,7 @@ shift ; extrafiles=$9
 shift ; opcfile=$9
 
 rootdir=${srcdir}/../..
+move_if_change="${CONFIG_SHELL:-/bin/sh} ${rootdir}/move-if-change"
 
 test -z "${opcfile}" && opcfile=/dev/null
 
@@ -70,11 +71,11 @@ arch)
 		-B ${tmp}-arch.c1 \
 		-N ${tmp}-all.h1
 	sed $sedscript < ${tmp}-arch.h1 > ${tmp}-arch.h
-	${rootdir}/move-if-change ${tmp}-arch.h ${srcdir}/arch.h
+	${move_if_change} ${tmp}-arch.h ${srcdir}/arch.h
 	sed $sedscript < ${tmp}-arch.c1 > ${tmp}-arch.c
-	${rootdir}/move-if-change ${tmp}-arch.c ${srcdir}/arch.c
+	${move_if_change} ${tmp}-arch.c ${srcdir}/arch.c
 	sed $sedscript < ${tmp}-all.h1 > ${tmp}-all.h
-	${rootdir}/move-if-change ${tmp}-all.h ${srcdir}/cpuall.h
+	${move_if_change} ${tmp}-all.h ${srcdir}/cpuall.h
 
 	rm -f ${tmp}-arch.h1 ${tmp}-arch.c1 ${tmp}-all.h1
 	;;
@@ -136,11 +137,11 @@ cpu | decode | cpu-decode)
 	case $action in
 	*cpu*)
 		sed $sedscript < ${tmp}-cpu.h1 > ${tmp}-cpu.h
-		${rootdir}/move-if-change ${tmp}-cpu.h ${srcdir}/cpu${suffix}.h
+		${move_if_change} ${tmp}-cpu.h ${srcdir}/cpu${suffix}.h
 		sed $sedscript < ${tmp}-cpu.c1 > ${tmp}-cpu.c
-		${rootdir}/move-if-change ${tmp}-cpu.c ${srcdir}/cpu${suffix}.c
+		${move_if_change} ${tmp}-cpu.c ${srcdir}/cpu${suffix}.c
 		sed $sedscript < ${tmp}-mod.c1 > ${tmp}-mod.c
-		${rootdir}/move-if-change ${tmp}-mod.c ${srcdir}/model${suffix}.c
+		${move_if_change} ${tmp}-mod.c ${srcdir}/model${suffix}.c
 		rm -f ${tmp}-cpu.h1 ${tmp}-cpu.c1 ${tmp}-mod.c1
 		;;
 	esac
@@ -148,36 +149,36 @@ cpu | decode | cpu-decode)
 	case $action in
 	*decode*)
 		sed $sedscript < ${tmp}-dec.h1 > ${tmp}-dec.h
-		${rootdir}/move-if-change ${tmp}-dec.h ${srcdir}/decode${suffix}.h
+		${move_if_change} ${tmp}-dec.h ${srcdir}/decode${suffix}.h
 		sed $sedscript < ${tmp}-dec.c1 > ${tmp}-dec.c
-		${rootdir}/move-if-change ${tmp}-dec.c ${srcdir}/decode${suffix}.c
+		${move_if_change} ${tmp}-dec.c ${srcdir}/decode${suffix}.c
 		rm -f ${tmp}-dec.h1 ${tmp}-dec.c1
 		;;
 	esac
 
 	if test -f ${tmp}-ext.c1 ; then \
 		sed $sedscript < ${tmp}-ext.c1 > ${tmp}-ext.c ; \
-		${rootdir}/move-if-change ${tmp}-ext.c ${srcdir}/extract${suffix}.c ; \
+		${move_if_change} ${tmp}-ext.c ${srcdir}/extract${suffix}.c ; \
 		rm -f ${tmp}-ext.c1
 	fi
 	if test -f ${tmp}-read.c1 ; then \
 		sed $sedscript < ${tmp}-read.c1 > ${tmp}-read.c ; \
-		${rootdir}/move-if-change ${tmp}-read.c ${srcdir}/read${suffix}.c ; \
+		${move_if_change} ${tmp}-read.c ${srcdir}/read${suffix}.c ; \
 		rm -f ${tmp}-read.c1
 	fi
 	if test -f ${tmp}-write.c1 ; then \
 		sed $sedscript < ${tmp}-write.c1 > ${tmp}-write.c ; \
-		${rootdir}/move-if-change ${tmp}-write.c ${srcdir}/write${suffix}.c ; \
+		${move_if_change} ${tmp}-write.c ${srcdir}/write${suffix}.c ; \
 		rm -f ${tmp}-write.c1
 	fi
 	if test -f ${tmp}-sem.c1 ; then \
 		sed $sedscript < ${tmp}-sem.c1 > ${tmp}-sem.c ; \
-		${rootdir}/move-if-change ${tmp}-sem.c ${srcdir}/sem${suffix}.c ; \
+		${move_if_change} ${tmp}-sem.c ${srcdir}/sem${suffix}.c ; \
 		rm -f ${tmp}-sem.c1
 	fi
 	if test -f ${tmp}-semsw.c1 ; then \
 		sed $sedscript < ${tmp}-semsw.c1 > ${tmp}-semsw.c ; \
-		${rootdir}/move-if-change ${tmp}-semsw.c ${srcdir}/sem${suffix}-switch.c ; \
+		${move_if_change} ${tmp}-semsw.c ${srcdir}/sem${suffix}-switch.c ; \
 		rm -f ${tmp}-semsw.c1
 	fi
 
@@ -195,7 +196,7 @@ defs)
 		-i ${isa} \
 		-G ${tmp}-defs.h1
 	sed $sedscript < ${tmp}-defs.h1 > ${tmp}-defs.h
-	${rootdir}/move-if-change ${tmp}-defs.h ${srcdir}/defs${suffix}.h
+	${move_if_change} ${tmp}-defs.h ${srcdir}/defs${suffix}.h
 	rm -f ${tmp}-defs.h1
 	;;
 
@@ -216,11 +217,11 @@ desc)
 		-C ${tmp}-desc.c1 \
 		-O ${tmp}-opc.h1
 	sed $sedscript < ${tmp}-desc.h1 > ${tmp}-desc.h
-	${rootdir}/move-if-change ${tmp}-desc.h ${srcdir}/${arch}-desc.h
+	${move_if_change} ${tmp}-desc.h ${srcdir}/${arch}-desc.h
 	sed $sedscript < ${tmp}-desc.c1 > ${tmp}-desc.c
-	${rootdir}/move-if-change ${tmp}-desc.c ${srcdir}/${arch}-desc.c
+	${move_if_change} ${tmp}-desc.c ${srcdir}/${arch}-desc.c
 	sed $sedscript < ${tmp}-opc.h1 > ${tmp}-opc.h
-	${rootdir}/move-if-change ${tmp}-opc.h ${srcdir}/${arch}-opc.h
+	${move_if_change} ${tmp}-opc.h ${srcdir}/${arch}-opc.h
 
 	rm -f ${tmp}-desc.h1 ${tmp}-desc.c1 ${tmp}-opc.h1
 	;;
