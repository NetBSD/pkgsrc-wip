# $NetBSD: Makefile,v 1.1.1.1 2004/04/28 01:00:17 marc Exp $

DISTNAME=	j2sdk-1_4_2-src-scsl
PKGNAME=	jdk14-${JDK_VERSION}.${JDK_PATCHSET_VERSION}
CATEGORIES=	lang java
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		http://www.eyesbeyond.com/freebsddom/java/jdk14.html
EXTRACT_SUFX=	.zip
DISTFILES=	${SCSL_SRCFILE} ${SCSL_BINFILE} ${PATCHSETFILE}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.eyesbeyond.com/freebsddom/java/
COMMENT=	Java Development Kit 1.4.2

LICENSE=	scsl-2.3-license

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

RESTRICTED=	"Redistribution of source or binaries permitted only by license terms"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make m4
USE_LANGUAGES=		c c++
UNLIMIT_RESOURCES+=	datasize
EXTRACT_CMD_OPTS.zip=	-q
WRKSRC=			${WRKDIR}

JVM_HOME=		${LOCALBASE}/java/jdk-1.4.2
ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386

ALL_TARGET=	all # added to below
BUILD_DIRS=	${WRKSRC}/control/make
CHECK_SHLIBS=	no # scripts set LD_LIBRARY_PATH
NO_MTREE=	yes # since we change PREFIX below

.include "../../mk/bsd.prefs.mk"

# Let an installed version of this package bootstrap a later version
# (skips having to reinstall sun-jdk14 again)
#
#.if exists(${JVM_HOME}/LICENSE)
#BUILD_DEPENDS+=	jdk14>=1
#MAKE_ENV+=	ALT_BOOTDIR=${JVM_HOME}
#.else
#BUILD_DEPENDS+=	sun-jdk14>=1:../../lang/sun-jdk14
#MAKE_ENV+=	ALT_BOOTDIR=${LOCALBASE}/java/sun-1.4
#.endif
BUILD_DEPENDS+=	sun-jdk14>=1:../../lang/sun-jdk14
MAKE_ENV+=	ALT_BOOTDIR=${LOCALBASE}/java/sun-1.4

MOTIF_TYPE=	openmotif

# used to find "zip" and "unzipsfx"
MAKE_FLAGS+=	M4=${M4}
MAKE_FLAGS+=	ALT_DEVTOOLS_PATH=${LOCALBASE}/bin
MAKE_FLAGS+=	ALT_COMPILER_PATH=${BUILDLINK_DIR}/bin
MAKE_ENV+=	LANG=C
MAKE_ENV+=	JAVA_HOME=
MAKE_ENV+=	CLASSPATH=
MAKE_ENV+=	ALT_MOTIF_DIR=${MOTIFBASE}
MAKE_ENV+=	DEV_ONLY=YES
MAKE_ENV+=	SYS_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	LD_LIBRARY_PATH=
MAKE_ENV+=	NO_PLUGIN=YES

BUILDLINK_PASSTHRU_DIRS+= ${JVM_HOME}

JDK_VERSION=    1.4.2
JDK_PATCHSET_VERSION=   6
SUN_LINUX_JDK_VERSION=  1.4.2

SCSL_SRCFILE=	j2sdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=	j2sdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=	bsd-jdk14-patches-${JDK_PATCHSET_VERSION}.tar.gz

SCSL_DOWNLOAD=	http://wwws.sun.com/software/java2/download.html
PATCH_DOWNLOAD=	http://www.eyesbeyond.com/freebsddom/java/JDK14SCSLConfirm.html

JDKIMAGEDIR=	${BUILD_DIRS}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=	${BUILD_DIRS}/../build/bsd-i586/j2sdk-debug-image

.if !exists(${DISTDIR}/${SCSL_SRCFILE}) ||	\
	 !exists(${DISTDIR}/${SCSL_BINFILE}) ||	\
	 !exists(${DISTDIR}/${PATCHSETFILE})
INTERACTIVE_STAGE=	fetch
_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The files ${SCSL_SRCFILE} and ${SCSL_BINFILE}"; \
	${ECHO} " containing the Java(tm) 2 SDK, Standard Edition must be fetched"; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${SCSL_SRCFILE}"; \
	${ECHO} " and:"; \
	${ECHO} "	${DISTDIR}/${SCSL_BINFILE}"; \
	${ECHO} " from (choose the Download link for Java[tm] 2 SDK 1.4.2):"; \
	${ECHO} "	${SCSL_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " This requires a Sun Community Source Licensing account."; \
	${ECHO} ; \
	${ECHO} " Also, the file ${PATCHSETFILE} must be fetched into:"; \
	${ECHO} "	${DISTDIR}/${PATCHSETFILE}"; \
	${ECHO} " from:"; \
	${ECHO} "	${PATCH_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} "======================================================================"
.endif

SUBST_CLASSES+=		lbase jvm-home

SUBST_STAGE.lbase=	pre-configure
SUBST_FILES.lbase=	hotspot/src/os/bsd/vm/os_bsd.cpp
SUBST_SED.lbase=	-e 's,%%LOCALBASE%%,${LOCALBASE},g'

SUBST_STAGE.jvm-home=	pre-configure
SUBST_FILES.jvm-home=	j2se/make/common/Defs-bsd.gmk
SUBST_SED.jvm-home=	-e 's,%%JVM_HOME%%,${JVM_HOME},g'

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p0 -E -s <jdk14.patches
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	${MKDIR} ${WRKSRC}/control/build/bsd-i586/lib/i386/server

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	cd ${JDKIMAGEDIR} && ${PAX} -rwppm . ${PREFIX}
	${INSTALL_DATA_DIR} ${JVM_HOME}/jre/.systemPrefs
	${TOUCH} ${JVM_HOME}/jre/.systemPrefs/.system.lock
	${CHMOD} 644 ${JVM_HOME}/jre/.systemPrefs/.system.lock
	${TOUCH} ${JVM_HOME}/jre/.systemPrefs/.systemRootModFile
	${CHMOD} 644 ${JVM_HOME}/jre/.systemPrefs/.systemRootModFile

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk
PREFIX=		${JVM_HOME}
