# $NetBSD: Makefile,v 1.6 2015/02/24 17:25:10 blef Exp $

DISTNAME=	SFML-2.5.1-sources
PKGNAME=	${DISTNAME:S/-sources//:tl}
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfml-dev.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sfml-dev.org/
COMMENT=	Free multimedia C++ API
LICENSE=	zlib

WRKSRC=			${WRKDIR}/${DISTNAME:S/-sources//}
USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		rm
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
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
