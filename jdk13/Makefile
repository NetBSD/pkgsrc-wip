# $NetBSD: Makefile,v 1.21 2004/04/19 20:53:02 tvierling Exp $
#
# Some notes for those working on this package:
#
# * PKGNAME: 1.0.8 means "1.3.1-FCS, patchset 8" (FCS = Sun patch 0).
#
# * The HotSpot JVM is not yet built, and likely won't work until
#   NetBSD pre-2.0-current pthreads changes settle.  (This requires
#   implementing some lower level threads glue, as well.)

DISTNAME=	j2sdk-1_3_1-src
PKGNAME=	jdk13-1.0.8.20031122
WRKSRC=		${WRKDIR}
CATEGORIES=	lang
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tar.gz # must be explicitly specified for the ".if exists" below
DISTFILES=	${SCSL_DF} ${PATCH_DF}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.eyesbeyond.com/freebsddom/java/
COMMENT=	Sun's Java(tm) 2 SDK (SCSL+FreeBSDdom 1.3 release)

LICENSE=	scsl-2.3-license

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

RESTRICTED=	"Redistribution of source or binaries permitted only by license terms"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

EXTRACT_USING_PAX= YES # GNU tar barfs on really deep paths
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	YES

JVM_HOME=	${LOCALBASE}/java/jdk-1.3.1
ONLY_FOR_PLATFORM=	NetBSD-1.[4-9]*-i386 NetBSD-[2-9]*-i386

ALL_TARGET=	all # added to below
BUILD_DIRS=	${WRKSRC}/j2sdk1.3.1/make
CHECK_SHLIBS=	NO # scripts set LD_LIBRARY_PATH
MESSAGE_SRC=	${WRKDIR}/LegalReadme.txt
NO_MTREE=	YES # since we change PREFIX below
OWN_DIRS=	${PREFIX} ${PREFIX}/jre ${PREFIX}/jre/lib \
		${PREFIX}/jre/lib/images ${PREFIX}/jre/lib/images/cursors \
		${PREFIX}/jre/lib/security \
		${PREFIX}/jre/lib/applet ${PREFIX}/jre/lib/ext \
		${PREFIX}/jre/plugin
PLIST_SRC=	# added to below

.include "../../mk/bsd.prefs.mk"

# Let an installed version of this package bootstrap a later version
# (skips having to reinstall sun-jdk13 again)
#
.if exists(${JVM_HOME}/LICENSE)
BUILD_DEPENDS+=	jdk13>=1
MAKE_ENV+=	ALT_BOOTDIR=${JVM_HOME}
.else
BUILD_DEPENDS+=	sun-jdk13>=1:../../lang/sun-jdk13
MAKE_ENV+=	ALT_BOOTDIR=${LOCALBASE}/java/sun-1.3.1
.endif

# Build Mozilla plugin if JDK_WITH_PLUGIN=YES
#
.if defined(JDK_WITH_PLUGIN) && !empty(JDK_WITH_PLUGIN:M[Yy][Ee][Ss])
MOZILLA_PLUGINS_DIR= ${LOCALBASE}/lib/mozilla/plugins

ALL_TARGET+=	plugin
PLIST_SRC+=	${.CURDIR}/PLIST.plugin
PLIST_SUBST+=	MOZILLA_PLUGINS_DIR=${MOZILLA_PLUGINS_DIR}

MAKE_ENV+=	LIBG_HDRS="${LOCALBASE}/include/glib/glib-1.2 -I${LOCALBASE}/lib/glib/include"
MAKE_ENV+=	GTK_HDRS="${LOCALBASE}/include/gtk-1.2"
MAKE_ENV+=	LIBIDL_HDRS="${LOCALBASE}/include"

post-install:
	${LN} -f -s ${PREFIX}/jre/plugin/${MACHINE_ARCH}/ns600/libjavaplugin_oji.so ${MOZILLA_PLUGINS_DIR}/

.include "../../net/ORBit/buildlink3.mk"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif

ALL_TARGET+=	images
.if defined(JDK_WITH_BUNDLES) && !empty(JDK_WITH_BUNDLES:M[Yy][Ee][Ss])
ALL_TARGET+=	bundles
.endif

MOTIF_TYPE=	openmotif
PLIST_SRC+=	${.CURDIR}/PLIST

MAKE_FLAGS+=	ALT_DEVTOOLS_PATH=${LOCALBASE}/bin # used to find "zip" and "unzipsfx"
MAKE_ENV+=	ALT_MOTIF_DIR=${MOTIFBASE}
MAKE_ENV+=	BUILD_CLASSIC=yes
MAKE_ENV+=	CLASSPATH=
MAKE_ENV+=	JAVA_COMPILER=NONE
MAKE_ENV+=	JAVA_HOME=
MAKE_FLAGS+=	M4=${M4}
MAKE_ENV+=	OPENWINHOME=${MOTIFBASE}
MAKE_ENV+=	USE_GNU_M4=1
MAKE_ENV+=	USE_PTHREADS=false

SFILES=         content-types.properties
SFILES+=	flavormap.properties
SFILES+=	font.properties
SFILES+=	font.properties.ja
SFILES+=	font.properties.ru
SFILES+=	font.properties.uk
SFILES+=	font.properties.zh
SFILES+=	font.properties.zh_CN
SFILES+=	font.properties.zh_TW
SFILES+=	images/cursors/cursors.properties
SFILES+=	jvm.cfg
SFILES+=	psfont.properties.ja
SFILES+=	psfontj2d.properties
SFILES+=	security/java.policy
SFILES+=	security/java.security

SUPPORT_FILES=	# empty
.for f in ${SFILES}
SUPPORT_FILES+=	${PREFIX}/jre/lib/$f.default ${PREFIX}/jre/lib/$f
.endfor

PATCH_DF=	bsd-jdk131-patches-current.tar.gz
PATCH_DOWNLOAD=	http://www.eyesbeyond.com/freebsddom/java/JDK13SCSLConfirm.html

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
	${ECHO} " from (choose the Download link for Java[tm] 2 SDK 1.3.1):"; \
	${ECHO} "	${SCSL_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " This requires a Sun Community Source Licensing account."; \
	${ECHO} ; \
	${ECHO} " Also, the file ${PATCH_DF} must be fetched into:"; \
	${ECHO} "	${DISTDIR}/${PATCH_DF}"; \
	${ECHO} " from (choose Experimental patchset):"; \
	${ECHO} "	${PATCH_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} "======================================================================"
.endif

post-extract:
	${CHMOD} -R u+w ${WRKSRC}
	@cd ${WRKSRC} && ${GREP} '^mkdir -p ' BUILD | while read line; do \
		${ECHO} $$line; $$line; \
	done
	${MKDIR} ${WRKSRC}/j2sdk1.3.1/src/bsd/include

pre-patch:
	cd ${WRKSRC} && ${PATCH} -s <jdk131.patches
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM} -f

post-build:
.for f in ${SFILES}
	cd ${BUILD_DIRS}/../build/*/jdk-image-${MACHINE_ARCH}/jre/lib && ${MV} -f $f $f.default
.endfor

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	cd ${BUILD_DIRS}/../build/*/jdk-image-${MACHINE_ARCH} && ${PAX} -rw . ${PREFIX}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk
PREFIX=		${JVM_HOME}
