# $NetBSD$

DISTNAME=	mpdecimal-4.0.0
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
HOMEPAGE=	https://www.bytereef.org/mpdecimal/
COMMENT=	C/C++ arbitrary precision decimal floating point libraries
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99

USE_TOOLS+=		gmake
BUILD_TARGET=		default
TEST_TARGET=		check_local

# so that libmpdec++.so find libmpdec.so
CONFIGURE_ARGS+=	LDFLAGS="${COMPILER_RPATH_FLAG}${PREFIX}/lib" LDXXFLAGS="${COMPILER_RPATH_FLAG}${PREFIX}/lib"

PKGCONFIG_OVERRIDE+=	libmpdec/.pc/libmpdec.pc.in
PKGCONFIG_OVERRIDE+=	libmpdec++/.pc/libmpdec++.pc.in

.include "../../mk/bsd.pkg.mk"
