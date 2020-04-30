# $NetBSD$
#

# use date of commit as has no version only a tag

DISTNAME=	SSVMenuSystem
PKGNAME=	${DISTNAME}-20130713
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	03d32b26b2880a35d5daa1ad7ab6199a4d19c742

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVMenuSystem
COMMENT=	C++14 lambda-based library for quick creation of menus
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake/${PKGBASE}

post-install:
	${INSTALL_LIB} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
