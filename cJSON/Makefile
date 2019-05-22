# $NetBSD$

GITHUB_PROJECT=	cJSON
DISTNAME=	v1.7.12
PKGNAME=	${GITHUB_PROJECT}-1.7.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaveGamble/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/DaveGamble/cJSON/
COMMENT=	Ultralightweight JSON parser in ANSI C
LICENSE=	mit

WRKSRC=		${WRKDIR}/cJSON-1.7.12
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	library_config/libcjson_utils.pc.in
PKGCONFIG_OVERRIDE+=	library_config/libcjson.pc.in

.include "../../mk/bsd.pkg.mk"
