# $NetBSD: Makefile,v 1.12 2010/01/18 09:38:18 thomasklausner Exp $
#

DISTNAME=	compiz-0.5.0
PKGREVISION=	7
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_TOOLS+=		pkg-config msgfmt gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

# Let's kick it up a notch!

CONFIGURE_ARGS+= --enable-gconf
CONFIGURE_ARGS+= --enable-schemas-install
CONFIGURE_ARGS+= --enable-place
CONFIGURE_ARGS+= --enable-dbus
CONFIGURE_ARGS+= --enable-dbus-glib
CONFIGURE_ARGS+= --enable-annotate
CONFIGURE_ARGS+= --enable-gtk
CONFIGURE_ARGS+= --enable-metacity
CONFIGURE_ARGS+= --disable-fuse # XXX won't build, see TODO
CONFIGURE_ARGS+= --enable-gnome
CONFIGURE_ARGS+= --disable-inotify
CONFIGURE_ARGS+= --enable-librsvg

GCONF_SCHEMAS+=	gwd.schemas
GCONF_SCHEMAS+=	compiz.schemas
PKGCONFIG_OVERRIDE+=	compiz.pc.in
PKGCONFIG_OVERRIDE+=	libdecoration/libdecoration.pc.in

# walking this dependency graph will bring even the mightiest
# machine to its knees!  Imagine with KDE ... Muauahahaaha. ;)


.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/gnome-control-center/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
