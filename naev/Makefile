# $NetBSD: Makefile,v 1.7 2020/11/05 09:08:13 ryoon Exp $

DISTNAME=	naev-0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naev/naev
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	gmake intltool pkg-config
GNU_CONFIGURE=	yes

DEPENDS+=	bash-[0-9]*:../../shells/bash
REPLACE_BASH=	naev-confupdate.sh

INSTALL_TARGET=	install install-data-local

CONFIGURE_ARGS+=	--enable-debug=no
CONFIGURE_ARGS+=	--enable-lua=shared
CONFIGURE_ARGS+=	--disable-sdltest

INSTALL_MAKE_FLAGS+=	INSTALL_GAME_DIR="${INSTALL_GAME_DIR}"
INSTALL_MAKE_FLAGS+=	INSTALL_GAME_DATA="${INSTALL_GAME_DATA}"

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

# These scripts are not used once
# installed, they appear to be for
# developer use only -- but meson
# installs them anyway
pre-build:
	${RM} ${WRKSRC}/dat/gfx/metadata_sprite.sh
	${RM} ${WRKSRC}/dat/gfx/outfit/check.sh
	${RM} ${WRKSRC}/dat/gfx/planet/check.sh
	${RM} ${WRKSRC}/dat/gfx/ship/update.sh
	${RM} ${WRKSRC}/dat/snd/music/checkgain.sh

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/suitesparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
