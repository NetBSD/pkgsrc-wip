# $NetBSD$

DISTNAME=	OpenLara-0.0
GITHUB_PROJECT=	OpenLara
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=XProger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/XProger/OpenLara/
COMMENT=	Classic Tomb Raider open-source engine
LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	OpenLara
GIT_REPO.OpenLara=	git://github.com/XProger/OpenLara.git
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/OpenLara

USE_LANGUAGES=		c c++11

INSTALLATION_DIRS+=	bin
PTHREAD_AUTO_VARS=	YES

# build step adapted from ${WRKSRC}/src/platform/sdl2/build.sh
# TODO: add an option to use GLES
do-build:
	cd ${WRKSRC}/src/platform/sdl2 && \
	${CXX} -o ${WRKSRC}/OpenLara \
		`sdl2-config --cflags` \
		${PTHREAD_CPPFLAGS} ${PTHREAD_CFLAGS} \
		-fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections \
		-DNDEBUG -D__SDL2__ -DGL_GLEXT_PROTOTYPES \
		main.cpp \
		../../libs/stb_vorbis/stb_vorbis.c \
		../../libs/minimp3/minimp3.cpp \
		../../libs/tinf/tinflate.c \
		-I../../ \
		`sdl2-config --libs` -lGL -lm -lrt \
		${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OpenLara ${DESTDIR}${PREFIX}/bin/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
