# $NetBSD$

GITHUB_PROJECT=	piranha
DISTNAME=	v0.11
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=bluescarni/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bluescarni/piranha
COMMENT=	The Piranha computer algebra system
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

WRKSRC=		${WRKDIR}/piranha-0.11

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers-1.69.*
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
