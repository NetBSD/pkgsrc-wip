# $NetBSD: Makefile,v 1.9 2013/01/31 03:35:02 jeremy-c-reed Exp $

DISTNAME=	lxpanel-0.8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Lightweight X11 desktop panel from LXDE
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LXDE_CONF=		share/examples/lxde
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config intltool
CONFIGURE_ARGS+=	--with-plugins=none
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${LXDE_CONF}
# plugins may be comma separated:
# possible:
#Possible plugins are:
#			 netstatus, netstat, volume, volumealsa,
#			 cpu, deskno, batt, kbled, xkb, thermal,
#			 cpufreq, monitors, wnckpager
# TODO: maybe I need --enable-indicator-support ??

PKGCONFIG_OVERRIDE+=	lxpanel.pc.in

PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR}/lxpanel/default/panels 	\
		${PKG_SYSCONFDIR}/lxpanel/config		\
		${PKG_SYSCONFDIR}/lxpanel/two_panels/panels

CONF_FILES= ${LXDE_CONF}/xdg/lxpanel/default/config		\
	${PKG_SYSCONFDIR}/lxpanel/default/config 		\
	${LXDE_CONF}/xdg/lxpanel/default/panels/panel  		\
	${PKG_SYSCONFDIR}/lxpanel/default/panels/panel 	\
	${LXDE_CONF}/xdg/lxpanel/two_panels/config 			\
	${PKG_SYSCONFDIR}/lxpanel/two_panels/config 		\
	${LXDE_CONF}/xdg/lxpanel/two_panels/panels/bottom 	\
	${PKG_SYSCONFDIR}/lxpanel/two_panels/panels/bottom 	\
	${LXDE_CONF}/xdg/lxpanel/two_panels/panels/top 		\
	${PKG_SYSCONFDIR}/lxpanel/two_panels/panels/top

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../wip/libfm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
