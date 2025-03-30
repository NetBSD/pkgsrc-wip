# $NetBSD$

DISTNAME=	libbgcode-20231123
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	libbgcode
GITHUB_TAG=	8ae75bd0eea622f0e34cae311b3bd065b55eae9b

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.github.com/prusa3d/libbgcode
COMMENT=	Prusa Block & Binary G-code reader/writer/converter
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/heatshrink/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
