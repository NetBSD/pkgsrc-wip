# $NetBSD: Makefile,v 1.1.1.1 2005/09/24 07:07:43 gregschenzel Exp $
#

DISTNAME=		tile_0.7.1
CATEGORIES=		wip
MASTER_SITES=		http://www.unixdev.net/downloads/tile/0.7.1/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://tile.unixdev.net/
COMMENT=		X11 Window Tiler

WRKSRC=		${WRKDIR}/tile
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/man/man1
	cp ${WRKSRC}/tile.1 ${PREFIX}/man/man1/tile.1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

