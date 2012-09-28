# $NetBSD: Makefile,v 1.4 2012/09/28 21:24:37 asau Exp $
#

DISTNAME=	dmxproto-2.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=	Distributed Multi-headed X protocol headers from modular X.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	dmxproto.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
