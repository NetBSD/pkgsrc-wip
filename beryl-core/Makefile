# $NetBSD: Makefile,v 1.1.1.1 2007/06/25 08:22:46 dauphing Exp $
#

#DISTNAME=	compiz-0.5.0
DISTNAME=	beryl-core-0.2.1
CATEGORIES=	wm x11
MASTER_SITES=	http://public.enst.fr/beryl/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.go-compiz.org/
COMMENT=	Compositing window manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

#GCONF2_SCHEMAS+=	gwd.schemas
#GCONF2_SCHEMAS+=	compiz.schemas
PKGCONFIG_OVERRIDE+=	berylsettings.pc.in
PKGCONFIG_OVERRIDE+=	libdecoration/libdecoration.pc.in

USE_TOOLS+=		autoconf autoheader pkg-config gmake
#pre-configure:
#	cd ${WRKSRC}; autoconf; autoheader

#CONFIGURE_ARGS+=	--disable-inotify
#CFLAGS=			-g
#CFLAGS.SunOS+=		-I/usr/pkg/include
#LDFLAGS=		-g
#LDFLAGS.SunOS=		-g

#PKG_SUPPORTED_OPTIONS=	gnome kde
#PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz
#PKG_OPTIONS.compiz+=	gnome
#.include "../../mk/bsd.options.mk"

# this is as much as needed for the basic window decorator
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

#.if !empty(PKG_OPTIONS:Mgnome)
#CONFIGURE_ARGS+=	--enable-librsvg
#PLIST_SUBST+=		GNOME=""
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
#.else
#PLIST_SUBST+=		GNOME="@comment "
#.endif

#.if !empty(PKG_OPTIONS:Mkde)
#PLIST_SUBST+=		KDE=""
#.include "../../x11/kdebase3/buildlink3.mk"
#.include "../../sysutils/dbus-qt3/buildlink3.mk"
#.else
#PLIST_SUBST+=		KDE="@comment "
#.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
