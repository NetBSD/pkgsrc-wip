# $NetBSD$

PKGNAME=	libyuv-git-0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lemenkov/libyuv
COMMENT=	Project that includes YUV scaling and conversion functionality
LICENSE=	modified-bsd AND mpl-2.0

GIT_REPOSITORIES=	libyuv
GIT_REPO.libyuv=	https://github.com/lemenkov/libyuv.git
GIT_REVISION.libyuv=	1a746db4cee1df36a9de56dd1d13446507106032
WRKSRC=			${WRKDIR}/libyuv

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../wip/mk/git-package.mk"

.include "../../mk/bsd.pkg.mk"
