# $NetBSD: Makefile,v 1.1.1.1 2003/05/19 19:47:18 blef Exp $

DISTNAME=		abuse_sdl-0.7.0
CATEGORIES=		games
MASTER_SITES=		http://www.labyrinth.net.au/~trandor/abuse/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} abuse_datafiles.tar.gz

MAINTAINER=		soren@blef.org
HOMEPAGE=		http://www.labyrinth.net.au/~trandor/abuse/
COMMENT=		port of the Abuse game to SDL

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

post-patch:
	${SED} -e "s|/usr/local/share/games/abuse|${PREFIX}/share/abuse_sdl|"  \
       	${WRKSRC}/src/sdlport/setup.cpp > ${WRKSRC}/src/sdlport/setup.cpp.new
	${MV} ${WRKSRC}/src/sdlport/setup.cpp.new \
		${WRKSRC}/src/sdlport/setup.cpp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/abuse_sdl
	cd ${PREFIX}/share/abuse_sdl && \
	${GZCAT} ${DISTDIR}/abuse_datafiles.tar.gz | ${GTAR} xf - && \
	${CHOWN} -R ${SHAREOWN} . && \
	${CHGRP} -R ${SHAREGRP} . && \
	${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} '{}' ';' && \
	${FIND} . -type d -exec ${CHMOD} ${BINMODE} '{}' ';'

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
