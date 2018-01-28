# $NetBSD$
#

DISTNAME=	wayland-1.14.0
CATEGORIES=	graphics
MASTER_SITES=	http://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wayland.freedesktop.org
COMMENT=	Computer display server protocol
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-documentation

PKGCONFIG_OVERRIDE+=	src/wayland-client.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-cursor.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-scanner.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-server.pc.in


pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.include "../../wip/libepoll-shim/buildlink3.mk"
.else
BUILDLINK_TRANSFORM+=    rm:-lepoll-shim
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
