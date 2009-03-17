# $NetBSD: Makefile,v 1.1.1.1 2009/03/17 10:30:38 jihbed Exp $
#

DISTNAME=	glista-0.4
CATEGORIES=	time gnome
MASTER_SITES=	http://glista.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://prematureoptimization.org/glista/
COMMENT=	Simple task list management utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+= 	xdg-1.4
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=		--with-gtkspell
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
