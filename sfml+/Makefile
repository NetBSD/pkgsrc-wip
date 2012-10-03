# $NetBSD: Makefile,v 1.1 2012/10/03 15:05:59 othyro Exp $
#

DISTNAME=	SFML-1.6-sdk-linux-64
PKGNAME=	${DISTNAME:tl:S/-/+-/1:S/-sdk-linux-64//}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sfml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sfml.sourceforge.net/
COMMENT=	Free multimedia C++ API
LICENSE=	zlib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/SFML-1.6
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
CPPFLAGS+=		-I${BUILDLINK_PREFIX.glu}/include
CPPFLAGS+=		-I${BUILDLINK_PREFIX.freetype2}/include/freetype2
LDFLAGS+=		-L${BUILDLINK_PREFIX.libsndfile}/lib
MAKE_ENV+=		DESTDIR=${DESTDIR}${PREFIX}
INSTALL_ENV=		PREFIX=${PREFIX}
INSTALLATION_DIRS+=	include/SFML/Audio include/SFML/Graphics
INSTALLATION_DIRS+=	include/SFML/Network/Unix include/SFML/Network/Win32
INSTALLATION_DIRS+=	include/SFML/System/Unix include/SFML/System/Win32
INSTALLATION_DIRS+=	include/SFML/Window lib

.include "options.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
