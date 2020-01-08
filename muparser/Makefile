# $NetBSD$

DISTNAME=	muparser-2.2.6.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=beltoforion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beltoforion.de/article.php?a=muparser
COMMENT=	Parser for mathematical expressions
LICENSE=	mit

MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes
USE_CMAKE=	yes
#USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	build/autoconf/muparser.pc.in

do-test:
	cd ${WRKSRC}/samples/example1 && ${ECHO} quit | LD_LIBRARY_PATH=../../lib ./example1

.include "../../mk/bsd.pkg.mk"
