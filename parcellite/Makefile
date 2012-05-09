# $NetBSD: Makefile,v 1.5 2012/05/09 22:24:41 noud4 Exp $
#

DISTNAME=	parcellite-1.0.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parcellite/}

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
