# $NetBSD: Makefile,v 1.9 2013/01/31 03:35:02 jeremy-c-reed Exp $

DISTNAME=	lxpanel-0.8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Lightweight X11 desktop panel from LXDE

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config intltool
CONFIGURE_ARGS+=--with-plugins=none
# plugins may be comma separated:
# possible:
#Possible plugins are:
#			 netstatus, netstat, volume, volumealsa,
#			 cpu, deskno, batt, kbled, xkb, thermal,
#			 cpufreq, monitors, wnckpager
# TODO: maybe I need --enable-indicator-support ??

PKGCONFIG_OVERRIDE+=	lxpanel.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../wip/libfm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
