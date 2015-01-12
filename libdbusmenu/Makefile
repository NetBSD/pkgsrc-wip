# $NetBSD: Makefile,v 1.10 2015/01/12 05:13:24 obache Exp $
#

DISTNAME=	libdbusmenu-12.10.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/dbusmenu/12.10/12.10.2/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/dbusmenu/
COMMENT=	Small library created by pulling some code from indicator-applet
LICENSE=	gnu-lgpl-v3 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # xsltproc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt msgmerge intltool pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libdbusmenu-glib/dbusmenu-glib-0.4.pc.in
PKGCONFIG_OVERRIDE+=	libdbusmenu-gtk/dbusmenu-gtk3-0.4.pc.in
PKGCONFIG_OVERRIDE+=	libdbusmenu-gtk/dbusmenu-gtk-0.4.pc.in
PKGCONFIG_OVERRIDE+=	tests/dbusmenu-jsonloader-0.4.pc.in

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		HAVE_VALGRIND_TRUE=
CONFIGURE_ENV+=		HAVE_VALGRIND_FALSE='\#'

REPLACE_PYTHON+=	tools/dbusmenu-bench

.include "../../lang/python/application.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.libX11+=	libX11>=1.3
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
