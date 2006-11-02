# $NetBSD: Makefile,v 1.1.1.1 2006/11/02 11:40:00 jsonn Exp $
#

DISTNAME=		libXevie-1.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Event Interceptor Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/evieext/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
