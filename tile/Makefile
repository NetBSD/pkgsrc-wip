# $NetBSD: Makefile,v 1.2 2005/09/24 08:14:50 gregschenzel Exp $
#

DISTNAME=		tile_0.7.3
PKGNAME=		tile-0.7.3
CATEGORIES=		wip
MASTER_SITES=		http://www.unixdev.net/downloads/tile/0.7.3/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://tile.unixdev.net/
COMMENT=		X11 Window Tiler

WRKSRC=		${WRKDIR}/tile-0.7.3
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
