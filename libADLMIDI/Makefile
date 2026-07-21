# $NetBSD$

DISTNAME=	libADLMIDI-1.6.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wohlstand/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/Wohlstand/libADLMIDI/
COMMENT=	Software MIDI synthesizer library with OPL3 emulation
LICENSE=	gnu-gpl-v3

.include "../../devel/cmake/build.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libADLMIDI.pc.in

CMAKE_CONFIGURE_ARGS+=	-DlibADLMIDI_SHARED=ON

.include "../../mk/bsd.pkg.mk"
