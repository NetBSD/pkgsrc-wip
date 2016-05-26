# $NetBSD: Makefile,v 1.79 2016/01/25 19:58:45 joerg Exp $
#

DISTNAME=	gnome-control-center-3.16.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-control-center/3.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME3 configuration utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFLICTS+=		gnome2-control-center-[0-9]* control-center-[0-9]*

CPPFLAGS+=		-DDBUS_API_SUBJECT_TO_CHANGE

PKGCONFIG_OVERRIDE+=	libwindow-settings/gnome-window-settings-2.0.pc.in

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	vfsmoduleconfdir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	menudir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	autostartdir=${PREFIX}/share/applications

INSTALLATION_DIRS=	${EGDIR}

GCONF_SCHEMAS+=	control-center.schemas
GCONF_SCHEMAS+=	fontilus.schemas
GCONF_SCHEMAS+=	gnome-control-center.schemas

EGDIR=			${PREFIX}/share/examples/gnome-control-center
CONF_FILES+=		${EGDIR}/gnomecc.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnomecc.menu


#.include "options.mk"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.include "../../wip/colord-gtk/buildlink3.mk"
.include "../../wip/accountsservice/buildlink3.mk"
.include "../../wip/gnome-settings-daemon/buildlink3.mk"
.include "../../wip/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../wip/gnome-panel/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../wip/libpwquality/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
