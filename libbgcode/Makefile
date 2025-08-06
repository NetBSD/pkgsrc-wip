# $NetBSD$

DISTNAME=	libbgcode-20250220
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	libbgcode
GITHUB_TAG=	5041c093b33e2748e76d6b326f2251310823f3df

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
