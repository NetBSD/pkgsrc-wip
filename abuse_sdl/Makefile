# $NetBSD: Makefile,v 1.11 2005/04/11 21:09:38 tvierling Exp $

DISTNAME=		abuse_sdl-0.7.0
CATEGORIES=		games
MASTER_SITES=		http://www.labyrinth.net.au/~trandor/abuse/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} frabs210_unix.src.tar.bz2

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://www.labyrinth.net.au/~trandor/abuse/
COMMENT=		Port of the Abuse side scroller to SDL

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

SITES_frabs210_unix.src.tar.bz2=       http://www.cs.uidaho.edu/~cass0664/fRaBs/

CPPFLAGS+=-DPREFIX=\"\\\"${PREFIX}\\\"\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/abuse_sdl
	cd ${PREFIX}/share/abuse_sdl && \
		(${CP} -R ${WRKDIR}/frabs210_unix.src/* . && \
		${CHOWN} -R ${SHAREOWN} . && ${CHGRP} -R ${SHAREGRP} . && \
		${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} '{}' ';' && \
		${FIND} . -type d -exec ${CHMOD} ${BINMODE} '{}' ';')

.include "../../graphics/glu/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
