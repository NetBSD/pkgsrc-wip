# $NetBSD: Makefile,v 1.1.1.1 2012/01/17 13:26:29 jihbed Exp $
#

DISTNAME=	tile-0.8.4.0
PKGNAME=	tk${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	http://garr.dl.sourceforge.net/project/tktable/tile/tile-0-8-4-0/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://tktable.sourceforge.net/tile/
COMMENT=	Improved themeing engine for Tk
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11:Q}/lib
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
