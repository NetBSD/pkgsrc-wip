# $NetBSD$

DISTNAME=	nlohmann-json-3.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
GITHUB_PROJECT=	json
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://nlohmann.github.io/json/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
