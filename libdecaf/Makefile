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
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS:Q}
CMAKE_ARGS+=	-DCMAKE_CPP_FLAGS:STRING=${CPPFLAGS:Q}
CMAKE_ARGS+=	-DCMAKE_C_FLAGS:STRING=${CFLAGS:Q}

# These are required to prevent build breakage when tests are enabled
# This is probably due to the auto-generated headers clobbering with
# the #defines
CXXFLAGS+=	-D_NETBSD_SOURCE
CPPFLAGS+=	-D_NETBSD_SOURCE
CFLAGS+=	-D_NETBSD_SOURCE

PYTHON_FOR_BUILD_ONLY=		tool

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libdecaf.a

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
