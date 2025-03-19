# $NetBSD$

DISTNAME=	geocode-glib-3.26.4
PKGNAME=	${DISTNAME:S/glib/glib2/}
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/geocode-glib/${PKGVERSION_NOREV:R}/}
CATEGORIES=	geography gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/geocode-glib/
COMMENT=	GNOME convenience library for geocoding
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_TOOLS+=	pkg-config xgettext

PYTHON_FOR_BUILD_ONLY=	tool

MESON_ARGS+=	-Dsoup2=false

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/geocode-glib-2.0.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
