# $NetBSD$

DISTNAME=	libgudev-237
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgudev/237/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://download.gnome.org/sources/libgudev/237/ # TODO: check
COMMENT=	GObject bindings to libudev
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gudev-1.0.pc.in

.include "../../wip/libudev/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
