# $NetBSD$

DISTNAME=	trigger-rally-0.6.6.1
CATEGORIES=	games
MASTER_SITES=	https://downloads.sourceforge.net/project/trigger-rally/trigger-0.6.6.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/trigger-rally
COMMENT=	A 3D rally simulation racing game.
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS=	gmake chmod

BUILD_DIRS=	src
BUILD_TARGET=	build
MAKE_FILE=	GNUmakefile

SUBST_CLASSES+=		fix-mk
SUBST_STAGE.fix-mk=	pre-configure
SUBST_MESSAGE.fix-mk=	Fixing makefile.
SUBST_FILES.fix-mk=	src/GNUmakefile
SUBST_SED.fix-mk=	-e "s,/games,/share/games/trigger-rally,g"
SUBST_SED.fix-mk+=	-e "s,$(prefix)/share,$(prefix),g"
SUBST_SED.fix-mk+=	-e "s,/usr/local,${PREFIX},g"
SUBST_SED.fix-mk+=	-e "s,-I'./include', -I'./include' -I${PREFIX}/include,g"

SUBST_CLASSES+=			fix-errors
SUBST_STAGE.fix-errors=		pre-configure
SUBST_MESSAGE.fix-errors=	Fixing compile time errors.
SUBST_FILES.fix-errors=		src/PEngine/util.cpp
SUBST_FILES.fix-errors+=	src/Trigger/main.cpp
SUBST_SED.fix-errors=		-e 's,ErrorStr(),Error(),g'

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing game data paths.
SUBST_FILES.fix-paths=		src/Trigger/main.cpp
SUBST_FILES.fix-paths+=		bin/trigger-rally.config.defs
SUBST_SED.fix-paths=		-e 's,/usr/share/games/trigger-rally,${PREFIX}/share/games/trigger-rally,g'

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/trigger-rally
	${INSTALL_DATA} ${WRKSRC}/bin/trigger-rally ${DESTDIR}${PREFIX}/share/games/trigger-rally/
	${INSTALL_DATA} ${WRKSRC}/bin/trigger-rally.config.defs ${DESTDIR}${PREFIX}/share/games/trigger-rally/
	${INSTALL_DATA} ${WRKSRC}/data/data.zip ${DESTDIR}${PREFIX}/share/games/trigger-rally/
	${INSTALL_DATA} ${WRKSRC}/data/data.md5 ${DESTDIR}${PREFIX}/share/games/trigger-rally/

post-install:
	install -m 0755 -l s -o ${BINOWN} -g ${BINGRP} ${DESTDIR}${PREFIX}/share/games/trigger-rally/trigger-rally ${DESTDIR}${PREFIX}/bin/trigger-rally
	chmod +x ${DESTDIR}${PREFIX}/bin/trigger-rally

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
