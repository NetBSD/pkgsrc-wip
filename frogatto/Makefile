# $NetBSD$

PKGNAME=		frogatto-0
CATEGORIES=		games
GIT_REPOSITORIES=	anura frogatto

GIT_REPO.anura=		https://github.com/anura-engine/anura.git
GIT_REVISION.anura=	e837e63ea88b8426dafd9414f0fdd7f30ab58102
GIT_BRANCH.anura=	trunk

GIT_REPO.frogatto=	https://github.com/frogatto/frogatto.git
GIT_REVISION.frogatto=	8b0351854518af25b553c7fd50f6f2afb6d5e71b
GIT_BRANCH.frogatto=	master

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	Frogatto and Friends
LICENSE=	modified-bsd AND mit AND zlib # XXX not true, + cc-by-v3.0 also

USE_LANGUAGES=	c c++
GCC_REQD+=	4.8
USE_TOOLS+=	gmake pkg-config

# Anura provides the game engine, which needs to be compiled. Frogatto is
# simply the game data, no compiliation needed.
WRKSRC=		${WRKDIR}/anura

CFLAGS+=	-Wno-sign-compare
CFLAGS+=	-Wno-deprecated-declarations

.if "${OPSYS}" == "NetBSD"
LDFLAGS+=	-lexecinfo
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec/frogatto
INSTALLATION_DIRS+=	share/frogatto

ANURA_DIRS=	# defined
ANURA_DIRS+=	data
ANURA_DIRS+=	images
ANURA_DIRS+=	modules
ANURA_DIRS+=	music
ANURA_DIRS+=	update

FROGATTO_DIRS=	# defined
FROGATTO_DIRS+=	data
FROGATTO_DIRS+=	images
FROGATTO_DIRS+=	locale
FROGATTO_DIRS+=	music
FROGATTO_DIRS+=	music_aac
FROGATTO_DIRS+=	po
FROGATTO_DIRS+=	sounds
FROGATTO_DIRS+=	sounds_wav

FROGATTO_FILES=		# defined
FROGATTO_FILES+=	master-config.cfg
FROGATTO_FILES+=	module.cfg

# The call to pax(1) from wip/mk/git-package.mk complains of file names that
# are too long, related to the Xcode project in the MacOS directory. So, use
# this opportunity to remove that and tons of other inessential files.
post-fetch:
	${RM} -rf ${WRKDIR}/anura/MacOS
	${RM} -rf ${WRKDIR}/anura/vs2013

# Called frogatto-launcher on purpose to avoid conflict with source code repo
# for Frogatto.
pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/frogatto.template > ${WRKDIR}/frogatto-launcher

# Copy Frogatto's data into the Anura distribution, but install it as just
# one complete "Frogatto."
pre-install:
	${MKDIR} ${WRKDIR}/anura/modules/frogatto4
	for dir in ${FROGATTO_DIRS}; do										\
		${MKDIR} ${WRKDIR}/anura/modules/frogatto4/$${dir};						\
		cd ${WRKDIR}/frogatto/$${dir} && ${PAX} -r -w . ${WRKDIR}/anura/modules/frogatto4/$${dir};	\
	done
	for file in ${FROGATTO_FILES}; do							\
		${CP} ${WRKDIR}/frogatto/$${file} ${WRKDIR}/anura/modules/frogatto4/$${file};	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/frogatto-launcher ${DESTDIR}${PREFIX}/bin/frogatto
	${INSTALL_PROGRAM} ${WRKDIR}/anura/anura ${DESTDIR}${PREFIX}/libexec/frogatto/anura
	for dir in ${ANURA_DIRS}; do										\
		${MKDIR} ${DESTDIR}${PREFIX}/share/frogatto/$${dir};						\
		cd ${WRKDIR}/anura/$${dir} && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/frogatto/$${dir};	\
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
