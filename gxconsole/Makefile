# $NetBSD: Makefile,v 1.5 2010/09/11 21:45:51 jihbed Exp $
#

DISTNAME=	gxconsole-0.3.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxconsole/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gxconsole.sourceforge.net/
COMMENT=	Gxconsole is gtk-based reading system console messages like xconsole

PKG_DESTDIR_SUPPORT=		user-destdir
WRKSRC=		${WRKDIR}/gxconsole
GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
