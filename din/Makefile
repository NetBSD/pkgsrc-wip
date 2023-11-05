# $NetBSD: Makefile,v 1.47 2023/09/12 07:55:11 fox Exp $

DISTNAME=	din-57
CATEGORIES=	audio
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dinisnoise.org/
COMMENT=	Open source cross-platform sound synthesizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf autoreconf automake pkg-config gmake
GNU_CONFIGURE=	yes
CXXFLAGS+=	-std=c++11 -E

LIBS+=		-ltcl -lSDL -lGL -lpthread
LIBS.Darwin+=	-lSDLmain -lSDL -Wl,-framework,Cocoa

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fvi || ${ECHO} Ignore the warnings from autoreconf

.include "options.mk"

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../wip/rtaudio/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../wip/sdl12-compat/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
