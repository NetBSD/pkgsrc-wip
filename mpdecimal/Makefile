# $NetBSD$

DISTNAME=	mpdecimal-2.5.1
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
HOMEPAGE=	https://www.bytereef.org/mpdecimal/
COMMENT=	C/C++ arbitrary precision decimal floating point libraries
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
BUILD_TARGET=	default
TEST_TARGET=	check_local

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	CC=gcc CXX=g++

.include "../../mk/bsd.pkg.mk"
