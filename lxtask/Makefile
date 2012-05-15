# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:27:08 jeremy-c-reed Exp $

DISTNAME=	lxtask-0.1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Lightweight desktop-independent task manager

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
#USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libwnck/buildlink3.mk"
#.include "../../wip/menu-cache/buildlink3.mk"
#.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
