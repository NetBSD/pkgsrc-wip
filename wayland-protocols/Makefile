# $NetBSD$
#

DISTNAME=	wayland-protocols-1.17
CATEGORIES=	graphics
MASTER_SITES=	http://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wayland.freedesktop.org
COMMENT=	Additional wayland functionality
LICENSE=	mit

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	wayland-protocols.pc.in

.include "../../mk/bsd.pkg.mk"
