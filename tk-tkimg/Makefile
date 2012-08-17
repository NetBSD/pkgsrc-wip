# $NetBSD: Makefile,v 1.2 2012/08/17 18:21:28 mwilhelmy Exp $
#

DISTNAME=	tkimg-1.3-2008-01-16
PKGNAME=        tkimg-1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.flightlab.com/~joe/downloads/

MAINTAINER=	egavilan@eie.fceia.unr.edu.ar
HOMEPAGE=	http://www.flightlab.com/~joe/downloads/
COMMENT=	Add support for several image formats to Tk
#LICENSE=	# Same as Tcl

WRKSRC=		${WRKDIR}/tkimg-1.3
GNU_CONFIGURE=	yes
TEST_TARGET=	test

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
