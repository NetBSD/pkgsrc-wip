# $NetBSD$

DISTNAME=		anura-0
PKGNAME=		frogatto-4.28
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_PROJECT=		anura
GITHUB_TAG=		cdb63c9c7b500c1bdf61b405d659851c9903c101

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	The Frogatto and Friends game
LICENSE=	modified-bsd AND mit AND zlib # XXX + cc-by-v3.0 also

GITHUB_SUBMODULES+=	\
	anura-engine imgui 2379a8b3f21642f715a18749fbd0345c4acafa79 imgui

# The Frogatto data files aren't actually a submodule of Anura, but they need
# to end up "inside" the Anura source anyway, so this works well.
GITHUB_SUBMODULES+=	\
	dressupgeekout frogatto dressupgeekout-${PKGVERSION_NOREV} modules/frogatto4

USE_LANGUAGES=	c c++
GCC_REQD+=	4.8
USE_TOOLS+=	gmake pax pkg-config

# Anura provides the game engine, which needs to be compiled. Frogatto is
# simply the game data, no compiliation needed.
WRKSRC=		${WRKDIR}/anura-${GITHUB_TAG}

CFLAGS+=	-Wno-sign-compare
CFLAGS+=	-Wno-deprecated-declarations
CFLAGS+=	-Wno-strict-aliasing

.if "${OPSYS}" == "NetBSD"
LDFLAGS+=	-lexecinfo
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec/frogatto
INSTALLATION_DIRS+=	share/frogatto

ANURA_SHARE_DEST=	${DESTDIR}${PREFIX}/share/frogatto
FROGATTO_MODULE_DEST=	${ANURA_SHARE_DEST}/modules/frogatto4

ANURA_DIRS+=		data
ANURA_DIRS+=		images
ANURA_DIRS+=		music
ANURA_DIRS+=		update
ANURA_DIRS+=		modules/gui
ANURA_DIRS+=		modules/icons
ANURA_DIRS+=		modules/lib_2d
ANURA_DIRS+=		modules/tbs

FROGATTO_DIRS+=		data
FROGATTO_DIRS+=		images
FROGATTO_DIRS+=		locale
FROGATTO_DIRS+=		music
FROGATTO_DIRS+=		music_aac
FROGATTO_DIRS+=		po
FROGATTO_DIRS+=		sounds
FROGATTO_DIRS+=		sounds_wav

FROGATTO_FILES+=	master-config.cfg
FROGATTO_FILES+=	module.cfg
FROGATTO_FILES+=	LICENSE

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/frogatto.template > ${WRKDIR}/frogatto

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/frogatto ${DESTDIR}${PREFIX}/bin/frogatto
	${INSTALL_PROGRAM} ${WRKSRC}/anura ${DESTDIR}${PREFIX}/libexec/frogatto/anura
	for dir in ${ANURA_DIRS}; do							\
		${MKDIR} ${ANURA_SHARE_DEST}/$${dir};					\
		cd ${WRKSRC}/$${dir} && ${PAX} -r -w . ${ANURA_SHARE_DEST}/$${dir};	\
	done
	for dir in ${FROGATTO_DIRS}; do										\
		${MKDIR} ${FROGATTO_MODULE_DEST}/$${dir};							\
		cd ${WRKSRC}/modules/frogatto4/$${dir} && ${PAX} -r -w . ${FROGATTO_MODULE_DEST}/$${dir};	\
	done
	for file in ${FROGATTO_FILES}; do							\
		${INSTALL_DATA} ${WRKSRC}/modules/frogatto4/$${file} ${FROGATTO_MODULE_DEST};	\
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
