# $NetBSD: Makefile,v 1.2 2012/01/09 17:05:22 thomasklausner Exp $
#

DISTNAME=	trayion-0.1.2
CATEGORIES=	x11
MASTER_SITES=	http://trayion.googlecode.com/files/

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://trayion.googlecode.com/
COMMENT=	FreeDesktop trayicon area for Ion3
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	X11_PREFIX=${BUILDLINK_PREFIX.libX11}

USE_TOOLS+=	gmake

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
