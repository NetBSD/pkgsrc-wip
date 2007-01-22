# $NetBSD: Makefile,v 1.26 2007/01/22 10:02:19 bsadewitz Exp $
#

DISTNAME=	libXfixes-4.0.3
CATEGORIES=	x11 devel
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=	XRandr's Xfixes extension and library from modular X.org

CONFLICTS+=		Xfixes-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4


GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
