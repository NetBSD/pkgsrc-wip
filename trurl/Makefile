# $NetBSD$

DISTNAME=	trurl-0.15
CATEGORIES=	www
MASTER_SITES=	https://curl.se/trurl/dl/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://curl.se/trurl/
COMMENT=	Command line tool for URL parsing and manipulation
# not completely, but near enough
LICENSE=	mit

USE_TOOLS+=	gmake

INSTALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

BUILD_TARGET=	trurl
TEST_TARGET=	test

PYTHON_FOR_BUILD_ONLY=	test

.include "../../lang/python/application.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
