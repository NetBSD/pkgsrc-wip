# $NetBSD: Makefile,v 1.5 2012/11/23 21:30:43 othyro Exp $
#

DISTNAME=	tkimg-1.3-2008-01-16
CATEGORIES=	graphics
MASTER_SITES=	http://www.flightlab.com/~joe/downloads/

MAINTAINER=	egavilan@eie.fceia.unr.edu.ar
HOMEPAGE=	http://www.flightlab.com/~joe/downloads/
COMMENT=	Add support for several image formats to Tk
LICENSE=	2-clause-bsd # XXX ? Same as Tcl

WRKSRC=			${WRKDIR}/tkimg-1.3
GNU_CONFIGURE=		yes
TEST_TARGET=		test
INSTALLATION_DIRS+=	lib/Img${PKGVERSION}.9

.include "options.mk"

.if ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit-vis
.elif ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
