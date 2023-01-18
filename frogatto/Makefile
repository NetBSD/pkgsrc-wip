# $NetBSD$

DISTNAME=		anura-0
PKGNAME=		frogatto-0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=anura-engine/}
GITHUB_PROJECT=		anura
GITHUB_TAG=		cdb63c9c7b500c1bdf61b405d659851c9903c101

FROGATTO_SHA=		ffea5dcfe0faad22c2840fb239cb6e9c6746b7d6
IMGUI_SHA=		2379a8b3f21642f715a18749fbd0345c4acafa79

FROGATTO=		${FROGATTO_SHA}.tar.gz
IMGUI=			${IMGUI_SHA}.tar.gz
DISTFILES+=		${DEFAULT_DISTFILES} ${FROGATTO} ${IMGUI}

SITES.${FROGATTO}+=	${MASTER_SITE_GITHUB:=frogatto/}frogatto/archive/
SITES.${IMGUI}+=	${MASTER_SITE_GITHUB:=anura-engine/}imgui/archive/

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	The Frogatto and Friends game
LICENSE=	modified-bsd AND mit AND zlib # XXX not true, + cc-by-v3.0 also

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

ANURA_DIRS+=	data
ANURA_DIRS+=	images
ANURA_DIRS+=	modules
ANURA_DIRS+=	music
ANURA_DIRS+=	update

FROGATTO_DIRS+=	data
FROGATTO_DIRS+=	images
FROGATTO_DIRS+=	locale
FROGATTO_DIRS+=	music
FROGATTO_DIRS+=	music_aac
FROGATTO_DIRS+=	po
FROGATTO_DIRS+=	sounds
FROGATTO_DIRS+=	sounds_wav

FROGATTO_FILES+=	master-config.cfg
FROGATTO_FILES+=	module.cfg

# Imgui is a submodule of Anura.
post-extract:
	${RM} -rf ${WRKSRC}/imgui
	${LN} -sf ${WRKDIR}/imgui-${IMGUI:S/.tar.gz//} ${WRKSRC}/imgui

# Called frogatto-launcher on purpose to avoid conflict with source code repo
# for Frogatto.
pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/frogatto.template > ${WRKDIR}/frogatto-launcher

# Copy Frogatto's data into the Anura distribution, but install it as just
# one complete "Frogatto."
pre-install:
	${MKDIR} ${WRKSRC}/modules/frogatto4
	for dir in ${FROGATTO_DIRS}; do											\
		${MKDIR} ${WRKSRC}/modules/frogatto4/$${dir};								\
		cd ${WRKDIR}/frogatto-${FROGATTO_SHA}/$${dir} && ${PAX} -r -w . ${WRKSRC}/modules/frogatto4/$${dir};	\
	done
	for file in ${FROGATTO_FILES}; do										\
		${INSTALL_DATA} ${WRKDIR}/frogatto-${FROGATTO_SHA}/$${file} ${WRKSRC}/modules/frogatto4/$${file};	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/frogatto-launcher ${DESTDIR}${PREFIX}/bin/frogatto
	${INSTALL_PROGRAM} ${WRKSRC}/anura ${DESTDIR}${PREFIX}/libexec/frogatto/anura
	for dir in ${ANURA_DIRS}; do									\
		${MKDIR} ${DESTDIR}${PREFIX}/share/frogatto/$${dir};					\
		cd ${WRKSRC}/$${dir} && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/frogatto/$${dir};	\
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
