# $NetBSD: Makefile,v 1.55 2015/10/10 01:57:52 ryoon Exp $
#

DISTNAME=	libgweather-3.36.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgweather/3.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Weather information access library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=		gweather.schemas
PKGCONFIG_OVERRIDE+=	data/gweather-3.0.pc.in

REPLACE_PYTHON=		meson/*.py

.include "../../lang/python/application.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/geocode-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.13.5
.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
