# $NetBSD: Makefile,v 1.1 2007/01/23 08:30:42 bsadewitz Exp $
#

DISTNAME=	dmxproto-2.2.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=	Distributed Multi-headed X protocol headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	dmxproto.pc.in


.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
