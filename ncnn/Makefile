# $NetBSD$

DISTNAME=	ncnn
GITHUB_TAG=	20240820
PKGNAME=	${DISTNAME}-${GITHUB_TAG}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/Tencent/ncnn/
COMMENT=	Neural network inference computing framework
LICENSE=	modified-bsd AND zlib AND 2-clause-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

.include "../../graphics/opencv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
