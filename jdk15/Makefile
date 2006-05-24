# $NetBSD: Makefile,v 1.7 2006/05/24 16:33:15 ghen Exp $

JDK_VERSION=    	1.5.0
JDK_PATCHSET_VERSION=   2
SUN_LINUX_JDK_VERSION=  1.5.0

DISTNAME=		jdk-1_5_0-src-scsl
PKGNAME=		jdk15-${JDK_VERSION}.${JDK_PATCHSET_VERSION}
CATEGORIES=		lang java
MASTER_SITES=		# http://www.sun.com/software/java2/download.html
#			http://www.eyesbeyond.com/freebsddom/java/jdk15.html
EXTRACT_SUFX=		.zip
DISTFILES=		${SCSL_SRCFILE} ${SCSL_BINFILE} ${PATCHSETFILE}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.eyesbeyond.com/freebsddom/java/
COMMENT=		Java Development Kit ${JDK_VERSION}

BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip

RESTRICTED=		Redistribution of source or binaries permitted only by license terms
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
LICENSE=		scsl23-license

USE_TOOLS+=		gmake m4
USE_LANGUAGES=		c c++
EXTRACT_CMD_OPTS.zip=	-q
WRKSRC=			${WRKDIR}
PLIST_SRC=      	PLIST.common

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386

BUILD_TARGET=		all # added to below
BUILD_DIRS=		${WRKSRC}/control/make
CHECK_SHLIBS=		no # scripts set LD_LIBRARY_PATH

.include "../../mk/bsd.prefs.mk"

JVM_HOME=		${LOCALBASE}/java/jdk-${JDK_VERSION}
JAVA_HOME=		${JVM_HOME}
JAVA_NAME=		jdk15
JAVA_UNLIMIT=		datasize
JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javap

# Let an installed version of this package bootstrap a later version
# (skips having to reinstall sun-jdk15 again)
#
#.if exists(${JVM_HOME}/LICENSE)
#BUILD_DEPENDS+=		jdk15>=1
#MAKE_ENV+=		ALT_BOOTDIR=${JVM_HOME}
#.else
BUILD_DEPENDS+=		sun-jdk15>=1:../../lang/sun-jdk15
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/sun-1.5
#.endif

MOTIF_TYPE=		openmotif

UNLIMIT_RESOURCES=	datasize

# used to find "zip" and "unzipsfx"
MAKE_FLAGS+=		M4=${M4:Q}
MAKE_FLAGS+=		ALT_DEVTOOLS_PATH=${LOCALBASE}/bin
MAKE_FLAGS+=		ALT_COMPILER_PATH=${WRAPPER_BINDIR:Q}
MAKE_ENV+=		LANG=C
MAKE_ENV+=		JAVA_HOME=
MAKE_ENV+=		CLASSPATH=
MAKE_ENV+=		ALT_MOTIF_DIR=${MOTIFBASE:Q}
MAKE_ENV+=		DEV_ONLY=YES
MAKE_ENV+=		SYS_CFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=		LD_LIBRARY_PATH=
MAKE_ENV+=		ALT_MOZILLA_PATH=${LOCALBASE:Q}

BUILDLINK_PASSTHRU_DIRS+= 	${JVM_HOME}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/jre/lib/i386/server

SCSL_SRCFILE=		jdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=		jdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=		bsd-jdk15-patches-${JDK_PATCHSET_VERSION}.tar.bz2

SCSL_DOWNLOAD=		http://wwws.sun.com/software/java2/download.html
PATCH_DOWNLOAD=		http://www.eyesbeyond.com/freebsddom/java/JDK15SCSLConfirm.html

JDKIMAGEDIR=		${BUILD_DIRS}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=		${BUILD_DIRS}/../build/bsd-i586/j2sdk-debug-image

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
	${ECHO} " from (choose the Download link for JDK 5.0):"; \
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

MESSAGE_SUBST+=		LOCALBASE=${LOCALBASE}
MESSAGE_SUBST+=		JAVA_HOME=${JAVA_HOME}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure

SUBST_FILES.paths=	control/make/common/Defs-bsd.gmk
SUBST_FILES.paths+=	deploy/make/common/Defs-bsd.gmk
SUBST_FILES.paths+=	deploy/make/plugin/common/config.gmk
SUBST_FILES.paths+=	deploy/make/plugin/unsupported/ns6-adapter/Makefile
SUBST_FILES.paths+=	hotspot/src/os/bsd/vm/os_bsd.cpp
SUBST_FILES.paths+=	j2se/make/common/Defs-bsd.gmk
SUBST_FILES.paths+=	motif/lib/Xm/Makefile
SUBST_FILES.paths+=	motif/lib/Xm/util/Makefile
SUBST_FILES.paths+=	j2se/src/solaris/native/sun/awt/fontpath.c
SUBST_FILES.paths+=	j2se/make/sun/xawt/Makefile
SUBST_FILES.paths+=	j2se/make/sun/awt/mawt.gmk

SUBST_SED.paths=	-e 's,%%LOCALBASE%%,${LOCALBASE},g'
SUBST_SED.paths+=	-e 's,%%X11BASE%%,${X11BASE},g'
SUBST_SED.paths+=	-e 's,%%JVM_HOME%%,${JVM_HOME},g'

BUILDLINK_PASSTHRU_DIRS+=	${JAVA_HOME}

.include "options.mk"

PLIST_SRC+=		PLIST.common_end

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p0 -E -s <jdk15.patches
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	${MKDIR} ${WRKSRC}/control/build/bsd-i586/lib/i386/server

do-install:
	${INSTALL_PROGRAM_DIR} ${JAVA_HOME}
	cd ${JDKIMAGEDIR} && ${PAX} -rwp ma . ${JAVA_HOME}
	${INSTALL_DATA_DIR} ${JAVA_HOME}/jre/.systemPrefs
	${TOUCH} ${JAVA_HOME}/jre/.systemPrefs/.system.lock
	${CHMOD} 644 ${JAVA_HOME}/jre/.systemPrefs/.system.lock
	${TOUCH} ${JAVA_HOME}/jre/.systemPrefs/.systemRootModFile
	${CHMOD} 644 ${JAVA_HOME}/jre/.systemPrefs/.systemRootModFile
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${JAVA_HOME}/jre/lib/security/cacerts
#	 ${INSTALL_DATA} ${FILESDIR}/cacerts \
#		${JAVA_HOME}/jre/javaws/cacerts

BROKEN=		This doesn't build yet. No bug-reports please.

.include "../../mk/java-env.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
