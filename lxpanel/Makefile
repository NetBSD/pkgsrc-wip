# $NetBSD: Makefile,v 1.4 2011/11/21 18:23:54 absd Exp $

DISTNAME=	lxpanel-0.3.999
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Lightweight X11 desktop panel from LXDE

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
CONFIGURE_ARGS+=--with-plugins=none
# TODO: thermal is still built when "none"
# plugins may be comma separated:
# netstatus, netstat, volume, volumealsa, cpu, deskno, batt, kbled, xkb, thermal

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	lxpanel.pc.in

# menu-cache, lxmenu-data

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/menu-cache/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
