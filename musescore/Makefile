# $NetBSD$

DISTNAME=	MuseScore-2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://ftp.osuosl.org/pub/musescore/releases/MuseScore-2.0.3/
EXTRACT_SUFX=	.zip

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://ftp.osuosl.org/pub/musescore/releases/MuseScore-2.0.3/
COMMENT=	Create, play and print beautiful sheet music
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME} # More than one possibility -- please check manually.

USE_TOOLS+=	make
USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC
#CCFLAGS+=	-fPIC
CMAKE_ARGS+=	-DALSOFT_BACKEND_PORTAUDIO:BOOL=OFF
CMAKE_ARGS+=	-DBUILD_PORTAUDIO:BOOL=OFF

#option(BUILD_JACK    "Build with support for ${JACK_LONGNAME} audio backend.
#jack >= ${JACK_MIN_VERSION} will be needed." ON)
#option(BUILD_PULSEAUDIO "Build with support for Pulseaudio audio backend." ON)
#option(BUILD_ALSA "Build with support for ALSA audio backend." ON)
#option(BUILD_PORTAUDIO "Build with support for Portaudio audio backend." ON)

DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

pre-install:
	cd ${WRKSCR} && make lrelease

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
#.include "../../audio/portaudio/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"


.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
