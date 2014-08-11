# $NetBSD: Makefile,v 1.2 2014/08/11 23:10:13 thomasklausner Exp $

DISTNAME=	dolphin-3.5-src
PKGNAME=	${DISTNAME:S/-src//1}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://dolphin-emu.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dolphin-emu.org/
COMMENT=	Gamecube/Wii/Triforce Emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgmerge pkg-config
GCC_REQD=	4.7

.include "options.mk"

CMAKE_ARGS+=	-DDISABLE_WX=ON # XXX requires wxGTK29
CXXFLAGS+=	-std=gnu++0x -std=c++0x

SUBST_CLASSES+=		soil
SUBST_FILES.soil=	Source/Core/VideoCommon/Src/HiresTextures.cpp
SUBST_MESSAGE.soil=	Fixing SOIL include path.
SUBST_SED.soil=		-e 's|SOIL/SOIL.h|SOIL.h|1'
SUBST_STAGE.soil=	post-patch

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
