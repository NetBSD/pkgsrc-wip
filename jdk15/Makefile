# $NetBSD: Makefile,v 1.29 2009/02/24 15:19:22 absd Exp $

.include "../../wip/jdk16/Makefile.common"

JDK_VERSION=		1.5.0
JDK_UPDATE=		13
# If updating, please check if patch-ar is still needed. (introduced in patch8)
JDK_PATCHSET_VERSION=	8
JDK_VERSION_STRING=	b05-jrl-25_sep_2007

DISTNAME=		jdk-${JDK_VERSION:S/./_/g}_${JDK_UPDATE}
PKGNAME=	jdk15-${JDK_VERSION}.${JDK_UPDATE}.${JDK_PATCHSET_VERSION}
MASTER_SITES+=		# http://download.java.net/tiger/archive/tiger_u${JDK_UPDATE}/
MASTER_SITES+=		# http://www.eyesbeyond.com/freebsddom/java/jdk15.html
DISTFILES=		${JRL_SRCFILE} ${JRL_BINFILE} ${PATCHSETFILE}

COMMENT=		Java Development Kit ${JDK_VERSION}

LICENSE=		sun-jrl-16-license

MAKE_JOBS_SAFE=		no
USE_TOOLS+=		patch pax
WRKSRC=			${WRKDIR}
PLIST_SRC=		PLIST.common

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386

JAVA_NAME=		jdk15
JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javap

.if exists(${LOCALBASE}/java/jdk-1.6.0/bin/javac) && defined(NOT_YET)
BUILD_DEPENDS+=		jdk16>=1
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/jdk-1.6.0
.elif exists(${LOCALBASE}/java/jdk-1.5.0/bin/javac)
#don't depend on my myself
#BUILD_DEPENDS+=	jdk15>=1
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/jdk-1.5.0
.elif exists(${LOCALBASE}/java/sun-6/bin/javac) && defined(NOT_YET)
BUILD_DEPENDS+=		sun-jdk6>=1:../../lang/sun-jdk6
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/sun-6
.else
BUILD_DEPENDS+=		sun-jdk15>=1:../../lang/sun-jdk15
MAKE_ENV+=		ALT_BOOTDIR=${LOCALBASE}/java/sun-1.5
.endif

.if !empty(MAKE_ENV:M*/java/sun-*) && !exists(/emul/linux/proc/uptime)
PKG_FAIL_REASON=	"If bootstrapping with Linux JDK,"
PKG_FAIL_REASON+=	"then /emul/linux/proc must be mounted. Run:"
PKG_FAIL_REASON+=	"mount -o linux -t procfs /dev/null /emul/linux/proc"
.endif

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

JRL_SRCFILE=		${DISTNAME}-fcs-src-${JDK_VERSION_STRING}.jar
JRL_BINFILE=		${DISTNAME}-fcs-bin-${JDK_VERSION_STRING}.jar
PATCHSETFILE=		bsd-jdk15-patches-${JDK_PATCHSET_VERSION}.tar.bz2

JRL_DOWNLOAD=	http://download.java.net/tiger/archive/tiger_u${JDK_UPDATE}/
PATCH_DOWNLOAD=	http://www.eyesbeyond.com/freebsddom/java/JDK15JRLConfirm.html

JDKIMAGEDIR=		${WRKDIR}/${BUILD_DIRS}/../build/bsd-i586/j2sdk-image
# JDKIMAGEDIR_G=	${WRKDIR}/${BUILD_DIRS}/../build/bsd-i586/j2sdk-debug-image

FETCH_MESSAGE+= " The source and patches for the Java (tm) 2 SDK require"
FETCH_MESSAGE+= " a Sun Java Research License, and cannot be"
FETCH_MESSAGE+= " fetched automatically."
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the JDK 5.0 JRL Source (${JRL_SRCFILE})"
FETCH_MESSAGE+= " and JRL Binaries (${JRL_BINFILE}) for J2SE from:"
FETCH_MESSAGE+= "       ${JRL_DOWNLOAD}"
FETCH_MESSAGE+= " and place them as:"
FETCH_MESSAGE+= "       ${DISTDIR}/${JRL_SRCFILE}"
FETCH_MESSAGE+= "       ${DISTDIR}/${JRL_BINFILE}"
.if !empty(PKG_OPTIONS:Mjdk15-jce)
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Additionally, for the Java Cryptography Extension"
FETCH_MESSAGE+= " please download jce_policy-1_5_0.zip from"
FETCH_MESSAGE+= "   http://java.sun.com/javase/downloads/index_jdk5.jsp"
FETCH_MESSAGE+= " via the link named Java Cryptography Extension (JCE)"
FETCH_MESSAGE+= " Unlimited Strength Jurisdiction Policy Files 5.0"
FETCH_MESSAGE+= " and place it in ${DISTDIR}"
.endif
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Please download the BSD JDK 1.5 Patchset ${JDK_PATCHSET_VERSION}"
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

.include "options.mk"

INSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.tmpl
DEINSTALL_TEMPLATES+=	${PKGDIR}/DEINSTALL.tmpl

PLIST_SRC+=		PLIST.common_end

.include "../../wip/jdk16/license-extract.mk"

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p0 -E -s <jdk15.patches
	${FIND} ${WRKSRC}/ -name '*.orig' -print | ${XARGS} ${RM} -f

post-patch:
	${MKDIR} ${WRKSRC}/control/build/bsd-i586/lib/i386/server

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${JDKIMAGEDIR} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}
	${INSTALL_DATA_DIR} ${DESTDIR}${JAVA_HOME}/jre/.systemPrefs
	${TOUCH} ${DESTDIR}${JAVA_HOME}/jre/.systemPrefs/.system.lock
	${CHMOD} 644 ${DESTDIR}${JAVA_HOME}/jre/.systemPrefs/.system.lock
	${TOUCH} ${DESTDIR}${JAVA_HOME}/jre/.systemPrefs/.systemRootModFile
	${CHMOD} 644 ${DESTDIR}${JAVA_HOME}/jre/.systemPrefs/.systemRootModFile
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${DESTDIR}${JAVA_HOME}/jre/lib/security/cacerts
#	 ${INSTALL_DATA} ${FILESDIR}/cacerts \
#		${DESTDIR}${JAVA_HOME}/jre/javaws/cacerts

.include "../../mk/java-env.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
