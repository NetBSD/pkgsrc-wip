# $NetBSD: Makefile,v 1.2 2003/04/27 12:27:09 cjep Exp $
#
## XXX PKGSRC-WIP:
## This is not ready for prime time.  The still work-in-progress issues:
##
## * The plugin is not built.
## * HotSpot is not built on -current.
## * The package does not build on -current (tar-pax issues, and others).
## * A minor patch from FreeBSD ports is missing and will be added.
#
# Some notes for those working on this package:
#
# * PKGNAME: 1.0.8 means "1.3.1-FCS, patchset 8" (FCS = Sun patch 0).
#
# * Because this all requires SCSL acceptance, the JRE is not
#   actually redistributable.  Thus source building is required, and
#   there's little point in separating JDK and JRE into separate
#   pkgsrc entities.
#
# * There is no LICENSE setting, since obtaining the source tarball
#   already requires having a SCSL-accepted login name and password.
#
# * The Mozilla/OJI plugin is not yet built; conditional framework
#   for this could be added, but making it an unconditional build
#   dependency would put heavy stress on this package at build time
#   for those who don't wish to build it.
#
# * The HotSpot JVM is not yet built, and likely won't work until
#   NetBSD pre-2.0-current pthreads changes settle.
#
# * Building is indirected through the "bundles" special target,
#   which produces wrapped zipfiles.  This is preferred to tarfiles
#   as they *don't* have file ownership information (and will thus
#   re-extract as root) and this is Sun's current preferred
#   distribution format.

DISTNAME=	j2sdk-1_3_1-src
PKGNAME=	jdk13-1.0.8
WRKSRC=		${WRKDIR}
CATEGORIES=	lang
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tar.gz # must be explicitly specified for the ".if exists" below
DISTFILES=	${SCSL_DF} ${PATCH_DF}

MAINTAINER=	tv@pobox.com
HOMEPAGE=	http://www.eyesbeyond.com/freebsddom/java/
COMMENT=	Sun's Java(tm) 2 SDK (SCSL+FreeBSDdom 1.3 release)

BUILD_DEPENDS+=	sun-jdk13>=1:../../lang/sun-jdk13
BUILD_DEPENDS+=	m4-[0-9]*:../../devel/m4
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

RESTRICTED=	"Redistribution of source or binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

EXTRACT_USING_PAX= YES # GNU tar barfs on really deep paths
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PKGINSTALL=	YES

JVM_HOME=	${LOCALBASE}/java/jdk-1.3.1
ONLY_FOR_PLATFORM=	NetBSD-1.[4-9]*-i386 NetBSD-[2-9]*-i386

ALL_TARGET=	all images bundles
BUILD_DIRS=	${WRKSRC}/j2sdk1.3.1/make
CHECK_SHLIBS=	NO # scripts set LD_LIBRARY_PATH
NO_MTREE=	YES # since we change PREFIX below
OWN_DIRS=	${PREFIX}

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	ALT_BOOTDIR=${LOCALBASE}/java/sun-1.3.1
MAKE_ARGS+=	ALT_DEVTOOLS_PATH=${LOCALBASE} # used to find "zip" and "unzipsfx"
MAKE_ENV+=	ALT_MOTIF_DIR=${MOTIFBASE}
MAKE_ENV+=	BUILD_CLASSIC=yes
MAKE_ARGS+=	M4=${LOCALBASE}/bin/gm4
MAKE_ENV+=	OPENWINHOME=${MOTIFBASE}
MAKE_ENV+=	USE_GNU_M4=1

PATCH_DF=	bsd-jdk131-patches-8.tar.gz
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
	${ECHO} " from (choose Patchset 8):"; \
	${ECHO} "	${PATCH_DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} "======================================================================"
.endif

post-extract:
	${CHMOD} -R u+w ${WRKSRC}
	@cd ${WRKSRC} && ${GREP} '^mkdir -p ' BUILD | while read line; do \
		${ECHO} $$line; $$line; \
	done

pre-patch:
	cd ${WRKSRC} && ${PATCH} -s <jdk131.patches
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM} -f

# the * wildcard (third line) pulls out the platform name automatically
post-build:
	@${ECHO_MSG} '=== Sun-style release bundle ".sh" files are now available'
	@${ECHO_MSG} '=== in the following directory:'
	@${ECHO_MSG} '=== ${WRKSRC}/j2sdk1.3.1/build/bsd-i386'

# Extracts from the .sh file, then flattens one directory, and
# fixes .so files to be symlinks.
do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	cd ${PREFIX} && ${ECHO} 'yes' | ${WRKSRC}/j2sdk1.3.1/build/bsd-i386/jdk-1.3.1-*-bsd-i386.sh >/dev/null
	${MV} ${PREFIX}/jdk1.3.1/* ${PREFIX}/
	${RMDIR} ${PREFIX}/jdk1.3.1

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk
PREFIX=		${JVM_HOME}
