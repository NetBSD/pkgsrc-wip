# $NetBSD: Makefile,v 1.7 2013/02/01 01:38:00 jeremy-c-reed Exp $

DISTNAME=	lxde-common-0.99.1
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Default configuration settings and scripts for LXDE
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool pkg-config gmake

DEPENDS+=	dbus>=1:../../sysutils/dbus
# Clearlooks is default GTK theme for the LXDE lxsession
DEPENDS+=	gtk2-engines>=0:../../x11/gtk2-engines
DEPENDS+=	lxpanel>=0:../../wip/lxpanel
DEPENDS+=	lxsession>=0:../../x11/lxsession
DEPENDS+=	openbox>=0:../../wm/openbox
DEPENDS+=	xprop>=0:../../x11/xprop

GNU_CONFIGURE=		yes
LXDE_CONF=		share/examples/lxde
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${LXDE_CONF}
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR}/lxpanel/LXDE 		\
			${PKG_SYSCONFDIR}/lxpanel/LXDE/panels 		\
			${PKG_SYSCONFDIR}/lxsession/LXDE 	\
			${PKG_SYSCONFDIR}/openbox/LXDE 		\
			${PKG_SYSCONFDIR}/pcmanfm/LXDE

CONF_FILES+=	${LXDE_CONF}/xdg/lxpanel/LXDE/config			\
				${PKG_SYSCONFDIR}/lxpanel/LXDE/config 			\
				${LXDE_CONF}/xdg/lxpanel/LXDE/panels/panel 		\
				${PKG_SYSCONFDIR}/lxpanel/LXDE/panels/panel		\
				${LXDE_CONF}/xdg/lxsession/LXDE/autostart 		\
				${PKG_SYSCONFDIR}/lxsession/LXDE/autostart  	\
				${LXDE_CONF}/xdg/lxsession/LXDE/desktop.conf 	\
				${PKG_SYSCONFDIR}/lxsession/LXDE/desktop.conf 	\
				${LXDE_CONF}/xdg/openbox/LXDE/menu.xml 			\
				${PKG_SYSCONFDIR}/openbox/LXDE/menu.xml 		\
				${LXDE_CONF}/xdg/openbox/LXDE/rc.xml 			\
				${PKG_SYSCONFDIR}/openbox/LXDE/rc.xml			\
				${LXDE_CONF}/xdg/pcmanfm/LXDE/pcmanfm.conf 		\
				${PKG_SYSCONFDIR}/pcmanfm/LXDE/pcmanfm.conf

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
