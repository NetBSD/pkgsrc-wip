# $NetBSD$

DISTNAME=	libdecaf-1.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ed448goldilocks/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	http://ed448goldilocks.sourceforge.net/
COMMENT=	Implementation of elliptic curve cryptography
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++11
CMAKE_ARGS+=	-DENABLE_TESTS=NO

# These are required to prevent build breakage when tests are enabled
# This is probably due to the auto-generated headers clobbering with
# the #defines
CFLAGS+=	-D_NETBSD_SOURCE

PYTHON_FOR_BUILD_ONLY=		tool

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libdecaf.a

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
