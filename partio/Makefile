# $NetBSD$

DISTNAME=		partio-1.17.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=wdas/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.disneyanimation.com/open-source/partio/
COMMENT=		Library for handling standard particle formats
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++14

CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_SHARED_LIBS:BOOL=ON

# https://github.com/wdas/partio/issues/104
# https://github.com/wdas/partio/issues/17
# see files src/tools/part*.py in the distfile
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

.include "../../devel/cmake/build.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
