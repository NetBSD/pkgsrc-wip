# $NetBSD: Makefile,v 1.7 2012/10/03 18:15:31 asau Exp $
#

DISTNAME=	nautilus-search-tool-0.3.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nautsearchtool/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://nautsearchtool.sourceforge.net/
COMMENT=	Extension to have search files on popup menu

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

# for gnome-search-tool
DEPENDS+=	gnome-utils>=2.26.0:../../misc/gnome-utils

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
