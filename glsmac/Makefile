# $NetBSD: Makefile,v 1.240 2022/11/23 16:19:06 lubo Exp $
#
# Some environment variables that can help debugging this:
# https://trac.webkit.org/wiki/EnvironmentVariables

DISTNAME=	development
PKGNAME=	${DISTNAME:S/glsmac/glsmac/}
CATEGORIES=	games
MASTER_SITES=	https://github.com/afwbkbc/glsmac/releases
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	zr90004@gmail.com
HOMEPAGE=	https://github.com/afwbkbc/glsmac
COMMENT=	NetBSD port of glsmac game from github
LICENSE=	gnu-agpl-v3

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake SDL2 SDL2_image glew ossp-uuid yaml-cpp

# Avoid million warnings
CFLAGS+=		-Wno-unused-parameter -Wno-undef
CXXFLAGS+=		-Wno-unused-parameter -Wno-undef

# Enabling -gdwarf-2 hits GNU ar limits on file size.
#CTF_SUPPORTED=	no

GCC_REQD+=		17

.include "../../mk/bsd.prefs.mk"

#CMAKE_CONFIGURE_ARGS+=		-DENABLE_X11_TARGET=ON

.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=		-DUSE_LIBDRM=OFF
.endif

CXXFLAGS.SunOS+=	-fpermissive
