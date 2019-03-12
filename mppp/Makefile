# $NetBSD$

GITHUB_PROJECT=	mppp
DISTNAME=	v0.12
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=bluescarni/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bluescarni/mppp/
COMMENT=	Multiprecision for modern C++
LICENSE=	mozilla-trademark-license

WRKSRC=		${WRKDIR}/mppp-0.12

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
