# $NetBSD$

COMMIT=     a8c181050c202854ae32433164e6bd5d1e7c4368
PKGNAME=    libyuv-git
DISTNAME=	${COMMIT}
CATEGORIES=	devel
MASTER_SITES=	https://chromium.googlesource.com/libyuv/libyuv/+archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://chromium.googlesource.com/libyuv/libyuv/
COMMENT=	project that includes YUV scaling and conversion functionality
LICENSE=	modified-bsd AND mpl-2.0

WRKSRC=		${WRKDIR}/
USE_CMAKE=  yes
USE_LANGUAGES= c c++

.include "../../mk/jpeg.buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
