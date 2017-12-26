# $NetBSD$

DISTNAME=	f1spirit.src_0.rc9-1615
PKGNAME=	f1spirit-1.0
CATEGORIES=	games
MASTER_SITES=	http://braingames.jorito.net/f1spirit/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f1spirit.jorito.net/
COMMENT=	Remake the Konami MSX1 classic F-1 Spirit
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/f1spirit-0.rc9.1615
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++ c

#LDFLAGS+=	-nostartfiles
CFLAGS+=	-Wno-write-strings

SHAREDIR=		${PREFIX}/share/f1spirit
INSTALLATION_DIRS=	bin ${SHAREDIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_FILES.prefix=	f1spirit.sh
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

pre-patch:
	${CP} ${FILESDIR}/f1spirit ${WRKSRC}/f1spirit.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f1spirit.sh \
	                ${DESTDIR}${PREFIX}/bin/f1spirit
	${INSTALL_PROGRAM} ${WRKSRC}/f1spirit \
	                ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/sound ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/tracks ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/demos ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/graphics ${DESTDIR}${SHAREDIR}
	${CP} -r ${WRKSRC}/sound/ ${WRKSRC}/tracks/ ${WRKSRC}/demos/ ${WRKSRC}/graphics/ ${DESTDIR}${SHAREDIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
