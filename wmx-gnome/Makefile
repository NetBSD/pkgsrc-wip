# $NetBSD: Makefile,v 1.1.1.1 2011/05/05 13:08:30 ishit Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
