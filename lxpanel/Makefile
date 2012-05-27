# $NetBSD: Makefile,v 1.6 2012/05/27 00:06:48 jeremy-c-reed Exp $

DISTNAME=	lxpanel-0.5.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Lightweight X11 desktop panel from LXDE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
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
.include "../../wip/menu-cache/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
