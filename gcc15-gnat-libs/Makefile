# $NetBSD: Makefile,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

GCC_PKGNAME=		gcc15-gnat
GCC_DIST_VERSION=	15.1.0

DISTNAME=	gcc-${GCC_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-libs-${GCC_DIST_VERSION}

## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc15-gnat package so that with the dependence pattern
## '{gcc15-gnat,gcc15-gnat-libs}>=15.1.*' pkg_add will choose gcc15-gnat-libs over gcc15-gnat.
PKGREVISION=	1

CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) GNAT support shared libraries
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=	pax

CHECK_SHLIBS_SUPPORTED=	no
CHECK_RELRO_SUPPORTED=	no

## Depend on exactly ${GCC_DIST_VERSION}.
TOOL_DEPENDS+=		${GCC_PKGNAME}-${GCC_DIST_VERSION}{,nb[0-9]*}:../../wip/${GCC_PKGNAME}

.include "../../mk/bsd.prefs.mk"

LIBGCC_SUBPREFIX=	${GCC_PKGNAME}
LIBGCC_PREFIX=		${PREFIX}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
BUILD_DEFS+=		GCC_PKGNAME
BUILD_DEFS+=		GCC_TARGET_MACHINE

LIBRARY_FILES=	${WRKDIR}/library_files

do-build:
	${PKG_INFO} -qL '${GCC_PKGNAME}-${GCC_DIST_VERSION}*' | \
	${SED} -n -e's,^${LIBGCC_PREFIX}/,,p' | \
	${SED} -n -e'/lib\/.*\/crt.*\.o/p' \
		-e'/lib\/.*\/adalib\/lib.*\.so.*/p' \
		-e'/.*\/ada_target_properties/p' \
		-e'/lib\/lib.*\.so.*/p' \
		> ${LIBRARY_FILES}

TARGET_LIBDIR=	${GCC_PKGNAME}/${GCC_TARGET_MACHINE}/lib

do-install:
	${TEST} -d ${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR} || \
		${MKDIR} ${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR}
	cd ${LIBGCC_PREFIX} && \
		${PAX} -rw -s '/^\(.*\/\)\([^\/]*\)/\2/' \
		${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR} <${LIBRARY_FILES}

GENERATE_PLIST+=	${ECHO} '@pkgdir ${TARGET_LIBDIR}' ;
GENERATE_PLIST+=	${SED} -e 's,^\(.*\/\)\([^\/]*\),\2,' ${LIBRARY_FILES} | \
			${SED} -e 's,^,${LIBGCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/lib/,' ;

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
