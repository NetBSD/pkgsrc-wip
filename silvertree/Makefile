# $NetBSD: Makefile,v 1.1.1.1 2007/09/03 19:24:05 thomasklausner Exp $
#

DISTNAME=	silvertree-0.1
CATEGORIES=	games
MASTER_SITES=	http://silvertree.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.silvertreerpg.org/
COMMENT=	Silver Tree, an open source role playing game

WRKSRC=		${WRKDIR}/silvertree
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CFLAGS+=	 -I${BUILDLINK_PREFIX.MesaLib}/include/GL
CFLAGS+=	 -I${BUILDLINK_PREFIX.boost-libs}/include/boost

INSTALLATION_DIRS=	bin libexec \
			share/silvertree/data share/silvertree/images \
			share/silvertree/images/items \
			share/silvertree/images/portraits \
			share/silvertree/images/units

post-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/silvertree
	${ECHO} "cd ${PREFIX}/share/silvertree" >> ${WRKSRC}/silvertree
	${ECHO} "${PREFIX}/libexec/silvertree" >> ${WRKSRC}/silvertree

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/silvertree ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/game ${PREFIX}/libexec/silvertree
	${INSTALL_DATA} ${WRKSRC}/map[-23c]* ${PREFIX}/share/silvertree
	${INSTALL_DATA} ${WRKSRC}/*ttf ${PREFIX}/share/silvertree
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/silvertree/data
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/silvertree/images
	${INSTALL_DATA} ${WRKSRC}/images/items/* \
		${PREFIX}/share/silvertree/images/items
	${INSTALL_DATA} ${WRKSRC}/images/portraits/* \
		${PREFIX}/share/silvertree/images/portraits
	${INSTALL_DATA} ${WRKSRC}/images/units/* \
		${PREFIX}/share/silvertree/images/units

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
