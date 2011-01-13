# $NetBSD: Makefile,v 1.5 2011/01/13 09:56:05 thomasklausner Exp $
#

DISTNAME=	nautilus-search-tool-0.3.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nautsearchtool/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://nautsearchtool.sourceforge.net/
COMMENT=	Extension to have search files on popup menu

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config intltool
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
