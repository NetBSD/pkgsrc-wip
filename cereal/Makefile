# $NetBSD$

DISTNAME=	cereal-1.3.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=USCiLab/}
GITHUB_PROJECT=	cereal
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/USCiLab/cereal
COMMENT=	C++11 library for serialization
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

# Requires stubs-32.h on CentOS, not provided by pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DSKIP_PORTABILITY_TEST=ON

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
