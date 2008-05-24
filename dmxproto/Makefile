# $NetBSD: Makefile,v 1.2 2008/05/24 22:31:40 tnn2 Exp $
#

DISTNAME=	dmxproto-2.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
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
