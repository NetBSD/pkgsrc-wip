# $NetBSD: Makefile,v 1.1 2007/06/29 21:19:04 bsadewitz Exp $
#

DISTNAME=	grandr-0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	GTK2 utility for changing RandR settings

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

BUILDLINK_API_DEPENDS+=	xrandr>=1.2:../../x11/libXrandr
BUILDLINK_API_DEPENDS+=	GConf2>=2.0:../../devel/Gconf2
BUILDLINK_API_DEPENDS+=	gtk2>=2.0:../../x11/gtk2

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
