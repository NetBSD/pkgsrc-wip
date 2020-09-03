# $NetBSD$

DISTNAME=	cJSON-1.7.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaveGamble/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/DaveGamble/cJSON/
COMMENT=	Ultralightweight JSON parser in ANSI C
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DENABLE_CJSON_UTILS=On
TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}

PKGCONFIG_OVERRIDE+=	library_config/libcjson_utils.pc.in
PKGCONFIG_OVERRIDE+=	library_config/libcjson.pc.in

.include "../../mk/bsd.pkg.mk"
