# $NetBSD$

DISTNAME=	crosswrench-0.0
CATEGORIES=	pkgtools

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/niclasr/crosswrench/
COMMENT=	Python wheel installer written in C++
LICENSE=	mit

GIT_REPO=	https://github.com/niclasr/crosswrench.git

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DEXTERNAL_LIBS:BOOL=ON

.include "../../devel/cxxopts/buildlink3.mk"
.include "../../devel/pstreams/buildlink3.mk"
.include "../../devel/pystring/buildlink3.mk"
.include "../../security/botan2/buildlink3.mk"
.include "../../wip/csv2/buildlink3.mk"
.include "../../wip/libzippp/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
