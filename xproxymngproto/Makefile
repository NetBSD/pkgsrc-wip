# $NetBSD$

DISTNAME=	xproxymanagementprotocol-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=	Proxy manager headers
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	xproxymngproto.pc.in

.include "../../mk/bsd.pkg.mk"
