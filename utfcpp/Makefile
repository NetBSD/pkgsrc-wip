# $NetBSD$

DISTNAME=	utfcpp-4.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nemtrif/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/nemtrif/utfcpp/
COMMENT=	UTF-8 with C++ in a Portable Way
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
