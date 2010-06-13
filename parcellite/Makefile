# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:12 thomasklausner Exp $
#

DISTNAME=	parcellite-0.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://xyhthyx.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://parcellite.sourceforge.net/
COMMENT=	Parcellite is a lightweight GTK+ clipboard manager

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl intltool gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
