# $NetBSD: Makefile,v 1.16 2004/07/01 13:18:28 thomasklausner Exp $
#
# Some notes for those working on this package:
#
# * PKGNAME: 2.0.11 means "1.2.2-FCS, patchset 11" (FCS = Sun patch 0).
#
# * The JDBC-ODBC bridge is not supported, because of the fact that
#   the pkgsrc build of unixodbc needs userland pthreads (which
#   messes with green_threads).

DISTNAME=	jdk1_2_2-src
PKGNAME=	jdk12-2.0.11
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SUNSITE:=devel/lang/java/blackdown.org/JDK-1.2.2/i386/FCS/}
EXTRACT_SUFX=	.tar.gz # must be explicitly specified for the ".if exists" below
DISTFILES=	${SCSL_DF} ${PATCH_DF} ${BOOTSTRAP_DF}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.eyesbeyond.com/freebsddom/java/
COMMENT=	Sun's Java(tm) 2 SDK (SCSL+FreeBSDdom 1.2 release)

LICENSE=	scsl-2.3-license

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

RESTRICTED=	"Redistribution of source or binaries permitted only by SCSL license terms"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	YES

JVM_HOME=	${PREFIX}/java/jdk-1.2.2
ONLY_FOR_PLATFORM=	NetBSD-1.[4-9]*-i386 NetBSD-[2-9]*-i386

ALL_TARGET=	world release-images
BUILD_DIRS=	${WRKSRC}/build/bsd
CHECK_SHLIBS=	NO # scripts set LD_LIBRARY_PATH
MAKEFILE=	GNUmakefile
OWN_DIRS=	${JVM_HOME} ${JVM_HOME}/jre ${JVM_HOME}/jre/lib \
		${JVM_HOME}/jre/lib/images ${JVM_HOME}/jre/lib/images/cursors \
		${JVM_HOME}/jre/lib/security
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if defined(JDK_WITH_BUNDLES) && !empty(JDK_WITH_BUNDLES:M[Yy][Ee][Ss])
ALL_TARGET+=	release-bundles
.endif

MOTIF_TYPE=	openmotif

MAKE_FLAGS+=	LOCALDIR=${LOCALBASE} # used to find "zip" and "unzipsfx"
MAKE_FLAGS+=	M4=${M4}
MAKE_ENV+=	ALT_BOOTDIR=${WRKSRC}/jdk1.2.2
MAKE_ENV+=	ALT_MOTIF_DIR=${MOTIFBASE}
MAKE_ENV+=	HAVE_ODBC=no
MAKE_ENV+=	LD_RUN_PATH=${MOTIFBASE}/lib:${X11BASE}/lib # substitute for -rpath option
MAKE_ENV+=	OPENWINHOME=${MOTIFBASE}
MAKE_ENV+=	USE_GNU_M4=1

SFILES=		content-types.properties
SFILES+=	flavormap.properties
SFILES+=	font.properties
SFILES+=	font.properties.ja
SFILES+=	images/cursors/cursors.properties
SFILES+=	security/java.security

SUPPORT_FILES=	# empty
.for f in ${SFILES}
SUPPORT_FILES+=	${JVM_HOME}/jre/lib/$f.default ${JVM_HOME}/jre/lib/$f
.endfor

BOOTSTRAP_DF=	j2sdk-1.2.2-FCS-linux-i386-glibc-2.1.3.tar.bz2

PATCH_DF=	bsd-jdk122-patches-11.tar.gz
PATCH_DOWNLOAD=	http://www.eyesbeyond.com/freebsddom/java/JDKSCSLConfirm.html

SCSL_DF=	${DISTNAME}${EXTRACT_SUFX}
SCSL_DOWNLOAD=	http://wwws.sun.com/software/java2/download.html

.if !exists(${DISTDIR}/${SCSL_DF}) || !exists(${DISTDIR}/${PATCH_DF})
INTERACTIVE_STAGE=	fetch
_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${SCSL_DF} containing the"; \
	${ECHO} " Java(tm) 2 SDK, Standard Edition must be fetched"; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${SCSL_DF}"; \
	${ECHO} " from (choose the second Download link for Java[tm] 2 SDK 1.2.2):"; \
	${ECHO} "	${SCSL_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " This requires a Sun Community Source Licensing account."; \
	${ECHO} ; \
	${ECHO} " Also, the file ${PATCH_DF} must be fetched into:"; \
	${ECHO} "	${DISTDIR}/${PATCH_DF}"; \
	${ECHO} " from (choose Patchset 11):"; \
	${ECHO} "	${PATCH_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} "======================================================================"
.endif

pre-patch:
	@for dir in build src ext/i18n/build ext/i18n/src ext/iiimp/build; do \
		(cd ${WRKSRC}/$$dir && ${LN} -s solaris bsd); \
	done
	cd ${WRKSRC}/build/bsd && ${PATCH} -s -p1 <${WRKSRC}/build.patches
	cd ${WRKSRC}/build/share && ${PATCH} -s -p1 <${WRKSRC}/buildshare.patches
	cd ${WRKSRC}/src/bsd && ${PATCH} -s -p1 <${WRKSRC}/src.patches
	cd ${WRKSRC}/src/share && ${PATCH} -s -p1 <${WRKSRC}/srcshare.patches
	cd ${WRKSRC}/ext && ${PATCH} -s -p1 <${WRKSRC}/ext.patches
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM} -f

post-build:
	@for f in `find ${BUILD_DIRS}/jdk-image-${MACHINE_ARCH} -name '*.so'`; do \
		if [ -f $$f.1.2.2 ]; then \
			${LN} -sf `basename $$f.1.2.2` $$f; \
		else true; fi; \
	done
.for f in ${SFILES}
	cd ${BUILD_DIRS}/jdk-image-${MACHINE_ARCH}/jre/lib && ${MV} -f $f $f.default
.endfor

do-install:
	${INSTALL_PROGRAM_DIR} ${JVM_HOME}
	cd ${BUILD_DIRS}/jdk-image-${MACHINE_ARCH} && ${PAX} -rw . ${JVM_HOME}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
