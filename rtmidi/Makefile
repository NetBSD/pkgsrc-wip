# $NetBSD$

DISTNAME=	rtmidi-5.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.music.mcgill.ca/~gary/rtmidi/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.music.mcgill.ca/~gary/rtmidi/
COMMENT=	Realtime MIDI IO library
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON

PKGCONFIG_OVERRIDE+=	rtmidi.pc.in

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
