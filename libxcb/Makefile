# $NetBSD: Makefile,v 1.2 2006/11/25 16:32:40 jeremy-c-reed Exp $
#

DISTNAME=	libxcb-1.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	X protocol C-language Binding

BUILD_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LDFLAGS}
CONFIGURE_ARGS+=	--disable-build-docs	# or needs doxygen

PKGCONFIG_OVERRIDE+=	xcb-composite.pc.in
PKGCONFIG_OVERRIDE+=	xcb-damage.pc.in
PKGCONFIG_OVERRIDE+=	xcb-dpms.pc.in
PKGCONFIG_OVERRIDE+=	xcb-glx.pc.in
PKGCONFIG_OVERRIDE+=	xcb-randr.pc.in
PKGCONFIG_OVERRIDE+=	xcb-record.pc.in
PKGCONFIG_OVERRIDE+=	xcb-render.pc.in
PKGCONFIG_OVERRIDE+=	xcb-res.pc.in
PKGCONFIG_OVERRIDE+=	xcb-screensaver.pc.in
PKGCONFIG_OVERRIDE+=	xcb-shape.pc.in
PKGCONFIG_OVERRIDE+=	xcb-shm.pc.in
PKGCONFIG_OVERRIDE+=	xcb-sync.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xevie.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xf86dri.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xfixes.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xinerama.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xlib.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xprint.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xtest.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xv.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xvmc.pc.in
PKGCONFIG_OVERRIDE+=	xcb.pc.in

# libXdmcp is optional; adds support for XDM-AUTHORIZATION-1 in
# addition to MIT-MAGIC-COOKIE-1.
.include "../../x11/libXdmcp/buildlink3.mk"

.include "../../wip/xcb-proto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
