# $NetBSD: Makefile,v 1.2 2008/01/19 15:26:35 tnn2 Exp $

.include "../../wip/jdk16/Makefile.common"

JDK_VERSION=		1.6.0
JDK_UPDATE=		3
JDK_PATCHSET_VERSION=	3
JDK_VERSION_STRING=	b05-jrl-24_sep_2007

DISTNAME=		jdk-6u${JDK_UPDATE}
PKGNAME=	jdk16-${JDK_VERSION}.${JDK_UPDATE}.${JDK_PATCHSET_VERSION}
MASTER_SITES+=		# http://download.java.net/jdk6/6u3/
MASTER_SITES+=		# http://www.eyesbeyond.com/freebsddom/java/jdk16.html
DISTFILES=		${JRL_SRCFILE} ${JRL_BINFILE} ${PATCHSETFILE}

COMMENT=		Java Development Kit ${JDK_VERSION}

LICENSE=		sun-jrl-16-license

USE_TOOLS+=		patch
WRKSRC=			${WRKDIR}
PLIST_SRC=		PLIST.common

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386

JVM_HOME=		${LOCALBASE}/java/jdk-${JDK_VERSION}
JAVA_HOME=		${JVM_HOME}
JAVA_NAME=		jdk16
JAVA_UNLIMIT=		datasize
JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javap

# Let an installed version of this package bootstrap a later version
# (skips having to reinstall sun-jdk16 again)
#
#.if exists(${JVM_HOME}/LICENSE)
#BUILD_DEPENDS+=		jdk16>=1
#MAKE_ENV+=		ALT_BOOTDIR=${JVM_HOME}
#.else
BUILD_DEPENDS+=		sun-jdk15>=1:../../lang/sun-jdk15
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/sun-1.5
#.endif

#For bootstrapping with wip/jdk15
#MAKE_ENV+=		ALT_BOOTDIR=${PREFIX}/java/jdk-1.5.0

# used to find "zip" and "unzipsfx"
MAKE_FLAGS+=		M4=${M4:Q}
MAKE_FLAGS+=		ALT_DEVTOOLS_PATH=${LOCALBASE}/bin
MAKE_FLAGS+=		ALT_COMPILER_PATH=${WRAPPER_BINDIR:Q}
MAKE_ENV+=		LANG=C
MAKE_ENV+=		JAVA_HOME=
MAKE_ENV+=		CLASSPATH=
MAKE_ENV+=		ALT_MOTIF_DIR=${MOTIFBASE:Q}
MAKE_ENV+=		DEV_ONLY=YES
MAKE_ENV+=		SYS_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=		LD_LIBRARY_PATH=
MAKE_ENV+=		SKIP_COMPARE_IMAGES=YES

# MAKE_ENV+=		WRAPPER_DEBUG=yes

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		DONT_ENABLE_IPV6=YES
.endif


BUILDLINK_PASSTHRU_DIRS+=	${JVM_HOME}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/jre/lib/i386/server

JRL_SRCFILE=		${DISTNAME}-fcs-src-${JDK_VERSION_STRING}.jar
JRL_BINFILE=		${DISTNAME}-fcs-bin-${JDK_VERSION_STRING}.jar
PATCHSETFILE=		bsd-jdk16-patches-${JDK_PATCHSET_VERSION}.tar.bz2

JRL_DOWNLOAD=	http://download.java.net/jdk6/6u3/
PATCH_DOWNLOAD=	http://www.eyesbeyond.com/freebsddom/java/JDK16JRLConfirm.html

JDKIMAGEDIR=		${WRKDIR}/${BUILD_DIRS}/../build/bsd-i586/j2sdk-image
# JDKIMAGEDIR_G=	${WRKDIR}/${BUILD_DIRS}/../build/bsd-i586/j2sdk-debug-image

FETCH_MESSAGE+= " The source and patches for the Java (tm) 2 SDK require"
FETCH_MESSAGE+= " a Sun Java Research License, and cannot be"
FETCH_MESSAGE+= " fetched automatically."
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the JDK 6.0 JRL Source (${JRL_SRCFILE})"
FETCH_MESSAGE+= " and JRL Binaries (${JRL_BINFILE}) for J2SE from:"
FETCH_MESSAGE+= "       ${JRL_DOWNLOAD}"
FETCH_MESSAGE+= " and place them as:"
FETCH_MESSAGE+= "       ${DISTDIR}/${JRL_SRCFILE}"
FETCH_MESSAGE+= "       ${DISTDIR}/${JRL_BINFILE}"
.if !empty(PKG_OPTIONS:Mjdk16-jce)
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Additionally, for the Java Cryptography Extension"
FETCH_MESSAGE+= " please download jce_policy-6.zip from"
FETCH_MESSAGE+= "   http://java.sun.com/javase/downloads/index.jsp"
FETCH_MESSAGE+= " via the link named Java Cryptography Extension (JCE)"
FETCH_MESSAGE+= " Unlimited Strength Jurisdiction Policy Files 6"
FETCH_MESSAGE+= " and place it in ${DISTDIR}"
.endif
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the BSD JDK 1.6 Patchset ${JDK_PATCHSET_VERSION}"
FETCH_MESSAGE+= " (${PATCHSETFILE}) from:"
FETCH_MESSAGE+= "      ${PATCH_DOWNLOAD}"
FETCH_MESSAGE+= " and place it as:"
FETCH_MESSAGE+= "      ${DISTDIR}/${PATCHSETFILE}"
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Then resume this build by running '"${MAKE:Q}"' again."

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

INTERACTIVE_STAGE+=	extract

.include "../../wip/jdk16/license-extract.mk"

# Don't attempt to patch mozilla headers if we don't have them
.if empty(PKG_OPTIONS:Mjdk16-plugin)
PATCH_FILTER_CMD=	${AWK} '/^Index:/ {skip=0} /^Index:.*mozilla_headers_18.*/ {skip=1} /.*/ {if (!skip) print $$0}'
.else
PATCH_FILTER_CMD=	cat
.endif
pre-patch:
	cd ${WRKSRC} && ${PATCH_FILTER_CMD} < jdk16.patches | ${PATCH} -p0 -E -s
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
#	${INSTALL_DATA} ${FILESDIR}/cacerts \
#		${JAVA_HOME}/jre/lib/security/cacerts
#	 ${INSTALL_DATA} ${FILESDIR}/cacerts \
#		${JAVA_HOME}/jre/javaws/cacerts

MAKE_ENV+=	ALT_CUPS_HEADERS_PATH=${PREFIX}/include
BUILDLINK_DEPMETHOD.cups?=	build
.include "../../print/cups/buildlink3.mk"

.include "../../mk/java-env.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
