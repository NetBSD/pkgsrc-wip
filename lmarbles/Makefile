# $NetBSD: Makefile,v 1.1.1.1 2003/06/12 05:50:36 cubidou Exp $
#

DISTNAME=	lmarbles-1.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-style arcade game

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-profile-path=${LOCALBASE}/share/games

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/manual.html ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/arrow.jpg ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/arrow2.jpg ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/crumble.jpg ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/marbles.jpg ${PREFIX}/share/doc/html/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/teleport.jpg ${PREFIX}/share/doc/html/lmarbles

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
