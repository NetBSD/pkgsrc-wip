# $NetBSD$

DISTNAME=	${COMMIT}
PKGNAME=	libyuv-git-0
CATEGORIES=	devel
MASTER_SITES=	https://chromium.googlesource.com/libyuv/libyuv/+archive/
COMMIT=		1a746db4cee1df36a9de56dd1d13446507106032

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://chromium.googlesource.com/libyuv/libyuv/
COMMENT=	Project that includes YUV scaling and conversion functionality
LICENSE=	modified-bsd AND mpl-2.0

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
FETCH_USING=	curl

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
