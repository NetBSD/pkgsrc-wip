# $NetBSD: Makefile,v 1.6 2003/08/30 16:51:00 blef Exp $

DISTNAME=		abuse_sdl-0.7.0
CATEGORIES=		games
MASTER_SITES=		http://www.labyrinth.net.au/~trandor/abuse/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} frabs210_unix.src.tar.bz2

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://www.labyrinth.net.au/~trandor/abuse/
COMMENT=		Port of the Abuse side scroller to SDL

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

SITES_frabs210_unix.src.tar.bz2=       http://www.cs.uidaho.edu/~cass0664/fRaBs/

CFLAGS+=-DPREFIX=\"\\\"${PREFIX}\\\"\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/abuse_sdl
	cd ${PREFIX}/share/abuse_sdl && \
		(${CP} -R ${WRKDIR}/frabs210_unix.src/* . && \
		${CHOWN} -R ${SHAREOWN} . && ${CHGRP} -R ${SHAREGRP} . && \
		${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} '{}' ';' && \
		${FIND} . -type d -exec ${CHMOD} ${BINMODE} '{}' ';')

.include "../../graphics/glu/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
