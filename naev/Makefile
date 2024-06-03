# $NetBSD: Makefile,v 1.7 2020/11/05 09:08:13 ryoon Exp $

DISTNAME=		naev-0.11.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_SUBMODULES=	naev naev-artwork-production e2d2edab2317d296eb14a830505b1dc41d02dec1 artwork

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naev/naev
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
REPLACE_BASH=	naev-confupdate.sh

CFLAGS+=	-fopenmp
LDFLAGS+=	-lomp -lcamd

GAME_DIR=	${PREFIX}/share/naev/

INSTALL_TARGET=	install install-data-local ${GAME_DIR}

MESON_ARGS+=		-Dndata_path="${GAME_DIR}"

SUBST_CLASSES+=		alloca
SUBST_FILES.alloca+=	meson.build
SUBST_FILES.alloca+=	src/utf8.c
SUBST_SED.alloca+=	-e "s,HAVE_ALLOCA_H,NAEV_HAVE_ALLOCA_H,"
SUBST_STAGE.alloca=	post-extract
SUBST_MESSAGE.alloca=	Avoid symbol conflict with SDL2.

SUBST_CLASSES+=		bash
SUBST_FILES.bash+=	artwork/gfx/outfit/check.sh
SUBST_FILES.bash+=	artwork/gfx/spob/check.sh
SUBST_FILES.bash+=	artwork/gfx/ship/update.sh
SUBST_FILES.bash+=	artwork/snd/music/checkgain.sh
SUBST_SED.bash+=	-e "s,/usr/bin/env ,${PREFIX}/bin/,"
SUBST_STAGE.bash=	post-extract
SUBST_MESSAGE.bash=	Use the pkgsrc bash

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../net/enet/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/suitesparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
