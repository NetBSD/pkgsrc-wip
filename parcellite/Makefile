# $NetBSD: Makefile,v 1.1.1.1 2009/03/09 01:42:02 jihbed Exp $
#

DISTNAME=	parcellite-0.9
CATEGORIES=	editors
MASTER_SITES=	http://xyhthyx.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://parcellite.sourceforge.net/
COMMENT=	Parcellite is a lightweight GTK+ clipboard manager

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl intltool gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
