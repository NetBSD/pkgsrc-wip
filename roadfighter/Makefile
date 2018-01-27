# $NetBSD$

DISTNAME=	roadfighter.src_1.0.1269
PKGNAME=	roadfighter-1.0
CATEGORIES=	games
MASTER_SITES=	http://braingames.jorito.net/roadfighter/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roadfighter.jorito.net/
COMMENT=	Remake the Konami MSX classic game Road Fighter
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/roadfighter-1.0.1269
#USE_TOOLS=	gmake
USE_LANGUAGES=	c++ c
CFLAGS+=	-Wno-write-strings

SHAREDIR=		${PREFIX}/share/roadfighter
INSTALLATION_DIRS=	bin ${SHAREDIR}


SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_FILES.prefix=	roadfighter.sh
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

pre-patch:
	${MV} ${WRKSRC}/src/sge/* ${WRKSRC}
	${RMDIR} ${WRKSRC}/src/sge/
	${MV} ${WRKSRC}/src/* ${WRKSRC}
	${CP} ${FILESDIR}/roadfighter ${WRKSRC}/roadfighter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roadfighter.sh \
	                ${DESTDIR}${PREFIX}/bin/roadfighter
	${INSTALL_PROGRAM} ${WRKSRC}/roadfighter \
	                ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/sound ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/fonts ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/maps ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/graphics ${DESTDIR}${SHAREDIR}
	${CP} -r ${WRKSRC}/maps/ ${WRKSRC}/fonts/ ${WRKSRC}/sound/ ${WRKSRC}/graphics/ ${DESTDIR}${SHAREDIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
