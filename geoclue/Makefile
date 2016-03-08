# $NetBSD: Makefile,v 1.24 2014/05/05 00:47:53 ryoon Exp $

DISTNAME=	geoclue-2.2.0
CATEGORIES=	geography
MASTER_SITES=	https://www.freedesktop.org/software/geoclue/releases/2.2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/GeoClue
COMMENT=	Geoinformation service API and base providers
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS=	intltool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	geoclue.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

# for documentation build
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFIGURE_ARGS=		--disable-3g-source
CONFIGURE_ARGS+=	--disable-cdma-source
CONFIGURE_ARGS+=	--disable-nmea-source
CONFIGURE_ARGS+=	--disable-modem-gps-source
#for test
#.include "../../x11/gtk2/buildlink3.mk"

.include "../../devel/glibmm/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
