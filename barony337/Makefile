# $NetBSD$

GITHUB_PROJECT=	Barony
DISTNAME=	Barony-3.3.7
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=TurningWheel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TurningWheel/Barony/
COMMENT=	First person rogue-like
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DPNG_NAMES=png16 \
		-DEDITOR_EXE_NAME=barony-editor \
		-DDATA_DIR=ON -DOPENAL_ENABLED=ON

CFLAGS+=	-Wno-write-strings
LDFLAGS+=	-lexecinfo

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
