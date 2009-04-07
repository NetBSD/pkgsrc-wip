# $NetBSD: Makefile,v 1.2 2009/04/07 12:21:40 jihbed Exp $
#

DISTNAME=	imagination-1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://ovh.dl.sourceforge.net/sourceforge/imagination/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://imagination.sourceforge.net/
COMMENT=	Imagination a simple and lightweight DVD slideshow maker

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool perl gmake
USE_LANGUAGES=	c c++
USE_DIRS+=	xdg-1.4


.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
