# $NetBSD$
#

DISTNAME=	wayland-1.9.90
CATEGORIES=	graphics
MASTER_SITES=	http://rainbow-runner.nl/freebsd/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wayland.freedesktop.org
COMMENT=	Computer display server protocol
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS+=	--disable-documentation

PKGCONFIG_OVERRIDE+=	src/wayland-client.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-cursor.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-scanner.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-server.pc.in

.include "../../devel/libffi/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
