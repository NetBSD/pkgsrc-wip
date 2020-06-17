# $NetBSD: Makefile,v 1.24 2014/05/05 00:47:53 ryoon Exp $

DISTNAME=	geoclue-2.5.3
CATEGORIES=	geography
MASTER_SITES=	https://gitlab.freedesktop.org/geoclue/geoclue/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/GeoClue
COMMENT=	Geoinformation service API and base providers
LICENSE=	gnu-gpl-v2 # or later

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS=	intltool

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	geoclue.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

# for documentation build
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

MESON_ARGS=		-D3g-source=false
MESON_ARGS+=		-Dcdma-source=false
MESON_ARGS+=		-Dnmea-source=false
MESON_ARGS+=		-Dmodem-gps-source=false

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/meson/build.mk"

.include "../../mk/bsd.pkg.mk"
