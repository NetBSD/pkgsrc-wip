# $NetBSD$
#

# use date of commit as has no version only a tag.

DISTNAME=	SSVJsonCpp
PKGNAME=	${DISTNAME}-20130708
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	a45c64c418dc0b1fab1eec52fa70b6a14308c635

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVJsonCpp
COMMENT=	Cleaned up fork of JsonCpp 0.6.0-rc2
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/

.include "../../mk/bsd.pkg.mk"
