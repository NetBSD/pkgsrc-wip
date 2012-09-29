# $NetBSD: Makefile,v 1.7 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=	gconf-cleaner-0.0.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://gconf-cleaner.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/gconf-cleaner/
COMMENT=	Cleaning tool for GConf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool gmake
USE_LANGUAGES=	c c++

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
