# $NetBSD$

DISTNAME=	rtaudio-5.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.music.mcgill.ca/~gary/rtaudio/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.music.mcgill.ca/~gary/rtaudio/
COMMENT=	Realtime audio IO library
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON

PKGCONFIG_OVERRIDE+=	rtaudio.pc.in

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
