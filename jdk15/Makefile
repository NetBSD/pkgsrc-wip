# $NetBSD: Makefile,v 1.14 2007/05/02 09:29:38 absd Exp $

JDK_VERSION=		1.5.0
JDK_PATCHSET_VERSION=	4

DISTNAME=		jdk-1_5_0-src-scsl
PKGNAME=		jdk15-${JDK_VERSION}.${JDK_PATCHSET_VERSION}
CATEGORIES=		lang java
MASTER_SITES=		# http://www.sun.com/software/java2/download.html
# 			  http://www.eyesbeyond.com/freebsddom/java/jdk15.html
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

USE_TOOLS+=		gmake m4 patch
USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}
PLIST_SRC=		PLIST.common

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
MAKE_ENV+=		SKIP_COMPARE_IMAGES=YES

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		DONT_ENABLE_IPV6=YES
.endif


BUILDLINK_PASSTHRU_DIRS+=	${JVM_HOME}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/jre/lib/i386/server

SCSL_SRCFILE=		jdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=		jdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=		bsd-jdk15-patches-${JDK_PATCHSET_VERSION}.tar.bz2

SCSL_DOWNLOAD=		http://wwws.sun.com/software/java2/download.html
PATCH_DOWNLOAD=		http://www.eyesbeyond.com/freebsddom/java/JDK15SCSLConfirm.html

JDKIMAGEDIR=		${BUILD_DIRS}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=		${BUILD_DIRS}/../build/bsd-i586/j2sdk-debug-image

INTERACTIVE_STAGE=	fetch
FETCH_MESSAGE+= " The source and patches for the Java (tm) 2 SDK require"
FETCH_MESSAGE+= " a Sun Community Source Licensing account, and cannot be"
FETCH_MESSAGE+= " fetched automatically."
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the JDK 5.0 SCSL Source (${SCSL_SRCFILE})"
FETCH_MESSAGE+= " and SCSL Binaries (${SCSL_BINFILE}) for J2SE from:"
FETCH_MESSAGE+= "       ${SCSL_DOWNLOAD}"
FETCH_MESSAGE+= " and place them as:"
FETCH_MESSAGE+= "       ${DISTDIR}/${SCSL_SRCFILE}"
FETCH_MESSAGE+= "       ${DISTDIR}/${SCSL_BINFILE}"
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the BSD JDK 1.5 Patchset ${JDK_PATCHSET_VERSION}"
FETCH_MESSAGE+= " (${PATCHSETFILE}) from:"
FETCH_MESSAGE+= "      ${PATCH_DOWNLOAD}"
FETCH_MESSAGE+= " and place it as:"
FETCH_MESSAGE+= "      ${DISTDIR}/${PATCHSETFILE}"
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Then resume this build by running '${MAKE}' again."

MESSAGE_SUBST+=		LOCALBASE=${LOCALBASE}
MESSAGE_SUBST+=		JAVA_HOME=${JAVA_HOME}
MESSAGE_SUBST+=		MOZILLA=${MOZILLA}

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

INSTALL_TEMPLATES+=     ${PKGDIR}/INSTALL.tmpl
DEINSTALL_TEMPLATES+=   ${PKGDIR}/DEINSTALL.tmpl

PLIST_SRC+=		PLIST.common_end

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p0 -E -s <jdk15.patches
	${FIND} ${WRKSRC}/ -name '*.orig' -print | ${XARGS} ${RM} -f

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

.include "../../mk/java-env.mk"
.include "../../www/seamonkey/gecko-depends.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
