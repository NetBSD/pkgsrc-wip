# $NetBSD: Makefile,v 1.47 2023/09/12 07:55:11 fox Exp $

DISTNAME=	din-57
CATEGORIES=	audio
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dinisnoise.org/
COMMENT=	Open source cross-platform sound synthesizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoconf autoreconf pkg-config gmake
GNU_CONFIGURE=	yes

CXXFLAGS+=	-std=c++20

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
LIBS+=	-ltcl -lpthread -lSDLmain -lSDL -framework Cocoa -framework OpenGL
.else
LIBS+=	-ltcl -lSDL -lGl -lpthread
.endif

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../wip/sdl12-compat/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
