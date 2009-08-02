# $NetBSD: Makefile,v 1.3 2009/08/02 22:54:16 jihbed Exp $
#

DISTNAME=	gconf-cleaner-0.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://gconf-cleaner.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/gconf-cleaner/
COMMENT=	Cleaning tool for GConf

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool gmake
USE_LANGUAGES=	c c++

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
