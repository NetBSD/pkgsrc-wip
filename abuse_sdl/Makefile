# $NetBSD: Makefile,v 1.3 2003/06/02 22:48:32 blef Exp $

DISTNAME=		abuse_sdl-0.7.0
CATEGORIES=		games
MASTER_SITES=		http://www.labyrinth.net.au/~trandor/abuse/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} frabs210_unix.src.tar.bz2
SITES_frabs210_unix.src.tar.bz2=	http://www.cs.uidaho.edu/~cass0664/fRaBs/

MAINTAINER=		soren@blef.org
HOMEPAGE=		http://www.labyrinth.net.au/~trandor/abuse/
COMMENT=		Port of the Abuse side scroller to SDL

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

post-patch:
	${SED} -e "s|/usr/local/share/games/abuse|${PREFIX}/share/abuse_sdl|"  \
       	${WRKSRC}/src/sdlport/setup.cpp > ${WRKSRC}/src/sdlport/setup.cpp.new
	${MV} ${WRKSRC}/src/sdlport/setup.cpp.new ${WRKSRC}/src/sdlport/setup.cpp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/abuse_sdl
	cd ${PREFIX}/share/abuse_sdl && \
		(${MV} ${WRKDIR}/frabs210_unix.src/* . && \
		${CHOWN} -R ${SHAREOWN} . && ${CHGRP} -R ${SHAREGRP} . && \
		${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} '{}' ';' && \
		${FIND} . -type d -exec ${CHMOD} ${BINMODE} '{}' ';')

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
