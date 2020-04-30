# $NetBSD$
#

# use date of commit as has no version only a tag

DISTNAME=	SSVUtilsJson
PKGNAME=	${DISTNAME}-20130714
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	95836250e3a9b65883f22991190e652a455121c1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVUtilsJson
COMMENT=	C++14 utility library for Json
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

MODULES=	${SSVJSONCPP_MODULE} ${SSVUTILS_MODULE}

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF
CMAKE_ARGS+=	-DMODULES=${MODULES:ts;:Q}

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake/${PKGBASE}

post-install:
	${INSTALL_LIB} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/${PKGBASE}

.include "../../wip/SSVJsonCpp/buildlink3.mk"
.include "../../wip/SSVUtils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
