# $NetBSD$

DISTNAME=	woof_1.1.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fabiangreffrath/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/fabiangreffrath/woof/
COMMENT=	Continuation of Lee Killough's Doom source port MBF
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99
USE_CMAKE=	yes
CMAKE_ARGS+=	-G "Unix Makefiles" ..
CONFIGURE_DIRS=	build
WRKSRC=		${WRKDIR}/woof-${DISTNAME}

pre-configure:
		cd ${WRKSRC}; mkdir build

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
