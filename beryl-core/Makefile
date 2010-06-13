# $NetBSD: Makefile,v 1.4 2010/06/13 22:46:57 thomasklausner Exp $
#

DISTNAME=	beryl-core-0.2.1
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://releases.beryl-project.org/0.2.1/
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Core component of the Beryl compositing window manager

.include "../../wip/beryl/Makefile.inc"

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	perl
USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool
USE_LIBTOOL+=	yes


PKGCONFIG_OVERRIDE+=	beryl.pc.in
PKGCONFIG_OVERRIDE+=	berylsettings.pc.in
PKGCONFIG_OVERRIDE+=	libberyldecoration/libberyldecoration.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.beryl
PKG_SUPPORTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
PLIST_SUBST+=	GNOME=""

.include "../../devel/GConf/buildlink3.mk"
.else
PLIST_SUBST+=	GNOME="@comment "

.include "../../devel/glib2/buildlink3.mk"
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
