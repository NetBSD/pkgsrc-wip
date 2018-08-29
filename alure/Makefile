# $NetBSD$

DISTNAME=	alure-1.2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	bastiangermann@fishpost.de
HOMEPAGE=	http://kcat.strangesoft.net/alure
COMMENT=	Helps manage common tasks with OpenAL applications
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DDUMB=OFF -DDYNLOAD=OFF -DFLUIDSYNTH=OFF -DMODPLUG=ON

PKGCONFIG_OVERRIDE+=	alure-static.pc.in
PKGCONFIG_OVERRIDE+=	alure.pc.in

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
