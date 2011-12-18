# $NetBSD: Makefile,v 1.3 2011/12/18 14:09:00 absd Exp $

DISTNAME=	lxterminal-0.1.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Desktop-independent VTE-based terminal emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
