# $NetBSD$

DISTNAME=	oneTBB-${PKGVERSION}
PKGNAME=	threadingbuildingblocks-${PKGVERSION}
PKGVERSION=	2020.3
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
GITHUB_PROJECT=	oneTBB
GITHUB_TAG=	${PKGVERSION:S/./_U/}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	http://threadingbuildingblocks.org/
COMMENT=	Library that provides thread building blocks
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64 *-*-earmv6 *-*-earmv7 *-*-i386

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax
BUILD_TARGET=	default
TEST_TARGET=	test

# NOTE: TBB breaks with newer versions of gcc with aggressive DSE, and must
# be built with "-flifetime-dse=1". This should happen automatically, but
# has been found to be somewhat fragile.
# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71388

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Linux
BUILD_OPSYS=	linux
.else
BUILD_OPSYS=	${OPSYS}
.endif

INSTALLATION_DIRS=	include/tbb lib

# Docs are doxygen, but the detailed documentation appears to have moved online.
#
#BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

post-extract:
	${CP}	${FILESDIR}/NetBSD.inc ${WRKSRC}/build/NetBSD.inc; \
	${CP}	${FILESDIR}/NetBSD.clang.inc ${WRKSRC}/build/NetBSD.clang.inc; \
	${CP}	${FILESDIR}/NetBSD.gcc.inc ${WRKSRC}/build/NetBSD.gcc.inc;

do-install:
	cd ${WRKSRC}; \
	${INSTALL_LIB} build/${BUILD_OPSYS}*release/libtbb.so \
		${DESTDIR}${PREFIX}/lib; \
	${INSTALL_LIB} build/${BUILD_OPSYS}*release/libtbbmalloc.so \
		${DESTDIR}${PREFIX}/lib; \
	cd ${WRKSRC}/include/tbb/ && pax -rw . ${DESTDIR}${PREFIX}/include/tbb/;

.include "../../mk/bsd.pkg.mk"
